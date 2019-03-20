#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <math.h>
#include <unistd.h>

#include "mcp23008.h"

int begin(int fd)
{
  wiringPiI2CWriteReg8(fd, MCP23008_IODIRA, 0x00);
  // Wait at least 4.5ms
  delay(5);

  wiringPiI2CWriteReg8(fd, MCP23008_GPIOA, 0x00);  // configure for output
  // Wait at least 4.5ms
  delay(5);

  return 0;
}

int writeBarLed(int fd, unsigned char ucData)
{
  wiringPiI2CWriteReg8(fd, MCP23008_GPIOA, ucData);
  // Wait at least 4.5ms
  delay(5);

  return 0;
}
