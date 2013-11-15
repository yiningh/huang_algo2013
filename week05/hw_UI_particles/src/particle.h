#pragma once
#include "ofMain.h"

class Particle{
    public:
        Particle(){};
        void init( ofVec3f thatVel );
        void update(bool toggleValue);
        void draw(float circSliderValue );

        ofVec3f vel;
        ofVec3f pos;
        float lifeSpan;
        float age;
        bool bIsDead;
};
