#pragma once

#include <stdbool.h>


typedef enum {
    off
} traffic_light_phases;

typedef struct {
    bool red ;
    bool yellow ;
    bool green ;
    traffic_light_phases phase;

} TrafficLight;

TrafficLight* createTrafficLight();
void tick(TrafficLight* trafficLight);