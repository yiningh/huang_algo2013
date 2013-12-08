#pragma once

#include "ofMain.h"
#include "ofxOpticalFlowFarneback.h"
#include "ofxOpenCv.h"
#include "ofxOsc.h"

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

        ofLight pointLight;
        ofLight pointLight2;
        ofMaterial material;

        ofVideoGrabber vidGrabber;

        ofShader shader;
        ofImage colormap, bumpmap;
        GLUquadricObj *quadric;

        ofxOpticalFlowLK flowSolver;
        ofFbo fbo;
        ofFbo texFbo;
        ofPixels pix;
        ofPixels texPix;
        ofImage img;
        ofImage perlinImg;
        ofImage texImg;
        ofImage smallVidImg;
        int yPos;

        ofIcoSpherePrimitive icoSphere;

        //OSC
        ofxOscSender mSender;

};
