#include "Person.h"



Person::Person()
{
}


Person::~Person()
{
}


void Person::setup()
{
	loc.set(10, 10);
	vel.set(0, 0);
	acc.set(0, 0);
	maxSpeed = 9;
	maxForce = 0.5;

	p1.load("images/p1.png");


}

void Person::update()
{
	vel += acc;
	loc += vel;
	acc *= 0; 

}

void Person::draw()
{

	//ofFill();
	//ofPushMatrix();
	//ofTranslate(ofGetWindowWidth(), ofGetWindowHeight());
	//ofRotate(30);
	//p1.draw(loc);
	//ofPopMatrix();

	p1.draw(loc);

}

void Person::applyForce(ofPoint f)
{
	acc += f;
}


void Person::steeringWithArriveForce(ofPoint target)
{
	ofPoint desiredVel = target - loc;

	desiredVel *= maxSpeed;


	float dist = desiredVel.length();
	desiredVel.normalize();

	if (dist < 100) {
		float m = ofMap(dist, 0, 100, 0, maxSpeed);
		desiredVel *= m;
	}
	else {
		desiredVel *= maxSpeed;
	}

	ofPoint steer;
	steer = desiredVel - vel;
	steer.limit(maxForce);

	applyForce(steer);
}
