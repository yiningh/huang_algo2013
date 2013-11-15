#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    myRect.pos.x = 20;
	myRect.pos.y = ofGetWindowHeight() / 2;
}

//--------------------------------------------------------------
void testApp::update(){
    myRect.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(200,150,150);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofRect(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    myRect.draw();
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
    if( key == ' '){
        ofToggleFullscreen();
    }
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
