#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	
	serial.setup(0, 9600);
	serial.listDevices();
	if (serial.isInitialized()) {
		cout << "yes" << endl;

	}
	else {
		cout << "no" << endl;
	}

	//char data = serial.readByte();
	//cout << data << endl;

	/*ofSerial mySerial;
	if (mySerial.setup()) {
		printf("serial is setup!"); 
	}*/

	//serial.setup();

	/*if (serial.setup()) {
		
		int data = serial.readByte();
		cout << data << endl;
	}*/

	//cout << arduino.isArduinoReady() << endl;

}

//--------------------------------------------------------------
void ofApp::update() {
	//int data = serial.readByte();
	//if (counter % 30 == 0) {
	//	cout << data << endl;
	//}

	//counter++;
	/*if (serial.setup()) {
		cout << "WORRRRRK" << endl;
	}*/
}

//--------------------------------------------------------------
void ofApp::draw() {

	//char data = serial.readByte();
	//cout << data << endl;	

	//int data = serial.readByte();
	//if (counter % 20 == 0) {
	//	cout << data << endl;
	//}

	//counter++;

	
	
	int result = serial.readBytes(&bytes[0],4);
	
	string results(bytes);
	int data = ofToInt(results);
	
	cout << data <<endl;
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
