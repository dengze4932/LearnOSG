#include <osgDB/ReadFile>
#include <osgViewer/CompositeViewer>
#include <osgViewer/Viewer>
#include <osg/Vec4f>
#include <osg/StateSet>
int main()
{
    osg::ref_ptr<osg::StateSet> pStateSet = new osg::StateSet();

    osg::ref_ptr<osgViewer::CompositeViewer>  cViewer = new osgViewer::CompositeViewer();
    osgViewer::Viewer* viewer = new osgViewer::Viewer();
    osgViewer::Viewer* viewer2 = new osgViewer::Viewer();
    viewer->setSceneData( osgDB::readNodeFile("cow.osgt"));
    viewer->getCamera()->setClearColor(osg::Vec4f(1, 1, 1, 0.2));
    viewer2->getCamera()->setClearColor(osg::Vec4f(1, 1, 0,0.8));
   
    //pStateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
    viewer->setUpViewOnSingleScreen();
    cViewer->addView(viewer2);
    cViewer->addView(viewer);
    
    return cViewer->run();
}