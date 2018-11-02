#pragma once

#include "ofMain.h"
class Crowds
{
public:
	Crowds();
	~Crowds();

	void setup();
	void update(ofPoint(_attractor));
	void draw();

	ofPoint pos;
	ofPoint vel;
	ofPoint pct;

	float dist;
	bool activated;
	float brightness;

	ofImage c1;
	ofImage c2;
	ofImage c3;
};

