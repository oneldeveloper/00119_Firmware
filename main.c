#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adxl34x.h"
#include "mcc_generated_files/mcc.h"
#include "average.h"

#define AVERAGE_SAMPLES 10

int16_t samplesX[AVERAGE_SAMPLES];
int16_t samplesY[AVERAGE_SAMPLES];
int16_t samplesZ[AVERAGE_SAMPLES];
int16_t *pSamplesX = samplesX;
int16_t *pSamplesY = samplesY;
int16_t *pSamplesZ = samplesZ;
uint8_t samplesIndex = 0;

bool write(uint8_t address, uint8_t value)
{
    
  printf("Writing value %X in register %X\n", value, address);
  return true;
}

bool read(uint8_t address, uint8_t *value)
{
  CS_SetLow();
  SPI_Exchange8bit(address);
  value = SPI_Exchange8bit(NULL);
  CS_SetHigh(); 
}

bool writeMul(uint8_t n, uint8_t address, uint8_t *value)
{
    CS_SetLow();
    SPI_Exchange8bit(address);
    uint8_t bytesWrite = SPI_Exchange8bitBuffer(value, n, NULL);
    CS_SetHigh(); 
    if (bytesWrite == n)      
      return true;
    return false;
}

bool readMul(uint8_t n, uint8_t address, uint8_t *value)
{
    CS_SetLow();
    SPI_Exchange8bit(address);
    uint8_t bytesRead = SPI_Exchange8bitBuffer(NULL, n, value);
    CS_SetHigh(); 
    if (bytesRead == n)      
      return true;
    return false;
}

void readAccData()
{
    int16_t x, y, z;
    if (getAccelerationVectors(&x, &y, &z)== false)
        printf("Failed to read acceleration\r\n");
    else
    {
        *pSamplesX++ = x;
        *pSamplesY++ = y;
        *pSamplesZ++ = z;
        samplesIndex++;
        if (samplesIndex < AVERAGE_SAMPLES)
            return;
        samplesIndex = 0;
        pSamplesX = samplesX;
        pSamplesY = samplesY;
        pSamplesZ = samplesZ;
        int16_t averageX, averageY, averageZ;
        averageX = average(pSamplesX, AVERAGE_SAMPLES);
        averageY = average(pSamplesY, AVERAGE_SAMPLES);
        averageZ = average(pSamplesZ, AVERAGE_SAMPLES);
        printf("%d\t%d\t%d\r\n", averageX, averageY, averageZ);
    }
        //printf("%d\t%d\t%d\r\n", x, y, z);
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
    0,			//uint8_t threshold_activity;
    0,			//uint8_t threshod_inactivity;
    0,			//uint8_t time_inactivity; 
    0,			//uint8_t act_inact_ctl;
    0,			//uint8_t threshold_ff;
    0,			//uint8_t time_ff; 
    0,			//uint8_t tap_axes; 
    0,			//uint8_t act_tap_status; 
    0x08,			//uint8_t bw_rate;
    0x08,			//uint8_t power_ctl; 
    0x80,			//uint8_t int_enable; 
    0,			//uint8_t int_map;
    0,			//uint8_t int_source; 
    0x04,			//uint8_t data_format; 
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
      SYSTEM_Initialize();
      INT0_SetInterruptHandler(readAccData);
      INTERRUPT_GlobalInterruptEnable();
      INTERRUPT_PeripheralInterruptEnable();
      CS_SetHigh();          
      setReadWriteByteInterfaces(write, read);     
      setReadWriteMultipleByteInterfaces(writeMul, readMul);
      __delay_ms(100);
      uint8_t devId;
      readDeviceId(&devId);
      initializeDevice(&adxl34x_reg_init);
      
      t_adxl34x_reg readDevice;
      printf("read device: %d\n", readDeviceReg(&readDevice));
      uint8_t *p = &readDevice;
      for(int i = 0x1D; i < 0x1D + 29; i++)
        printf("Reg 0x%2X = 0x%2X\r\n", i, *p++);
      //printf("Initialize device: %d\n", initializeDevice(adxl34x_reg_init));
      //printf("ExitAutospeed mode: %d\n",exitAutoSleepMode());
      //printf("Enter low power mode: %d\n", enterLowPowerMode());
      //printf("Exit low power mode: %d\n", exitLowPowerMode());
      while(1);
    }

