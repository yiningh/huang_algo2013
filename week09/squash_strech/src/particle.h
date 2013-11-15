#pragma once
#include "ofMain.h"

class Particle{
public:
    Particle();

    void addForce( ofVec2f force );
    void update();
    void draw();

    void addRepulsionForce( float px, float py, float radius, float strength );
    void addAttractionForce(float px, float py, float radius, float strength);
    ofVec2f pos, vel, acc;
    float damping;
    float circWidth, circHeight;
};
