
#pragma once
#include "ofMain.h"
#include "fish.h"

class Controller{
public:
    void addFish( int num );
    void update( float effectZone = 80.0f, float pushAway = 0.4, float goTogether = 0.7 );
    void draw();

    vector<Fish> fishGrill;
};
