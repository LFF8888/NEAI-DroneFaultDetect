#ifndef ABOUTSCREENVIEW_HPP
#define ABOUTSCREENVIEW_HPP

#include <gui_generated/aboutscreen_screen/aboutScreenViewBase.hpp>
#include <gui/aboutscreen_screen/aboutScreenPresenter.hpp>

class aboutScreenView : public aboutScreenViewBase
{
public:
    aboutScreenView();
    virtual ~aboutScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ABOUTSCREENVIEW_HPP
