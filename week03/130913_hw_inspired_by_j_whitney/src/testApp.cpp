#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(40);
    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    myFlower.update();
    myDot.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor( 0, 0, 0, 255*0.02 );
    ofFill();
    ofRect( 0,0, ofGetWindowWidth(), ofGetWindowHeight() );
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2 - 100 );
        //myDot.draw();
        myFlower.draw();
    }ofPopMatrix();

    ofPushMatrix();{
        ofTranslate( ofGetWindowWidth() / 2 + 100, ofGetWindowHeight() / 2 - 100 );
        ofScale(-1, 1);
        myFlower.draw();
    }ofPopMatrix();

    ofPushMatrix();{
        ofTranslate( ofGetWindowWidth() / 2 + 100, ofGetWindowHeight() / 2);
        ofScale(-1, -1);
        myFlower.draw();
    }ofPopMatrix();

    ofPushMatrix();{
        ofScale(1, 1);
        ofTranslate( ofGetWindowWidth() / 2 - 100, ofGetWindowHeight() / 2  );
        myFlower.draw();
    }ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
