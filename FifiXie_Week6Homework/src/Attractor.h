#pragma once
#include"ofMain.h"
class Attractor
{
public:
	Attractor();
	~Attractor();

	void setup(ofPoint _pos, float _radius, float _angle, float _vel);
	void update(float _updatedRadius);
	void draw();

	ofPoint pos;
	float radius;
	float angle;
	float vel;

};

