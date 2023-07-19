#ifndef SATELITEVIEW_HPP
#define SATELITEVIEW_HPP

#include <gui_generated/satelite_screen/SateliteViewBase.hpp>
#include <gui/satelite_screen/SatelitePresenter.hpp>

class SateliteView : public SateliteViewBase
{
public:
    SateliteView();
    virtual ~SateliteView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SATELITEVIEW_HPP
