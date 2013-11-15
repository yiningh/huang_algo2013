#include "particle.h"

Particle::Particle(){
    damping = ofRandom(0.95, 0.85);
    circWidth = 50.0;
    circHeight = 50.0;
}

void Particle::addForce( ofVec2f force ){
    acc += force;
}

void Particle::update(){
    vel += acc;
    pos += vel;
    vel *= damping;
    circHeight = ofClamp(circHeight, 25.0, 55.0);
    circWidth = ofClamp(circWidth, 25.0, 55.0);

    if( pos.x < 25 && vel.x < 0 ){
        circWidth *= ofMap(acc.length(), 0, 1, 1, 0.89);
        circHeight *= ofMap(acc.length(), 0, 1, 1, 1.05);
        if( pos.x < 10 ){
            vel.x *= -1;
        }
    }else if( pos.x < 25 && vel.x > 0 ){
        circWidth += ofMap(acc.length(), 0, 1, 1.5, 1.9);
        circHeight -= ofMap(acc.length(), 0, 1, 1.2, 1.6);
        if(circWidth > 50.0){circWidth = 50.0;};
        if(circHeight < 50.0){circHeight = 50.0;};
    }

    if( pos.x > ofGetWindowWidth() - 25 && vel.x > 0 ){
        circWidth *= ofMap(acc.length(), 0, 1, 1, 0.89);
        circHeight *= ofMap(acc.length(), 0, 1, 1, 1.05);
        if( pos.x > ofGetWindowWidth() - 10 ){
            vel.x *= -1;
        }
    }else if( pos.x > ofGetWindowWidth() - 25 && vel.x < 0 ){
        circWidth += ofMap(acc.length(), 0, 1, 1.5, 1.9);
        circHeight -= ofMap(acc.length(), 0, 1, 1.2, 1.6);
        if(circWidth > 50.0){circWidth = 50.0;};
        if(circHeight < 50.0){circHeight = 50.0;};
    }

    if( pos.y < 25 && vel.y < 0 ){
        circHeight *= ofMap(acc.length(), 0, 1, 1, 0.89);
        circWidth *= ofMap(acc.length(), 0, 1, 1, 1.05);
        if( pos.y < 10 ){
            vel.y *= -1;
        }
    }else if( pos.y < 25 && vel.y > 0 ){
        circHeight += ofMap(acc.length(), 0, 1, 1.5, 1.9);
        circWidth -= ofMap(acc.length(), 0, 1, 1.2, 1.6);
        if(circHeight > 50.0){circHeight = 50.0;};
        if(circWidth < 50.0){circWidth = 50.0;};
    }

    if( pos.y > ofGetWindowHeight() - 25 && vel.y > 0 ){
        circHeight *= ofMap(acc.length(), 0, 1, 1, 0.89);
        circWidth *= ofMap(acc.length(), 0, 1, 1, 1.05);
        if( pos.y > ofGetWindowHeight() - 10 ){
            vel.y *= -1;
        }
    }else if( pos.y > ofGetWindowHeight() - 25 && vel.y < 0 ){
        circHeight += ofMap(acc.length(), 0, 1, 1.5, 1.9);
        circWidth -= ofMap(acc.length(), 0, 1, 1.2, 1.6);
        if(circHeight > 50.0){circHeight = 50.0;};
        if(circWidth < 50.0){circWidth = 50.0;};
    }

    circWidth++;
    circHeight++;
    if(circHeight > 50.0){circHeight = 50.0;};
    if(circWidth > 50.0){circWidth = 50.0;};


    acc.set(0);
}

void Particle::draw(){
    ofSetColor(205,164,65);
    ofEllipse(pos, circWidth, circHeight);
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

    if( diff.length() < radius ){
        float pct = 1 - ( diff.length() / radius );
        diff.normalize();
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
    }
}
