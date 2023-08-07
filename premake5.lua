workspace "PacMan"
   configurations { "Debug", "Release", "Dist" }
   platforms {"x64"}

project "PacMan"
   kind "ConsoleApp"
   language "C++"
   targetdir "_bin/%{cfg.buildcfg}"
   objdir "_int-bin"

   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
	  
   filter "configurations:Dist"
      defines { "DISTRIBUTION" }
      optimize "On"