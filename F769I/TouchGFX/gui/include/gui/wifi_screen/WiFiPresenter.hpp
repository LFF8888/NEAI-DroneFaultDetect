#ifndef WIFIPRESENTER_HPP
#define WIFIPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class WiFiView;

class WiFiPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    WiFiPresenter(WiFiView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~WiFiPresenter() {};

private:
    WiFiPresenter();

    WiFiView& view;
};

#endif // WIFIPRESENTER_HPP
