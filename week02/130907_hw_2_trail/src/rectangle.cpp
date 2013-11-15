#include "ofMain.h"
#include "rectangle.h"

rectangle::rectangle()
{
    catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	//ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(255-myColor,100,myColor);
    //ofFill();
    ofLine(pos.x, pos.y, pos.y, pos.x);
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
