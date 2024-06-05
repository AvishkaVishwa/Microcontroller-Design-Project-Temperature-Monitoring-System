#ifndef MAX7219_H
#define MAX7219_H

#include <avr/io.h>
#include <stdbool.h>

// Pin connections for the MAX7219
#define DATA_IN PB3  // MOSI
#define CLK PB5      // SCK
#define LOAD PB2     // SS

// Function prototypes
void MAX7219_init(void);
void MAX7219_send(uint8_t address, uint8_t data);
void displayTemperature(int temperature, bool isCelsius);
int celsiusToFahrenheit(int tempC);
int fahrenheitToCelsius(int tempF);

#endif
