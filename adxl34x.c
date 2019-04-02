#include <stdio.h>
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


//Write and read interface
bool (*commWriteByte)(uint8_t, uint8_t);
bool (*commReadByte)(uint8_t, uint8_t*);

void setReadWriteInterfaces(bool (*write_Interface)(uint8_t, uint8_t), bool (*read_Interface)(uint8_t, uint8_t*))
{
	commWriteByte = write_Interface;
	commReadByte = read_Interface;
}



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
};


bool enterAutoSleepMode (uint8_t threshold, uint8_t time)
{
    if (commWriteByte(THRESH_INACT, threshold) == false)
       return false;
    if(commWriteByte(TIME_INACT, time) == false)
       return false;
	//uint8_t power_ctl_save = adxl34x_reg.power_ctl;
	uint8_t power_ctl_save = 0x81;
	power_ctl_save |= PCTL_AUTO_SLEEP | PCTL_LINK;
	if (commWriteByte(POWER_CTL, power_ctl_save) == false)
	return false;
	adxl34x_reg.power_ctl = power_ctl_save;
	return true;
}
bool exitAutoSleepMode()
{
	uint8_t power_ctl_save = adxl34x_reg.power_ctl;
	power_ctl_save &= ~PCTL_AUTO_SLEEP & ~PCTL_LINK;
	if (commWriteByte(POWER_CTL, power_ctl_save) == false)
	return false;
	adxl34x_reg.power_ctl = power_ctl_save;
	return true;
}
bool enterStandByMode()
{
	uint8_t power_ctl_save = adxl34x_reg.power_ctl;
	power_ctl_save &= ~PCTL_MEASURE;
	if (commWriteByte(POWER_CTL, power_ctl_save) == false)
	return false;
	adxl34x_reg.power_ctl = power_ctl_save;
	return true;
}
bool exitStandByMode()
{
	uint8_t power_ctl_save = adxl34x_reg.power_ctl;
	power_ctl_save |= PCTL_MEASURE;
	if (commWriteByte(POWER_CTL, power_ctl_save) == false)
	return false;
	adxl34x_reg.power_ctl = power_ctl_save;
	return true;	
}

bool enterLowPowerMode()
{
	uint8_t bw_rate_save = adxl34x_reg.bw_rate;
	bw_rate_save |= LOW_POWER;
	if (commWriteByte(BW_RATE, bw_rate_save) == false)
		return false;
	adxl34x_reg.bw_rate = bw_rate_save;
	return true;
}
bool exitLowPowerMode()
{
	uint8_t bw_rate_save = adxl34x_reg.bw_rate;
	bw_rate_save &= ~LOW_POWER;
	if (commWriteByte(BW_RATE, bw_rate_save) == false)
		return false;
	adxl34x_reg.bw_rate = bw_rate_save;
	return true;
}


bool setDataRate(uint8_t rate)
{
	uint8_t bw_rate_save = adxl34x_reg.bw_rate;
	bw_rate_save &= 0xF0;
	bw_rate_save |= rate;
	if (commWriteByte(BW_RATE, bw_rate_save) == false)
		return false;
	adxl34x_reg.bw_rate = bw_rate_save;
	return true;
}

bool interruptEnableDisable(bool data_ready, bool single_tap, bool double_tap, bool activity,
					bool inactivity, bool free_fall, bool watermark, bool overrun)
{
	uint8_t int_enable = 0;
	if (data_ready)
		int_enable |= DATA_READY;
	else
		int_enable &= ~DATA_READY;
	if (single_tap)	
		int_enable |= SINGLE_TAP;
	else
		int_enable &= ~SINGLE_TAP;
	if (double_tap)
		int_enable |= DOUBLE_TAP;
	else
		int_enable &= ~DOUBLE_TAP;
	if (activity) 
		int_enable |= ACTIVITY;
	else
		int_enable &= ~ACTIVITY;
	if (inactivity)
		int_enable |= INACTIVITY;
	else
		int_enable &= ~INACTIVITY;
	if (free_fall)
		int_enable |= FREE_FALL;
	else
		int_enable &= ~FREE_FALL;
	if (watermark)
		int_enable |= WATERMARK;
	else
		int_enable &= ~WATERMARK;
	if (overrun)
		int_enable |= OVERRUN;
	else
		int_enable &= ~OVERRUN;
	if (commWriteByte(INT_ENABLE, int_enable) == false)
		return false;
	adxl34x_reg.int_enable = int_enable;
	return true;				
}

bool interruptMap(bool data_ready, bool single_tap, bool double_tap, bool activity,
					bool inactivity, bool free_fall, bool watermark, bool overrun)
{
	uint8_t int_map = 0;
	if (data_ready)
		int_map |= DATA_READY;
	else
		int_map &= ~DATA_READY;
	if (single_tap)	
		int_map |= SINGLE_TAP;
	else
		int_map &= ~SINGLE_TAP;
	if (double_tap)
		int_map |= DOUBLE_TAP;
	else
		int_map &= ~DOUBLE_TAP;
	if (activity) 
		int_map |= ACTIVITY;
	else
		int_map &= ~ACTIVITY;
	if (inactivity)
		int_map |= INACTIVITY;
	else
		int_map &= ~INACTIVITY;
	if (free_fall)
		int_map |= FREE_FALL;
	else
		int_map &= ~FREE_FALL;		
	if (watermark)
		int_map |= WATERMARK;
	else
		int_map &= ~WATERMARK;
	if (overrun)
		int_map |= OVERRUN;
	else
		int_map &= ~OVERRUN;
	if (commWriteByte(INT_MAP, int_map) == false)
		return false;
	adxl34x_reg.int_enable = int_map;
	return true;	
}

bool interruptInvert(bool invert)
{
	uint8_t data_format = adxl34x_reg.data_format;
	if (invert)
		data_format |= INT_INVERT;
	else
		data_format &= ~INT_INVERT;
	if (commWriteByte(DATA_FORMAT, data_format) == false)
		return false;
	adxl34x_reg.data_format = data_format;
	return true;	
}

bool getInterruptSource(t_adxl34x_reg *source)
{
	uint8_t int_source;
	if (commReadByte(INT_SOURCE, &int_source) == false)
		return false;
	source->int_source.data_ready = int_source & 0x80;
	source->int_source.single_tap = int_source & 0x40;
	source->int_source.double_tap = int_source & 0x20;
	source->int_source.activity = int_source & 0x01;
	source->int_source.inactivity = int_source & 0x08;
	source->int_source.free_fall = int_source & 0x04;
	source->int_source.watermark = int_source & 0x02;
	source->int_source.overrun = int_source & 0x01;
	return true;
}

bool setFifoMode(t_fifo_mode mode, uint8_t samples, bool trigMap)
{
	uint8_t fifo_ctl = (uint8_t)mode * 0x40 + (0x0F & samples) + (trigMap << 4);
	
	if (commWriteByte(FIFO_CTL, fifo_ctl) == false)
		return false;
	adxl34x_reg.fifo_ctl = fifo_ctl;
}

bool getFifoStatus(t_adxl34x_reg *status)
{
	uint8_t fifo_status;
	if (commReadByte(FIFO_STATUS, &fifo_status) == false)
		return false;
	status->fifo_status.fifo_trig = fifo_status && 0x80;
	status->fifo_status.entries = fifo_status & 0x3F;
	return true;	
}

bool setOffset(int8_t x, int8_t y, int8_t z)
{
	if (commWriteByte(OFSX, x) == false)
		return false;
	adxl34x_reg.offset_x = x;
	if (commWriteByte(OFSY, y) == false)
		return false;
	adxl34x_reg.offset_y = y;
	if (commWriteByte(OFSZ, z) == false)
		return false;
	adxl34x_reg.offset_z = z;
	return true;
}

bool setTapConfig(uint8_t threshold, uint8_t duration, uint8_t latent, uint8_t window)
{
	if (commWriteByte(THRESH_TAP, threshold) == false)
	return false;
	adxl34x_reg.thresh_tap = threshold;
	if (commWriteByte(DUR, duration) == false)
		return false;
	adxl34x_reg.dur = duration;
	if (commWriteByte(LATENT, latent) == false)
		return false;
	adxl34x_reg.latent = latent;
	if (commWriteByte(WINDOW, window) == false)
		return false;	
	adxl34x_reg.window = window;
	return true;
}

bool setActInactConfig(uint8_t threshold_act, uint8_t threshold_inact, uint8_t time_inact, uint8_t act_inact_ctl)
{
	if (commWriteByte(THRESH_ACT, threshold_act) == false)
		return false;
	adxl34x_reg.threshold_activity = threshold_act;
	if (commWriteByte(THRESH_INACT, threshold_inact) == false)
		return false;
	adxl34x_reg.threshod_inactivity = threshold_inact;
	if (commWriteByte(TIME_INACT, time_inact) == false)
		return false;
	adxl34x_reg.time_inactivity = time_inact;
	if (commWriteByte(ACT_INACT_CTL, act_inact_ctl) == false)
		return false;
	adxl34x_reg.act_inact_ctl.ACT_ac_dc = act_inact_ctl & 0x80;
	adxl34x_reg.act_inact_ctl.ACT_X_enable = act_inact_ctl & 0x40;
	adxl34x_reg.act_inact_ctl.ACT_Y_enable = act_inact_ctl & 0x20;
	adxl34x_reg.act_inact_ctl.ACT_Z_enable = act_inact_ctl & 0x10;
	adxl34x_reg.act_inact_ctl.INACT_ac_dc = act_inact_ctl & 0x08;
	adxl34x_reg.act_inact_ctl.INACT_X_enable = act_inact_ctl & 0x04;
	adxl34x_reg.act_inact_ctl.INACT_Y_enable = act_inact_ctl & 0x02;
	adxl34x_reg.act_inact_ctl.INACT_Z_enable = act_inact_ctl & 0x01;
	return true;
}
