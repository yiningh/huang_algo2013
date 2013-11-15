#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 60 );
    img.loadImage("03.jpg");
    pix = img.getPixelsRef();
    dist = 10.0f;
    ofEnableDepthTest();
    cam.setDistance(1000);
    cam.setGlobalPosition(500,500,1000);
    ofEnableLighting();
    ofSetSmoothLighting(true);
    light.setPosition(500,500,500);
    ofSetGlobalAmbientColor(100);

    //cam.setTarget(ofVec3f(500,1000,1200));
    //ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
        light.enable();
        cam.begin();
            //cam.getTarget();
                for(int y=0; y<pix.getHeight(); y++)
                {
                    for(int x=0; x<pix.getWidth(); x++)
                    {
                        ofColor c = pix.getColor(x, y);
                        if(c.a > 0)
                        {
                            float b = c.getBrightness();
                            float z = ofMap(b, 0, 255, -100, 100);
                            ofSetColor(c);
                            ofPushMatrix();
                            ofRotateX(0);
                            ofSphere(x*dist, y*dist, z*dist*0.5, 15);
                            ofPopMatrix();
                        }
                    }
                }
        cam.end();
        light.disable();
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
