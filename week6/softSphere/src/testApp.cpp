#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(50);
    ofBackground(255);
    ofEnableAlphaBlending();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);

    points.assign(10000,ofPoint());
    points2.assign(10000,ofPoint());
    angle.assign(10000, float());
    radius.assign(10000, float());
    myColor.assign(10000, ofColor());

    for (int i=0; i<points.size(); i++) {
        ofPoint &p = points[i];
        float &a = angle[i];
        float &r = radius[i];

        p.x = i*ofRandomf();
        p.y = i*ofRandomf();
        p.z = i*ofRandomf();

        p /= sqrt(p.x*p.x+p.y*p.y+p.z*p.z);

        p *= 100;
        a = ofRandom(0,PI);
        r = ofRandom(5,10);
        myColor[i] = ofColor(100 + ofRandom(100, -50), 180);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<points.size(); i++) {
        ofPoint &p = points[i];
        ofPoint &p2 = points2[i];
        angle[i] +=  0.06;
        p2.x = p.x/10 + cos(angle[i])*radius[i];
        p2.y = p.y/10 + sin(angle[i])*radius[i];
        p2.z = p.z/10 + atan(angle[i])*radius[i];
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //center
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);

    ofRotateY(rotX += (mouseX-rotX) * .1);
    ofRotateX(rotY += (mouseY-rotY) * .1);
    ofSetColor(180);
    ofSphere(0, 0, 0, 100);

    for (int i=0; i<points.size(); i++) {
        ofPoint &p = points[i];
        ofPoint &p2 = points2[i];
        ofPushMatrix();
        ofTranslate(p.x, p.y, p.z);
        ofSetColor(myColor[i]);
        ofSetLineWidth(1.5);
        ofLine(0,0,0, p2.x, p2.y, p2.z);
        ofPopMatrix();
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
