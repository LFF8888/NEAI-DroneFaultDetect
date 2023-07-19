#ifndef CONTROLPRESENTER_HPP
#define CONTROLPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ControlView;

class ControlPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ControlPresenter(ControlView& v);

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

    virtual ~ControlPresenter() {};

private:
    ControlPresenter();

    ControlView& view;
};

#endif // CONTROLPRESENTER_HPP
