#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "PDBLoader.hpp"

#include <fstream>

using namespace ci;
using namespace ci::app;
using namespace std;

class cellVIEWinCinderApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
private:
    CameraPersp camera;
    Molecule * loadedMolecule;
    gl::VboRef vboPositions;
};

void cellVIEWinCinderApp::setup()
{
    string pathToFile = getAssetPath("2rcj.pdb").string();
    loadedMolecule = PDBLoader::loadFromFile(pathToFile.c_str());
    
    //positionsVBO = gl::Vbo::create(GL_ARRAY_BUFFER);
    vector<float> positions;
    for (auto mol : loadedMolecule->atoms)
    {
        positions.push_back(mol.position.x);
        positions.push_back(mol.position.y);
        positions.push_back(mol.position.z);
    }
    
    //vboPositions.create(GL_ARRAY_BUFFER, positions);
    vboPositions = gl::Vbo::create(GL_ARRAY_BUFFER, positions); // it should probably be used like this
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
    
    gl::setMatrices(this->camera);
    
    this->vboPositions->bind();
    //gl::drawElements(GL_POINTS, )
    gl::drawArrays(GL_POINTS, 0, this->loadedMolecule->atoms.size());
    
    gl::drawSphere(vec3(), 1, 20);
}

CINDER_APP( cellVIEWinCinderApp, RendererGl )
