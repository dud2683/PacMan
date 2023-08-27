workspace "PacMan"
	configurations { "Debug", "Release", "Dist" }
	platforms {"x64"}

project "PacMan"
	kind "ConsoleApp"
	language "C++"
	targetdir "_bin/%{cfg.buildcfg}"
	objdir "_int-bin"
	
	cppdialect "C++20"
	 
	pchheader "common.h"
	pchsource "%{prj.location}/src/common.cpp"
	
	
	includedirs{
		"src",
		"src/ThirdParties/glfw-3.3.8/include",
		"src/ThirdParties/spdlog-1.12.0/include",
		"src/ThirdParties/glad/include",
		"src/ThirdParties/stbImage"
	}
	libdirs{
		"src/ThirdParties/glfw-3.3.8/lib-vc2019"
	}
	links{
		"glfw3.lib",
		"opengl32.lib"
	}
	files { "src/**.h", "src/**.cpp", "src/**.c", "src/**.txt" }

	filter "files:**.c"
		flags {"NoPCH"}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE", "NDEBUG" }
		optimize "On"
	  
	filter "configurations:Dist"
		defines { "DISTRIBUTION" }
		optimize "On"
	