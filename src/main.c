#include "main.h"
#include <avr/io.h>  // Include the avr/io.h header file
#include <avr/delay.h>  // Include the avr/delay.h header file

// Variables for storing the state
int temperatureC = 0;  // Initial temperature in Celsius
bool isCelsius = true;  // Start in Celsius mode
bool alarmAcknowledged = false;  // New variable to track alarm acknowledgment

// Debouncing variables
unsigned long lastDebounceTimeInc = 0;
unsigned long lastDebounceTimeDec = 0;
unsigned long lastDebounceTimeMode = 0;
unsigned long lastDebounceTimeAck = 0;
const unsigned long debounceDelay = 200;

// Variables to keep track of button state
bool lastIncButtonState = 1;
bool lastDecButtonState = 1;
bool lastModeButtonState = 1;
bool lastAckButtonState = 1;  // New variable for acknowledgment button state

// Variables for blinking alarm LED
unsigned long lastBlinkTime = 0;
bool alarmState = 0;
const unsigned long blinkInterval = 500;  // Blink interval in milliseconds

int main(void) {
    // Initialize SPI
    SPI_MasterInit();

    // Initialize the MAX7219
    MAX7219_init();

    // Initialize the push buttons as inputs with pull-up resistors
    DDRD &= ~(1 << INC_BUTTON) & ~(1 << DEC_BUTTON) & ~(1 << MODE_BUTTON);
    PORTD |= (1 << INC_BUTTON) | (1 << DEC_BUTTON) | (1 << MODE_BUTTON);
    DDRB &= ~(1 << ACK_BUTTON);
    PORTB |= (1 << ACK_BUTTON);

    // Initialize the LEDs as outputs
    DDRB |= (1 << LED1) | (1 << ALARM_LED);
    DDRD |= (1 << LED2) | (1 << LED3) | (1 << LED4);

    while (1) {
        // Read button states
        bool incButtonState = !(PIND & (1 << INC_BUTTON));
        bool decButtonState = !(PIND & (1 << DEC_BUTTON));
        bool modeButtonState = !(PIND & (1 << MODE_BUTTON));
        bool ackButtonState = !(PINB & (1 << ACK_BUTTON));  // Read the acknowledgment button state

        // Debounce and handle buttons
        handleButton(incButtonState, &lastIncButtonState, &lastDebounceTimeInc, increaseTemperature);
        handleButton(decButtonState, &lastDecButtonState, &lastDebounceTimeDec, decreaseTemperature);
        handleButton(modeButtonState, &lastModeButtonState, &lastDebounceTimeMode, switchMode);
        handleButton(ackButtonState, &lastAckButtonState, &lastDebounceTimeAck, toggleAlarmAcknowledgment);

        // Update the seven-segment display
        displayTemperature(temperatureC, isCelsius);

        // Update the LEDs based on the temperature
        updateLEDs();

        // Handle blinking of the alarm LED
        handleAlarmBlink();

        _delay_ms(10);  // Small delay to avoid busy looping
    }

    return 0;
}

void updateLEDs() {
    // Calculate brightness levels for each LED based on the temperature
    int led1Brightness = (temperatureC <= 15) ? (temperatureC * 17) : 0;
    int led2Brightness = (temperatureC > 15 && temperatureC <= 25) ? ((temperatureC - 16) * 28) : 0;
    int led3Brightness = (temperatureC > 25 && temperatureC <= 35) ? ((temperatureC - 26) * 28) : 0;
    int led4Brightness = (temperatureC > 35 && temperatureC <= 40) ? ((temperatureC - 36) * 51) : 0;

    // Apply the calculated brightness to each LED
    OCR0A = led1Brightness;
    OCR0B = led2Brightness;
    OCR2A = led3Brightness;
    OCR2B = led4Brightness;
}

void handleAlarmBlink() {
    if (temperatureC >= 40 && !alarmAcknowledged) {  // Check if the alarm is acknowledged
        if ((millis() - lastBlinkTime) >= blinkInterval) {
            alarmState = !alarmState;
            if (alarmState) {
                PORTB |= (1 << ALARM_LED);
            } else {
                PORTB &= ~(1 << ALARM_LED);
            }
            lastBlinkTime = millis();
        }
    } else {
        PORTB &= ~(1 << ALARM_LED);
    }
}

void increaseTemperature() {
    temperatureC++;
    alarmAcknowledged = false;  // Reset alarm acknowledgment when temperature changes
}

void decreaseTemperature() {
    temperatureC--;
    alarmAcknowledged = false;  // Reset alarm acknowledgment when temperature changes
}

void switchMode() {
    isCelsius = !isCelsius;
}

void toggleAlarmAcknowledgment() {
    alarmAcknowledged = true;  // Acknowledge the alarm
    PORTB &= ~(1 << ALARM_LED);  // Turn off the alarm LED
}

void handleButton(bool currentState, bool *lastState, unsigned long *lastDebounceTime, void (*action)()) {
    if (currentState != *lastState) {
        *lastDebounceTime = millis();
    }

    if ((millis() - *lastDebounceTime) > debounceDelay) {
        if (currentState == 0) {
            action();
        }
    }

    *lastState = currentState;
}

unsigned long millis() {
    return micros() / 1000;
}

unsigned long micros() {
    return (timer0_overflow_count << 8) + TCNT0;
}
