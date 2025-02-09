project "GLFW"
	kind "StaticLib"
	language "C"
	files {
		"include/GLFW/glfw3.h",
		"include/GLFW/glfw3native.h",
		"src/glfw_config.h",
		"src/context.c",
		"src/init.c",
		"src/input.c",
		"src/monitor.c",
		"src/null_init.c",
		"src/null_joystick.c",
		"src/null_monitor.c",
		"src/null_window.c",
		"src/platform.c",
		"src/vulkan.c",
		"src/window.c"
	}
	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}
	targetdir "%{wks.location}/libs/%{cfg.buildcfg}"
	objdir "obj/%{cfg.buildcfg}"

	filter "system:windows"
		files {
			"src/wgl_context.c",
			"src/win32_init.c",
			"src/win32_joystick.c",
			"src/win32_module.c",
			"src/win32_monitor.c",
			"src/win32_thread.c",
			"src/win32_time.c",
			"src/win32_window.c",
			"src/egl_context.c",
			"src/osmesa_context.c"
		}
		defines {
			"_GLFW_WIN32"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		symbols "Off"
