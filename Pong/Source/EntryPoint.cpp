#include "PongApp.h"

int main(int argc, char** argv) {
	if (Pong::App::Init())
		Pong::App::GameLoop();
	return 0;
}

#if defined(PONG_WINDOWS) && defined(NDEBUG)
#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow) {
	if (Pong::App::Init())
		Pong::App::GameLoop();
	return 0;
}
#endif
