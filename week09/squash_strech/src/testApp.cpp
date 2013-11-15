#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    for (int i = 0; i < 50; i++){
        Particle p;
        ofVec2f newPos( ofRandomWidth(), ofRandomHeight() );
        p.pos = newPos;
        particleList.push_back(p);

    }
}
//--------------------------------------------------------------
void testApp::update(){
 for(int i = 0; i < particleList.size(); i ++){
    particleList[i].addRepulsionForce(mouseX, mouseY, 100, 30);
    particleList[i].update();
 }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackgroundGradient(ofColor(233, 178, 48), ofColor(152,129,73), OF_GRADIENT_CIRCULAR);
    for(int i =0; i < particleList.size(); i ++){
        particleList[i].draw();
    }
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
