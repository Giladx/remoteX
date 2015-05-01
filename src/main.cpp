#include "ofMain.h"
#include "testApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1050, 545, OF_WINDOW);		// <-------- setup the GL context
    ofSetWindowPosition(0 ,0);
    ofSetWindowTitle("RemoteX by Gil@d.x");
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new testApp());

}
