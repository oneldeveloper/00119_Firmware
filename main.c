#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "adxl34x.h"

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

 char *input;
  int main(int argc, char *argv[])
    {
      setReadWriteInterfaces(&write, &read);
      bool result = enterAutoSleepMode(10, 20);
      result = exitAutoSleepMode();
      result = enterLowPowerMode();
      result = exitLowPowerMode();
      char c = getchar();
    }

