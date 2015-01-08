#ifndef __SETUP_SCENE_H__
#define __SETUP_SCENE_H__

#include "cocos2d.h"
#include "CustomDataTypes.h"


USING_NS_CC;

class SetupScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
	// a selector callback
    void menuNextCallback(cocos2d::Ref* pSender);

	// a selector callback
	void menuPreviousCallback(cocos2d::Ref* pSender);

	
    // implement the "static create()" method manually
	CREATE_FUNC(SetupScene);

private:
	/* curent setup step */
	int SetupStep;
	/* background image */
	Sprite * Background;
	/* next step button */
	MenuItemImage * NextButton;
	/* next step button */
	MenuItemImage * PreviousButton;

	/**/
	Menu * menuNext;
	Menu * menuPrevious;

	/* next step button */
	MenuItemImage * LangDown;
	Menu * menuLangDown;
	/* step inactive images */
	Sprite * StepInactive[NumberOfSettupSteps];
	/* step active images */
	Sprite * StepActive;

	MoveBy * MoveByAction[2];

	FadeTo * FadeToAction[3];


	/* Get position of the resources */
	Vec2 m_Getposition(TAR_tenResources enPosType);
};

#endif // __SETUP_SCENE_H__
