#include "dots.h"

Dots::Dots()
{
    radius = 200.0f;
}

Dots::~Dots()
{
    //dtor
}

void Dots::update(){
    float tempAng = ofGetElapsedTimef()/20 ;
    angle.push_back( tempAng );
    if( angle.size() > 500 ){
        angle.erase( angle.begin() );
    }

    for(int i = 0; i < angle.size(); i++){
        ofVec2f tempPos;
        tempPos.x = radius * cos( TWO_PI * angle[i] * 3.4 );
        tempPos.y = radius * sin( TWO_PI * angle[i] * 4.7 );
        pos.push_back(tempPos);
        if( pos.size() > 500 ){
            pos.erase( pos.begin() );
        }
    }
}

void Dots::draw(){
    ofPushMatrix();{
        for( int i = 0; i < angle.size(); i++){
            ofCircle(pos[i], 8 );
        }
    }ofPopMatrix();
}
