#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ofBackground(50, 100, 50, 255);
	//ofEnableSmoothing();
    ofSetCircleResolution(60);

    sender.setup(HOST, PORT);

    bgImage.loadImage("image/bg.png");

    video_color_r = 10; video_color_g = 10; video_color_b = 10; video_color_a = 10;
    drawPadding = false;

    //gui0->loadSettings("gui1Settings.xml");

//--GUI0--------------------------------------------------------

    gui0 = new ofxUISuperCanvas("Input");
//    gui0->setScrollAreaToScreen();
    gui0->setPosition(0, 50);
//    gui0->setMinified(true);
//    gui0->setScrollableDirections(false, true);
//    gui0->setDimensions(150, ofGetHeight());
    gui0->addSpacer();
    gui0->addLabel("Video");
    gui0->addSpacer();
    gui0->addButton("rdp", false);
    gui0->addFPSSlider("fps");
    gui0->addToggle( "v on/off", false);
    gui0->addButton( "v load", false);

    gui0->addMinimalSlider("v x scale", 0.1, 10.0, 1.0);
    gui0->addMinimalSlider("v y scale", 0.1, 10.0, 1.0);
    gui0->addToggle("v fit", false);
    gui0->addToggle("v keep aspect", false);

    gui0->addToggle("v hflip", false );
    gui0->addToggle("v vflip", false );

    gui0->addMinimalSlider("v red", 0.0, 1.0, &video_color_r);
    gui0->addMinimalSlider("v green", 0.0, 1.0, &video_color_g);
    gui0->addMinimalSlider("v blue", 0.0, 1.0, &video_color_b);
    gui0->addMinimalSlider("v alpha", 0.0, 1.0, &video_color_a);

//--GUI0 Example code----------------------------------------------


    gui0->addMinimalSlider("speed", -2.0, 4.0, 1.0);
    gui0->addToggle( "v loop", true);
    gui0->addToggle( "v greenscreen", false);
    gui0->addSpacer();
    gui0->addLabel("Audio");
    gui0->addSpacer();
	gui0->addMinimalSlider("audio", 0.0, 1.0, 1 &video_volume);
    gui0->addSpacer();

    gui0->autoSizeToFitWidgets();

    //gui0->getRect()->setWidth(ofGetWidth());
    ofAddListener(gui0->newGUIEvent,this,&testApp::guiEvent);

//--GUI1--------------------------------------------------------

    gui1 = new ofxUISuperCanvas("Draw");
//    gui1->setDimensions(150, ofGetHeight());
//    gui1->setScrollAreaToScreen();
    gui1->setPosition(210, 50);
//    gui1->setScrollableDirections(false, true);

    gui1->addSpacer();
    gui1->addLabel("Image");
    gui1->addSpacer();
    gui1->addToggle( "i on/off", false);
    gui1->addToggle( "i load", false);
    gui1->addMinimalSlider("i scale x", 0.1, 10.0, 1);
    gui1->addMinimalSlider("i scale y", 0.1, 10.0, 1);
    gui1->addToggle( "i fit", false);
    gui1->addToggle( "i aspect ratio", false);

    gui1->addToggle( "i hflip", false);
    gui1->addToggle( "i vflip", false);
    gui1->addToggle( "i greenscreen", false);
    gui1->addMinimalSlider("i red", 0.0, 1.0, 1.0);
    gui1->addMinimalSlider("i green", 0.0, 1.0, 1.0);
    gui1->addMinimalSlider("i blue", 0.0, 1.0, 1.0);
    gui1->addMinimalSlider("i alpha", 0.0, 1.0, 1.0);

    gui1->addSpacer();


    gui1->autoSizeToFitWidgets();

//    gui1->getRect()->setWidth(ofGetWidth());
    ofAddListener(gui1->newGUIEvent,this,&testApp::guiEvent);


//--GUI2--------------------------------------------------------

    gui2 = new ofxUISuperCanvas("Global");
//    gui2->setScrollAreaToScreen();
//    gui2->setScrollableDirections(false, true);
    gui2->setPosition(840, 50);
//    gui2->setDimensions(150, ofGetHeight());
    gui2->addSpacer();
    gui2->addLabel("Live Projection");
    gui2->addSpacer();
    gui2->addToggle("live stop/start", false);
    gui2->addToggle("live resync", false);
    gui2->addToggle("live fc on/off", false);
    gui2->addToggle("display gui", true);
//    gui2->addToggle("modesetup on/off", false);
    gui2->addToggle("mpe", false);

    gui2->addSpacer();
    gui2->addLabel("Project");
    gui2->addSpacer();
    gui2->addButton("direct save", false);
    gui2->addButton("direct load", false);
    gui2->addButton("save file", false);
    gui2->addButton("load file", false);

    gui2->addSpacer();
    gui2->addLabel("Edge Blend");
    gui2->addSpacer();
    gui2->addToggle( "eb on/off", false);
    gui2->addMinimalSlider("power", 0.0, 4.0, 1.0);
    gui2->addMinimalSlider("gamma", 0.0, 4.0, 1.8);
    gui2->addMinimalSlider("luminance", -4.0, 4.0, 1.0);
    gui2->addMinimalSlider("left edge", 0.0, 0.5, 0.3);
    gui2->addMinimalSlider("right edge", 0.0, 0.5, 0.3);
    gui2->addMinimalSlider("top edge", 0.0, 0.5, 0.3);
    gui2->addMinimalSlider("bottom edge", 0.0, 0.5, 0.3);

    gui2->addSpacer();

    gui2->autoSizeToFitWidgets();

    //gui2->getRect()->setWidth(ofGetWidth());
    ofAddListener(gui2->newGUIEvent,this,&testApp::guiEvent);



//--GUI3--------------------------------------------------------

    gui3 = new ofxUISuperCanvas("Quad");
//    gui3->setDimensions(150, ofGetHeight());
//    gui3->setScrollAreaToScreen();
    gui3->setPosition(630, 50);
//    gui3->setScrollableDirections(false, true);

    gui3->addSpacer();
    gui3->addLabel("Surface");
    gui3->addSpacer();
    gui3->addToggle( "show/hide", true);
    gui3->addToggle( "use timeline", true);
    gui3->addMinimalSlider("seconds", 10, 3600, 100);
    gui3->addToggle( "tl tint", false);
    gui3->addToggle( "tl color", false);
    gui3->addToggle( "tl alpha", false);
    gui3->addToggle( "tl 4 slides", false);

    float dim = (gui3->getGlobalCanvasWidth() - gui3->getPadding()*7.0)*0.5;

    gui3->addSpacer();
    gui3->addLabel("Blending modes");
    gui3->addSpacer();
    gui3->addToggle( "bm on/off", false);

    vector<string> items;
    items.push_back("screen");
    items.push_back("add");
    items.push_back("subtract");
    items.push_back("multiply");

    gui3->addDropDownList("blending mode", items, dim);
    gui3->addLabel("");
    gui3->addLabel("");
    gui3->addLabel("");
    gui3->addLabel("");

    gui3->addSpacer();
    gui3->addLabel("Mask");
    gui3->addSpacer();
    gui3->addToggle("m on/off", false);
    gui3->addToggle("m invert", false);
    gui3->addToggle("mask edit on/off", false);
    gui3->addSpacer();



    gui3->autoSizeToFitWidgets();

    //gui3->getRect()->setWidth(ofGetWidth());
    ofAddListener(gui3->newGUIEvent,this,&testApp::guiEvent);


//----GUI4--------------------------------------------------------

    gui4 = new ofxUISuperCanvas("Capture & CV");
//    gui4->setScrollAreaToScreen();
//    gui4->setScrollableDirections(false, true);
    gui4->setPosition(420, 50);
    //gui4->setDimensions(150, ofGetHeight());
    gui4->addSpacer();
    gui4->addLabel("Camera");
    gui4->addSpacer();
    gui4->addToggle( "c on/off", false);
    gui4->addToggle("c load", false);
    gui4->addMinimalSlider("c scale x", 0.1, 10.0, 1);
    gui4->addMinimalSlider("c scale y", 0.1, 10.0, 1);
    gui4->addToggle( "c fit", false);
    gui4->addToggle( "c aspect ratio", false);
    gui4->addToggle( "c hflip", false);
    gui4->addToggle( "c vflip", false);
    gui4->addMinimalSlider("c red", 0.0, 1.0, 1.0);
    gui4->addMinimalSlider("c green", 0.0, 1.0, 1.0);
    gui4->addMinimalSlider("c blue", 0.0, 1.0, 1.0);
    gui4->addMinimalSlider("c alpha", 0.0, 1.0, 1.0);
    gui4->addToggle( "c greenscreen", false);

    gui4->addSpacer();
    gui4->addLabel("Greenscreen");
    gui4->addSpacer();
	gui4->addMinimalSlider("threshold", 0.0, 255.0, 10.0);

    gui4->addMinimalSlider("gs red", 0.0, 1.0, 0.0);
    gui4->addMinimalSlider("gs green", 0.0, 1.0, 0.0);
    gui4->addMinimalSlider("gs blue", 0.0, 1.0, 0.0);
    gui4->addMinimalSlider("gs alpha", 0.0, 1.0, 0.0);

    gui4->addSpacer();



    gui4->autoSizeToFitWidgets();

    //gui4->getRect()->setWidth(ofGetWidth());

    ofAddListener(gui4->newGUIEvent,this,&testApp::guiEvent);


//----GUI5------------------------------------------------------
    gui5 = new ofxUISuperCanvas("Active Surface");
    gui5->setDimensions(750, 50);
    gui5->setPosition(0, 0);

    gui5->addMinimalSlider("Number", 0.0, 72.0, 3.0 , 350 , 20);
    gui5->addSpacer();


    gui5->autoSizeToFitWidgets();

    //gui5->getRect()->setWidth(ofGetWidth());

    ofAddListener(gui5->newGUIEvent,this,&testApp::guiEvent);

//----GUI6------------------------------------------------------

    gui6 = new ofxUISuperCanvas("OpenCV");
    gui6->setPosition(420, 50);
//    gui6->setDimensions(150, ofGetHeight());
    gui6->setVisible(false);
    gui6->addSpacer();
    gui6->addLabel("Kinect");
    gui6->addSpacer();
    gui6->addToggle("k on/off", false);
    gui6->addToggle("k close/open", false);
    gui6->addToggle("k show img", false);
    gui6->addToggle("k grayscale", false);
    gui6->addToggle("k mask", false);
    gui6->addToggle("k detect", false);
    gui6->addMinimalSlider("k scale x", 0.1, 10.0, 1.0);
    gui6->addMinimalSlider("k scale y", 0.1, 10.0, 1.0);
    gui6->addMinimalSlider("k red", 0.0, 1.0, 1.0);
    gui6->addMinimalSlider("k green", 0.0, 1.0, 1.0);
    gui6->addMinimalSlider("k blue", 0.0, 1.0, 1.0);
    gui6->addMinimalSlider("k alpha", 0.0, 1.0, 1.0);
    gui6->addMinimalSlider("k threshold near", 0.0, 255.0, 255.0);
    gui6->addMinimalSlider("k threshold far", 0.0, 255.0, 0.0);
    gui6->addMinimalSlider("k angle", -30.0, 30.0, 0.0);
    gui6->addMinimalSlider("k blur", 0.0, 10.0,  3.0);
    gui6->addMinimalSlider("k min blob", 0.01, 1.0, 0.01);
    gui6->addMinimalSlider("k max blob", 0.01, 1.0, 1.0);
    gui6->addMinimalSlider("k smooth", 0.0, 20.0, 10.0);
    gui6->addMinimalSlider("k simplify", 0.0, 2.0, 0.0);
    gui6->addSpacer();

    gui6->autoSizeToFitWidgets();

    ofAddListener(gui6->newGUIEvent,this,&testApp::guiEvent);

//----GUI7------------------------------------------------------

    gui7 = new ofxUISuperCanvas("Image");
    gui7->setPosition(210, 50);
//    gui7->setDimensions(150, ofGetHeight());
    gui7->setVisible(false);
    gui7->addSpacer();
    gui7->addLabel("Slideshow");
    gui7->addSpacer();
    gui7->addToggle("sh on/off", false);
    gui7->addToggle("sh load", false);
    gui7->addMinimalSlider("sh duration", 0.1, 15.0, 1.0);
    gui7->addToggle("sh fit", false);
    gui7->addToggle("sh aspect ratio", false);

    gui7->addSpacer();
    gui7->addLabel("Solid Color");
    gui7->addSpacer();
    gui7->addToggle( "sc on/off", false);
    gui7->addMinimalSlider("sc red", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("sc green", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("sc blue", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("sc alpha", 0.0, 1.0, 0.0);

    gui7->addSpacer();
    gui7->addLabel("Transition");
    gui7->addSpacer();
    gui7->addToggle("tr on/off",false);
    gui7->addMinimalSlider("tr red", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("tr green", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("tr blue", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("tr alpha", 0.0, 1.0, 0.0);
    gui7->addMinimalSlider("tr duration", 0.1, 60.0, 1.0);
    gui7->addSpacer();




    gui7->autoSizeToFitWidgets();

    ofAddListener(gui7->newGUIEvent,this,&testApp::guiEvent);

//----GUI8------------------------------------------------------
    gui8 = new ofxUISuperCanvas("Surface");
//    gui8->setDimensions(150, ofGetHeight());
//    gui3->setScrollAreaToScreen();
    gui8->setPosition(630, 50);
    gui8->setVisible(false);


    gui8->addSpacer();
    gui8->addLabel("rectangular crop");
    gui8->addSpacer();
    gui8->addMinimalSlider("top", 0.0, 1.0, 0.0 );
    gui8->addMinimalSlider("right", 0.0, 1.0, 0.0 );
    gui8->addMinimalSlider("left", 0.0, 1.0, 0.0 );
    gui8->addMinimalSlider("bottom", 0.0, 1.0, 0.0 );

    gui8->addSpacer();
    gui8->addLabel("circular crop");
    gui8->addSpacer();
    gui8->addMinimalSlider("x", 0.0, 1.0, 0.5 );
    gui8->addMinimalSlider("y", 0.0, 1.0, 0.5 );
    gui8->addMinimalSlider("radius", 0.0, 2.0, 0.0 );


    gui8->addSpacer();
    gui8->addLabel("Deform");
    gui8->addSpacer();
    gui8->addToggle("d on/off", false);
    gui8->addToggle("bezier", false);
    gui8->addButton("spherize light", false);
    gui8->addButton("spherize strong", false);
    gui8->addButton("bezier reset", false);
    gui8->addToggle("grid", false);
    gui8->addMinimalSlider("rows num", 2, 15, 5 );
    gui8->addMinimalSlider("columns num", 2, 20, 5 );
    gui8->addToggle("edit", false);
    gui8->addSpacer();

    gui8->autoSizeToFitWidgets();

    ofAddListener(gui8->newGUIEvent,this,&testApp::guiEvent);

//----GUI9------------------------------------------------------

    gui9 = new ofxUISuperCanvas("Surface");
//    gui9->setDimensions(150, ofGetHeight());
//    gui3->setScrollAreaToScreen();
    gui9->setPosition(840, 50);
    gui9->setVisible(false);

    gui9->addSpacer();
    gui9->addLabel("Placement");
    gui9->addSpacer();
    gui9->addMinimalSlider("move x", -1600.0, 1600.0, 0.0);
    gui9->addMinimalSlider("move y", -1600.0, 1600.0, 0.0);
    gui9->addMinimalSlider("width", 0.0, 2400.0, 1280.0);
    gui9->addMinimalSlider("height", 0.0, 2400.0, 1024.0);
    gui9->addButton( "reset", false);
    gui9->addSpacer();

    gui9->autoSizeToFitWidgets();


    ofAddListener(gui9->newGUIEvent,this,&testApp::guiEvent);





   // guiTabBar->loadSettings("settings/", "ui-");

}

//--------------------------------------------------------------
void testApp::update()
{

}

//--------------------------------------------------------------
void testApp::draw()
{

   // bgImage.draw(0,0);

/*    ofBackground(red, green, blue, 255);
*/
}
//--------------------------------------------------------------
void testApp::guiEvent(ofxUIEventArgs &e)
{
/*    string name = e.widget->getName();
	int kind = e.widget->getKind();
    string canvasParent = e.widget->getCanvasParent()->getName();
    cout << canvasParent << endl;
*/
    cout << e.widget->getName() << endl;
    if(e.widget->getName() == "BACKGROUND VALUE")
    {
        ofxUISlider *slider = (ofxUISlider *) e.widget;
        ofBackground(slider->getScaledValue());
    }
    else if(e.widget->getName() == "FULLSCREEN")
    {
        ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
        ofSetFullscreen(toggle->getValue());
    }

    string name = e.getName();
    int kind = e.getKind();

    //video

    if(name == "v on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "v load")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/load");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "rdp")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    cmd = "remmina";

    //ofxOscMessage m;
    //m.setAddress("/active/video/load");
    //m.addIntArg(button->getValue());
    //sender.sendMessage(m);
    }
    if(name == "v x scale")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/mult/x");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "v y scale")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/mult/y");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "v fit")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/fit");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "v keep aspect")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/keepaspect");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "v hflip")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/hmirror");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "v vflip")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/vmirror");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "v red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "v green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "v blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "v alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "audio")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/volume");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "speed")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/speed");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "v loop")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/loop");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "v greenscreen")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/video/greenscreen");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }

        //greenscreen

    if(name == "threshold")
    {
    ofxUICircleSlider *csliderValue = (ofxUICircleSlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/greenscreen/threshold");
    m.addFloatArg(csliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "gs red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/greenscreen/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "gs green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/greenscreen/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "gs blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/greenscreen/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "gs alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/greenscreen/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }

    //Kinect
    if(name == "k on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/show");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "k close/open")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/close");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "k show img")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/show/image");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "k grayscale")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/show/grayscale");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "k mask")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/mask");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "k detect")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/contour");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "k scale x")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/mult/x");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k scale y")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/mult/y");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k threshold near")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/threshold/near");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k threshold far")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/threshold/far");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k angle")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/angle");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k blur")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/blur");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k smooth")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/contour/smooth");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k simplify")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/contour/simplify");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k min blob")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/contour/area/min");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k max blob")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/contour/area/max");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "k alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/kinect/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }




    //slideshow
    if(name == "sh on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/slideshow/show");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "sh load")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/slideshow/folder");
    m.addIntArg( 0 );
    //m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }

    if(name == "sh fit")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/slideshow/fit");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "sh duration")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/slideshow/duration");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
/*    if(name == "show/hide")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/show");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
*/
    //timeline

    if(name == "use timeline")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/timeline/toggle");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "seconds")
    {
    ofxUIMinimalSlider *sliderValue = (ofxUIMinimalSlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/timeline/duration");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "tl tint")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/timeline/tint");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "tl color")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/timeline/color");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "tl alpha")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/timeline/alpha");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "tl 4 slides")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/timeline/slides");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }

    //camera

    if(name == "c on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "c load")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "c scale x")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/mult/x");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "c scale y")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/mult/y");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "c fit")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/fit");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "c aspect ratio")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/keepaspect");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "c hflip")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/hmirror");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "c vflip")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/vmirror");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "c red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "c green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "c blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "c alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "audio")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/volume");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "c greenscreen")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/cam/greenscreen");
    m.addFloatArg(toggle->getValue());
    sender.sendMessage(m);
    }
    //image

    if(name == "i on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i load")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/load");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i fit")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/fit");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i aspect ratio")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/keepaspect");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i scale x")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/mult/x");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "i scale y")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/mult/y");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "i hflip")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/hmirror");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i vflip")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/vmirror");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i greenscreen")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/greenscreen");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "i red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "i green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "i blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "i alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/img/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }

    //placement
    if(name == "move x")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/placement/x");
    m.addIntArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
     if(name == "move y")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/placement/y");
    m.addIntArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "width")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/placement/w");
    m.addIntArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "height")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/placement/h");
    m.addIntArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "reset")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/placement/reset");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }

    //edge blend

    if(name == "eb on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
     if(name == "power")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/power");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "gamma")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/gamma");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "luminance")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/luminance");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "left edge")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/amount/left");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "right edge")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/amount/right");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "top edge")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/amount/top");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "bottom edge")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/edgeblend/amount/bottom");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }

     //blend modes

     if(name == "bm on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/blendmodes/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
     if(name == "screen")
    {
    ofxUIDropDownList *ddl = (ofxUIDropDownList *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/blendmodes/mode");
    m.addIntArg(0);
    //m.addIntArg(1);
    //m.addIntArg(3);
    //m.addIntArg(4);
    m.addIntArg(ddl->getValue());
    sender.sendMessage(m);
    }
    if(name == "add")
    {
    ofxUIDropDownList *ddl = (ofxUIDropDownList *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/blendmodes/mode");
    m.addIntArg(1);
    //m.addIntArg(1);
    //m.addIntArg(3);
    //m.addIntArg(4);
    m.addIntArg(ddl->getValue());
    sender.sendMessage(m);
    }
    if(name == "subtract")
    {
    ofxUIDropDownList *ddl = (ofxUIDropDownList *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/blendmodes/mode");
    m.addIntArg(2);
    //m.addIntArg(1);
    //m.addIntArg(3);
    //m.addIntArg(4);
    m.addIntArg(ddl->getValue());
    sender.sendMessage(m);
    }
    if(name == "multiply")
    {
    ofxUIDropDownList *ddl = (ofxUIDropDownList *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/blendmodes/mode");
    m.addIntArg(3);
    //m.addIntArg(1);
    //m.addIntArg(3);
    //m.addIntArg(4);
    m.addIntArg(ddl->getValue());
    sender.sendMessage(m);
    }

    //solid color

    if(name == "sc on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "sc red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "sc green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "sc blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "sc alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }

    //Projection

    if(name == "live resync")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/resync");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "live stop/start")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/stop");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "direct save")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/save");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "direct load")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/load");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "load file")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/loadfile");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "save file")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/savefile");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "live fc on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/fullscreen/toggle");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "display gui")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/gui/toggle");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }

/*    if(name == "modesetup on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/mode/setup/toggle");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
*/
    //mask

    if(name == "m on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/mask/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "m invert")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/mask/invert");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "mask edit on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/projection/mode/masksetup/toggle");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }

    //Deform
    if(name == "d on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "bezier")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/bezier");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "spherize light")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/bezier/spherize/light");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "spherize strong")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/bezier/spherize/strong");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "bezier reset")
    {
    ofxUIButton *button = (ofxUIButton *) e.getButton();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/bezier/reset");
    m.addIntArg(button->getValue());
    sender.sendMessage(m);
    }
    if(name == "grid")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/grid");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "rows num")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/grid/rows");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "columns num")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/grid/columns");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "edit")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/deform/edit");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }

    //crop

    if(name == "top")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/rectangular/top");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "right")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/rectangular/right");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "left")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/rectangular/left");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "bottom")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/rectangular/bottom");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "x")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/circular/x");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "y")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/circular/y");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "radius")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/crop/circular/radius");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    //active surface
    if(name == "Number")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/set");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    //transition
    if(name == "tr on/off")
    {
    ofxUIToggle *toggle = (ofxUIToggle *) e.getToggle();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/trans/show");
    m.addIntArg(toggle->getValue());
    sender.sendMessage(m);
    }
    if(name == "tr red")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/trans/color/1");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "tr green")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/trans/color/2");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "tr blue")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/trans/color/3");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "tr alpha")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/trans/color/4");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }
    if(name == "tr duration")
    {
    ofxUISlider *sliderValue = (ofxUISlider *) e.getSlider();
    cout << "got event from: " << name << endl;
    ofxOscMessage m;
    m.setAddress("/active/solid/trans/duration");
    m.addFloatArg(sliderValue->getValue());
    sender.sendMessage(m);
    }

}
//[--------------------------------------------------------------
void testApp::exit()
{
//    delete gui0;
//    delete gui1;
}
//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    switch (key)
    {
    case 'b':
        {
        ofxOscMessage m;
        m.setAddress("/active/deform/edit");
        sender.sendMessage(m);
        }
           break;

    case 'p':
        {
            drawPadding = !drawPadding;
            gui0->setDrawWidgetPadding(drawPadding);
            gui1->setDrawWidgetPadding(drawPadding);
            gui2->setDrawWidgetPadding(drawPadding);
            gui3->setDrawWidgetPadding(drawPadding);
            gui4->setDrawWidgetPadding(drawPadding);
            gui5->setDrawWidgetPadding(drawPadding);
            gui6->setDrawWidgetPadding(drawPadding);
            gui7->setDrawWidgetPadding(drawPadding);
            gui8->setDrawWidgetPadding(drawPadding);
            gui9->setDrawWidgetPadding(drawPadding);

        }
            break;

        case 'g':
        {
            gui0->toggleVisible();
            gui1->toggleVisible();
            gui2->toggleVisible();
            gui3->toggleVisible();
            gui4->toggleVisible();
            gui5->toggleVisible();
            gui6->toggleVisible();
            gui7->toggleVisible();
            gui8->toggleVisible();
            gui9->toggleVisible();


        }
            break;

        case 't':
        {
            gui4->toggleVisible();
            gui6->toggleVisible();
            gui1->toggleVisible();
            gui7->toggleVisible();
            gui3->toggleVisible();
            gui8->toggleVisible();
            gui2->toggleVisible();
            gui9->toggleVisible();
        }

             break;
        case 's':
            {
            gui0->saveSettings("gui0Settings.xml");
            gui1->saveSettings("gui1Settings.xml");
            gui2->saveSettings("gui2Settings.xml");
            gui3->saveSettings("gui3Settings.xml");
            gui4->saveSettings("gui4Settings.xml");
            gui5->saveSettings("gui5Settings.xml");
            gui6->saveSettings("gui6Settings.xml");
            gui7->saveSettings("gui7Settings.xml");
            gui8->saveSettings("gui8Settings.xml");
            gui9->saveSettings("gui9Settings.xml");
            }
        case 'l':
            {
                gui0->loadSettings("gui0Settings.xml");
                gui1->loadSettings("gui1Settings.xml");
                gui2->loadSettings("gui2Settings.xml");
                gui3->loadSettings("gui3Settings.xml");
                gui4->loadSettings("gui4Settings.xml");
                gui5->loadSettings("gui5Settings.xml");
                gui6->loadSettings("gui6Settings.xml");
                gui7->loadSettings("gui7Settings.xml");
                gui8->loadSettings("gui8Settings.xml");
                gui9->loadSettings("gui9Settings.xml");
            }
              break;
        case '1':
            {
                gui0->setMinified(true);
                gui1->setMinified(true);
                gui2->setMinified(true);
                gui3->setMinified(true);
                gui4->setMinified(true);
//                gui5->setMinified(true);
                gui6->setMinified(true);
                gui7->setMinified(true);
                gui8->setMinified(true);
                gui9->setMinified(true);
            }
                  break;

            case '2':
            {
                gui0->setMinified(false);
                gui1->setMinified(false);
                gui2->setMinified(false);
                gui3->setMinified(false);
                gui4->setMinified(false);
//                gui5->setMinified(false);
                gui6->setMinified(false);
                gui7->setMinified(false);
                gui8->setMinified(false);
                gui9->setMinified(false);
            }
                  break;
        default:
            break;
    }
/*     // toggles fullscreen mode
    if(key == 'f')

        bFullscreen = !bFullscreen;

        if(!bFullscreen)
        {
            ofSetFullscreen(false);
        }
        else if(bFullscreen == 1)
        {
            ofSetFullscreen(true);
        }
*/
}
//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{
/*
    gui0->getRect()->setHeight(y);
*/
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{


}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
