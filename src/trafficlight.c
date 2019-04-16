#include "trafficlight.h"
#include <stdlib.h>

TrafficLight* createTrafficLight(){
    TrafficLight* trafficLight = malloc(sizeof(TrafficLight));
    trafficLight->red = false;
    trafficLight->yellow = false;
    trafficLight->green = false;
    trafficLight->phase = off;
    return trafficLight;
}


void tick(TrafficLight* trafficLight){
    //control logic here ...


}