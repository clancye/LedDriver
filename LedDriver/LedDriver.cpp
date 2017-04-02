#include "LedDriver.h"

static uint16_t *ledsAddress;
enum {ALL_LEDS_ON = ~0, ALL_LEDS_OFF = ~ALL_LEDS_ON};
void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	*ledsAddress = 0;
}

static uint16_t convertLedNumberToBit(int led)
{
	return (1 << (led - 1));
}

void LedDriver_TurnOn(int ledToTurnOn)
{
	*ledsAddress |= convertLedNumberToBit(ledToTurnOn);	
}

void LedDriver_TurnOff(int ledToTurnOff)
{
	*ledsAddress ^= (1 << (ledToTurnOff -1));
}

void LedDriver_TurnOnAllLeds()
{
	*ledsAddress = ALL_LEDS_ON;
}
