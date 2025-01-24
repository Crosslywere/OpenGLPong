#include "PongApp.h"
#include <Windows.h>

int main(int argc, char** argv) {
	if (Pong::App::Init())
		Pong::App::GameLoop();
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
	if (Pong::App::Init())
		Pong::App::GameLoop();
	return 0;
}
