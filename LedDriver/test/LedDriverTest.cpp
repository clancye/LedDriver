#include "gtest/gtest.h"
#include <stdint.h>
#include "LedDriver.h"

class ledDriverTest : public ::testing::Test
{
protected:
	uint16_t virtualLeds;
};

TEST_F(ledDriverTest, LedsOffAfterCreate)
{
	LedDriver_Create(&virtualLeds);
	ASSERT_EQ(0, virtualLeds);
}

TEST_F(ledDriverTest, TurnOnLedOne)
{
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	ASSERT_EQ(1, virtualLeds);
}

TEST_F(ledDriverTest, TurnOffLedOne)
{
	LedDriver_Create(&virtualLeds);
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	ASSERT_EQ(0,virtualLeds);
}	
