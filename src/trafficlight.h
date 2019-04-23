#pragma once

#include <stdbool.h>


typedef enum {
    RED,
    GREEN,
    RED_YELLOW,
    YELLOW_BLINK,
    GREEN_BLINK,
    YELLOW
} traffic_light_phases;

typedef struct {
    bool red ;
    bool yellow ;
    bool green ;
    traffic_light_phases state;
    int ticksInState;       // the number of ticks spent in the same state

} TrafficLight;

TrafficLight* createTrafficLight();
void tick(TrafficLight* trafficLight);