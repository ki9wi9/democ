#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <string.h>

#include "mcp23008.h"

int setup() {
  int fd = wiringPiI2CSetup(MCP23008_I2CADDR);
  if (0 > fd) {
    fprintf(stderr, "ERROR: Unable to access module: %s\n", strerror (errno));
    exit(-1);
  }
  if (0 > begin(fd)) {
    fprintf(stderr, "ERROR: module not found\n");
    exit(-1);
  }
	return fd;
}

int loop(int fd) {
	uint8_t index = 0;
	uint8_t ucLSB = 0x01;

	for (index = 0; index < 8; index++, ucLSB <<= 1) {
	  writeBarLed(fd, ucLSB);
	  delay(100);  // Wait 100ms
	}
	ucLSB = 0x80;
	for (index = 0; index < 8; index++, ucLSB >>= 1) {
	  writeBarLed(fd, ucLSB);
	  delay(100);  // Wait 100ms
	}

	if (!ucLSB) {
	  printf("Done MCP23008 Module\n");
		return -1;  // done with loop
	}
	
	return 0;  // loop again
}

int main() {
	int fd = setup();
	while ( !loop(fd) );
  return 0;
}
