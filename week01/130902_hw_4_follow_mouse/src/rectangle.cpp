#include "ofMain.h"
#include "rectangle.h"

rectangle::rectangle()
{
    catchUpSpeed = 0.03f;
}

rectangle::~rectangle()
{
    //dtor
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(150,150,myColor);
    ofRect(pos.x, pos.y, 40, 40);
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
