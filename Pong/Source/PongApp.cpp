#include "PongApp.h"

static void processKeyboardInputs(GLFWwindow*);

namespace Pong {

	GLFWwindow* App::sWindow = nullptr;

	bool App::Init() {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
		sWindow = glfwCreateWindow(800, 450, "OpenGL Pong", nullptr, nullptr);;
		if (sWindow == nullptr) {
			return false;
		}
		glfwMakeContextCurrent(sWindow);
		glfwSwapInterval(1);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			return false;
		}
		return true;
	}

	void App::GameLoop() {
		while (!glfwWindowShouldClose(sWindow)) {
			glClear(GL_COLOR_BUFFER_BIT);
			processKeyboardInputs(sWindow);
			// render frame
			glfwSwapBuffers(sWindow);
			glfwPollEvents();
		}
		DeInit();
	}

	void App::DeInit() {
		glfwDestroyWindow(sWindow);
		glfwTerminate();
	}

}

void processKeyboardInputs(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}
