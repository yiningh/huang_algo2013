#pragma once
#ifndef BALL_H
#define BALL_H


class ball
{
    public:
        ball();
        virtual ~ball();
        void init(float mousePosX, float mousePosY);
        void update();
        void draw();

        ofPoint pos;
        ofPoint vel;
    protected:
    private:
};

#endif // BALL_H
