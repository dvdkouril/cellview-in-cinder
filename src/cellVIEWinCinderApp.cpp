#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class cellVIEWinCinderApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void cellVIEWinCinderApp::setup()
{
}

void cellVIEWinCinderApp::mouseDown( MouseEvent event )
{
}

void cellVIEWinCinderApp::update()
{
}

void cellVIEWinCinderApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( cellVIEWinCinderApp, RendererGl )