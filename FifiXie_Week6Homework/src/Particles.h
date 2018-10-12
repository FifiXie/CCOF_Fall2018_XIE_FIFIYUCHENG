#pragma once

#include "ofMain.h"
class Particles
{
public:
	Particles();
	~Particles();

	void init();
	void updateParticles(ofPoint(_pos));
	//void updateParticles();
	void drawParticles();

	ofPoint posp;
	ofPoint vel;
	ofPoint pct;

	int groupId;

	float dist;
	bool activated;
	float brightness;
};