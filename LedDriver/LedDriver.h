#include <stdint.h>

void LedDriver_Create(uint16_t *ledAddress);
void LedDriver_TurnOn(int ledToTurnOn);
void LedDriver_TurnOff(int ledToTurnOff);
void LedDriver_TurnOnAllLeds();
