#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    //ofBackgroundGradient( 230, 190, OF_GRADIENT_CIRCULAR);
    //ofBackground(255);
    ofSetFrameRate(60);
    //ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    depthOfField.setup(ofGetWindowWidth(), ofGetWindowHeight() );

    for( int i = 0; i < 100; i++ ){
        addParticle();
    }
    ofSetSmoothLighting(true);
    ofEnableLighting();
    ofEnableAlphaBlending();
    ofSetSphereResolution(100);
    ofEnableDepthTest();

    light.setDiffuseColor( ofColor(255.f, 255.f, 255.f));
	light.setSpecularColor( ofColor(255.f, 255.f, 255.f));
    light.setPosition(500, 500 , 500);

    AmbientColor = ofColor(255);
    AmbientColor.setBrightness(100);
    ofSetGlobalAmbientColor(AmbientColor);
    //light.setAmbientColor(AmbientColor);

    lightColor = ofColor(255);
    lightColor.setBrightness( 200.0f );
    lightColor.setSaturation( 0.0f );
    lightColor.setHue(0.0f);

    light.setDiffuseColor(lightColor);

    material.setShininess( 50 );
    materialColor = ofColor(155,207,255);

    ofColor SpecMatCol = materialColor;
    SpecMatCol.setBrightness(200);
	material.setSpecularColor( materialColor );

    cam.setTarget(ofVec3f(0,0,0));

    depthOfField.setFocalRange(100);
    depthOfField.shadorColor.set(255,255,255,255);
}

//--------------------------------------------------------------
void testApp::update(){

    depthOfField.setFocalDistance(250);

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

    depthOfField.begin();
    ofClear(255,0);
    ofBackground(230);
    //ofBackgroundGradient( 230, 190, OF_GRADIENT_CIRCULAR);
    //ofSetColor(materialColor);
    cam.begin( depthOfField.getDimensions() );
    cam.getTarget();
    light.enable();
    material.begin();
    for( vector<Particle>::iterator it = pList.begin(); it != pList.end(); it++){
        it -> draw();
    }
    material.end();
    light.disable();
    cam.end();
    depthOfField.end();
    //depthOfField.getFbo().draw(0, 0);
    if(ofGetKeyPressed('f')){
		depthOfField.drawFocusAssist(0, 0);
	}
	else{
		depthOfField.getFbo().draw(0, 0);
	}


}

void testApp::addParticle(){
    //to init the vel/direction
    Particle p;
    ofVec3f vel = ofVec3f( ofRandom(1.0, -1.0), ofRandom(1.0, -1.0), ofRandom(1.0, -1.0) ) * 15.0;
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
     //light.setPosition(x, y, 0);
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