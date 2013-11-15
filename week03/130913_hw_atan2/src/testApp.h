#pragma once

#include "ofMain.h"

class Bird {
public:
    ofPoint pos, mousePos;
    float angle;

    void draw() {
        ofPushMatrix();{
            ofTranslate( pos.x, pos.y );

            float dx = mousePos.x - pos.x;
            float dy = mousePos.y - pos.y;

            angle = atan2( dy , dx );

            ofRotate( ofRadToDeg(angle) );

            ofSetColor( 0 );

            ofFill();
            ofSetColor(0,0,0);
            ofBeginShape();
            ofVertex(101,61);
            ofVertex(101,43);
            ofVertex(232,52);
            ofVertex(101,61);
            ofEndShape();

            ofFill();
            ofSetColor(255,127,0);
            ofBeginShape();
            ofVertex(55,0);
            ofBezierVertex(47,0,40,1,33,4);
            ofBezierVertex(23,6,9,8,0,1);
            ofBezierVertex(0,1,11,11,23,11);
            ofBezierVertex(11,20,4,35,4,51);
            ofBezierVertex(4,79,27,103,55,103);
            ofBezierVertex(84,103,107,79,107,51);
            ofBezierVertex(107,23,84,0,55,0);
            ofEndShape();

            ofFill();
            ofSetColor(255,255,255);
            ofBeginShape();
            ofVertex(97,37);
            ofBezierVertex(97,48,88,57,76,57);
            ofBezierVertex(65,57,55,48,55,37);
            ofBezierVertex(55,25,65,16,76,16);
            ofBezierVertex(88,16,97,25,97,37);
            ofEndShape();

            ofFill();
            ofSetColor(0,0,0);
            ofBeginShape();
            ofVertex(90,37);
            ofBezierVertex(90,44,84,51,76,51);
            ofBezierVertex(68,51,62,44,62,37);
            ofBezierVertex(62,29,68,23,76,23);
            ofBezierVertex(84,23,90,29,90,37);
            ofEndShape();



        }ofPopMatrix();
    }

};


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    Bird bird1, bird2, bird3, bird4, bird5, bird6, bird7, bird8, bird9;
    float angle;
};
