#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (float x = 0.25; x < 1; x += 0.25) {

		for (float y = 0.33; y < 1; y += 0.33) {

			this->draw_three(glm::vec2(ofGetWidth() * x, ofGetHeight() * y), 5000, 23);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_three(glm::vec2 location, int number_of_loop, float scale) {

	ofPushMatrix();
	ofTranslate(location);
	
	glm::vec2 point, prev_point;
	for (int i = 0; i < number_of_loop; i++) {

		float p = ofRandom(100);
		if (p < 1) {

			point.x = 0 * prev_point.x + 0 * prev_point.y + 0;
			point.y = 0 * prev_point.x + 0.16 * prev_point.y + 0;
		}
		else if (p < 8) {

			point.x = 0.2 * prev_point.x + -0.26 * prev_point.y + 0.0;
			point.y = 0.23 * prev_point.x + 0.22 * prev_point.y + 1.6;
		}
		else if (p < 15) {

			point.x = -0.15 * prev_point.x + 0.28 * prev_point.y + 0.0;
			point.y = 0.26 * prev_point.x + 0.24 * prev_point.y + 0.44;
		}
		else {

			point.x = 0.85 * prev_point.x + 0.04 * prev_point.y + 0.0;
			point.y = -0.04 * prev_point.x + 0.85 * prev_point.y + 1.5;
		}

		ofDrawCircle(point * -scale, ofMap(ofNoise(location.x + point.x * 0.3, location.y + point.y * 0.3, ofGetFrameNum() * 0.03), 0, 1, 0.1, 2));
		prev_point = point;
	}

	ofPopMatrix();
}


//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}