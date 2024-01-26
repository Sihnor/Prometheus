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

#elif PS_PLATFORM_LINUX

#ifdef PS_BUILD_DLL
    #define PROMETHEUS_API __attribute__((visibility("default")))

#else

    #define PROMETHEUS_API

#endif

#else

#error Prometheus only supports Windows!

#endif
