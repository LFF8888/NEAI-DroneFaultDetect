/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef LOCKSCREENVIEWBASE_HPP
#define LOCKSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/lockscreen_screen/lockScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/AnimatedImage.hpp>
#include <touchgfx/EasingEquations.hpp>
#include <touchgfx/mixins/FadeAnimator.hpp>

class lockScreenViewBase : public touchgfx::View<lockScreenPresenter>
{
public:
    lockScreenViewBase();
    virtual ~lockScreenViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);
    virtual void transitionBegins();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Image glassless;
    touchgfx::FadeAnimator< touchgfx::Image > glass;
    touchgfx::FadeAnimator< touchgfx::Image > bigLock;
    touchgfx::FadeAnimator< touchgfx::Image > glasslessTop;
    touchgfx::FadeAnimator< touchgfx::AnimatedImage > waitAnimate;
    touchgfx::FadeAnimator< touchgfx::Image > unlockNote;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback < lockScreenViewBase, const touchgfx::FadeAnimator<touchgfx::Image>& > fadeGlassEndedCallback;
    touchgfx::Callback < lockScreenViewBase, const touchgfx::FadeAnimator<touchgfx::AnimatedImage>& > showWaitEndedCallback;
    touchgfx::Callback < lockScreenViewBase, const touchgfx::FadeAnimator<touchgfx::Image>& > showGlassEndedCallback;

    /*
     * Callback Handler Declarations
     */
    void fadeGlassEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Image>& comp);
    void showWaitEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::AnimatedImage>& comp);
    void showGlassEndedCallbackHandler(const touchgfx::FadeAnimator<touchgfx::Image>& comp);

};

#endif // LOCKSCREENVIEWBASE_HPP
