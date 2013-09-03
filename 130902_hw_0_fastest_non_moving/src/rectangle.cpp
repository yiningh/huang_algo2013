#include "ofMain.h"
#include "rectangle.h"

rectangle::rectangle()
{
    //ctor
}

rectangle::~rectangle()
{
    //dtor
}

void rectangle::update(){

	pos.x = pos.x + 0.001;
    //pos.y = pos.y + ofRandom(-1,1);
}

void rectangle::draw(){
    ofFill();
    ofEnableAlphaBlending();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(150,200,255,200);

    ofRect(pos.x, pos.y, 20,20);
}
