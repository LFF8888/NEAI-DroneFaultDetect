#ifndef MAPVIEW_HPP
#define MAPVIEW_HPP

#include <gui_generated/map_screen/MapViewBase.hpp>
#include <gui/map_screen/MapPresenter.hpp>

class MapView : public MapViewBase
{
public:
    MapView();
    virtual ~MapView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAPVIEW_HPP
