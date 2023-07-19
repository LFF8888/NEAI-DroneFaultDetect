#ifndef BATTERYVIEW_HPP
#define BATTERYVIEW_HPP

#include <gui_generated/battery_screen/BatteryViewBase.hpp>
#include <gui/battery_screen/BatteryPresenter.hpp>

class BatteryView : public BatteryViewBase
{
public:
    BatteryView();
    virtual ~BatteryView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // BATTERYVIEW_HPP
