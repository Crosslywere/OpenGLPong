#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace Pong {

	struct Shader {

	};

	class App {
	public:
		static bool Init();
		static void GameLoop();
		static void DeInit();
	private:
		static GLFWwindow* sWindow;
	};

}
