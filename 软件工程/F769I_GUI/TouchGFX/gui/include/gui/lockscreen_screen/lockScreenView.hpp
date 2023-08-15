#ifndef LOCKSCREENVIEW_HPP
#define LOCKSCREENVIEW_HPP

#include <gui_generated/lockscreen_screen/lockScreenViewBase.hpp>
#include <gui/lockscreen_screen/lockScreenPresenter.hpp>

class lockScreenView : public lockScreenViewBase
{
public:
    lockScreenView();
    virtual ~lockScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LOCKSCREENVIEW_HPP
