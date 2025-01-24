
workspace "OpenGLPong"
	platforms "x64"
	configurations {
		"Debug",
		"Release"
	}
	startproject "Pong"

	IncludeDir = {}
	IncludeDir["GLAD"] = "%{wks.location}/Dependencies/GLAD/include"
	IncludeDir["GLFW"] = "%{wks.location}/Dependencies/GLFW/include"

	include "Pong"

	include "Dependencies/GLAD"
	include "Dependencies/GLFW"