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
        ofSetColor(194,181,155);
        ofBeginShape();
        ofVertex(75,37);
        ofBezierVertex(75,58,58,75,37,75);
        ofBezierVertex(16,75,0,58,0,37);
        ofBezierVertex(0,16,16,0,37,0);
        ofBezierVertex(58,0,75,16,75,37);
        ofEndShape();

        ofFill();
        ofSetColor(190,30,45);
        ofBeginShape();
        ofVertex(71,37);
        ofBezierVertex(71,56,56,71,37,71);
        ofBezierVertex(18,71,3,56,3,37);
        ofBezierVertex(3,18,18,3,37,3);
        ofBezierVertex(56,3,71,18,71,37);
        ofEndShape();

        ofFill();
        ofSetColor(109,110,113);
        ofBeginShape();
        ofVertex(68,37);
        ofBezierVertex(68,54,54,68,37,68);
        ofBezierVertex(20,68,7,54,7,37);
        ofBezierVertex(7,20,20,7,37,7);
        ofBezierVertex(54,7,68,20,68,37);
        ofEndShape();

        ofFill();
        ofSetColor(167,169,172);
        ofBeginShape();
        ofVertex(53,37);
        ofBezierVertex(53,46,46,53,37,53);
        ofBezierVertex(28,53,21,46,21,37);
        ofBezierVertex(21,28,28,21,37,21);
        ofBezierVertex(46,21,53,28,53,37);
        ofEndShape();

        ofFill();
        ofSetColor(39,170,225);
        ofBeginShape();
        ofVertex(48,37);
        ofBezierVertex(48,43,43,48,37,48);
        ofBezierVertex(31,48,26,43,26,37);
        ofBezierVertex(26,31,31,26,37,26);
        ofBezierVertex(43,26,48,31,48,37);
        ofEndShape();

    }ofPopMatrix();
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}
