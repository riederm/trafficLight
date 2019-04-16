#include "vendor/unity.h"
#include "../src/trafficlight.h"
#include <stdlib.h>
#include <stdio.h>

TrafficLight* trafficLight;

void setUp(void) {
   trafficLight = createTrafficLight();
}

void tearDown(void){
   free(trafficLight);
}

void initiallyTrafficLightIsOff(void)
{
   TEST_ASSERT_FALSE(trafficLight->green)
   TEST_ASSERT_FALSE(trafficLight->red)
   TEST_ASSERT_FALSE(trafficLight->yellow)
   TEST_ASSERT_EQUAL(trafficLight->phase, off);
}


int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(initiallyTrafficLightIsOff);

   UnityEnd();

   return 0;
}