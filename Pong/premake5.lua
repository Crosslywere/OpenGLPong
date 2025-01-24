project "Pong"
	language "C++"
	cppdialect "C++20"
	files {
		"Source/**.cpp",
		"Source/**.h"
	}
	vpaths {
		["Source Files"] = "**.cpp",
		["Header Files"] = "**.h"
	}
	libdirs {
		"%{wks.location}/lib/%{cfg.buildcfg}"
	}
	links {
		"GLAD",
		"GLFW"
	}
	includedirs {
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.GLFW}"
	}
	targetdir "%{wks.location}/Binary/%{cfg.buildcfg}"
	objdir "obj/%{cfg.buildcfg}"

	filter "configurations:Debug"
		kind "ConsoleApp"
		runtime "Debug"
		symbols "On"
		defines {
			"DEBUG"
		}

	filter "configurations:Release"
		kind "WindowedApp"
		runtime "Release"
		optimize "On"
		symbols "Off"
		defines {
			"NDEBUG"
		}
