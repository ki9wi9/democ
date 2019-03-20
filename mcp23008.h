#ifndef _MCP23008_H_
#define _MCP23008_H_

#include <stdint.h>

#define MCP23008_I2CADDR 0x20

#define MCP23008_IODIRA          0x00
#define MCP23008_GPIOA           0x09

int begin(int fd);

int writeBarLed(int fd, unsigned char ucData);

#endif
