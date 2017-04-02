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
