#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    mReceiver.setup(123456);
    ofBackground( 246,210,231 );
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
}

void testApp::checkOsc(){
    while( mReceiver.hasWaitingMessages() ){
        ofxOscMessage m;
        mReceiver.getNextMessage( &m ); //pass, fill in the message

        string addr = m.getAddress();

        if( addr == "/mouse/pos"){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);

            mousePos.set( xPos, yPos );
        }else

        if( addr == "/ball/pos"){
            int xPos = m.getArgAsFloat(0);
            int yPos = m.getArgAsFloat(1);

            ballPos.set( xPos, yPos );
        }
    }
}
//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle("receiver_two_-1,1");
    ofPushMatrix();
    ofTranslate( -ofGetWindowWidth(), 0);
    ofSetColor( 247, 235 ,233 );
    ofCircle( ballPos, 20 );
    ofPopMatrix();
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