#ifndef CONTROLVIEW_HPP
#define CONTROLVIEW_HPP

#include <gui_generated/control_screen/ControlViewBase.hpp>
#include <gui/control_screen/ControlPresenter.hpp>

class ControlView : public ControlViewBase
{
public:
    ControlView();
    virtual ~ControlView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // CONTROLVIEW_HPP
