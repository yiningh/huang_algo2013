#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);

    for( int i = 0; i < 50; i++ ){
        addParticle();
    }
    ofSetSmoothLighting(true);
    ofEnableLighting();
    ofEnableAlphaBlending();
    //ofSetGlobalAmbientColor(ofColor(0, 0, 0));
    ofSetSphereResolution(100);

    //material.setShininess(0);

    //material.setSpecularColor(ofColor(0, 0, 255, 255));
    //material.setEmissiveColor(ofColor(180, 180, 180, 255));
    //material.setDiffuseColor(ofColor(0, 255, 0, 255));
    //material.setAmbientColor(ofColor(0, 0, 255, 255*0.001));


    light.setSpotlight( 1000, 0 );
    //light.setOrientation( ofVec3f(100, -100, -100) );
    setLightOri(light, ofVec3f(0,0,0));
    light.setPosition(ofVec3f(0,700,200));
    //light.setAmbientColor(ofColor(255, 255,255, 255*0.001));
    light.setSpecularColor(ofFloatColor(230,230,230));
    light.setDiffuseColor(ofFloatColor(180,180,180));

    ofSetGlobalAmbientColor(ofColor(230));
    /*
    light.setDiffuseColor(ofFloatColor(255.0, 0.0, 0.0f));
    light.setSpecularColor(ofColor(0, 0, 255));
    light.setSpotlight();
    light.setSpotConcentration(10);
    light.setSpotlightCutOff(10);
    setLightOri(light, ofVec3f(0,0,0));
    light.setPosition(0, 0, 300);
    */
    cam.setTarget(ofGetWindowSize()/2);


}

void testApp::setLightOri(ofLight &light, ofVec3f rot){
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light.setOrientation(q);
}

//--------------------------------------------------------------
void testApp::update(){
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

    ofBackgroundGradient( 230, 190, OF_GRADIENT_CIRCULAR);


    cam.begin();
    cam.getTarget();
    light.enable();
    //material.begin();

    ofSetColor(255);
    for( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++){
        it -> draw();
    }
    //material.end();
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
