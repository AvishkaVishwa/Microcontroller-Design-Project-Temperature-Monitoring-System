#ifndef SPI_H
#define SPI_H

#include <avr/io.h>

// Function prototypes
void SPI_MasterInit(void);
void SPI_MasterTransmit(char cData);

#endif
