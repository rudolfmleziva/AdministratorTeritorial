#include "SetupScene.h"


Scene* SetupScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = SetupScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SetupScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	SetupStep = 0;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Background = Sprite::create("./Data/Pix/Win32/Background.png");
	Background->setAnchorPoint(Vec2(0, 0));
	Background->setPosition(Vec2(origin.x, origin.y));
	// add the sprite as a child to this layer
	this->addChild(Background, 0);
	
	NextButton = CCMenuItemImage::create(
		"./Data/Pix/Win32/Button-Next.png",
		"./Data/Pix/Win32/Button-Next.png",
		CC_CALLBACK_1(SetupScene::menuNextCallback, this));
	NextButton->setAnchorPoint(Vec2::ZERO);
	NextButton->setPosition(Vec2(visibleSize.width - visibleSize.width / 4 - NextButton->getContentSize().width / 2,
		 NextButton->getContentSize().height));
	//closeItem->setScale(0.2f)

	// create menu, it's an autorelease object
	auto menu = Menu::create(NextButton, NULL);
	menu->setAnchorPoint(Vec2::ZERO);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	StepInactive[0] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[0]->setAnchorPoint(Vec2(0, 0));
	StepInactive[0]->setPosition(Vec2(visibleSize.width / 2 - StepInactive[0]->getContentSize().width * 2,
		NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[0]->getContentSize().height) / 2));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[0], 1);

	StepInactive[1] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[1]->setAnchorPoint(Vec2(0, 0));
	StepInactive[1]->setPosition(Vec2(visibleSize.width/2-StepInactive[1]->getContentSize().width/2,
		NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[0]->getContentSize().height)/2));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[1], 1);

	StepInactive[2] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[2]->setAnchorPoint(Vec2(0, 0));
	StepInactive[2]->setPosition(Vec2(visibleSize.width/2+StepInactive[2]->getContentSize().width,
		NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[0]->getContentSize().height)/2));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[2], 1);

	StepActive = Sprite::create("./Data/Pix/Win32/step-active.png");
	StepActive->setAnchorPoint(Vec2(0, 0));
	StepActive->setPosition(Vec2(visibleSize.width / 2 - StepInactive[0]->getContentSize().width * 2,
		NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[0]->getContentSize().height) / 2));
	// add the sprite as a child to this layer
	this->addChild(StepActive, 2);


    return true;
}

void SetupScene::menuNextCallback(Ref* pSender)
{

	auto label = Label::createWithTTF("Hello World\nThis is the thing", "./Data/Font/Simsun.ttf", 42);

	// position the label on the center of the screen
	label->setPosition(Vec2(50, label->getHeight()));
	int a = label->getCommonLineHeight();
	label->setAnchorPoint(Vec2(0,0));
	//label->setTextColor(Color4B(0, 0, 0, 255));
	//label->enableOutline(Color4B(0, 0, 0, 255),1);
	//label->enableGlow(Color4B(0, 0, 0, 255)/*,1*/);
	label->enableOutline(Color4B(0, 0, 0, 255), 1);
	
	// add the label as a child to this layer
	this->addChild(label, 2);
}
#if 0
void SetupScene::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
#endif