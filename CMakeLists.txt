cmake_minimum_required(VERSION 3.27)
project(Prometheus)

set(CMAKE_CXX_STANDARD 17)

set(WORKSPACE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(OUTPUT_DIR "${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_SYSTEM_PROCESSOR}")


if (WIN32 AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_compile_definitions(PS_PLATFORM_WINDOWS)
endif ()

if (UNIX AND NOT APPLE AND CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_compile_definitions(PS_PLATFORM_LINUX)
endif ()

set(CMAKE_CONFIGURATION_TYPES "Debug;Release;MinSizeRel" CACHE STRING "" FORCE)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(PS_DEBUG)

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # G++ oder Clang++ spezifische Optionen
        add_compile_options(-g -O0 -Wall -Wextra)
    elseif (MSVC)
        # Visual Studio spezifische Optionen
        add_compile_options(/MDd /Zi /Ob0 /Od /RTC1)
    endif ()
    message(STATUS "Debug-Build wird erstellt. CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(PS_RELEASE)

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # G++ oder Clang++ spezifische Optionen
        add_compile_options(-O3 -Wall -Wextra)
    elseif (MSVC)
        # Visual Studio spezifische Optionen
        add_compile_options(/MD /O2 /Ob2 /DNDEBUG)
    endif ()
    message(STATUS "Release-Build wird erstellt. CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")


elseif (CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    add_compile_definitions(PS_MINSIZEREL)

    if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        # G++ oder Clang++ spezifische Optionen
        add_compile_options(-Os -Wall -Wextra)
    elseif (MSVC)
        # Visual Studio spezifische Optionen
        add_compile_options(/MD /Os /Ob2 /DNDEBUG)
    endif ()
    message(STATUS "MinSizeRel-Build wird erstellt. CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}")

else ()
    message(FATAL_ERROR "Ungültiger Build-Typ: ${CMAKE_BUILD_TYPE}")
endif ()

add_subdirectory(Prometheus)
add_subdirectory(Sandbox)
