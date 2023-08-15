#ifndef BATSCREENVIEW_HPP
#define BATSCREENVIEW_HPP

#include <gui_generated/batscreen_screen/batScreenViewBase.hpp>
#include <gui/batscreen_screen/batScreenPresenter.hpp>

class batScreenView : public batScreenViewBase
{
public:
    batScreenView();
    virtual ~batScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // BATSCREENVIEW_HPP
