#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adxl34x.h"
#include "mcc_generated_files/mcc.h"

bool write(uint8_t address, uint8_t value)
{
    
  printf("Writing value %X in register %X\r\n", value, address);
  CS_SetLow();
  SPI_Exchange8bit(address);
  SPI_Exchange8bit(value);
  CS_SetHigh(); 
  return true;
}

bool read(uint8_t address, uint8_t *value)
{
  CS_SetLow();
  SPI_Exchange8bit(address + 0x80);
  *value = SPI_Exchange8bit(NULL);
  printf("Register %X has value %X\r\n", address, *value);
  CS_SetHigh(); 
  return true;
}

bool writeMul(uint8_t n, uint8_t address, uint8_t *value)
{
    CS_SetLow();
    SPI_Exchange8bit(address + 0x40);
    uint8_t bytesWrite = SPI_Exchange8bitBuffer(value, n, NULL);
    CS_SetHigh(); 
    if (bytesWrite == n)      
      return true;
    return false;
}

bool readMul(uint8_t n, uint8_t address, uint8_t *value)
{
    CS_SetLow();
    SPI_Exchange8bit(address + 0xC0);
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
        printf("x=%5d, y=%5d, z=%5d\r\n", x, y, z);
}

void ManageAdxlIRQ()
{
    uint8_t int_source;
    if (getInterruptSource(&int_source) == false)
    {
        printf("Can't read IRQ status");
        return;
    }
    if (int_source & 0x80)
        readAccData();
    if (int_source & 0x10)
        printf("Activity detected\r\n");
    if (int_source & 0x08)
        printf("Inactivity edtected\r\n");
    return;
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
    0x07,			//uint8_t bw_rate;
    0x08,			//uint8_t power_ctl; 
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

 char *input;
 
 
  int main(int argc, char *argv[])
    {
      SYSTEM_Initialize();
      INT0_SetInterruptHandler(ManageAdxlIRQ);
      INTERRUPT_GlobalInterruptEnable();
      INTERRUPT_PeripheralInterruptEnable();
      CS_SetHigh();          
      setReadWriteByteInterfaces(write, read);     
      setReadWriteMultipleByteInterfaces(writeMul, readMul);
      __delay_ms(100);
      uint8_t devId;
      //readDeviceId(&devId);
      initializeDevice(&adxl34x_reg_init);     
      t_adxl34x_reg readDevice;
      readDeviceReg(&readDevice);
      uint8_t *p = &readDevice;
      for(int i = 0x1D; i < 0x1D + 29; i++)
        printf("Reg 0x%2X = 0x%2X\r\n", i, *p++);
      //printf("Initialize device: %d\n", initializeDevice(adxl34x_reg_init));
      //printf("ExitAutospeed mode: %d\n",exitAutoSleepMode());
      //printf("Enter low power mode: %d\n", enterLowPowerMode());
      //printf("Exit low power mode: %d\n", exitLowPowerMode());
      setActInactConfig(20, 18, 1, 0xAA);
      interruptEnableDisable(true, false, false, true, true, false, false, false);        
      while(1);
    }

