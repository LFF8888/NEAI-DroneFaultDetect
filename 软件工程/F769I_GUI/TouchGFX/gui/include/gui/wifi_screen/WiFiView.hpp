#ifndef WIFIVIEW_HPP
#define WIFIVIEW_HPP

#include <gui_generated/wifi_screen/WiFiViewBase.hpp>
#include <gui/wifi_screen/WiFiPresenter.hpp>

class WiFiView : public WiFiViewBase
{
public:
    WiFiView();
    virtual ~WiFiView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // WIFIVIEW_HPP
