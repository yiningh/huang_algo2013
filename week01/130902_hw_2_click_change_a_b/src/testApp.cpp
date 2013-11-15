#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){

    rightLeft = 0;

	// set the "a" and "b" positions of the rectangle
	myRectangle.posa.x = 10;
	myRectangle.posa.y = 100;
	myRectangle.posb.x = 500;
	myRectangle.posb.y = 140;
	myRectangle.interpolateByPct(0);	// start at 0 pct
	pct = 0;							// a variable we can alter
}

//--------------------------------------------------------------
void testApp::update(){

	pct += 0.001f;							// increase by a certain amount
	if (pct > 1) {
		pct = 0;							// just between 0 and 1 (0% and 100%)
	}
	myRectangle.interpolateByPct(pct);		// go between pta and ptb

}

//--------------------------------------------------------------
void testApp::draw(){
	myRectangle.draw();
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
    rightLeft = !rightLeft;

    if(rightLeft == 0){
        myRectangle.posa.x = x;
        myRectangle.posa.y = y;
    }else{
        myRectangle.posb.x = x;
        myRectangle.posb.y = y;
    }
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
