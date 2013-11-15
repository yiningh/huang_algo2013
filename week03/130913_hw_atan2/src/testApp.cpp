#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    ofBackground(255);
    angle = 1;
    ofSetCircleResolution(100);


    bird1.pos = bird2.pos = bird3.pos = bird4.pos = bird5.pos = bird6.pos = bird7.pos = bird8.pos = bird9.pos = ofPoint( ofGetWindowWidth()/2 - 75, ofGetWindowHeight() * 0.5 );
    //bird2.pos = ofPoint( ofGetWindowWidth()/2 + 75, ofGetWindowHeight() * 0.5 );
}

//--------------------------------------------------------------
void testApp::update(){
    angle += 0.002;

    bird1.pos.x = 500 + cos( angle * 3.7 )*300 ;
    bird1.pos.y = 300 + sin( angle * 4.5 )*300 ;

    bird2.pos.x = 600 + cos( angle * 1.4 )*200 ;
    bird2.pos.y = 200 +sin( angle * 3.6 )*200 ;

    bird3.pos.x = 200 + cos( angle * 4.2 )*300 ;
    bird3.pos.y = 400 + sin( angle * 2.2 )*300 ;

    bird4.pos.x = 700 + cos( angle * 4.8 )*100 ;
    bird4.pos.y = 500 +sin( angle * 2.3 )*20 ;

    bird5.pos.x = 800 + cos( angle * 1.9 )*50 ;
    bird5.pos.y = 300 + sin( angle * 0.3 )*100 ;

    bird6.pos.x = 900 + cos( angle * 3.2 )*400 ;
    bird6.pos.y = 600 +sin( angle * 8.2 )*200 ;

    bird7.pos.x = 400 + cos( angle * 1.3 )*200 ;
    bird7.pos.y = 800 + sin( angle * 4.5 )*100 ;

    bird8.pos.x = 300 + cos( angle * 1.4 )*100 ;
    bird8.pos.y = 900 +sin( angle * 3.6 )*100 ;

    bird9.pos.x = 200 + cos( angle * 1.4 )*200 ;
    bird9.pos.y = 100 +sin( angle * 3.6 )*200 ;

    ofPoint mousePos( mouseX, mouseY );

    bird1.mousePos = mousePos;
    bird2.mousePos = mousePos;
    bird3.mousePos = mousePos;
    bird4.mousePos = mousePos;
    bird5.mousePos = mousePos;
    bird6.mousePos = mousePos;
    bird7.mousePos = mousePos;
    bird8.mousePos = mousePos;
    bird9.mousePos = mousePos;
}

//--------------------------------------------------------------
void testApp::draw(){

    bird1.draw();
    bird2.draw();
    bird3.draw();
    bird4.draw();
    bird5.draw();
    bird6.draw();
    bird7.draw();
    bird8.draw();
    bird9.draw();

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
