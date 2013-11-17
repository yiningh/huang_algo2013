
#include "controller.h"

void Controller::addFish(int num){
    for( int i = 0; i < num; i++){
        float phi = ofRandom( 0, TWO_PI );
		float costheta = ofRandom( -1.0f, 1.0f );

		float rho = sqrt( 1.0f - costheta * costheta );
		float x = rho * cos( phi );
		float y = rho * sin( phi );
		float z = costheta;

        ofVec3f randVec(x, y, z);

		ofVec3f pos = randVec * ofRandom( 100.0f, 600.0f );
		ofVec3f vel = -randVec;

		Fish fish(pos, vel);
        fishGrill.push_back(fish);
    }
}

void Controller::update(float effectZone, float pushAway, float goTogether){

    float zoneRadiusSq = effectZone * effectZone;

    for( vector<Fish>::iterator f1 = fishGrill.begin(); f1 != fishGrill.end(); ++f1){

        vector<Fish>::iterator f2 = f1 + 1;
        for( f2 ; f2 != fishGrill.end(); ++f2){

            ofVec2f direction = f1->pos - f2->pos;
            float distance = direction.lengthSquared();

            float pct = distance/zoneRadiusSq;
            if( pct == 0 ){
                pct = 0.0000001;
            }
            if( distance < zoneRadiusSq ){
                //too far -> attract
                if( pct < pushAway ){
                        float adjustedPct = 1.0 - ofMap(pct, 0.0, pushAway, 0.0, 1.0);
                        ofVec2f force = direction.normalized() * adjustedPct * 0.03;
                        f1->applyForce( force );
                        f2->applyForce( -force );
                }
                else if( pct < goTogether ){
                        float adjustedPct = 1.0 - ofMap(pct, pushAway, goTogether, 0.0, 1.0);
                        float F = adjustedPct * 0.005;

                        f1->applyForce( f2->vel.normalized() * F );
                        f2->applyForce( f1->vel.normalized() * F );
                }
                else{
                    float attractStr = ofMap(pct, goTogether, 1.0f, 0.0f, 1.0f) * 0.01f;
                    ofVec2f force = direction.normalized() * attractStr;
                    f1->applyForce(-force);
                    f2->applyForce(force);
                }
            }
        }
        f1->moveToCenter( ofVec3f(0,0,0) );
    }

    for(vector<Fish>::iterator fish = fishGrill.begin(); fish != fishGrill.end(); ++fish){
        fish->update();
    }
}

void Controller::draw(){
    for(vector<Fish>::iterator fish = fishGrill.begin(); fish != fishGrill.end(); ++fish){
        fish->draw();
    }
}
