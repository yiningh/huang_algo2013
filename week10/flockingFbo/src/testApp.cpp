#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    ofSetVerticalSync( true );
    ofEnableAlphaBlending();
    ofBlendMode(OF_BLENDMODE_ADD);


    ofBackground( 255,218,137 );
    ctr.addFish( 800 );

    //ofEnableDepthTest();
    cam.setDistance(1000);

    myFbo.allocate(ofGetWindowWidth(), ofGetWindowHeight());

    ofSetSmoothLighting(true);
    ofSetGlobalAmbientColor(ofColor(0,74,125));
    light.setPosition(1000,1000,0);
    light.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    light.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    material.setShininess( 120 );
    material.setAmbientColor(ofColor((80,184,255)));
	material.setSpecularColor(ofColor(100, 170, 236, 255));

}

//--------------------------------------------------------------
void testApp::update(){
    ctr.update(80.0f, 0.4f, 0.75f);
    ofSetWindowTitle("frame rate: "+ofToString(ofGetFrameRate(), 2));
}

//--------------------------------------------------------------
void testApp::draw(){

    myFbo.begin();
        cam.begin();
        light.enable();
        material.begin();
            ofClear(0);
            ctr.draw();
        material.end();
        light.disable();
        cam.end();
    myFbo.end();

    myFbo.draw(0,0);
    ofPushMatrix();
        ofTranslate(ofGetWindowWidth(), ofGetWindowHeight());
        myFbo.draw(0,0, -ofGetWindowWidth(), -ofGetWindowHeight());
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
