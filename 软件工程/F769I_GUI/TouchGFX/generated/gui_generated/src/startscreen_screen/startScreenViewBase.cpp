/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/startscreen_screen/startScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

startScreenViewBase::startScreenViewBase() :
    buttonCallback(this, &startScreenViewBase::buttonCallbackHandler),
    frameCountInteraction1Interval(0)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    backGround.setPosition(0, 0, 800, 480);
    backGround.setColor(touchgfx::Color::getColorFromRGB(227, 234, 241));
    add(backGround);

    backPicture.setXY(0, 0);
    backPicture.setBitmap(touchgfx::Bitmap(BITMAP_MONITOR_ID));
    add(backPicture);

    tch_LOGO.setXY(138, 436);
    tch_LOGO.setBitmap(touchgfx::Bitmap(BITMAP_TCHGFX_LOGO_ID));
    add(tch_LOGO);

    tofGauge.setBackground(touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_GAUGE_TINY_BACKGROUNDS_ACTIVE_PRECISION_ID));
    tofGauge.setPosition(288, 308, 120, 120);
    tofGauge.setCenter(60, 60);
    tofGauge.setStartEndAngle(-90, 90);
    tofGauge.setRange(0, 100);
    tofGauge.setValue(100);
    tofGauge.setNeedle(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_GAUGE_TINY_NEEDLES_ROUGH_ID, 5, 33);
    tofGauge.setMovingNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    tofGauge.setSteadyNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    add(tofGauge);

    speedGauge.setBackground(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_GAUGE_SMALL_BACKGROUNDS_ACTIVE_ID));
    speedGauge.setPosition(125, 227, 184, 184);
    speedGauge.setCenter(92, 92);
    speedGauge.setStartEndAngle(-90, 90);
    speedGauge.setRange(0, 100);
    speedGauge.setValue(0);
    speedGauge.setNeedle(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_GAUGE_SMALL_NEEDLES_ROUGH_ID, 8, 53);
    speedGauge.setMovingNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    speedGauge.setSteadyNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    add(speedGauge);

    batGauge.setBackground(touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_GAUGE_TINY_BACKGROUNDS_ACTIVE_PRECISION_ID));
    batGauge.setPosition(26, 308, 120, 120);
    batGauge.setCenter(60, 60);
    batGauge.setStartEndAngle(-90, 90);
    batGauge.setRange(0, 100);
    batGauge.setValue(84);
    batGauge.setNeedle(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_GAUGE_TINY_NEEDLES_ROUGH_ID, 5, 33);
    batGauge.setMovingNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    batGauge.setSteadyNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    add(batGauge);

    tofGaugeText.setXY(322, 381);
    tofGaugeText.setColor(touchgfx::Color::getColorFromRGB(87, 87, 87));
    tofGaugeText.setLinespacing(0);
    tofGaugeText.setWildcard(touchgfx::TypedText(T___SINGLEUSE_B4XX).getText());
    tofGaugeText.resizeToCurrentText();
    tofGaugeText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Z579));
    add(tofGaugeText);

    speedGaugeText.setXY(173, 344);
    speedGaugeText.setColor(touchgfx::Color::getColorFromRGB(87, 87, 87));
    speedGaugeText.setLinespacing(0);
    Unicode::snprintf(speedGaugeTextBuffer, SPEEDGAUGETEXT_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_NHIM).getText());
    speedGaugeText.setWildcard(speedGaugeTextBuffer);
    speedGaugeText.resizeToCurrentText();
    speedGaugeText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SOPT));
    add(speedGaugeText);

    batGaugeText.setXY(51, 381);
    batGaugeText.setColor(touchgfx::Color::getColorFromRGB(87, 87, 87));
    batGaugeText.setLinespacing(0);
    batGaugeText.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SYUL));
    add(batGaugeText);

    design.setXY(174, 413);
    design.setColor(touchgfx::Color::getColorFromRGB(133, 133, 133));
    design.setLinespacing(0);
    design.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CDDU));
    add(design);

    stateNormal.setXY(110, 156);
    stateNormal.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    stateNormal.setLinespacing(0);
    stateNormal.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GKND));
    add(stateNormal);

    stateFree.setXY(73, 156);
    stateFree.setColor(touchgfx::Color::getColorFromRGB(199, 12, 12));
    stateFree.setLinespacing(0);
    stateFree.setTypedText(touchgfx::TypedText(T___SINGLEUSE_282G));
    add(stateFree);

    stateShake.setXY(85, 156);
    stateShake.setColor(touchgfx::Color::getColorFromRGB(199, 12, 12));
    stateShake.setLinespacing(0);
    stateShake.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PWYE));
    add(stateShake);

    stateBarrier.setXY(116, 156);
    stateBarrier.setColor(touchgfx::Color::getColorFromRGB(199, 12, 12));
    stateBarrier.setLinespacing(0);
    stateBarrier.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W0Q0));
    add(stateBarrier);

    start.setXY(40, 62);
    start.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    start.setLinespacing(0);
    start.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PET7));
    add(start);

    returnBut.setXY(0, 400);
    returnBut.setBitmaps(touchgfx::Bitmap(BITMAP_RETURN1_ID), touchgfx::Bitmap(BITMAP_RETURN2_ID));
    returnBut.setAction(buttonCallback);
    add(returnBut);
}

startScreenViewBase::~startScreenViewBase()
{

}

void startScreenViewBase::setupScreen()
{

}

void startScreenViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &returnBut)
    {
        //returnMain
        //When returnBut clicked change screen to mainScreen
        //Go to mainScreen with screen transition towards West
        application().gotomainScreenScreenCoverTransitionWest();
    }
}

void startScreenViewBase::handleTickEvent()
{
    frameCountInteraction1Interval++;
    if(frameCountInteraction1Interval == TICK_INTERACTION1_INTERVAL)
    {
        //Interaction1
        //When every N tick execute C++ code
        //Execute C++ code
        application().gotomainScreenScreenCoverTransitionWest();
        frameCountInteraction1Interval = 0;
    }
}
