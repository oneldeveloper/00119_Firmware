# 1 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 127 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 145 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 176 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 212 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 254 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 407 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);


#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const


int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 2 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdbool.h" 1 3
# 3 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 1 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 135 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 150 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 166 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;
# 181 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int32_t;





typedef long long int64_t;
# 196 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;
# 217 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 237 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 155 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int32_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint32_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 155 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdint.h" 2 3
# 4 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c" 2
# 1 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h" 1





typedef enum { BYPASS = 0, FIFO = 1, STREAM = 2, TRIGGER = 3} t_fifo_mode;

typedef struct {
    _Bool data_ready;
    _Bool single_tap;
    _Bool double_tap;
    _Bool activity;
    _Bool inactivity;
    _Bool free_fall;
    _Bool watermark;
    _Bool overrun;
} t_int_source;

typedef struct {
    _Bool fifo_trig;
    uint8_t entries;
} t_fifo_status;

typedef struct {
    _Bool ACT_ac_dc;
    _Bool ACT_X_enable;
    _Bool ACT_Y_enable;
    _Bool ACT_Z_enable;
    _Bool INACT_ac_dc;
    _Bool INACT_X_enable;
    _Bool INACT_Y_enable;
    _Bool INACT_Z_enable;
} t_act_inact_ctl;

typedef struct {
    const uint8_t dev_id;
    uint8_t thresh_tap;
    int8_t offset_x;
    int8_t offset_y;
    int8_t offset_z;





    uint8_t dur;






    uint8_t latent;





    uint8_t window;






    uint8_t threshold_activity;






    uint8_t threshod_inactivity;
# 86 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t time_inactivity;
# 99 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    t_act_inact_ctl act_inact_ctl;







    uint8_t threshold_ff;






    uint8_t time_ff;
# 123 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t tap_axes;
# 141 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t act_tap_status;




    uint8_t bw_rate;
# 210 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t power_ctl;


    uint8_t int_enable;





    uint8_t int_map;
# 232 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    t_int_source int_source;
# 256 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t data_format;
# 268 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t data_x0;
    uint8_t data_x1;
    uint8_t data_y0;
    uint8_t data_y1;
    uint8_t data_z0;
    uint8_t data_z1;
# 285 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    uint8_t fifo_ctl;
# 299 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.h"
    t_fifo_status fifo_status;
} t_adxl34x_reg;


void setReadWriteByteInterfaces(_Bool (*write_Interface)(uint8_t, uint8_t), _Bool (*read_Interface)(uint8_t, uint8_t*));
void setReadWriteMultipleByteInterfaces(_Bool (*write_Interface)(uint8_t, uint8_t, uint8_t*), _Bool (*read_Interface)(uint8_t, uint8_t, uint8_t*));


_Bool initializeDevice(t_adxl34x_reg init_values);
_Bool readDeviceReg(t_adxl34x_reg *model);

_Bool enterAutoSleepMode (uint8_t threshold, uint8_t time);
_Bool exitAutoSleepMode();
_Bool enterStandByMode();
_Bool exitStandByMode();
_Bool enterLowPowerMode();
_Bool exitLowPowerMode();

_Bool setDataRate(uint8_t rate);





_Bool interruptEnableDisable(_Bool data_ready, _Bool single_tap, _Bool double_tap, _Bool activity,
     _Bool inactivity, _Bool free_fall, _Bool watermark, _Bool overrun);


_Bool interruptMap(_Bool data_ready, _Bool single_tap, _Bool double_tap, _Bool activity,
     _Bool inactivity, _Bool free_fall, _Bool watermark, _Bool overrun);


_Bool interruptInvert(_Bool invert);

_Bool setOffset(int8_t x, int8_t y, int8_t z);
_Bool setTapConfig(uint8_t threshold, uint8_t duration, uint8_t latent, uint8_t window);
# 5 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c" 2
# 103 "C:/Users/tec4.ele/MPLABXProjects/00119Repo.X/adxl34x.c"
_Bool (*commWriteByte)(uint8_t, uint8_t);
_Bool (*commReadByte)(uint8_t, uint8_t*);
_Bool (*commWriteMultipleBytes)(uint8_t, uint8_t, uint8_t*);
_Bool (*commReadMultipleBytes)(uint8_t, uint8_t, uint8_t*);

void setReadWriteByteInterfaces(_Bool (*write_Interface)(uint8_t, uint8_t), _Bool (*read_Interface)(uint8_t, uint8_t*))
{
 commWriteByte = write_Interface;
 commReadByte = read_Interface;
}
void setReadWriteMultipleByteInterfaces(_Bool (*writeInterface)(uint8_t, uint8_t, uint8_t*), _Bool (*readInterface)(uint8_t, uint8_t, uint8_t*))
{
 commWriteMultipleBytes = writeInterface;
 commReadMultipleBytes = readInterface;
}


t_adxl34x_reg adxl34x_reg;

_Bool enterAutoSleepMode (uint8_t threshold, uint8_t time)
{
    if (commWriteByte(0x25, threshold) == 0)
       return 0;
    if(commWriteByte(0x26, time) == 0)
       return 0;

 uint8_t power_ctl_save = 0x81;
 power_ctl_save |= (1 << 4) | (1 << 5);
 if (commWriteByte(0x2D, power_ctl_save) == 0)
 return 0;
 adxl34x_reg.power_ctl = power_ctl_save;
 return 1;
}
_Bool exitAutoSleepMode()
{
 uint8_t power_ctl_save = adxl34x_reg.power_ctl;
 power_ctl_save &= ~(1 << 4) & ~(1 << 5);
 if (commWriteByte(0x2D, power_ctl_save) == 0)
 return 0;
 adxl34x_reg.power_ctl = power_ctl_save;
 return 1;
}
_Bool enterStandByMode()
{
 uint8_t power_ctl_save = adxl34x_reg.power_ctl;
 power_ctl_save &= ~(1 << 3);
 if (commWriteByte(0x2D, power_ctl_save) == 0)
 return 0;
 adxl34x_reg.power_ctl = power_ctl_save;
 return 1;
}
_Bool exitStandByMode()
{
 uint8_t power_ctl_save = adxl34x_reg.power_ctl;
 power_ctl_save |= (1 << 3);
 if (commWriteByte(0x2D, power_ctl_save) == 0)
 return 0;
 adxl34x_reg.power_ctl = power_ctl_save;
 return 1;
}

_Bool enterLowPowerMode()
{
 uint8_t bw_rate_save = adxl34x_reg.bw_rate;
 bw_rate_save |= (1 << 4);
 if (commWriteByte(0x2C, bw_rate_save) == 0)
  return 0;
 adxl34x_reg.bw_rate = bw_rate_save;
 return 1;
}
_Bool exitLowPowerMode()
{
 uint8_t bw_rate_save = adxl34x_reg.bw_rate;
 bw_rate_save &= ~(1 << 4);
 if (commWriteByte(0x2C, bw_rate_save) == 0)
  return 0;
 adxl34x_reg.bw_rate = bw_rate_save;
 return 1;
}


_Bool setDataRate(uint8_t rate)
{
 uint8_t bw_rate_save = adxl34x_reg.bw_rate;
 bw_rate_save &= 0xF0;
 bw_rate_save |= rate;
 if (commWriteByte(0x2C, bw_rate_save) == 0)
  return 0;
 adxl34x_reg.bw_rate = bw_rate_save;
 return 1;
}

_Bool interruptEnableDisable(_Bool data_ready, _Bool single_tap, _Bool double_tap, _Bool activity,
     _Bool inactivity, _Bool free_fall, _Bool watermark, _Bool overrun)
{
 uint8_t int_enable = 0;
 if (data_ready)
  int_enable |= (1 << 7);
 else
  int_enable &= ~(1 << 7);
 if (single_tap)
  int_enable |= (1 << 6);
 else
  int_enable &= ~(1 << 6);
 if (double_tap)
  int_enable |= (1 << 5);
 else
  int_enable &= ~(1 << 5);
 if (activity)
  int_enable |= (1 << 4);
 else
  int_enable &= ~(1 << 4);
 if (inactivity)
  int_enable |= (1 << 3);
 else
  int_enable &= ~(1 << 3);
 if (free_fall)
  int_enable |= (1 << 2);
 else
  int_enable &= ~(1 << 2);
 if (watermark)
  int_enable |= (1 << 1);
 else
  int_enable &= ~(1 << 1);
 if (overrun)
  int_enable |= (1 << 0);
 else
  int_enable &= ~(1 << 0);
 if (commWriteByte(0x2E, int_enable) == 0)
  return 0;
 adxl34x_reg.int_enable = int_enable;
 return 1;
}

_Bool interruptMap(_Bool data_ready, _Bool single_tap, _Bool double_tap, _Bool activity,
     _Bool inactivity, _Bool free_fall, _Bool watermark, _Bool overrun)
{
 uint8_t int_map = 0;
 if (data_ready)
  int_map |= (1 << 7);
 else
  int_map &= ~(1 << 7);
 if (single_tap)
  int_map |= (1 << 6);
 else
  int_map &= ~(1 << 6);
 if (double_tap)
  int_map |= (1 << 5);
 else
  int_map &= ~(1 << 5);
 if (activity)
  int_map |= (1 << 4);
 else
  int_map &= ~(1 << 4);
 if (inactivity)
  int_map |= (1 << 3);
 else
  int_map &= ~(1 << 3);
 if (free_fall)
  int_map |= (1 << 2);
 else
  int_map &= ~(1 << 2);
 if (watermark)
  int_map |= (1 << 1);
 else
  int_map &= ~(1 << 1);
 if (overrun)
  int_map |= (1 << 0);
 else
  int_map &= ~(1 << 0);
 if (commWriteByte(0x2F, int_map) == 0)
  return 0;
 adxl34x_reg.int_enable = int_map;
 return 1;
}

_Bool interruptInvert(_Bool invert)
{
 uint8_t data_format = adxl34x_reg.data_format;
 if (invert)
  data_format |= (1 << 5);
 else
  data_format &= ~(1 << 5);
 if (commWriteByte(0x31, data_format) == 0)
  return 0;
 adxl34x_reg.data_format = data_format;
 return 1;
}

_Bool getInterruptSource(t_adxl34x_reg *source)
{
 uint8_t int_source;
 if (commReadByte(0x30, &int_source) == 0)
  return 0;
 source->int_source.data_ready = int_source & 0x80;
 source->int_source.single_tap = int_source & 0x40;
 source->int_source.double_tap = int_source & 0x20;
 source->int_source.activity = int_source & 0x01;
 source->int_source.inactivity = int_source & 0x08;
 source->int_source.free_fall = int_source & 0x04;
 source->int_source.watermark = int_source & 0x02;
 source->int_source.overrun = int_source & 0x01;
 return 1;
}

_Bool setFifoMode(t_fifo_mode mode, uint8_t samples, _Bool trigMap)
{
 uint8_t fifo_ctl = (uint8_t)mode * 0x40 + (0x0F & samples) + (trigMap << 4);

 if (commWriteByte(0x38, fifo_ctl) == 0)
  return 0;
 adxl34x_reg.fifo_ctl = fifo_ctl;
}

_Bool getFifoStatus(t_adxl34x_reg *status)
{
 uint8_t fifo_status;
 if (commReadByte(0x39, &fifo_status) == 0)
  return 0;
 status->fifo_status.fifo_trig = fifo_status && 0x80;
 status->fifo_status.entries = fifo_status & 0x3F;
 return 1;
}

_Bool setOffset(int8_t x, int8_t y, int8_t z)
{
 if (commWriteByte(0x1E, x) == 0)
  return 0;
 adxl34x_reg.offset_x = x;
 if (commWriteByte(0x1F, y) == 0)
  return 0;
 adxl34x_reg.offset_y = y;
 if (commWriteByte(0x20, z) == 0)
  return 0;
 adxl34x_reg.offset_z = z;
 return 1;
}

_Bool setTapConfig(uint8_t threshold, uint8_t duration, uint8_t latent, uint8_t window)
{
 if (commWriteByte(0x1D, threshold) == 0)
 return 0;
 adxl34x_reg.thresh_tap = threshold;
 if (commWriteByte(0x21, duration) == 0)
  return 0;
 adxl34x_reg.dur = duration;
 if (commWriteByte(0x22, latent) == 0)
  return 0;
 adxl34x_reg.latent = latent;
 if (commWriteByte(0x23, window) == 0)
  return 0;
 adxl34x_reg.window = window;
 return 1;
}

_Bool setActInactConfig(uint8_t threshold_act, uint8_t threshold_inact, uint8_t time_inact, uint8_t act_inact_ctl)
{
 if (commWriteByte(0x24, threshold_act) == 0)
  return 0;
 adxl34x_reg.threshold_activity = threshold_act;
 if (commWriteByte(0x25, threshold_inact) == 0)
  return 0;
 adxl34x_reg.threshod_inactivity = threshold_inact;
 if (commWriteByte(0x26, time_inact) == 0)
  return 0;
 adxl34x_reg.time_inactivity = time_inact;
 if (commWriteByte(0x27, act_inact_ctl) == 0)
  return 0;
 adxl34x_reg.act_inact_ctl.ACT_ac_dc = act_inact_ctl & 0x80;
 adxl34x_reg.act_inact_ctl.ACT_X_enable = act_inact_ctl & 0x40;
 adxl34x_reg.act_inact_ctl.ACT_Y_enable = act_inact_ctl & 0x20;
 adxl34x_reg.act_inact_ctl.ACT_Z_enable = act_inact_ctl & 0x10;
 adxl34x_reg.act_inact_ctl.INACT_ac_dc = act_inact_ctl & 0x08;
 adxl34x_reg.act_inact_ctl.INACT_X_enable = act_inact_ctl & 0x04;
 adxl34x_reg.act_inact_ctl.INACT_Y_enable = act_inact_ctl & 0x02;
 adxl34x_reg.act_inact_ctl.INACT_Z_enable = act_inact_ctl & 0x01;
 return 1;
}

_Bool initializeDevice(t_adxl34x_reg init_values)
{
 return commWriteMultipleBytes(29, 0x1D, &init_values.thresh_tap);
}

_Bool readDeviceReg(t_adxl34x_reg *model)
{
 return commReadMultipleBytes(29, 0x1D, &model->thresh_tap);
}
