#include "Crowds.h"



Crowds::Crowds()
{
}


Crowds::~Crowds()
{
}


void Crowds::setup() {
	c1.load("images/c1.png");
	c2.load("images/c2.png");
	c3.load("images/c3.png");

	pos.set(ofRandom(ofGetWindowWidth()), ofRandom(ofGetWindowHeight()));

	float velMin = 0.0009;
	float velMax = 0.0018;
	float randomVel = ofRandom(velMin, velMax);
	vel.set(randomVel, randomVel);
	activated = false;

	brightness = 0;
}
void Crowds::update(ofPoint(_attractor)) {
	dist = ofDist(pos.x, pos.y, _attractor.x, _attractor.y);

	if (dist < 90) {
		activated = true;
	}

	if (activated) {
		pct += vel;
		pos = (ofPoint(1, 1) - pct)*pos + pct * _attractor;

		if (brightness < 253) {
		brightness += 2;
		}
	}


}

void Crowds::draw() {
	ofSetColor(225, 225, 225, brightness);
	c1.draw(pos);
	c2.draw(ofRandom(pos.x - 50, pos.x - 47), ofRandom(pos.y - 48, pos.y - 45));
	c3.draw(ofRandom(pos.x + 22, pos.x + 24.5), ofRandom(pos.y + 22, pos.y + 24.5));
	c1.draw(ofRandom(pos.x + 30, pos.x + 33), ofRandom(pos.y - 38, pos.y - 41));
	c2.draw(ofRandom(pos.x - 10, pos.x - 13), ofRandom(pos.y + 4, pos.y + 7));
	c3.draw(ofRandom(pos.x - 31, pos.x - 31.5), ofRandom(pos.y - 38, pos.y - 38.5));
	ofSetColor(225, 225, 225, 225);
	c2.draw(ofRandom(pos.x + 10, pos.x + 13), ofRandom(pos.y - 4, pos.y - 7));

}

