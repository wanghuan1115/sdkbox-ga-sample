#include "HelloWorldScene.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "PluginGoogleAnalytics/PluginGoogleAnalytics.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    FileUtils::getInstance()->addSearchPath("res");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto rootNode = CSLoader::createNode("MainScene.csb");
    addChild(rootNode);
    
    auto btnEvent = rootNode->getChildByName<ui::Button*>("btnEvent");
    btnEvent->addClickEventListener(CC_CALLBACK_1(HelloWorld::onEvent, this));
    
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    
    return true;
}

void HelloWorld::onEvent(cocos2d::Ref* sender)
{
    sdkbox::PluginGoogleAnalytics::logEvent("Test", "Click", "", 1);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
