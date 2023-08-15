#ifndef FIRSTSCREEENVIEW_HPP
#define FIRSTSCREEENVIEW_HPP

#include <gui_generated/firstscreeen_screen/firstScreeenViewBase.hpp>
#include <gui/firstscreeen_screen/firstScreeenPresenter.hpp>

class firstScreeenView : public firstScreeenViewBase
{
public:
    firstScreeenView();
    virtual ~firstScreeenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // FIRSTSCREEENVIEW_HPP
