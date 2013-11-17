
#pragma once
#include "ofMain.h"

class Fish{
public:
    Fish();
    Fish(ofVec3f _pos, ofVec3f _vel);
    void applyForce( ofVec3f force );
    void moveToCenter( ofVec3f center );
    void update();
    void draw();

    ofVec3f pos, vel, acc;
};
