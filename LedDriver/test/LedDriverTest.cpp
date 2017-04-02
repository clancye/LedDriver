#include "gtest/gtest.h"
#include <stdint.h>
#include "LedDriver.h"

class ledDriverTest : public ::testing::Test
{
protected:
	uint16_t virtualLeds;
	void SetUp() {
		LedDriver_Create(&virtualLeds);
	}
};

TEST_F(ledDriverTest, LedsOffAfterCreate)
{
	ASSERT_EQ(0, virtualLeds);
}

TEST_F(ledDriverTest, TurnOnLedOne)
{
	LedDriver_TurnOn(1);
	ASSERT_EQ(1, virtualLeds);
}

TEST_F(ledDriverTest, TurnOffLedOne)
{
	LedDriver_TurnOn(1);
	LedDriver_TurnOff(1);
	ASSERT_EQ(0,virtualLeds);
}

TEST_F(ledDriverTest, TurnOnMultipleLeds)
{
	LedDriver_TurnOn(7);
	LedDriver_TurnOn(8);
	ASSERT_EQ(0xC0, virtualLeds);
}

TEST_F(ledDriverTest, TurnOffMultipleLeds)
{
	virtualLeds = 0xffff;
	LedDriver_TurnOff(16);
	LedDriver_TurnOff(12);
	LedDriver_TurnOff(8);
	LedDriver_TurnOff(2);
	ASSERT_EQ(0x777D, virtualLeds);
}	

TEST_F(ledDriverTest, TurnOnAllLeds)
{
	virtualLeds = 0;
	LedDriver_TurnOnAllLeds();
	ASSERT_EQ(0xffff, virtualLeds);
}
