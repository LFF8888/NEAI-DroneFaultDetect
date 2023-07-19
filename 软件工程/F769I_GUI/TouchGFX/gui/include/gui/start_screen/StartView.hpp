#ifndef STARTVIEW_HPP
#define STARTVIEW_HPP

#include <gui_generated/start_screen/StartViewBase.hpp>
#include <gui/start_screen/StartPresenter.hpp>

class StartView : public StartViewBase
{
public:
    StartView();
    virtual ~StartView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // STARTVIEW_HPP
