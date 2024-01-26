//
// Created by Marcel on 1/23/2024.
//
#pragma once
#include <iostream>


#ifdef PS_PLATFORM_WINDOWS

extern Prometheus::Application *Prometheus::CreateApplication();

int main(int argc, char *argv[]) {
    (void)argc;
    argv[0] = nullptr;

    auto app = Prometheus::CreateApplication();
    app->Run();
    delete app;

    return 0;
}


#endif //PS_PLATFORM_WINDOWS

#ifdef PS_PLATFORM_LINUX

extern Prometheus::Application *Prometheus::CreateApplication();

int main(const int argc, char *argv[]) {
    //(void)argc;
    //argv[0] = nullptr;

    auto app = Prometheus::CreateApplication();
    app->Run();
    delete app;
    app = nullptr;

    return 0;
}

#endif //PS_PLATFORM_LINUX