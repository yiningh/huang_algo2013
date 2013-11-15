#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){
    for(int i = 0; i < myBall.size(); i++){
        myBall[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < myBall.size(); i++){
        myBall[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    ball tempMyBall;
    myBall.push_back(tempMyBall);
    myBall[myBall.size()-1].init(mouseX, mouseY);
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
