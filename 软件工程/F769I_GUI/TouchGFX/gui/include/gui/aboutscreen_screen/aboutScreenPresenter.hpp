#ifndef ABOUTSCREENPRESENTER_HPP
#define ABOUTSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class aboutScreenView;

class aboutScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    aboutScreenPresenter(aboutScreenView& v);

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

    virtual ~aboutScreenPresenter() {}

private:
    aboutScreenPresenter();

    aboutScreenView& view;
};

#endif // ABOUTSCREENPRESENTER_HPP
