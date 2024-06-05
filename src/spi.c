#include "spi.h"

// Initialize the SPI as Master
void SPI_MasterInit(void) {
    // Set MOSI and SCK output, all others input
    DDRB = (1 << DATA_IN) | (1 << CLK) | (1 << LOAD);
    // Enable SPI, Master, set clock rate fck/16
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

// Transmit data via SPI
void SPI_MasterTransmit(char cData) {
    // Start transmission
    SPDR = cData;
    // Wait for transmission to complete
    while (!(SPSR & (1 << SPIF)));
}
