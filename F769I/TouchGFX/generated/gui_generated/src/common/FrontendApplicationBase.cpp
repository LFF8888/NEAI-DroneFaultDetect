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
#include <gui/start_screen/StartView.hpp>
#include <gui/start_screen/StartPresenter.hpp>
#include <gui/main_screen/mainView.hpp>
#include <gui/main_screen/mainPresenter.hpp>
#include <gui/wifi_screen/WiFiView.hpp>
#include <gui/wifi_screen/WiFiPresenter.hpp>
#include <gui/battery_screen/BatteryView.hpp>
#include <gui/battery_screen/BatteryPresenter.hpp>
#include <gui/satelite_screen/SateliteView.hpp>
#include <gui/satelite_screen/SatelitePresenter.hpp>
#include <gui/control_screen/ControlView.hpp>
#include <gui/control_screen/ControlPresenter.hpp>
#include <gui/map_screen/MapView.hpp>
#include <gui/map_screen/MapPresenter.hpp>

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

// Start

void FrontendApplicationBase::gotoStartScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoStartScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoStartScreenNoTransitionImpl()
{
    touchgfx::makeTransition<StartView, StartPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// main

void FrontendApplicationBase::gotomainScreenCoverTransitionNorth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotomainScreenCoverTransitionNorthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotomainScreenCoverTransitionNorthImpl()
{
    touchgfx::makeTransition<mainView, mainPresenter, touchgfx::CoverTransition<NORTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotomainScreenCoverTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotomainScreenCoverTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotomainScreenCoverTransitionWestImpl()
{
    touchgfx::makeTransition<mainView, mainPresenter, touchgfx::CoverTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// WiFi

void FrontendApplicationBase::gotoWiFiScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoWiFiScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoWiFiScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<WiFiView, WiFiPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Battery

void FrontendApplicationBase::gotoBatteryScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoBatteryScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoBatteryScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<BatteryView, BatteryPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Satelite

void FrontendApplicationBase::gotoSateliteScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoSateliteScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoSateliteScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<SateliteView, SatelitePresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Control

void FrontendApplicationBase::gotoControlScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoControlScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoControlScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<ControlView, ControlPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Map

void FrontendApplicationBase::gotoMapScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMapScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMapScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<MapView, MapPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}