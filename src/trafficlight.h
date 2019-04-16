#pragma once

#include <stdbool.h>


typedef enum {
        waiting,
        red,
        wait_for_green,
        green,
        wait_for_red,
        yellow
    } traffic_light_phases;

typedef struct {
    bool red ;
    bool yellow ;
    bool green ;

    int ticksInState;
    traffic_light_phases phase;

} TrafficLight;

TrafficLight* createTrafficLight();
void tick(TrafficLight* trafficLight);