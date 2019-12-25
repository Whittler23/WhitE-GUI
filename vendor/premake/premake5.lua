printf ""
printf "Building WhitEGUI......"
printf ""

workspace "WhitEGUI"
    architecture "x64"
    location "../../"
	cppdialect "C++17"
    
    configurations {
        "Debug",
        "Release"
    }
    
project "WhitEGUI"
    language "C++"
    kind "StaticLib"

    targetdir "../../bin/bin/" 
	objdir "../../bin/obj/" 

    files {
         "../../src/**.cpp",
         "../../includes/**.hpp",
		 "../../src/**.inl"
    }

    defines { "SFML_STATIC" }

    libdirs { "../../vendor/sfml-2.5.1/lib" }

    includedirs{
        "../../includes",
        "../../src",
        "../../vendor/sfml-2.5.1/include",
    }

    links{
        "opengl32.lib",
        "winmm.lib",
        "gdi32.lib",
        "freetype.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "openal32.lib"
    }

    filter{ "configurations:Debug" }
        symbols "On"

        links{
            "sfml-graphics-s-d",
            "sfml-audio-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d"
        }
		
		defines{ "WE_DEBUG" }

    filter{ "configurations:Release" }
        optimize "On"

        links{
            "sfml-graphics-s",
            "sfml-audio-s", 
            "sfml-window-s",
            "sfml-system-s"
        }
		
		defines{ "WE_RELEASE" }

		
    filter{ "system:Windows" }
        defines{ "WE_WINDOWS" }

    filter{ "system:Unix" }
        defines{ "WE_LINUX" }

    filter{}
	
printf ""
printf "Building GUI Sandbox..."
printf ""
    
project "WhitEGUISandbox"
    language "C++"
    kind "ConsoleApp"

    targetdir "../../Sandbox/bin/bin/%{cfg.buildcfg}/" 
	objdir "../../Sandbox/bin/obj/%{cfg.buildcfg}/" 

    files {
         "../../Sandbox/**.cpp",
         "../../Sandbox/**.hpp"
    }

    defines { "SFML_STATIC" }

    libdirs { 
	"../../vendor/sfml-2.5.1/lib",
	"../../bin/bin/"
	}

    includedirs{
        "../../includes",
        "../../vendor/sfml-2.5.1/include"
    }

    links{
        "opengl32.lib",
        "winmm.lib",
        "gdi32.lib",
        "freetype.lib",
        "flac.lib",
        "vorbisenc.lib",
        "vorbisfile.lib",
        "vorbis.lib",
        "ogg.lib",
        "openal32.lib",
		"WhitEGUI.lib"
    }

    filter{ "configurations:Debug" }
        symbols "On"

        links{
            "sfml-graphics-s-d",
            "sfml-audio-s-d",
            "sfml-window-s-d",
            "sfml-system-s-d"
        }

    filter{ "configurations:Release" }
        optimize "On"

        links{
            "sfml-graphics-s",
            "sfml-audio-s", 
            "sfml-window-s",
            "sfml-system-s"
			}
       

	

