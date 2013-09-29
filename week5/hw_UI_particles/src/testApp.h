#pragma once

#include "ofMain.h"
#include "particle.h"
#include "ofxDOF.h"
#include "ofxUI.h"

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
    void addParticle();
    void setLightOri(ofLight &light, ofVec3f rot);
    void exit();

    vector<Particle> pList;
    ofEasyCam cam;
    ofLight light;
    ofMaterial material;
    ofColor lightColor, materialColor, AmbientColor;
    //ofxBlur blur;
    ofxDOF depthOfField;

    void guiEvt( ofxUIEventArgs &e );
    ofxUICanvas *gui;
    bool toggleValue;
    float circSliderValue;
    float grav;
};
