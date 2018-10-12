#include "Particles.h"



Particles::Particles()
{
}


Particles::~Particles()
{
}


void Particles::init() {
	posp.set(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));

	float velMin = 0.00001;
	float velMax = 0.00006;
	float randomVel = ofRandom(velMin, velMax);
	vel.set(randomVel, randomVel);
	activated = false;

	brightness = 50;
}
void Particles::updateParticles(ofPoint(_attractor)) {
	dist = ofDist(posp.x, posp.y, _attractor.x, _attractor.y);

	if (dist < 1000) {
		activated = true;
	}

	if (activated) {
		pct += vel;
		//(1-pct)*currentPos + pct*dest
		posp = (ofPoint(1, 1) - pct)*posp + pct * _attractor;

		//if (brightness < 253) {
			//brightness += 2;
		//}
	}

}

void Particles::drawParticles() {
	ofSetColor(ofRandom(175, 255), ofRandom(0, 255), ofRandom(75, 255), 98);
	ofDrawCircle(posp, 2);

}

