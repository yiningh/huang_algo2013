#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);

	ofEnableAlphaBlending();

	for(int i = 0; i < 10; i++){
        rectangle myTempRects;
        myRectList.push_back(myTempRects);
	}

	for(int i = 0; i < myRectList.size(); i++){
        myRectList[i].pos.x = 100 +i*3;
        myRectList[i].pos.y = 50+ i*3;
        myRectList[i].myColor = 45 + i*20;
        myRectList[i].catchUpSpeed = 0.005f * i + 0.005f;
    }

}

//--------------------------------------------------------------
void testApp::update(){
    for( int i = 0; i < 10; i++){
        myRectList[i].xenoToPoint(mouseX, mouseY);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i = 0; i < 10; i++){
        myRectList[i].draw();
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
