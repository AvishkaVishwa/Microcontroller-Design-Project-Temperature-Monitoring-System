#ifndef MAIN_H
#define MAIN_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "spi.h"
#include "max7219.h"

// Pin connections for the push buttons and LEDs
#define INC_BUTTON PD2
#define DEC_BUTTON PD3
#define MODE_BUTTON PD4
#define ACK_BUTTON PB0  // New pin for the acknowledgment button
#define LED1 PB1
#define LED2 PD5
#define LED3 PD6
#define LED4 PD7
#define ALARM_LED PB4

// Variables for storing the state
extern int temperatureC;  // Initial temperature in Celsius
extern bool isCelsius;  // Start in Celsius mode
extern bool alarmAcknowledged;  // New variable to track alarm acknowledgment

// Debouncing variables
extern unsigned long lastDebounceTimeInc;
extern unsigned long lastDebounceTimeDec;
extern unsigned long lastDebounceTimeMode;
extern unsigned long lastDebounceTimeAck;
extern const unsigned long debounceDelay;

// Variables to keep track of button state
extern bool lastIncButtonState;
extern bool lastDecButtonState;
extern bool lastModeButtonState;
extern bool lastAckButtonState;  // New variable for acknowledgment button state

// Variables for blinking alarm LED
extern unsigned long lastBlinkTime;
extern bool alarmState;
extern const unsigned long blinkInterval;  // Blink interval in milliseconds

// Function prototypes
void updateLEDs(void);
void handleAlarmBlink(void);
void increaseTemperature(void);
void decreaseTemperature(void);
void switchMode(void);
void toggleAlarmAcknowledgment(void);
void handleButton(bool currentState, bool *lastState, unsigned long *lastDebounceTime, void (*action)());
unsigned long millis(void);
unsigned long micros(void);

#endif // MAIN_H
