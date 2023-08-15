#ifndef FIRSTSCREEENPRESENTER_HPP
#define FIRSTSCREEENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class firstScreeenView;

class firstScreeenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    firstScreeenPresenter(firstScreeenView& v);

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

    virtual ~firstScreeenPresenter() {}

private:
    firstScreeenPresenter();

    firstScreeenView& view;
};

#endif // FIRSTSCREEENPRESENTER_HPP
