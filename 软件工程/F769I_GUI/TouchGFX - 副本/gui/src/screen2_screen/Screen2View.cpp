#include <gui/screen2_screen/Screen2View.hpp>

Screen2View::Screen2View() {

}

void Screen2View::setupScreen() {
	Screen2ViewBase::setupScreen();
}

void Screen2View::tearDownScreen() {
	Screen2ViewBase::tearDownScreen();
}
void Screen2View::function2(int value) {
	gauge1.setValue(value);
	gauge1.invalidate();
}
