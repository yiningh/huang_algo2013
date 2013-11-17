#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );

    ofBackground(0);

    particleList.clear();

    for( int i=0; i<300; i++ ){
        addParticle();
    }

    myRotate = false;
    myPattern = false;
}

void testApp::addParticle() {
    Particle part;
    part.pos = ofVec2f( ofRandomWidth(), ofRandomHeight() );

    particleList.push_back( part );
}

//--------------------------------------------------------------
void testApp::update(){

    for( int i=0; i<particleList.size(); i++ ){
        ofVec2f forceAtPos = myField.getForceAtPosition(particleList[i].pos) * 0.005;
        particleList[i].applyForce( forceAtPos );
        particleList[i].update();
    }

    if(myRotate){
        myField.setRotate(mouseX, mouseY);
    }

    if(myPattern){
        myField.setPattern();
    }
    myField.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255);
    myField.draw();

    ofSetColor(0, 255, 255);
    for( int i=0; i<particleList.size(); i++ ){
        particleList[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom( 20.0 );
    }else if( key == '2' ){
        myField.setPerlin();
    }

    if( key == '3' ){
        myRotate = true;
    }else{
        myRotate = false;
    }

    if( key == '4' ){
        myPattern = true;
    }else{
        myPattern = false;
    }

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){


    if( button == OF_MOUSE_BUTTON_1 ){
//        myField.addRepelForce(x, y, 100, 2.0);
        myField.addCircularForce(x, y, 300, 2.0);
    }else{
        myField.addAttractForce(x, y, 100, 2.0);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    mouseDragged(x, y, button);
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
