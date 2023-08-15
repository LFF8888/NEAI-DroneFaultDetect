#include <gui/screen1_screen/Screen1View.hpp>


Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::functionAdd()
{
    counter++;
    Unicode::snprintf(textNumberBuffer, TEXTNUMBER_SIZE, "%d", counter);
    textNumber.invalidate();
}

void Screen1View::functionSub()
{
    counter--;
    Unicode::snprintf(textNumberBuffer, TEXTNUMBER_SIZE, "%d", counter);
    textNumber.invalidate();
}
