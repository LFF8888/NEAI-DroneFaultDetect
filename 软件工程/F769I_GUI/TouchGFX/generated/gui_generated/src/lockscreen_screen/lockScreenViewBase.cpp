/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/lockscreen_screen/lockScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>

lockScreenViewBase::lockScreenViewBase() :
    fadeGlassEndedCallback(this, &lockScreenViewBase::fadeGlassEndedCallbackHandler),
    showWaitEndedCallback(this, &lockScreenViewBase::showWaitEndedCallbackHandler),
    showGlassEndedCallback(this, &lockScreenViewBase::showGlassEndedCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    glassless.setXY(0, 0);
    glassless.setBitmap(touchgfx::Bitmap(BITMAP_GLASSLESS_ID));
    add(glassless);

    glass.setXY(0, 0);
    glass.setBitmap(touchgfx::Bitmap(BITMAP_GLASS_ID));
    add(glass);

    bigLock.setXY(279, 117);
    bigLock.setBitmap(touchgfx::Bitmap(BITMAP_LOCK_ID));
    add(bigLock);

    glasslessTop.setXY(0, 0);
    glasslessTop.setBitmap(touchgfx::Bitmap(BITMAP_GLASSLESS_ID));
    add(glasslessTop);

    waitAnimate.setXY(241, 333);
    waitAnimate.setBitmaps(BITMAP_WAIT1_ID, BITMAP_WAIT3_ID);
    waitAnimate.setUpdateTicksInterval(12);
    waitAnimate.startAnimation(false, true, true);
    waitAnimate.setAlpha(0);
    add(waitAnimate);

    unlockNote.setXY(143, 333);
    unlockNote.setBitmap(touchgfx::Bitmap(BITMAP_UNLOCKNOTE_ID));
    unlockNote.setAlpha(0);
    add(unlockNote);
}

lockScreenViewBase::~lockScreenViewBase()
{

}

void lockScreenViewBase::setupScreen()
{
    transitionBegins();
}

void lockScreenViewBase::handleKeyEvent(uint8_t key)
{
    if(48 == key)
    {
        //fadeGlass
        //When hardware button 48 clicked fade glass
        //Fade glass to alpha:0 with LinearIn easing in 500 ms (30 Ticks)
        glass.clearFadeAnimationEndedAction();
        glass.setFadeAnimationDelay(180);
        glass.startFadeAnimation(0, 30, touchgfx::EasingEquations::linearEaseIn);
        glass.setFadeAnimationEndedAction(fadeGlassEndedCallback);
    
    }

    if(48 == key)
    {
        //showWait
        //When hardware button 48 clicked fade waitAnimate
        //Fade waitAnimate to alpha:255 with LinearIn easing in 300 ms (18 Ticks)
        waitAnimate.clearFadeAnimationEndedAction();
        waitAnimate.startFadeAnimation(255, 18, touchgfx::EasingEquations::linearEaseIn);
        waitAnimate.setFadeAnimationEndedAction(showWaitEndedCallback);
    
    }

    if(48 == key)
    {
        //fadeUnlockNote
        //When hardware button 48 clicked fade unlockNote
        //Fade unlockNote to alpha:0 with LinearIn easing in 500 ms (30 Ticks)
        unlockNote.clearFadeAnimationEndedAction();
        unlockNote.startFadeAnimation(0, 30, touchgfx::EasingEquations::linearEaseIn);
    
    }
}

void lockScreenViewBase::fadeGlassEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Image>& comp)
{
    //first
    //When fadeGlass completed change screen to mainScreen
    //Go to mainScreen with no screen transition
    application().gotomainScreenScreenNoTransition();
}

void lockScreenViewBase::transitionBegins()
{
    //showGlass
    //When screen transition begins fade glass
    //Fade glass to alpha:255 with LinearIn easing in 500 ms (30 Ticks)
    glass.clearFadeAnimationEndedAction();
    glass.startFadeAnimation(255, 30, touchgfx::EasingEquations::linearEaseIn);
    glass.setFadeAnimationEndedAction(showGlassEndedCallback);

    //fadeGlassless
    //When screen transition begins fade glasslessTop
    //Fade glasslessTop to alpha:0 with LinearIn easing in 500 ms (30 Ticks)
    glasslessTop.clearFadeAnimationEndedAction();
    glasslessTop.startFadeAnimation(0, 30, touchgfx::EasingEquations::linearEaseIn);
}

void lockScreenViewBase::showWaitEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::AnimatedImage>& comp)
{
    //fadeWait
    //When showWait completed fade waitAnimate
    //Fade waitAnimate to alpha:0 with LinearIn easing in 500 ms (30 Ticks)
    waitAnimate.clearFadeAnimationEndedAction();
    waitAnimate.setFadeAnimationDelay(138);
    waitAnimate.startFadeAnimation(0, 30, touchgfx::EasingEquations::linearEaseIn);

    //fadeBigLock
    //When showWait completed fade bigLock
    //Fade bigLock to alpha:0 with LinearIn easing in 500 ms (30 Ticks)
    bigLock.clearFadeAnimationEndedAction();
    bigLock.setFadeAnimationDelay(162);
    bigLock.startFadeAnimation(0, 30, touchgfx::EasingEquations::linearEaseIn);
}

void lockScreenViewBase::showGlassEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Image>& comp)
{
    //showUnlockNote
    //When showGlass completed fade unlockNote
    //Fade unlockNote to alpha:255 with LinearIn easing in 500 ms (30 Ticks)
    unlockNote.clearFadeAnimationEndedAction();
    unlockNote.startFadeAnimation(255, 30, touchgfx::EasingEquations::linearEaseIn);
}
