#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){


	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:

	ofSetVerticalSync(true);

	// set background:

	ofBackground(30,30,30);

	// now we are using multiple rectangles....
	// set the "a" and "b" positions of the
	for (int i = 0; i < 30; i++){
		myRectangles[i].posa.x = 0;
		myRectangles[i].posa.y = 10 + i*20;
		myRectangles[i].posb.x = 400;
		myRectangles[i].posb.y = 10 + i*20;
		myRectangles[i].shaper = 0.4 + 0.2 * i;
		myRectangles[i].interpolateByPct(0);	// start at 0 pct
	}
	pct = 0;							// a variable we can alter...
}

//--------------------------------------------------------------
void testApp::update(){


	pct += 0.003f;							// increase by a certain amount
	if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
	for (int i = 0; i < 30; i++){
		myRectangles[i].interpolateByPct(pct);		// go between pta and ptb
	}

	for(int i = 0; i < 30; i++){
        if (myRectangles[i].mySize >= ofGetWindowWidth()*2){
            myRectangles[i].mySize = 20;
            myRectangles[i].shaper = 2;
        }
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	for (int i = 0; i < 30; i++){
		ofSetColor(198,246,55);
		//if (i == 3) ofSetColor(255,0,0);
		myRectangles[i].draw();
	}

	ofSetColor(255,255,255);
	for (int i = 0; i < 30; i++){
		ofLine(0,i*20, ofGetWidth(), i*20);
	}


}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
