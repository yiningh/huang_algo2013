#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofBackgroundGradient( 230, 190, OF_GRADIENT_CIRCULAR);
    ofBackground(240);
    ofSetFrameRate(60);

    for( int i = 0; i < 50; i++ ){
        addParticle();
    }
    ofSetSmoothLighting(true);
    ofEnableLighting();
    ofEnableAlphaBlending();
    ofSetSphereResolution(100);
    ofEnableDepthTest();

    light.setDiffuseColor( ofColor(0.f, 255.f, 0.f));
    // specular color, the highlight/shininess color //
	light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    light.setPosition(ofGetWindowWidth()/2, ofGetWindowHeight()/2 , 0);

    material.setShininess( 30 );

    lightColor.setBrightness( 84.f );
    lightColor.setSaturation( 62.f );
    lightColor.setHue(195.0);

    materialColor.setBrightness(84);
    materialColor.setSaturation(62);

    ofSetGlobalAmbientColor(ofColor(200));

    cam.setTarget(ofGetWindowSize()/2);
}

//--------------------------------------------------------------
void testApp::update(){

    light.setDiffuseColor(lightColor);
    materialColor.setHue(195);
	material.setSpecularColor( materialColor );

    for( vector<Particle>::iterator it=pList.begin(); it != pList.end(); ){
        it -> update();
        if( it->bIsDead ){
            it = pList.erase( it );
        }else{
            it++;
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){

    //ofBackgroundGradient( 230, 190, OF_GRADIENT_CIRCULAR);
    ofSetColor(light.getDiffuseColor());

    cam.begin();
    cam.getTarget();
    light.enable();
    material.begin();

    //ofSetColor(255);
    for( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++){
        it -> draw();
    }
    material.end();
    light.disable();
    cam.end();

}

void testApp::addParticle(){
    //to init the vel/direction
    Particle p;
    ofVec3f vel = ofVec3f( ofRandom(1.0, -1.0), ofRandom(1.0, -1.0), ofRandom(1.0, -1.0) ) * 5.0;
    p.init( vel );
    pList.push_back( p );
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
    for( int i = 0; i < 50; i++ ){
        addParticle();
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
