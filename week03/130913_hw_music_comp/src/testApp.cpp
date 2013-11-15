#include "testApp.h"

void Lines( float xPos ){
    ofRect( xPos, 0, ofRandom( 20, 30 ), 1000 );
}

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate( 200 );
    ofEnableAlphaBlending();

    for( int i = 0; i < NUM_SQ; i++){
        ofVec2f tempPos;
        tempPos.x = i * ( ofGetWindowWidth() + 80 ) / NUM_SQ;
        pos.push_back( tempPos );
    }

    for( int i = 0; i < NUM_LINE; i++ ){
        linePos[i].x = i * ofRandom( 2, 13 );
    }

    ofVec2f temp;
    circlePos.push_back(temp);

    angle = 0;
    turn = 0;

    ofSeedRandom();

    vel.x = ofRandom( 3, 2 );
    vel.y = 0;
    tempCircVal.x = 0;
    tempCircVal.y = ofRandom( 0, ofGetWindowHeight() );

    timeOne = ofGetElapsedTimef();

    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    for( int i = 0; i < NUM_SQ; i++){
        pos[i].x ++;
        if( pos[i].x > ofGetWindowWidth() + 40){
            pos[i].x = -40;
        }
    }

    for( int i = 0; i < NUM_LINE; i++ ){
        linePos[i].x += 2;
        if( linePos[i].x > ofGetWindowWidth() ){
            linePos[i].x = -100;
        }
    }

    timeTwo = ofGetElapsedTimef();

    if( timeTwo - timeOne >= 3 && timeTwo - timeOne < 6 ){
        turn = 1;
    }

    if( timeTwo - timeOne >= 6 && timeTwo - timeOne < 9 ){
        turn = 2;
    }

    if( timeTwo - timeOne >= 9 ){
        turn = 0;
        tempCircVal.y += ofRandom( 100, -100 );
        vel.x = ofRandom( 1, 0 );
        vel.y = 0;
        timeOne = ofGetElapsedTimef();
    }

    /*
    ===================
    motion statements
    ===================
    */
    if ( turn == 0 ){
        tempCircVal += vel;
        circlePos.push_back( tempCircVal );

        if(tempCircVal.x >= ofGetWindowWidth() + 3){
            tempCircVal.x = 0;
        }
    }

    if ( turn == 1  ){
        angle += 0.01;
        ofVec2f tempVal;
        tempVal.x = circlePos[circlePos.size()].x + ( cos( angle )  );
        tempVal.y = circlePos[circlePos.size()].y +  ( sin( angle )  );
        circlePos.push_back( tempVal );
    }

    if( turn == 2 ){
        dirVal = circlePos[circlePos.size()] - circlePos[circlePos.size() - 2];
        ofVec2f tempValue2;
        tempValue2 = circlePos[circlePos.size()] + dirVal;
        circlePos.push_back( tempValue2 );
    }

    /*========== end of statement ==============*/

    if( circlePos.size() > 100 ){
            circlePos.erase( circlePos.begin() );
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,0,0, 255 * 0.04 );
    ofRect( 0, 0, ofGetWindowWidth(), ofGetWindowHeight() );
    ofSetColor( 0 );
    for( int i = 0; i < NUM_SQ; i ++){
        ofRect( pos[i].x ,  0 , 40, ofGetWindowHeight() );
    }


    ofSetColor( 150, 150, 150, 255 * 0.09 );
    for( int i = 0; i < NUM_LINE; i ++ ){
        Lines( linePos[i].x );
    }

    /*==first==*/
    ofSetColor(0, 0, 0, 255*0.08);
    for( int i = 0; i < circlePos.size(); i++ ){
        ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
        ofCircle( myPos, 2+ofRandom(-1, 1) );
    }

    ofPushMatrix();{
        ofTranslate( 10 , 6 );
        for( int i = 0; i < circlePos.size(); i++ ){
            ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
            ofCircle( myPos, 2+ofRandom(-1, 1) );
        }
        ofTranslate( ofRandom( 5, 2 ) , ofRandom( 1, 5 ) );
        //ofScale( 1.5, 1.5 );
        ofSetColor(0, 0, 0, 255* 0.04 );
        for( int i = 0; i < circlePos.size(); i++ ){
            ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
            ofCircle( myPos, 5+ofRandom(-1, 1) );
        }
    }ofPopMatrix();
    /*===end of first == */

    /*=====second=========*/
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth(), 0 );
        ofRotate( 90 );
        ofSetColor(0, 0, 0, 255*0.08);
        for( int i = 0; i < circlePos.size(); i++ ){
            ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
            ofCircle( myPos, 2+ofRandom(-1, 1) );
        }

        ofPushMatrix();{
            ofTranslate( 10 , 6 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 2+ofRandom(-1, 1) );
            }
            ofTranslate( ofRandom( 5, 2 ) , ofRandom( 1, 5 ) );
            //ofScale( 1.5, 1.5 );
            ofSetColor(0, 0, 0, 255* 0.04 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 5+ofRandom(-1, 1) );
            }
        }ofPopMatrix();
    }ofPopMatrix();
    /*=========end of second =========*/

    /*=====third========*/
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth()/2, 0 );
        ofRotate( 45 );
        ofSetColor(0, 0, 0, 255*0.08);
        for( int i = 0; i < circlePos.size(); i++ ){
            ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
            ofCircle( myPos, 2+ofRandom(-1, 1) );
        }

        ofPushMatrix();{
            ofTranslate( 10 , 6 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 2+ofRandom(-1, 1) );
            }
            ofTranslate( ofRandom( 5, 2 ) , ofRandom( 1, 5 ) );
            //ofScale( 1.5, 1.5 );
            ofSetColor(0, 0, 0, 255* 0.04 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 5+ofRandom(-1, 1) );
            }
        }ofPopMatrix();
    }ofPopMatrix();
    /*=========end of thrid =========*/

    /*===== forth ========*/
    ofPushMatrix();{
        ofTranslate(ofGetWindowWidth(), ofGetWindowHeight() );
        ofScale( -1, -1 );
        ofSetColor(0, 0, 0, 255*0.08);
        for( int i = 0; i < circlePos.size(); i++ ){
            ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
            ofCircle( myPos, 2+ofRandom(-1, 1) );
        }

        ofPushMatrix();{
            ofTranslate( 10 , 6 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 2+ofRandom(-1, 1) );
            }
            ofTranslate( ofRandom( 5, 2 ) , ofRandom( 1, 5 ) );
            //ofScale( 1.5, 1.5 );
            ofSetColor(0, 0, 0, 255* 0.02 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 2+ofRandom(-1, 1) );
            }
        }ofPopMatrix();
    }ofPopMatrix();

    /*===== fifth =========*/
    ofPushMatrix();{
        ofTranslate(0, ofGetWindowHeight() );
        ofScale(1, -1);
        ofSetColor( 0, 0, 0, 255 * 0.08 );
        for( int i = 0; i < circlePos.size(); i++ ){
            ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
            ofCircle( myPos, 2+ofRandom(-1, 1) );
        }

        ofPushMatrix();{
            ofTranslate( 10 , 6 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 2+ofRandom(-1, 1) );
            }
            ofTranslate( ofRandom( 5, 2 ) , ofRandom( 1, 5 ) );
            //ofScale( 1.5, 1.5 );
            ofSetColor(0, 0, 0, 255* 0.04 );
            for( int i = 0; i < circlePos.size(); i++ ){
                ofVec2f myPos = ( circlePos[i] + ofRandomf() ) ;
                ofCircle( myPos, 5+ofRandom(-1, 1) );
            }
        }ofPopMatrix();
    }ofPopMatrix();
    /*=========end of second =========*/


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
