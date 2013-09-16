#include "flower.h"

Flower::Flower()
{
    rotation = 60;
    radius = 50;
}

Flower::~Flower()
{
    //dtor
}

void Flower::update(){
    rotation += 0.1f;
    pos.x = radius * cos( 3.4 );
    pos.y = radius * sin( 4.7 );
}

void singleShape(){
    ofNoFill();
    ofSetColor(39, 240, 255, 255 * 0.4);
    ofBeginShape();
    ofVertex(62,-120);
    ofBezierVertex(45,-142,22,-113,43,-64);
    ofBezierVertex(57,-30,43,-14,38,-7);
    ofBezierVertex(33,0,15,10,0,6);
    ofBezierVertex(-13,3,-6,-10,8,-3);
    ofBezierVertex(51,19,60,-33,50,-53);
    ofBezierVertex(38,-79,36,-130,62,-120);
    ofEndShape();
}

void Flower::draw(){
    ofPushMatrix();{
    ofRotate(rotation);
    ofTranslate(pos);
    //singleShape();

        ofPushMatrix();{
            ofRotate(rotation);
            ofTranslate(pos);
            singleShape();

            ofPushMatrix();{
                ofTranslate(pos);
                ofRotate(rotation);
                singleShape();

                ofPushMatrix();{
                    ofTranslate(pos);
                    ofRotate(rotation);
                    singleShape();

                        ofPushMatrix();{
                            ofTranslate(pos);
                            ofRotate(rotation);
                            singleShape();

                            ofPushMatrix();{
                                ofTranslate(pos);
                                ofRotate(rotation);
                                singleShape();

                                ofPushMatrix();{
                                    ofTranslate(pos);
                                    ofRotate(rotation);
                                    singleShape();

                                    ofPushMatrix();{
                                        ofTranslate(pos);
                                        ofRotate(rotation);
                                        singleShape();

                                        ofPushMatrix();{
                                            ofTranslate(pos);
                                            ofRotate(rotation);
                                            singleShape();

                                            ofPushMatrix();{
                                                ofTranslate(pos);
                                                ofRotate(rotation);
                                                singleShape();

                                                ofPushMatrix();{
                                                    ofTranslate(pos);
                                                    ofRotate(rotation);
                                                    singleShape();

                                                       ofPushMatrix();{
                                                            ofTranslate(pos);
                                                            ofRotate(rotation);
                                                            singleShape();
                                                        }ofPopMatrix();

                                                }ofPopMatrix();

                                            }ofPopMatrix();

                                        }ofPopMatrix();


                                    }ofPopMatrix();

                                }ofPopMatrix();

                            }ofPopMatrix();

                        }ofPopMatrix();

                }ofPopMatrix();

            }ofPopMatrix();

        }ofPopMatrix();

    }ofPopMatrix();
}

