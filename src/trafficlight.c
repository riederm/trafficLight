#include "trafficlight.h"
#include <stdlib.h>

TrafficLight* createTrafficLight(){
    TrafficLight* trafficLight = malloc(sizeof(TrafficLight));
    trafficLight->red = false;
    trafficLight->yellow = false;
    trafficLight->green = false;
    trafficLight->phase = waiting;
    trafficLight->ticksInState = 0;
    return trafficLight;
}

void transit(TrafficLight* trafficLight, traffic_light_phases phase){
    trafficLight->phase = phase;
    trafficLight->ticksInState = -1;
}

void update(TrafficLight* trafficLight, bool r, bool y, bool g){
    trafficLight->red = r;
    trafficLight->yellow = y;
    trafficLight->green = g;
}

void tl_waiting(TrafficLight* trafficLight){
    update(trafficLight, false, false, false);
}

void tl_red(TrafficLight* trafficLight){
    update(trafficLight, true, false, false);

    if (trafficLight->ticksInState == 12){
        transit(trafficLight, wait_for_green);
    }
}

void tl_wait_for_green(TrafficLight* trafficLight){
    update(trafficLight, true, true, false);

    if (trafficLight->ticksInState == 2){
        transit(trafficLight, green);
    }
}

void tl_green(TrafficLight* trafficLight){
     update(trafficLight, false, false, true);
     if (trafficLight->ticksInState == 5){
         transit(trafficLight, wait_for_red);
     }
}


void tl_wait_for_red(TrafficLight* trafficLight){
     update(trafficLight, false, false, trafficLight->ticksInState % 2);
     if (trafficLight->ticksInState == 5){
         transit(trafficLight, yellow);
     }
}

void tl_yellow(TrafficLight* trafficLight){
     update(trafficLight, false, true, false);
     if (trafficLight->ticksInState == 4){
         transit(trafficLight, red);
     }
}

void tick(TrafficLight* trafficLight){
    switch (trafficLight->phase)
    {
        case waiting: {
            tl_waiting(trafficLight);
            break;
        } case red:{
            tl_red(trafficLight);
            break;
        } case wait_for_green: {
            tl_wait_for_green(trafficLight);
            break;
        } case green: {
            tl_green(trafficLight);
            break;
        } case wait_for_red:{
            tl_wait_for_red(trafficLight);
            break;
        } case yellow:{
            tl_yellow(trafficLight);
            break;
        }
        default:
            break;
    }

    trafficLight->ticksInState++;


}