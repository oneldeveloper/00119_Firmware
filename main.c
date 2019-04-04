#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adxl34x.h"
#include "mcc_generated_files/device_config.h";
#include "mcc_generated_files/eusart1.h"
#include "mcc_generated_files/spi1.h"

bool write(uint8_t address, uint8_t value)
{
  printf("Writing value %X in register %X\n", value, address);
  return true;
}

bool read(uint8_t address, uint8_t *value)
{
  *value = 0xF8;
  return true;
}

bool writeMul(uint8_t n, uint8_t address, uint8_t *value)
{
  for (int i = 0; i < n; i++)
    printf("Writing value %X in register %X\n", *value++, address + i);
  return true;  
}

bool readMul(uint8_t n, uint8_t address, uint8_t *value)
{
  *value = 0xF8;
  return true;
}

static const t_adxl34x_reg  adxl34x_reg_init = {
    0b11100101, //id
    0,			//uint8_t thresh_tap = ; 
    0,			//int8_t  offset_x = 0; 
    0,			//int8_t  offset_y = 0; 
    0,			//int8_t  offset_z = 0;
    0,			//uint8_t dur = 0; 
    0,			//uint8_t latent; 
    0,			//uint8_t window;
    5,			//uint8_t threshold_activity;
    5,			//uint8_t threshod_inactivity;
    1,			//uint8_t time_inactivity; 
    ,			//uint8_t act_inact_ctl;
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
    1			//uint8_t fifo_status; 
};

 char *input;
 
 
  int main(int argc, char *argv[])
    {
      EUSART1_Initialize();
      SPI1_Initialize();
      
      setReadWriteByteInterfaces(&write, &read);
      setReadWriteMultipleByteInterfaces(&writeMul, readMul);     
      printf("Initialize device: %d\n", initializeDevice(adxl34x_reg_init));
      printf("ExitAutospeed mode: %d\n",exitAutoSleepMode());
      printf("Enter low power mode: %d\n", enterLowPowerMode());
      printf("Exit low power mode: %d\n", exitLowPowerMode());
      char c = getchar();
      return 0;
    }

