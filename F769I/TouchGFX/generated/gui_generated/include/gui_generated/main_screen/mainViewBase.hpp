/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MAINVIEWBASE_HPP
#define MAINVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/Button.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/containers/clock/DigitalClock.hpp>

class mainViewBase : public touchgfx::View<mainPresenter>
{
public:
    mainViewBase();
    virtual ~mainViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Button WIFI_BUT;
    touchgfx::Button SAT_BUT;
    touchgfx::Button BAT_BUT;
    touchgfx::Button MAP_BUT;
    touchgfx::Button CTRL_BUT;
    touchgfx::Image image1;
    touchgfx::Image image1_1;
    touchgfx::Image image1_2;
    touchgfx::Image image1_3;
    touchgfx::TextArea textArea1;
    touchgfx::TextArea textArea1_1;
    touchgfx::TextArea textArea1_1_1;
    touchgfx::TextArea textArea1_1_1_1;
    touchgfx::DigitalClock digitalClock1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<mainViewBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // MAINVIEWBASE_HPP