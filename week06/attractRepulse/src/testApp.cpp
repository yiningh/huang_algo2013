#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    ofSetCircleResolution( 100 );
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    for (int i = 0; i < 50; i++){
        Particle p;
        ofVec2f newPos( ofRandomWidth(), ofRandomHeight() );
        p.pos = newPos;
        p.pSize = 100 - i;
        particleList.push_back(p);
    }
    ofBackground(230);
    bigPos = ofGetWindowSize() / 2;
    bigAcc = ofVec2f(ofRandom(-1, 1), ofRandom(-1, 1));
    angle = 1;
}

//--------------------------------------------------------------
void testApp::update(){
    angle += 0.1;
    bigAcc.x += (cos(angle)*20)/60;
    bigAcc.y += (sin(angle *1.2)*20)/30;
    bigPos += bigAcc;
    if(bigPos.x < 0 || bigPos.x > ofGetWindowWidth()){
        bigAcc.x *= -1;
    }
    if(bigPos.y < 0 || bigPos.y > ofGetWindowHeight()){
        bigAcc.y *= -1;
    }

    for(vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++){
        it->addAttractionForce(bigPos.x, bigPos.y, 800, 0.5);
        it->addRepulsionForce(bigPos.x, bigPos.y, 200, 5);
        it->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //ofBackgroundGradient(230,180,OF_GRADIENT_CIRCULAR);
    ofFill();
    ofColor(150,0.01);
    //ofRect(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    for(vector<Particle>::iterator it = particleList.begin(); it != particleList.end(); it++){
        it->draw();
    }
    //ofColor(0);
    //ofCircle(bigPos.x, bigPos.y, 20);
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
