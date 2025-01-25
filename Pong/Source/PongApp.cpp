#include "PongApp.h"

enum AppState {
	MENU,
	PAUSED,
	PLAYING,
};

enum MenuOption {
	PLAY,
	EXIT,
};

static inline struct AppData {
	AppState state{ AppState::MENU };
	MenuOption option{ MenuOption::PLAY };
} g_AppData;

static inline GLFWwindow* g_WindowPtr;

static void KeyboardCallbackFn(GLFWwindow* window, int key, int scancode, int action, int mods);

static void ProcessKeyboardInputs();

static void DeInit();

bool Pong::App::Init() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	g_WindowPtr = glfwCreateWindow(800, 450, "OpenGL Pong", nullptr, nullptr);;
	if (g_WindowPtr == nullptr) {
		return false;
	}
	glfwMakeContextCurrent(g_WindowPtr);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return false;
	}
	glfwSwapInterval(1);
	glfwSetKeyCallback(g_WindowPtr, KeyboardCallbackFn);
	return true;
}

void Pong::App::GameLoop() {
	while (!glfwWindowShouldClose(g_WindowPtr)) {
		glClear(GL_COLOR_BUFFER_BIT);
		if (g_AppData.state == PLAYING) {
			ProcessKeyboardInputs();
			// render frame
		}
		glfwSwapBuffers(g_WindowPtr);
		glfwPollEvents();
	}
	DeInit();
}

static void SwapOption() {
	if (g_AppData.state != PLAYING) {
		switch (g_AppData.option) {
		case PLAY:
			g_AppData.option = EXIT;
			break;
		case EXIT:
			g_AppData.option = PLAY;
			break;
		}
	}
}

static void KeyboardCallbackFn(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		switch (g_AppData.state) {
		case MENU:
			glfwSetWindowShouldClose(window, GLFW_TRUE);
			break;
		case PAUSED:
			g_AppData.state = PLAYING;
			break;
		case PLAYING:
			g_AppData.state = PAUSED;
			break;
		}
	}
	if (action != GLFW_RELEASE) {
		switch (key) {
		case GLFW_KEY_UP:
			SwapOption();
			break;
		case GLFW_KEY_DOWN:
			SwapOption();
			break;
		}
	}

}

static void ProcessKeyboardInputs() {
	if (glfwGetKey(g_WindowPtr, GLFW_KEY_W) == GLFW_PRESS) {
		// Player 1 Up
	}
	if (glfwGetKey(g_WindowPtr, GLFW_KEY_S) == GLFW_PRESS) {
		// Player 1 Down
	}
	if (glfwGetKey(g_WindowPtr, GLFW_KEY_UP) == GLFW_PRESS) {
		// Player 2 Up
	}
	if (glfwGetKey(g_WindowPtr, GLFW_KEY_DOWN) == GLFW_PRESS) {
		// Player 2 Down
	}
}

static void DeInit() {
	glfwDestroyWindow(g_WindowPtr);
	glfwTerminate();
}
