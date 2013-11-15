#include "ofMain.h"
#ifndef DOTS_H
#define DOTS_H


class Dots
{
    public:
        Dots();
        virtual ~Dots();

        void draw();
        void update();

        vector<ofVec2f> pos;
        vector<float> angle;
        float radius;
        float difSize;

};

#endif // DOTS_H
