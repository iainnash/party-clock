#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("BauhausStd-Medium.otf", 100, true, true, true);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    
    ofSetBackgroundColorHex(0x6dd4c2);
    
    const float scale = 0.2;
    const int cutoff = 11;
    const string logoText = "Silver Dream Factory";
    
    int hours = ofGetHours();
    int adjustment = 0;
    if (hours < 5) {
        adjustment = 24;
        hours += 99;
    }
    int minutes = ofGetMinutes();
    int seconds = ofGetSeconds();
    int displayHours = hours;
    int displayMinutes = minutes;
    int displaySeconds = seconds;
    
    int fullSeconds = hours * minutes * 60 + (seconds % 60);
    
    if (hours > cutoff) {
        int cutoffSeconds = (60 * 60 * cutoff);
        int partialSeconds = fullSeconds - cutoffSeconds;
        int scaledSeconds = (int)partialSeconds * scale + cutoffSeconds;
        displayHours = (scaledSeconds / (60 * 60));
        displayMinutes = (scaledSeconds / 60) % 60;
        displaySeconds = scaledSeconds % 60;
    }
    
    string amPm = "am";
    if (displayHours - adjustment > 12) {
        displayHours -= 12;
        amPm = "pm";
    }
    if (adjustment) {
        displayHours -= adjustment;
    }
    
    std::stringstream iss;
    iss << displayHours << ":";
    iss << setfill('0') << setw(2) << displayMinutes;
    iss << ":";
    iss << setfill('0') << setw(2) << displaySeconds;
    iss << ' ' << amPm << endl;
    
    auto time = iss.str();
    
    //ofTranslate(, 0);
    ofPushMatrix();
    ofScale(0.75);
    ofSetHexColor(0x0057b7);
    auto scaleSize = font.getStringBoundingBox(logoText, 0, 0);
    int logoXOffset = -1 * scaleSize.width / 2;
    font.drawStringAsShapes(logoText, logoXOffset, scaleSize.height*1.4);
    ofPopMatrix();
    
    int timeXOffset = -1 * font.getStringBoundingBox(time, 0, 0).width / 2;
    ofSetHexColor(0xf8a3e6);
    font.drawStringAsShapes(time, timeXOffset, -1*scaleSize.height*1.4);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
