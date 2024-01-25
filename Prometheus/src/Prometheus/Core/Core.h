//
// Created by Marcel on 1/23/2024.
//
#pragma once

#ifdef PS_PLATFORM_WINDOWS

    #ifdef PS_BUILD_DLL
        #define PROMETHEUS_API __declspec(dllexport)

    #else

        #define PROMETHEUS_API __declspec(dllimport)

    #endif

#else

    #error Prometheus only supports Windows!

#endif
