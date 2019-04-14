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

int16_t sensivity;

bool write(uint8_t address, uint8_t value)
{
  INTERRUPT_GlobalInterruptDisable();
  CS_SetLow();
  SPI_Exchange8bit(address);
  SPI_Exchange8bit(value);
  CS_SetHigh(); 
  INTERRUPT_GlobalInterruptEnable();
  printf("Write 0x%2X into 0x%2X\r\n", value, address);
  return true;
}

bool read(uint8_t address, uint8_t *value)
{
  INTERRUPT_GlobalInterruptDisable();
  CS_SetLow();
  SPI_Exchange8bit(address);
  *value = SPI_Exchange8bit(NULL);
  CS_SetHigh(); 
  INTERRUPT_GlobalInterruptEnable();
  printf("Register 0x%2X has value 0x%2X\r\n", address, *value);
  return true;
}

bool writeMul(uint8_t n, uint8_t address, uint8_t *value)
{
    INTERRUPT_GlobalInterruptDisable();
    CS_SetLow();
    SPI_Exchange8bit(address);
    uint8_t bytesWrite = SPI_Exchange8bitBuffer(value, n, NULL);
    CS_SetHigh(); 
    INTERRUPT_GlobalInterruptEnable();
    if (bytesWrite == n)      
      return true;
    return false;
}

bool readMul(uint8_t n, uint8_t address, uint8_t *value)
{
    INTERRUPT_GlobalInterruptDisable();
    CS_SetLow();
    SPI_Exchange8bit(address);
    uint8_t bytesRead = SPI_Exchange8bitBuffer(NULL, n, value);
    CS_SetHigh(); 
    INTERRUPT_GlobalInterruptEnable();    
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
        printf("x=%5d, y=%5d, z=%5d\r\n", x, y, z);
}

void handleAdxlIRQ()
{
    
    
    INTERRUPT_GlobalInterruptDisable();
    uint8_t intSource;
    if (getInterruptSource(&intSource) == false)
    {
        printf("Failed to read interrupt source\r\n");
        return;
    }
    if (intSource & 0x80)
    {
        printf("Read Acceleration data\r\n");
        int16_t x, y, z;
        if (getAccelerationVectors(&x, &y, &z)== false)
            printf("Failed to read acceleration\r\n");
        else
        {
            *pSamplesX++ = x;
            *pSamplesY++ = y;
            *pSamplesZ++ = z;
            samplesIndex++;
            if (samplesIndex >= AVERAGE_SAMPLES)
            {
                samplesIndex = 0;
                pSamplesX = samplesX;
                pSamplesY = samplesY;
                pSamplesZ = samplesZ;
                int16_t averageX, averageY, averageZ;
                averageX = average(pSamplesX, AVERAGE_SAMPLES);
                averageY = average(pSamplesY, AVERAGE_SAMPLES);
                averageZ = average(pSamplesZ, AVERAGE_SAMPLES);
                printf("%d\t%d\t%d\r\n", averageX, averageY, averageZ);
                if (averageY > sensivity)
                    Led_SetHigh();
            }
        }
    }
    if (intSource & 0x10)
    {
        printf("Activity detected\r\n");
        samplesIndex = 0;
        pSamplesX = samplesX;
        pSamplesY = samplesY;
        pSamplesZ = samplesZ;
        interruptEnableDisable(true, false, false, true, true, false, false, false); //enable data ready interrupt
    }
    if (intSource & 0x08)
    {
        int16_t x, y, z;
        getAccelerationVectors(&x, &y, &z);
        printf("Inactivity detected\r\n");
        interruptEnableDisable(false, false, false, true, true, false, false, false); //disable data ready interrupt
        Led_SetLow();
    }
    INTERRUPT_GlobalInterruptEnable();
        //printf("%d\t%d\t%d\r\n", x, y, z);
}

static t_adxl34x_reg  adxl34x_reg_init = {
    0b11100101, //id
    0,			//uint8_t thresh_tap = ; 
    0,			//int8_t  offset_x = 0; 
    0,			//int8_t  offset_y = 0; 
    0,			//int8_t  offset_z = 0;
    0,			//uint8_t dur = 0; 
    0,			//uint8_t latent; 
    0,			//uint8_t window;
    20,			//uint8_t threshold_activity;
    18,			//uint8_t threshod_inactivity;
    1,			//uint8_t time_inactivity; 
    0x99,			//uint8_t act_inact_ctl;
    0,			//uint8_t threshold_ff;
    0,			//uint8_t time_ff; 
    0,			//uint8_t tap_axes; 
    0,			//uint8_t act_tap_status; 
    0x08,			//uint8_t bw_rate;
    0x28,			//uint8_t power_ctl; 
    0x00,			//uint8_t int_enable; 
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

 
 
  int main(int argc, char *argv[])
    {

      SYSTEM_Initialize();
      sensivity = (PORTA & 0x0F) * 100;
      printf("Sensivity is %2d\r\n", sensivity);
      INT0_SetInterruptHandler(handleAdxlIRQ);
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

      //printf("Initialize device: %d\n", initializeDevice(adxl34x_reg_init));
      //printf("ExitAutospeed mode: %d\n",exitAutoSleepMode());
      //printf("Enter low power mode: %d\n", enterLowPowerMode());
      //printf("Exit low power mode: %d\n", exitLowPowerMode());
      uint8_t s = (sensivity /100) + 2;
      setActInactConfig(s, s , 1, 0xAA);
      interruptEnableDisable(false, false, false, true, true, false, false, false);
      if (readDeviceReg(&readDevice) == false)
      {
          printf("Reading device failed");
      }
      
      printf("Device id: %d\r\n", readDevice.dev_id );
      uint8_t *p = &readDevice.thresh_tap;
      for(int i = 0x1D; i < 0x1D + 29; i++)
        printf("Reg 0x%2X = 0x%2X\r\n", i, *p++);
      while(1);
    }

