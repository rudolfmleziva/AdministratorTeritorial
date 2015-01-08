#include "SetupScene.h"
#include "InternalSettings.hpp"
#include <string>
#include "Adapt.hpp"

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
	NextButton->setPosition(m_Getposition(TAR_nenSetupNextButton));

	// create menu, it's an autorelease object
	menuNext = Menu::create(NextButton, NULL);
	menuNext->setAnchorPoint(Vec2::ZERO);
	menuNext->setPosition(Vec2::ZERO);
	this->addChild(menuNext, 1);

	PreviousButton = CCMenuItemImage::create(
		"./Data/Pix/Win32/Button-Previous.png",
		"./Data/Pix/Win32/Button-Previous.png",
		CC_CALLBACK_1(SetupScene::menuPreviousCallback, this));
	PreviousButton->setAnchorPoint(Vec2::ZERO);
	PreviousButton->setPosition(m_Getposition(TAR_nenSetupPreviousButton));
	PreviousButton->setEnabled(false);
	//PreviousButton->setVisible(false);

	// create menu, it's an autorelease object
	menuPrevious = Menu::create(PreviousButton, NULL);
	menuPrevious->setAnchorPoint(Vec2::ZERO);
	menuPrevious->setPosition(Vec2::ZERO);
	this->addChild(menuPrevious, 1);

	StepInactive[0] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[0]->setAnchorPoint(Vec2::ZERO);
	StepInactive[0]->setPosition(m_Getposition(TAR_nenInactiveSetupStep1));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[0], 1);

	StepInactive[1] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[1]->setAnchorPoint(Vec2::ZERO);
	StepInactive[1]->setPosition(m_Getposition(TAR_nenInactiveSetupStep2));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[1], 1);

	StepInactive[2] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[2]->setAnchorPoint(Vec2::ZERO);
	StepInactive[2]->setPosition(m_Getposition(TAR_nenInactiveSetupStep3));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[2], 1);

	StepInactive[3] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[3]->setAnchorPoint(Vec2::ZERO);
	StepInactive[3]->setPosition(m_Getposition(TAR_nenInactiveSetupStep4));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[3], 1);

	StepInactive[4] = Sprite::create("./Data/Pix/Win32/step-inactive.png");
	StepInactive[4]->setAnchorPoint(Vec2::ZERO);
	StepInactive[4]->setPosition(m_Getposition(TAR_nenInactiveSetupStep5));
	// add the sprite as a child to this layer
	this->addChild(StepInactive[4], 1);

	StepActive = Sprite::create("./Data/Pix/Win32/step-active.png");
	StepActive->setAnchorPoint(Vec2::ZERO);
	StepActive->setPosition(m_Getposition(TAR_nenInactiveSetupStep1));
	// add the sprite as a child to this layer
	this->addChild(StepActive, 2);

	LangDown = CCMenuItemImage::create(
		"./Data/Pix/Win32/LangDown.png",
		"./Data/Pix/Win32/LangDown.png",
		CC_CALLBACK_1(SetupScene::menuNextCallback, this));
	LangDown->setAnchorPoint(Vec2::ZERO);
	LangDown->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));

	// create menu, it's an autorelease object
	menuLangDown = Menu::create(LangDown, NULL);
	menuLangDown->setAnchorPoint(Vec2::ZERO);
	menuLangDown->setPosition(Vec2::ZERO);
	this->addChild(menuLangDown, 1);

	Adapt adapt;
	//LabelTTF* label = LabelTTF::create(adapt.wstring_to_utf8(InternalSettings::Instance()->IS_sGetLanguageName(1)), "./Data/Font/NotoSans-Regular.ttf", 42, CCSize(), kCCTextAlignmentLeft);
	Label* label = Label::createWithTTF(adapt.wstring_to_utf8(InternalSettings::Instance()->IS_sGetLanguageName(1)), "./Data/Font/NotoSans-Regular.ttf", 42, CCSize(240,240), TextHAlignment::CENTER, TextVAlignment::TOP);
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	//label->setAnchorPoint(Vec2(0, 0));
	label->enableOutline(Color4B::BLACK, 1);
	label->setOpacity(70);
	//label->e
	//label->enableStroke(Color3B::BLACK, 1.0f, true);
	this->addChild(label, 2);

    return true;
}

void SetupScene::menuNextCallback(Ref* pSender)
{
#if 0
	Adapt adapt;
	wstring content = L"șț";
	TTFConfig ttfConfig("./Data/Font/Simsun.ttf", 42, GlyphCollection::CUSTOM, adapt.UTF8TOGBK(content).c_str());
	/*adapt.UTF8TOGBK(InternalSettings::Instance()->IS_sGetLanguageName(1))*/
	auto label = Label::createWithTTF(ttfConfig, adapt.UTF8TOGBK(content));

	// position the label on the center of the screen
	label->setPosition(Vec2(50, label->getHeight()));
	//int a = label->getCommonLineHeight();
	label->setAnchorPoint(Vec2(0,0));
	//label->setTextColor(Color4B(0, 0, 0, 255));
	//label->enableOutline(Color4B(0, 0, 0, 255),1);
	//label->enableGlow(Color4B(0, 0, 0, 255)/*,1*/);
	label->enableOutline(Color4B(0, 0, 0, 255), 1);
	
	// add the label as a child to this layer
	this->addChild(label, 2);
#endif
}

void SetupScene::menuPreviousCallback(Ref* pSender)
{

	
}

Vec2 SetupScene::m_Getposition(TAR_tenResources enPosType)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 result = Vec2::ZERO;

	switch (enPosType)
	{
		case TAR_nenInactiveSetupStep1:
			result.x = visibleSize.width / 2 - StepInactive[0]->getContentSize().width * 3 - StepInactive[0]->getContentSize().width/2;
			result.y = NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[0]->getContentSize().height) / 2;
			break;
		case TAR_nenInactiveSetupStep2:
			result.x = visibleSize.width / 2 - StepInactive[1]->getContentSize().width * 2;
			result.y = NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[1]->getContentSize().height) / 2;
			break;
		case TAR_nenInactiveSetupStep3:
			result.x = visibleSize.width / 2 - StepInactive[2]->getContentSize().width / 2;
			result.y = NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[2]->getContentSize().height) / 2;
			break;
		case TAR_nenInactiveSetupStep4:
			result.x = visibleSize.width / 2 + StepInactive[3]->getContentSize().width;
			result.y = NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[3]->getContentSize().height) / 2;
			break;
		case TAR_nenInactiveSetupStep5:
			result.x = visibleSize.width / 2 + StepInactive[4]->getContentSize().width * 2 + StepInactive[4]->getContentSize().width/2;
			result.y = NextButton->getContentSize().height + (NextButton->getContentSize().height - StepInactive[4]->getContentSize().height) / 2;
			break;
		case TAR_nenSetupNextButton:
			result.x = visibleSize.width - visibleSize.width / 4 - NextButton->getContentSize().width / 2;
			result.y = NextButton->getContentSize().height;
			break;
		case TAR_nenSetupPreviousButton:
			result.x = visibleSize.width - (visibleSize.width - visibleSize.width / 4 - PreviousButton->getContentSize().width / 2) - PreviousButton->getContentSize().width;
			result.y = PreviousButton->getContentSize().height;
			break;
		default:
			/* nothing to do */
			break;
	}
	return result;
}