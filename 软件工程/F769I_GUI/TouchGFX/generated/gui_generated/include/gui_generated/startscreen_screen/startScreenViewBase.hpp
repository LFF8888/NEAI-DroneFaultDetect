/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef STARTSCREENVIEWBASE_HPP
#define STARTSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/startscreen_screen/startScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/Gauge.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Button.hpp>

class startScreenViewBase : public touchgfx::View<startScreenPresenter>
{
public:
    startScreenViewBase();
    virtual ~startScreenViewBase();
    virtual void setupScreen();
    virtual void handleTickEvent();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Box backGround;
    touchgfx::Image backPicture;
    touchgfx::Image tch_LOGO;
    touchgfx::Gauge tofGauge;
    touchgfx::Gauge speedGauge;
    touchgfx::Gauge batGauge;
    touchgfx::TextAreaWithOneWildcard tofGaugeText;
    touchgfx::TextAreaWithOneWildcard speedGaugeText;
    touchgfx::TextArea batGaugeText;
    touchgfx::TextArea design;
    touchgfx::TextArea stateNormal;
    touchgfx::TextArea stateFree;
    touchgfx::TextArea stateShake;
    touchgfx::TextArea stateBarrier;
    touchgfx::TextArea start;
    touchgfx::Button returnBut;

    /*
     * Wildcard Buffers
     */
    static const uint16_t SPEEDGAUGETEXT_SIZE = 10;
    touchgfx::Unicode::UnicodeChar speedGaugeTextBuffer[SPEEDGAUGETEXT_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<startScreenViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

    /*
     * Tick Counter Declarations
     */
    static const uint32_t TICK_INTERACTION1_INTERVAL = 200;
    uint32_t frameCountInteraction1Interval;

};

#endif // STARTSCREENVIEWBASE_HPP
