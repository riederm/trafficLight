#include "vendor/unity.h"
#include "../src/trafficlight.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // for usleep

TrafficLight* trafficLight;

void setUp(void) {
   printf("setup\n");
    trafficLight = createTrafficLight();
}

void tearDown(void){
   printf("teardown\n");
   free(trafficLight);
}

void initiallyTrafficLightIsOff(void)
{
   TEST_ASSERT_FALSE(trafficLight->green)
   TEST_ASSERT_FALSE(trafficLight->red)
   TEST_ASSERT_FALSE(trafficLight->yellow)
   TEST_ASSERT_EQUAL(trafficLight->phase, waiting);
}

void initiallyTrafficLightIsRed2(void)
{
   printf("    initiallyTrafficLightIsRed2\n");
}

void doSleep(){
   usleep(250*1000);
}

int main(void)
{
   UnityBegin("test/test_isogram.c");

   RUN_TEST(initiallyTrafficLightIsOff);
   RUN_TEST(initiallyTrafficLightIsRed2);




   UnityEnd();
      const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
      printf(CLEAR_SCREEN_ANSI);

   TrafficLight* tl = createTrafficLight();
   tl->phase = red;
   int frame = 0;
   while(true)
   {
      tick(tl);
      printf("frame: %d\n", frame++);
      printf("  ------    \n");
      printf("  | %s |    \n", tl->red ? "R" : " ");
      printf("  ------    \n");
      printf("  | %s |    \n", tl->yellow ? "Y" : " ");
      printf("  ------    \n");
      printf("  | %s |    \n", tl->green ? "G" : " ");
      printf("  ------    \n");
      doSleep();
      const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
      printf(CLEAR_SCREEN_ANSI);

   }
   free(tl);
   
   

   return 0;
}