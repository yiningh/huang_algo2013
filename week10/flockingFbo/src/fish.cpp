
#include "fish.h"
Fish::Fish(){}
Fish::Fish(ofVec3f _pos, ofVec3f _vel ){
    pos = _pos;
    vel = _vel;
}

void Fish::applyForce( ofVec3f force ){
    acc += force;
}

void Fish::moveToCenter( ofVec3f center ){
     ofVec3f dir = pos - center;
     float distance = dir.length();

     if( distance > 300.0f ){
        dir.normalize();
        vel -= dir * (( distance - 300 ) * 0.0001f);
     }
}

void Fish::update(){
    vel += acc;
    vel.limit(3.0f); //don't go too fast
    if( vel.lengthSquared() < 1.0 ){
        vel = vel.normalized() * 1.0; //don't go too slow
    }
    pos += vel;
    vel *= 0.98f;

    acc.set(0);
}

void Fish::draw(){
    ofSetColor( 255 );
    ofSetLineWidth(5);
    ofSphere( pos, 0.5 );
    ofLine(pos, pos-vel*3 );

    ofSetLineWidth(4);
    ofLine( pos-vel*3, pos - vel*5 );

    ofSetLineWidth(3);
    ofLine( pos-vel*5, pos - vel*7 );

    ofSetLineWidth(2);
    ofLine( pos-vel*7, pos - vel*8 );

    ofSetLineWidth(1);
    ofLine( pos-vel*8, pos - vel*9 );


}
