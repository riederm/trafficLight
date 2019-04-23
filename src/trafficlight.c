#include "trafficlight.h"
#include <stdlib.h>

TrafficLight* createTrafficLight(){
    TrafficLight* trafficLight = malloc(sizeof(TrafficLight));
    trafficLight->red = true;
    trafficLight->yellow = false;
    trafficLight->green = false;
    trafficLight->state = RED;
    return trafficLight;
}

void setColors(TrafficLight* trafficLight, bool r, bool y, bool g){
    trafficLight->red = r;
    trafficLight->green = g;
    trafficLight->yellow = y;
}

void changeState(TrafficLight* trafficLight, traffic_light_phases newState){
    trafficLight->state = newState;
    trafficLight->ticksInState = 0;
}

void tick_RED(TrafficLight* trafficLight){
    setColors(trafficLight, true, false, false);

    if(trafficLight->ticksInState == 10){
        changeState(trafficLight, RED_YELLOW);
    }
}


void tick(TrafficLight* trafficLight){

    switch(trafficLight->state){

        case RED:{
            tick_RED(trafficLight);
            break;
        }
        case RED_YELLOW:{
            break;
        }
        case GREEN:{
            break;
        }
        case GREEN_BLINK:{
            break;
        }
        case YELLOW: {
            break;
        }
        case YELLOW_BLINK:{
            break;
        }
        default:{
            break;
        }

    }


}