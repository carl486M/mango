#pragma once
#define GLFW_HEADER_DEFINE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class mango {
public:
    mango(int width, int height, const char* title);
    void update();
    bool shouldQuit = false;
    ~mango();
    void quit();
private:
    int width, height, x, y;
    const char* title;
    GLFWwindow* window;
};