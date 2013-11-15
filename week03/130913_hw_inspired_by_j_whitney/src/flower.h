#include "ofMain.h"
#ifndef FLOWER_H
#define FLOWER_H


class Flower
{
    public:
        Flower();
        virtual ~Flower();
        void update();
        void draw();

        float rotation;
        ofVec2f pos;
        int radius;
        float angle;
};

#endif // FLOWER_H
