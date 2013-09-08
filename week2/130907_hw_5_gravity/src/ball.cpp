#include "ofMain.h"
#include "ball.h"

ball::ball()
{
    ofSeedRandom();
    vel.x = ofRandom(5,-5);
    vel.y = ofRandom(5,-5);
}

ball::~ball()
{
    //dtor
}

void ball::init(float mousePosX, float mousePosY){
    pos.x = mousePosX;
    pos.y = mousePosY;
}

void ball::update(){
    vel.y += 0.2;
    pos += vel;
    if(pos.x < 0 || pos.x > ofGetWindowWidth()-20)vel.x *= -1;
    if(pos.y < 0 || pos.y > ofGetWindowHeight()-20){vel.y *= -0.8;};
    if(pos.y > ofGetWindowHeight()- 19) pos.y = ofGetWindowHeight()-19;

}

void ball::draw(){
    ofCircle(pos.x, pos.y, 20);
}
