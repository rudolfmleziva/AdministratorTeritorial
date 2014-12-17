#include "AppDelegate.h"
#include "SetupScene.h"
#include "Adapt.hpp"

extern "C"
{
#include "InternalSettings.h"
#include "CustomDataTypes.h"
};

USING_NS_CC;

AppDelegate::AppDelegate() 
{
	IS_vSetInitialSettingValue();
}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
	Adapt adaptConfiguration;
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	
	/* Check if configuration file exist */
	if (FileUtils::getInstance()->isFileExist(std::string(IS_pchGetConfigurationFileName())))
	{
		/* Read and check if the configuration file */
		int a = 3;
	}
	else
	{
		/* create the configuration file */
		if (false == adaptConfiguration.boCreateDefaultXMLFile(IS_pchGetConfigurationFileName()))
		{
			IS_vSetProjectError(true);
		}
		/* Set Setup type */
		IS_vSetSetupType(TAR_enCleanSetup);
	}
    if(!glview) {
		glview = GLViewImpl::create((IS_vGetSetupType() == TAR_enCleanSetup) ? std::string(IS_pchGetDefaultAppName()) : std::string(IS_pchGetDefaultAppName()));
		glview->setFrameSize(960, 680);
        director->setOpenGLView(glview);
    }

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = SetupScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
