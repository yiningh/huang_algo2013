#include "ofMain.h"
#include "rectangle.h"

rectangle::rectangle()
{
    shaper = 2.0;

}

rectangle::~rectangle()
{
    //dtor
}

//------------------------------------------------------------------
void rectangle::draw() {
    mySize += shaper;
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
   //ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, 20+mySize,20);
}


//------------------------------------------------------------------
void rectangle::interpolateByPct(float myPct){
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
}
