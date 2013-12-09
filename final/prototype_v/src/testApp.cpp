#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate( 60 );
	ofBackground(20);
	ofDisableArbTex();
	ofEnableAlphaBlending();

    glShadeModel(GL_SMOOTH);
	quadric = gluNewQuadric();
    gluQuadricTexture(quadric, GL_TRUE);
    gluQuadricNormals(quadric, GLU_SMOOTH);

	vidGrabber.initGrabber(640, 480, true);
	flowSolver.setup(320, 240, 0.5, 3, 10, 1, 7, 1.5, false, true );

	//---light
    ofSetSmoothLighting(true);
    pointLight.setAmbientColor( ofFloatColor(.1, .08, .07) );
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    pointLight2.setDiffuseColor( ofFloatColor( 180.f/255.f, 120.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.9f, .9f, .9f));
    pointLight.setPosition((ofGetWidth()*.7), ofGetHeight()/3, 500);
    pointLight2.setPosition( -ofGetWidth()*.4, ofGetHeight(), 500);

    //---material
    material.setShininess( 100 );
	material.setSpecularColor(ofColor(255, 255, 255, 255));

    //---shader
    shader.load("shaders/displace.vert", "shaders/displace.frag");

    //---texture Images
    fbo.allocate( 640, 480 );
    texFbo.allocate( 640, 480 );
    img.allocate( 640, 480, OF_IMAGE_COLOR_ALPHA );
    smallVidImg.allocate( 30, 40, OF_IMAGE_COLOR_ALPHA );
    texImg.allocate( 640, 480, OF_IMAGE_COLOR_ALPHA );

    //---texImg.loadImage("bg.jpg");
    perlinImg.loadImage("perlin5.png");
    yPos = -480;

    //---OSC
    mSender.setup( "localhost", 55688 );
}
//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.update();
    if(vidGrabber.isFrameNew()){
        flowSolver.update(vidGrabber);
    }
    yPos += 10;
    if( yPos > 0 ){
        yPos = -480;
    }
}
//--------------------------------------------------------------
void testApp::draw(){
    ofSetWindowTitle("FPS: " + ofToString(ofGetFrameRate()));



    //---bump map
    fbo.begin();
    ofClear( 255, 255, 255, 0 );
    ofBlendMode(OF_BLENDMODE_ADD);
    perlinImg.draw(0,yPos,640,960);
    flowSolver.draw(vidGrabber.getWidth(), vidGrabber.getHeight(), 10, 3, 1); //1 = circle, 0 = line, 3 = colored
    fbo.end();
    //fbo.draw(500,0);
    fbo.readToPixels(pix);
    img.setFromPixels(pix);
    img.draw(0,0);

    //---texture to be shown
    texFbo.begin();
    ofClear( 255, 255, 255, 0 );
    //pix = vidGrabber.getPixelsRef();
    //pix.resize(30,40,OF_INTERPOLATE_BICUBIC);
    //smallVidImg.setFromPixels(pix);
    //smallVidImg.draw(500,0);
    vidGrabber.draw(0,0);
    flowSolver.drawColored(vidGrabber.getWidth(), vidGrabber.getHeight(), 10, 3);
    texFbo.end();
    texFbo.readToPixels(pix);
    texImg.setFromPixels(pix);
    texImg.draw(0,0);
    flowSolver.drawColored(vidGrabber.getWidth(), vidGrabber.getHeight(), 10, 3);
    ofBackground(170);

    ofEnableDepthTest();
    ofEnableLighting();
    pointLight.enable();
    pointLight2.enable();

	material.begin();

	shader.begin();
	shader.setUniformTexture("colormap", texImg, 1);
    shader.setUniformTexture("bumpmap", img , 2);
    shader.setUniform1i("maxHeight",ofGetWindowHeight()*0.2);
    shader.setUniform3f("CAMERA_POSITION", 1000, -100,300);

    ofPushMatrix();{
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        //ofRotateY(360*sinf(float(ofGetFrameNum())/500.0f));
        ofRotate(-90,1,0,0);
        gluSphere(quadric, 150, 400, 200);
    }ofPopMatrix();
    shader.end();
    material.end();
    glDisable(GL_TEXTURE_2D);
    ofDisableLighting();
    ofDisableDepthTest();
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

