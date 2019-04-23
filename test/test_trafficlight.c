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

void assertTrafficLight(traffic_light_phases expectedState,
                            bool expectedRed,
                            bool expectedYellow,
                            bool expectedGreen){
    TEST_ASSERT_EQUAL(trafficLight->state, expectedState);
    TEST_ASSERT_EQUAL(trafficLight->red, expectedRed);
    TEST_ASSERT_EQUAL(trafficLight->yellow, expectedYellow);
    TEST_ASSERT_EQUAL(trafficLight->green, expectedGreen);
}

void initiallyTrafficLightIsRED(void)
{
    assertTrafficLight(RED, true, false, false);
}

void itShouldChangeFromREDtoRED_YELLOWAfter10Ticks(){
    // GIVEN a RED tl
    trafficLight->state = RED;

    // WHEN 10 ticks happen
    for(int i=0; i<10; i++) tick(trafficLight);

    // THEN the tl should be RED_YELLOW
    assertTrafficLight(RED_YELLOW, true, true, false);
}


int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(initiallyTrafficLightIsRED);
   RUN_TEST(itShouldChangeFromREDtoRED_YELLOWAfter10Ticks);


   UnityEnd();

   return 0;
}