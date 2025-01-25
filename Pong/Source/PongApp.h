#pragma once

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace Pong {

	namespace App {
		/// <summary>Initialize the window and opengl</summary>
		/// <returns>true on success; false otherwise</returns>
		bool Init();
		/// <summary>Runs the application's main loop</summary>
		void GameLoop();
	}

}
