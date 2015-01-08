#include "AppDelegate.h"
#include "SetupScene.h"
#include "Adapt.hpp"
#include "InternalSettings.hpp"

extern "C"
{
#include "CustomDataTypes.h"
};

USING_NS_CC;


AppDelegate::AppDelegate() 
{
	InternalSettings::Instance()->IS_vSetInitialSettingValue();
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
	
	adaptConfiguration.vReadAvailableLanguages(InternalSettings::Instance()->IS_sGetPathsName().c_str());
	/* Check if configuration file exist */
	if (FileUtils::getInstance()->isFileExist(InternalSettings::Instance()->IS_sGetConfigurationFileName()))
	{
		/* Read and check if the configuration file */
		int a = 3;		
	}
	else
	{
		/* create the configuration file */
		if (false == adaptConfiguration.boCreateDefaultXMLFile(InternalSettings::Instance()->IS_sGetConfigurationFileName().c_str()))
		{
			InternalSettings::Instance()->IS_vSetProjectError(true);
		}
		/* Set Setup type */
		InternalSettings::Instance()->IS_vSetSetupType(TAR_enCleanSetup);
	}
    if(!glview) {
		glview = GLViewImpl::create((InternalSettings::Instance()->IS_vGetSetupType() == TAR_enCleanSetup || InternalSettings::Instance()->IS_vGetSetupType() == TAR_enNoSettup) ?
			InternalSettings::Instance()->IS_sGetDefaultAppName() : InternalSettings::Instance()->IS_sGetDefaultAppName());
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
