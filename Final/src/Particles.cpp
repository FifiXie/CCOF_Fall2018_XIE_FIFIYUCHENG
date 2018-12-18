#include "Particles.h"



Particles::Particles()
{
}


Particles::~Particles()
{
}


void Particles::setup()
{
	p1.load("images/1.png");
	p2.load("images/2.png");
	p3.load("images/3.png");
	//serial.listDevices();
	//serial.setup("COM12", 9600);

	/*if (serial.setup()) {
		cout << "serial is setup!" << endl;
	}*/
	
}

void Particles::update()
{

	/*int byteData = serial.readByte();
	
	pos.set(byteData, byteData);*/
	pos.set(ofGetMouseX(),ofGetMouseY());
}

void Particles::draw()
{
	
	p1.draw(pos-10,20,20);
	p1.draw(pos - 5, 20, 20);
	p1.draw(pos + 5, 20, 20);
	p1.draw(pos + 10, 20, 20);
	p2.draw(ofRandom(pos.x - 35,pos.x+35), ofRandom(pos.y - 35, pos.y + 35),5,5);
	p3.draw(ofRandom(pos.x*-2,pos.x*2), ofRandom(pos.y*-2, pos.y * 2),7,7);

}