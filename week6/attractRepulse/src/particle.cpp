
#include "particle.h"

Particle::Particle(){
    damping = ofRandom( 0.95, 0.85); //0.95;
    thisColor = ofColor(ofRandom(150,230), 50);
    thisAngle = ofRandom(1, 360);
    thisAngleInc = ofRandom(-1, 1);

}

void Particle::addForce( ofVec2f force ){
    acc += force;
}

void Particle::update(){
    vel += acc;
    pos += vel;
    vel *= damping;
    acc.set(0);
    thisAngle += thisAngleInc;
}

void Particle::draw(){
    ofSetColor(thisColor);
    ofSetLineWidth(0.5);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(pos-pos/4);
    ofScale(pSize*0.05, pSize*0.05);
    //ofRectMode(CENTER);
    ofRotate(thisAngle);
        ofBezier(9,6,16,13,29,11,34,5);
        ofBezier(34,5,39,0,34,-3,29,3);
        ofBezier(29,3,24,9,24,17,41,16);
        ofBezier(41,16,58,15,43,26,33,24);
        ofBezier(33,24,17,21,-12,37,12,38);
        ofBezier(12,38,38,39,29,29,12,20);
        ofBezier(12,20,-4,11,-3,-4,9,6);
        //ofCircle(pos, pSize);
    ofPopMatrix();
}

void Particle::addRepulsionForce(float px, float py, float radius, float strength){
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    ofVec2f diff = pos - posOfForce;

    if( diff.length() < radius ){
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
    }
}

void Particle::addAttractionForce(float px, float py, float radius, float strength){
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    ofVec2f diff = pos - posOfForce;
    pSize = (ofMap(diff.length(), 0, 1280, 300, 0));

    if( diff.length() < radius ){
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
    }
}
