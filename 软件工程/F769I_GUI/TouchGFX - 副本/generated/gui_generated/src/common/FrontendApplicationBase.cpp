/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
}

/*
 * Screen Transition Declarations
 */

// Screen2

void FrontendApplicationBase::gotoScreen2ScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoScreen2ScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen2ScreenNoTransitionImpl()
{
    touchgfx::makeTransition<Screen2View, Screen2Presenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
