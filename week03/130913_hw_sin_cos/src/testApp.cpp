#include "testApp.h"
#define NUM_NUM 1200

ofPoint pos[NUM_NUM];
float angle;
float amp[NUM_NUM];
float des;
//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    angle = 1;

    for( int i = 0; i < NUM_NUM; i++ ){
        pos[i].y = ofGetWindowHeight() / 2;
        pos[i].x = i;
        amp[i] = 0;
    }

    ofEnableAlphaBlending();
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    angle ++;
    for (int i = 0; i < NUM_NUM; i ++){
        pos[i].y = ofGetWindowHeight()/ 2 + sin( angle * i / 2000 ) * amp[i] ;
        if ( amp[i] > 0 ){
            amp[i] -= 0.3;
        }else{
            amp[i] = 0;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofFill();
    ofSetColor(255, 255, 255, 255*0.06 );
    ofRect( 0, 0, ofGetWindowWidth(), ofGetWindowHeight() );
    ofSetColor(100);
    ofNoFill();
    ofBeginShape();
    for(int i = 0; i < NUM_NUM; i ++){
        ofVertex(pos[i]);
    }
    ofEndShape();
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

    des = ofMap( mouseX, 0, ofGetWindowWidth(), 0, 100);
    angle = 1;

    for(int i = 0; i < NUM_NUM; i++ ){
        amp[i] = 0;
    }

    for(int i = 0; i < NUM_NUM; i++){
        if( mouseX == pos[i].x ){
            amp[i] = 100;
            for( int j = 0; j < NUM_NUM; j++ ){
                if( j - i > 0 ){
                    amp[j] = 100 - ( j - i )/8;
                }
                if( j - i < 0 ){
                    amp[j] = 100 + ( j - i )/8;
                }
                if( j == i ){
                    amp[j] = 100;
                }
            }

        }
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
