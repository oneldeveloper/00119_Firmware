#include <stdbool.h>
#include <stdint.h>
#include "adxl34x.h"


/* ADXL345/6 Register Map */
#define DEVID		0x00	/* R   Device ID */
#define THRESH_TAP	0x1D	/* R/W Tap threshold */
#define OFSX		0x1E	/* R/W X-axis offset */
#define OFSY		0x1F	/* R/W Y-axis offset */
#define OFSZ		0x20	/* R/W Z-axis offset */
#define DUR		0x21	/* R/W Tap duration */
#define LATENT		0x22	/* R/W Tap latency */
#define WINDOW		0x23	/* R/W Tap window */
#define THRESH_ACT	0x24	/* R/W Activity threshold */
#define THRESH_INACT	0x25	/* R/W Inactivity threshold */
#define TIME_INACT	0x26	/* R/W Inactivity time */
#define ACT_INACT_CTL	0x27	/* R/W Axis enable control for activity and */
				/* inactivity detection */
#define THRESH_FF	0x28	/* R/W Free-fall threshold */
#define TIME_FF		0x29	/* R/W Free-fall time */
#define TAP_AXES	0x2A	/* R/W Axis control for tap/double tap */
#define ACT_TAP_STATUS	0x2B	/* R   Source of tap/double tap */
#define BW_RATE		0x2C	/* R/W Data rate and power mode control */
#define POWER_CTL	0x2D	/* R/W Power saving features control */
#define INT_ENABLE	0x2E	/* R/W Interrupt enable control */
#define INT_MAP		0x2F	/* R/W Interrupt mapping control */
#define INT_SOURCE	0x30	/* R   Source of interrupts */
#define DATA_FORMAT	0x31	/* R/W Data format control */
#define DATAX0		0x32	/* R   X-Axis Data 0 */
#define DATAX1		0x33	/* R   X-Axis Data 1 */
#define DATAY0		0x34	/* R   Y-Axis Data 0 */
#define DATAY1		0x35	/* R   Y-Axis Data 1 */
#define DATAZ0		0x36	/* R   Z-Axis Data 0 */
#define DATAZ1		0x37	/* R   Z-Axis Data 1 */
#define FIFO_CTL	0x38	/* R/W FIFO control */
#define FIFO_STATUS	0x39	/* R   FIFO status */
#define TAP_SIGN	0x3A	/* R   Sign and source for tap/double tap */

/* DEVIDs */
#define ID_ADXL345	0xE5

/* INT_ENABLE/INT_MAP/INT_SOURCE Bits */
#define DATA_READY	(1 << 7)
#define SINGLE_TAP	(1 << 6)
#define DOUBLE_TAP	(1 << 5)
#define ACTIVITY	(1 << 4)
#define INACTIVITY	(1 << 3)
#define FREE_FALL	(1 << 2)
#define WATERMARK	(1 << 1)
#define OVERRUN		(1 << 0)

/* ACT_INACT_CONTROL Bits */
#define ACT_ACDC	(1 << 7)
#define ACT_X_EN	(1 << 6)
#define ACT_Y_EN	(1 << 5)
#define ACT_Z_EN	(1 << 4)
#define INACT_ACDC	(1 << 3)
#define INACT_X_EN	(1 << 2)
#define INACT_Y_EN	(1 << 1)
#define INACT_Z_EN	(1 << 0)

/* TAP_AXES Bits */
#define SUPPRESS	(1 << 3)
#define TAP_X_EN	(1 << 2)
#define TAP_Y_EN	(1 << 1)
#define TAP_Z_EN	(1 << 0)

/* ACT_TAP_STATUS Bits */
#define ACT_X_SRC	(1 << 6)
#define ACT_Y_SRC	(1 << 5)
#define ACT_Z_SRC	(1 << 4)
#define ASLEEP		(1 << 3)
#define TAP_X_SRC	(1 << 2)
#define TAP_Y_SRC	(1 << 1)
#define TAP_Z_SRC	(1 << 0)

/* BW_RATE Bits */
#define LOW_POWER	(1 << 4)
#define RATE(x)		((x) & 0xF)

/* POWER_CTL Bits */
#define PCTL_LINK	(1 << 5)
#define PCTL_AUTO_SLEEP (1 << 4)
#define PCTL_MEASURE	(1 << 3)
#define PCTL_SLEEP	(1 << 2)
#define PCTL_WAKEUP(x)	((x) & 0x3)

/* DATA_FORMAT Bits */
#define SELF_TEST	(1 << 7)
#define SPI		(1 << 6)
#define INT_INVERT	(1 << 5)
#define FULL_RES	(1 << 3)
#define JUSTIFY		(1 << 2)
#define RANGE(x)	((x) & 0x3)
#define RANGE_PM_2g		0
#define RANGE_PM_4g		1
#define RANGE_PM_8g		2
#define RANGE_PM_16g	3

typedef struct {
    const uint8_t   dev_id; 
    uint8_t thresh_tap; 
    int8_t  offset_x; 
    int8_t  offset_y; 
    int8_t  offset_z;
    /*The DUR register is eight bits and contains an unsigned time
    value representing the maximum time that an event must be
    above the THRESH_TAP threshold to qualify as a tap event. The
    scale factor is 625 μs/LSB. A value of 0 disables the single tap/
    double tap functions. */
    uint8_t dur; 
    /*The latent register is eight bits and contains an unsigned time
    value representing the wait time from the detection of a tap
    event to the start of the time window (defined by the window
    register) during which a possible second tap event can be detected.
    The scale factor is 1.25 ms/LSB. A value of 0 disables the double tap
    function. */
    uint8_t latent; 
    /*The window register is eight bits and contains an unsigned time
    value representing the amount of time after the expiration of the
    latency time (determined by the latent register) during which a
    second valid tap can begin. The scale factor is 1.25 ms/LSB. A
    value of 0 disables the double tap function.*/
    uint8_t window;
    /*The THRESH_ACT register is eight bits and holds the threshold
    value for detecting activity. The data format is unsigned, so the
    magnitude of the activity event is compared with the value in
    the THRESH_ACT register. The scale factor is 62.5 mg/LSB.
    A value of 0 may result in undesirable behavior if the activity
    interrupt is enabled.*/
    uint8_t threshold_activity;
    /*The THRESH_INACT register is eight bits and holds the threshold
    value for detecting inactivity. The data format is unsigned, so
    the magnitude of the inactivity event is compared with the value
    in the THRESH_INACT register. The scale factor is 62.5 mg/LSB.
    A value of 0 may result in undesirable behavior if the inactivity
    interrupt is enabled.*/
    uint8_t threshod_inactivity;
    /*The TIME_INACT register is eight bits and contains an unsigned
    time value representing the amount of time that acceleration
    must be less than the value in the THRESH_INACT register for
    inactivity to be declared. The scale factor is 1 sec/LSB. Unlike
    the other interrupt functions, which use unfiltered data (see the
    Threshold section), the inactivity function uses filtered output
    data. At least one output sample must be generated for the
    inactivity interrupt to be triggered. This results in the function
    appearing unresponsive if the TIME_INACT register is set to a
    value less than the time constant of the output data rate. A value
    of 0 results in an interrupt when the output data is less than the
    value in the THRESH_INACT register.*/
    uint8_t time_inactivity; 
    /*D7 ACT ac/dc, D6 ACT_X enable, D5 ACT_Y enable, D4 ACT_Z enable         
    D3 INACT ac/dc, D2 INACT_X enable, D1 INACT_Y enable, D0 INACT_Z enable
    A setting of 0 selects dc-coupled operation, and a setting of 1
    enables ac-coupled operation. In dc-coupled operation, the
    current acceleration magnitude is compared directly with
    THRESH_ACT and THRESH_INACT to determine whether
    activity or inactivity is detected.
    In ac-coupled operation for activity detection, the acceleration
    value at the start of activity detection is taken as a reference
    value. New samples of acceleration are then compared to this
    reference value, and if the magnitude of the difference exceeds
    the THRESH_ACT value, the device triggers an activity interrupt.*/
    uint8_t act_inact_ctl;
    /*The THRESH_FF register is eight bits and holds the threshold
    value, in unsigned format, for free-fall detection. The acceleration on
    all axes is compared with the value in THRESH_FF to determine if
    a free-fall event occurred. The scale factor is 62.5 mg/LSB. Note
    that a value of 0 mg may result in undesirable behavior if the freefall
    interrupt is enabled. Values between 300 mg and 600 mg
    (0x05 to 0x09) are recommended.*/
    uint8_t threshold_ff;
    /*The TIME_FF register is eight bits and stores an unsigned time
    value representing the minimum time that the value of all axes
    must be less than THRESH_FF to generate a free-fall interrupt.
    The scale factor is 5 ms/LSB. A value of 0 may result in undesirable
    behavior if the free-fall interrupt is enabled. Values between 100 ms
    and 350 ms (0x14 to 0x46) are recommended.*/
    uint8_t time_ff; 
    /*D7 D6 D5 D4 = 0, D3 Suppress  D2 TAP_X enable, D1 TAP_Y enable, D0 TAP_Z enable
    Setting the suppress bit suppresses double tap detection if
    acceleration greater than the value in THRESH_TAP is present
    between taps. See the Tap Detection section for more details.
    A setting of 1 in the TAP_X enable, TAP_Y enable, or TAP_Z
    enable bit enables x-, y-, or z-axis participation in tap detection.
    A setting of 0 excludes the selected axis from participation in
    tap detection.*/
    uint8_t tap_axes; 
    /*D7 = 0, D6 ACT_X source, D5 ACT_Y source, D4 ACT_Z source,
    D3 Asleep, D2 TAP_X source, D1 TAP_Y source, D0 TAP_Z source
    ACT_x Source and TAP_x Source Bits 
    These bits indicate the first axis involved in a tap or activity
    event. A setting of 1 corresponds to involvement in the event,
    and a setting of 0 corresponds to no involvement. When new
    data is available, these bits are not cleared but are overwritten by
    the new data. The ACT_TAP_STATUS register should be read
    before clearing the interrupt. Disabling an axis from participation
    clears the corresponding source bit when the next activity or
    single tap/double tap event occurs.
    Asleep Bit 
    A setting of 1 in the asleep bit indicates that the part is asleep,
    and a setting of 0 indicates that the part is not asleep. This bit
    toggles only if the device is configured for auto sleep. See the
    AUTO_SLEEP Bit section for more information on autosleep
    mode.*/
    uint8_t act_tap_status;
    /*D7 -D5 = 0, D4 LOW_POWER D3-D0 Rate
    A setting of 0 in the LOW_POWER bit selects normal operation,
    and a setting of 1 selects reduced power operation, which has
    somewhat higher noise*/
    uint8_t bw_rate;
    /*D7-D6 = 0, D5 Link, D4 AUTO_SLEEP, D3 Measure, D2 Sleep D1-D0 Wakeup 
    Link Bit 
    A setting of 1 in the link bit with both the activity and inactivity
    functions enabled delays the start of the activity function until
    inactivity is detected. After activity is detected, inactivity detection
    begins, preventing the detection of activity. This bit serially links
    the activity and inactivity functions. When this bit is set to 0,
    the inactivity and activity functions are concurrent. Additional
    information can be found in the Link Mode section.
    When clearing the link bit, it is recommended that the part be
    placed into standby mode and then set back to measurement
    mode with a subsequent write. This is done to ensure that the
    device is properly biased if sleep mode is manually disabled;
    otherwise, the first few samples of data after the link bit is cleared
    may have additional noise, especially if the device was asleep
    when the bit was cleared.
    AUTO_SLEEP Bit 
    If the link bit is set, a setting of 1 in the AUTO_SLEEP bit enables
    the auto-sleep functionality. In this mode, the ADXL345 automatically
    switches to sleep mode if the inactivity function is
    enabled and inactivity is detected (that is, when acceleration is
    below the THRESH_INACT value for at least the time indicated
    by TIME_INACT). If activity is also enabled, the ADXL345
    automatically wakes up from sleep after detecting activity and
    returns to operation at the output data rate set in the BW_RATE
    register. A setting of 0 in the AUTO_SLEEP bit disables automatic
    switching to sleep mode. See the description of the Sleep Bit in
    this section for more information on sleep mode.
    If the link bit is not set, the AUTO_SLEEP feature is disabled
    and setting the AUTO_SLEEP bit does not have an impact on
    device operation. Refer to the Link Bit section or the Link Mode
    section for more information on utilization of the link feature.
    When clearing the AUTO_SLEEP bit, it is recommended that the
    part be placed into standby mode and then set back to measurement
    mode with a subsequent write. This is done to ensure that
    the device is properly biased if sleep mode is manually disabled;
    otherwise, the first few samples of data after the AUTO_SLEEP
    bit is cleared may have additional noise, especially if the device
    was asleep when the bit was cleared.
    Measure Bit 
    A setting of 0 in the measure bit places the part into standby mode,
    and a setting of 1 places the part into measurement mode. The
    ADXL345 powers up in standby mode with minimum power
    consumption.
    Sleep Bit 
    A setting of 0 in the sleep bit puts the part into the normal mode
    of operation, and a setting of 1 places the part into sleep mode.
    Sleep mode suppresses DATA_READY, stops transmission of data
    to FIFO, and switches the sampling rate to one specified by the
    wakeup bits. In sleep mode, only the activity function can be used.
    When the DATA_READY interrupt is suppressed, the output
    data registers (Register 0x32 to Register 0x37) are still updated
    at the sampling rate set by the wakeup bits (D1:D0).
    When clearing the sleep bit, it is recommended that the part be
    placed into standby mode and then set back to measurement
    mode with a subsequent write. This is done to ensure that the
    device is properly biased if sleep mode is manually disabled;
    otherwise, the first few samples of data after the sleep bit is
    cleared may have additional noise, especially if the device was
    asleep when the bit was cleared.
    Wakeup Bits 
    These bits control the frequency of readings in sleep mode as
    described in Table 20.*/
    uint8_t power_ctl;
    /*D7 DATA_READY, D6 SINGLE_TAP, D5 DOUBLE_TAP, D4 Activity
    D3 Inactivity, D2 FREE_FALL, D1 Watermark D0 Overrun*/ 
    uint8_t int_enable; 
    /*D7 DATA_READY, D6 SINGLE_TAP, D5 DOUBLE_TAP, D4 Activity
    D3 Inactivity, D2 FREE_FALL, D1 Watermark D0 Overrun
    Any bits set to 0 in this register send their respective interrupts to
    the INT1 pin, whereas bits set to 1 send their respective interrupts
    to the INT2 pin. All selected interrupts for a given pin are OR’ed.*/
    uint8_t int_map;
    /*D7 DATA_READY, D6 SINGLE_TAP, D5 DOUBLE_TAP, D4 Activity
    D3 Inactivity, D2 FREE_FALL, D1 Watermark D0 Overrun
    Bits set to 1 in this register indicate that their respective functions
    have triggered an event, whereas a value of 0 indicates that the
    corresponding event has not occurred. The DATA_READY,
    watermark, and overrun bits are always set if the corresponding
    events occur, regardless of the INT_ENABLE register settings,
    and are cleared by reading data from the DATAX, DATAY, and
    DATAZ registers. The DATA_READY and watermark bits may
    require multiple reads, as indicated in the FIFO mode descriptions
    in the FIFO section. Other bits, and the corresponding interrupts,
    are cleared by reading the INT_SOURCE register.*/
    uint8_t int_source; 
    /* D7 SELF_TEST, D6 SPI, D5 INT_INVERT, D4 = 0, D3 FULL_RES, D2 Justify D1-D0 Range
    The DATA_FORMAT register controls the presentation of data
    to Register 0x32 through Register 0x37. All data, except that for
    the ±16 g range, must be clipped to avoid rollover.
    SELF_TEST Bit 
    A setting of 1 in the SELF_TEST bit applies a self-test force to
    the sensor, causing a shift in the output data. A value of 0 disables
    the self-test force.
    SPI Bit 
    A value of 1 in the SPI bit sets the device to 3-wire SPI mode,
    and a value of 0 sets the device to 4-wire SPI mode.
    INT_INVERT Bit 
    A value of 0 in the INT_INVERT bit sets the interrupts to active
    high, and a value of 1 sets the interrupts to active low.
    FULL_RES Bit 
    When this bit is set to a value of 1, the device is in full resolution
    mode, where the output resolution increases with the g range
    set by the range bits to maintain a 4 mg/LSB scale factor. When
    the FULL_RES bit is set to 0, the device is in 10-bit mode, and
    the range bits determine the maximum g range and scale factor.
    Justify Bit 
    A setting of 1 in the justify bit selects left-justified (MSB) mode,
    and a setting of 0 selects right-justified mode with sign extension.*/ 
    uint8_t data_format;
    /*These six bytes (Register 0x32 to Register 0x37) are eight bits
each and hold the output data for each axis. Register 0x32 and
Register 0x33 hold the output data for the x-axis, Register 0x34 and
Register 0x35 hold the output data for the y-axis, and Register 0x36
and Register 0x37 hold the output data for the z-axis. The output
data is twos complement, with DATAx0 as the least significant
byte and DATAx1 as the most significant byte, where x represent X,
Y, or Z. The DATA_FORMAT register (Address 0x31) controls
the format of the data. It is recommended that a multiple-byte
read of all registers be performed to prevent a change in data
between reads of sequential registers.*/
    uint8_t data_x0; 
    uint8_t data_x1;
    uint8_t data_y0;
    uint8_t data_y1; 
    uint8_t data_z0;
    uint8_t data_z1;
    /*D7-D6 FIFO_MODE, D5 Trigger, D4-D0 Samples
    Trigger Bit 
    A value of 0 in the trigger bit links the trigger event of trigger mode
    to INT1, and a value of 1 links the trigger event to INT2.
    Samples Bits 
    The function of these bits depends on the FIFO mode selected
    (see Table 23). Entering a value of 0 in the samples bits immediately
    sets the watermark status bit in the INT_SOURCE register,
    regardless of which FIFO mode is selected. Undesirable operation
    may occur if a value of 0 is used for the samples bits when trigger
    mode is used.*/ 
    uint8_t fifo_ctl; 
    /*D7 FIFO_TRIG, D6=0, D5-D0 Entries
    FIFO_TRIG Bit 
    A 1 in the FIFO_TRIG bit corresponds to a trigger event occurring,
    and a 0 means that a FIFO trigger event has not occurred.
    Entries Bits 
    These bits report how many data values are stored in FIFO.
    Access to collect the data from FIFO is provided through the
    DATAX, DATAY, and DATAZ registers. FIFO reads must be
    done in burst or multiple-byte mode because each FIFO level is
    cleared after any read (single- or multiple-byte) of FIFO. FIFO
    stores a maximum of 32 entries, which equates to a maximum
    of 33 entries available at any given time because an additional
    entry is available at the output filter of the device.*/ 
    uint8_t fifo_status; 
} t_adxl34x_reg;

t_adxl34x_reg adxl34x_reg;
static const t_adxl34x_reg  adxl34x_reg_init = {
    0b11100101, //id
    10,			//uint8_t thresh_tap = ; 
    0,			//int8_t  offset_x = 0; 
    0,			//int8_t  offset_y = 0; 
    0,			//int8_t  offset_z = 0;
    0,			//uint8_t dur = 0; 
    0,			//uint8_t latent; 
    0,			//uint8_t window;
    5,			//uint8_t threshold_activity;
    5,			//uint8_t threshod_inactivity;
    1,			//uint8_t time_inactivity; 
    0,			//uint8_t act_inact_ctl;
    5,			//uint8_t threshold_ff;
    1,			//uint8_t time_ff; 
    0,			//uint8_t tap_axes; 
    0,			//uint8_t act_tap_status; 
    0,			//uint8_t bw_rate;
    0,			//uint8_t power_ctl; 
    0,			//uint8_t int_enable; 
    0,			//uint8_t int_map;
    0,			//uint8_t int_source; 
    0,			//uint8_t data_format; 
    0,			//uint8_t data_x0; 
    0,			//uint8_t data_x1;
    0,			//uint8_t data_y0;
    0,			//uint8_t data_y1; 
    0,			//uint8_t data_z0;
    0,			//uint8_t data_z1;
    0,			//uint8_t fifo_ctl; 
    0			//uint8_t fifo_status; 
} ;

bool device_write_byte(uint8_t address, uint8_t value)
{
  printf("Writing value %x in register %x", value, address);
  return true;
}

bool device_read_byte(uint8_t address, uint8_t *readvalue);

bool enterAutoSleepMode (int threshold, int time)
{
    if (device_write_byte(THRESH_INACT, threshold) == false)
       return false;
    if(device_write_byte(TIME_INACT, time) == false)
       return false;
	uint8_t power_ctl_save = adxl34x_reg.power_ctl;
	power_ctl_save |= PCTL_AUTO_SLEEP | PCTL_LINK;
	if (device_write_byte(POWER_CTL, power_ctl_save) == false)
	return false;
	adxl34x_reg.power_ctl = power_ctl_save;
	return true;
}