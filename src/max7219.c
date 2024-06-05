#include "max7219.h"
#include "spi.h"

// Initialize the MAX7219
void MAX7219_init(void) {
    MAX7219_send(0x09, 0xFF);  // Decode mode to BCD for all digits
    MAX7219_send(0x0A, 0x08);  // Intensity (brightness)
    MAX7219_send(0x0B, 0x07);  // Scan limit (all digits)
    MAX7219_send(0x0C, 0x01);  // Shutdown register (normal operation)
    MAX7219_send(0x0F, 0x00);  // Display test (off)
}

// Send data to a specific MAX7219 register
void MAX7219_send(uint8_t address, uint8_t data) {
    PORTB &= ~(1 << LOAD);  // Bring LOAD (CS) low
    SPI_MasterTransmit(address);  // Send address
    SPI_MasterTransmit(data);  // Send data
    PORTB |= (1 << LOAD);  // Bring LOAD (CS) high
}

// Display temperature on the 7-segment display
void displayTemperature(int temperature, bool isCelsius) {
    // Define custom segments for 'C'
    uint8_t customC = 0b01001110;  // Segments a, f, e, d

    // Determine the temperature unit and set custom 'C' if necessary
    if (isCelsius) {
        MAX7219_send(4, customC);  // Custom 'C' in the first digit
    } else {
        MAX7219_send(4, 0b01100011);  // 'F' for Fahrenheit
    }

    // Get the temperature value in the correct unit
    int temp = isCelsius ? temperature : celsiusToFahrenheit(temperature);

    // Display the temperature value in the remaining three digits
    MAX7219_send(1, (temp / 100) % 10);  // Hundreds
    MAX7219_send(2, (temp / 10) % 10);   // Tens
    MAX7219_send(3, temp % 10);          // Units
}

int celsiusToFahrenheit(int tempC) {
    return (tempC * 9 / 5) + 32;
}

int fahrenheitToCelsius(int tempF) {
    return (tempF - 32) * 5 / 9;
}
