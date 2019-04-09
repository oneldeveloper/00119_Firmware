#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adxl34x.h"
#include "mcc_generated_files/mcc.h"

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
    //if (intSource & 0x80)
    {
        readAccData();
    }
    if (intSource & 0x10)
    {
        printf("Activity detected\r\n");
        Led_SetHigh();
    }
    if (intSource & 0x08)
    {
        printf("Inactivity detected\r\n");
        Led_SetLow();
    }
    INTERRUPT_GlobalInterruptEnable();
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
    0x07,			//uint8_t bw_rate;
    0x28,			//uint8_t power_ctl; 
    0x00,			//uint8_t int_enable; 
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

 
 
  int main(int argc, char *argv[])
    {

      SYSTEM_Initialize();
      uint8_t sensivity = PORTA & 0x0F;
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
      if (readDeviceReg(&readDevice) == false)
      {
          printf("Reading device failed");
      }
      
      printf("Device id: %d\r\n", readDevice.dev_id );
      uint8_t *p = &readDevice.thresh_tap;
      for(int i = 0x1D; i < 0x1D + 29; i++)
        printf("Reg 0x%2X = 0x%2X\r\n", i, *p++);
      //printf("Initialize device: %d\n", initializeDevice(adxl34x_reg_init));
      //printf("ExitAutospeed mode: %d\n",exitAutoSleepMode());
      //printf("Enter low power mode: %d\n", enterLowPowerMode());
      //printf("Exit low power mode: %d\n", exitLowPowerMode());
      uint8_t s = sensivity + 2;
      setActInactConfig(s , s   , 2, 0x22);
      interruptEnableDisable(false, false, false, true, true, false, false, false);
      while(1);
    }

