project "GLAD"
	kind "StaticLib"
	language "C"
	files {
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c",
	}
	includedirs {
		"%{IncludeDir.GLAD}"
	}
	defines {
		"_CRT_SECURE_NO_WARNINGS",
	}
	targetdir "%{wks.location}/libs/%{cfg.buildcfg}"
	objdir "obj/%{cfg.buildcfg}"

