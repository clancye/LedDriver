#include "LedDriver.h"

static uint16_t *ledsAddress;

void LedDriver_Create(uint16_t *address)
{
	ledsAddress = address;
	*ledsAddress = 0;
}

void LedDriver_TurnOn(int ledToTurnOn)
{
	*ledsAddress |= (1 << (ledToTurnOn - 1));	
}

void LedDriver_TurnOff(int ledToTurnOff)
{
	*ledsAddress ^= (1 << (ledToTurnOff -1));
}
