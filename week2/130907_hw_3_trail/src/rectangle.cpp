#include "ofMain.h"
#include "rectangle.h"

rectangle::rectangle()
{
    catchUpSpeed = 0.03f;

}

//------------------------------------------------------------------
void rectangle::draw() {
    ofPushMatrix();{
        ofTranslate(pos.x, pos.y);
        ofScale(1.5,1.5,1);
        ofFill();
        ofSetColor(236,0,myColor);
        ofBeginShape();
        ofVertex(15,11);
        ofBezierVertex(9,7,14,-2,20,0);
        ofBezierVertex(27,4,25,9,24,20);
        ofBezierVertex(23,31,25,45,30,47);
        ofBezierVertex(35,49,39,45,34,39);
        ofBezierVertex(29,33,13,31,6,33);
        ofBezierVertex(-1,35,-2,44,6,41);
        ofBezierVertex(14,38,18,28,32,17);
        ofBezierVertex(47,6,47,28,38,26);
        ofBezierVertex(28,24,19,15,15,11);
        ofEndShape();
        //ofLine(pos.x, pos.y, pos.y, pos.x);
    }ofPopMatrix();
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
