#include "particle.h"

void Particle::init( ofVec3f thatVel ){
    vel = thatVel;
    lifeSpan = ofRandom( 50, 150 );
    age = 0;
    pos = ofVec3f(0,0,0);//ofGetWindowSize()/2;
    bIsDead = false;
}

void Particle::update(){
    float noise = ofNoise( pos.x*0.005, pos.y*0.005, pos.z*0.005 ) * 15.0;
    float agePct = 1- ( (float)age / (float)lifeSpan);
    pos += ofVec3f( cos(noise), sin(noise), atan(noise) ) * ( 1.0-agePct );
    pos += vel;
    vel *= 0.97;
    age++;

    if( age > lifeSpan ){
        bIsDead = true;
    }
}

void Particle::draw(){
    if( bIsDead ){
        return;
    }
    float agePct = 1.0 - ( (float)age / (float)lifeSpan );
    float dist = sqrt(pos.x*pos.x + pos.y*pos.y);
    int alpha = ofMap( dist, 0, 400, 255, 50 );
    //cout<<dist<<endl;
    ofColor ballColor = ofColor( 155, 207, 255, alpha);
    float darkness = ofMap( dist, 0, 1000, 250, 0);
    ballColor.setSaturation(darkness);
    ofSetColor(ballColor);
    ofSphere(pos, 20.0* (agePct));
}

