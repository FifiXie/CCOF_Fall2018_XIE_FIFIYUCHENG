#pragma once

#include"ofMain.h"

class Person
{
public:
	Person();
	~Person();

	void setup();
	void update();
	void draw();

	void applyForce(ofPoint f);
	void steeringWithArriveForce(ofPoint target);

	ofPoint loc;
	ofPoint vel;
	ofPoint acc;
	float maxSpeed;
	float maxForce;

	ofImage p1;
	ofImage p2;
};

