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
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Background = Sprite::create(
#ifdef _DEBUG
		"./Data/Pix/Win32/Background.png"
#else
		"../Data/Pix/Win32/Background.png"	
#endif
		);
	Background->setAnchorPoint(Vec2(0, 0));
	Background->setPosition(Vec2(origin.x, origin.y));
	// add the sprite as a child to this layer
	this->addChild(Background, 0);
	
	NextButton = CCMenuItemImage::create(
#ifdef _DEBUG
		"./Data/Pix/Win32/Button-Next.png",
		"./Data/Pix/Win32/Button-Next.png",
#else
		"../Data/Pix/Win32/Button-Next.png",
		"../Data/Pix/Win32/Button-Next.png",
#endif
		CC_CALLBACK_1(SetupScene::menuNextCallback, this));
	NextButton->setAnchorPoint(Vec2(0, 0));
	NextButton->setPosition(Vec2(visibleSize.width - visibleSize.width / 4 - NextButton->getContentSize().width / 2,
		origin.y + visibleSize.width / 2 + NextButton->getContentSize().height / 2));
	//closeItem->setScale(0.2f)

	// create menu, it's an autorelease object
	auto menu = Menu::create(NextButton, NULL);
	menu->setAnchorPoint(Vec2(0, 0));
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

#if 0
	// add the sprite as a child to this layer
	this->addChild(background, 6);
	auto footer = Sprite::create("Footer.png");
	Size footerSize = footer->getContentSize();
	footer->setPosition(Vec2(visibleSize.width / 2 + origin.x, origin.y + footerSize.height/2 ));

	// add the sprite as a child to this layer
	this->addChild(footer, 7);

	auto imagine = Sprite::create("iulia.jpg");
    imagine->setPosition(Vec2(visibleSize.width / 2 + origin.x , visibleSize.height / 2 + origin.y));
	this->addChild(imagine, 3);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	//closeItem->setScale(0.2f)

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
#endif
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