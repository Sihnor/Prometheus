//
// Created by Marcel on 1/23/2024.
//
#pragma once
#include <iostream>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>


#ifdef PS_PLATFORM_WINDOWS

extern Prometheus::Application *Prometheus::CreateApplication();

int main(int argc, char *argv[]) {
    (void)argc;
    argv[0] = nullptr;

    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extension supported\n";

    glm::mat4 matrix;
    glm::vec4 vec;
    auto test = matrix * vec;

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);

    glfwTerminate();

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