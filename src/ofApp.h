#ifndef OF APP
#define OF APP

#include "ofMain.h"
#include "ofxUI.h"
#include "ofxOsc.h"

#define HOST "localhost"
#define PORT 12345


class ofApp : public ofBaseApp
{
	public:

    void setup();
	void update();
	void draw();
	void exit();

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofImage bgImage;
/*    ofxUIScrollableCanvas *gui0;
    ofxUIScrollableCanvas *gui1;
    ofxUIScrollableCanvas *gui2;
    ofxUIScrollableCanvas *gui3;
    ofxUIScrollableCanvas *gui4;
    ofxUIScrollableCanvas *gui5;
    ofxUIScrollableCanvas *gui6;
    ofxUIScrollableCanvas *gui7;
    ofxUIScrollableCanvas *gui8;
    ofxUIScrollableCanvas *gui9;
    ofxUISuperCanvas *gui5;
*/

	ofxUISuperCanvas *gui0;
	ofxUISuperCanvas *gui1;
    ofxUISuperCanvas *gui2;
    ofxUISuperCanvas *gui3;
    ofxUISuperCanvas *gui4;
    ofxUISuperCanvas *gui5;
    ofxUISuperCanvas *gui6;
    ofxUISuperCanvas *gui7;
    ofxUISuperCanvas *gui8;
    ofxUISuperCanvas *gui9;
    ofxUISuperCanvas *gui10;
    ofxUISuperCanvas *gui11;

//    ofxUITabBar *guiTabBar;

	void guiEvent(ofxUIEventArgs &e);

    bool drawPadding;
    bool bFullscreen;

	float red, green, blue;
	float videox;
    float videoy;
    float video_color_r;
    float video_color_g;
    float video_color_b;
    float video_color_a;
    float video_speed;

    int video_volume;

    ofxOscSender sender;
    ofTrueTypeFont font;
    ofVideoGrabber vid;
};

#endif
