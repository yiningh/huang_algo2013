#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    mSender.setup( "localhost", 12345 );
    mSender2.setup( "localhost", 123456 );
    mSender3.setup( "localhost", 1234567 );
    ofBackground( 255, 200, 35);

    pos = ofGetWindowSize() / 2;
    vel = ofVec2f( ofRandom(-5,5), ofRandom(-3,3) );
}

//--------------------------------------------------------------
void testApp::update(){
    pos += vel;
    if(pos.x < 0 || pos.x > ofGetWindowWidth()*2){
        vel.x *= -1;
    }
    if(pos.y < 0 || pos.y > ofGetWindowHeight()*2){
        vel.y *= -1;
    }

    ofxOscMessage m2;
    m2.setAddress("/ball/pos");
    m2.addFloatArg(pos.x);
    m2.addFloatArg(pos.y);

    mSender.sendMessage( m2 );

    ofxOscMessage m22;
    m22.setAddress("/ball/pos");
    m22.addFloatArg(pos.x);
    m22.addFloatArg(pos.y);

    mSender2.sendMessage( m22 );

    ofxOscMessage m23;
    m23.setAddress("/ball/pos");
    m23.addFloatArg(pos.x);
    m23.addFloatArg(pos.y);

    mSender3.sendMessage( m23 );
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255, 135, 135);
    ofCircle( pos, 20);

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    /*
    mousePos.set( x, y );

    ofxOscMessage m;
    m.setAddress("/mouse/pos");
    m.addIntArg(mousePos.x);
    m.addIntArg(mousePos.y);

    mSender.sendMessage( m );
    */
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
