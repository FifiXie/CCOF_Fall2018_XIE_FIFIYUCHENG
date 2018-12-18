#pragma once
#include "ofMain.h"


class Particles
{
public:
	Particles();
	~Particles();


	void setup();
	void update();
	void draw();

	ofImage p1;
	ofImage p2;
	ofImage p3;

	ofPoint pos;
	//ofSerial serial;
};

