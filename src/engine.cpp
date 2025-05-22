#include "mango/engine.hpp"
#include "GLFW/glfw3.h"
#include <stdio.h>
#include <stdexcept>

void error_callback(int error, const char* description)
{
    fprintf(stderr, "[GLFW Error] %s\n", description);
}

mango::mango(int width, int height, const char* title) {
    glfwSetErrorCallback(error_callback);
    if(!glfwInit()) {
        throw std::runtime_error("[ERROR] Could not initialize GLFW\n");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    mango::window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (mango::window == nullptr) {
        throw std::runtime_error("[ERROR] Could not make GLFW window\n");
    }
    glfwMakeContextCurrent(mango::window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("[ERROR] Cannot initalize GLAD\n");
    }

    glViewport(0, 0, width, height);
    printf("mangoL!B v1.0.0 by Carl486 (%d.%d.%d, on platform)\n",
         GLFW_VERSION_MAJOR, GLFW_VERSION_MINOR, GLFW_VERSION_REVISION
    );

    const unsigned char* gpu = glGetString(GL_RENDERER);
    printf("Rendering on %s\n", gpu);
}

void mango::update() {
    glfwPollEvents();
    mango::shouldQuit = glfwWindowShouldClose(mango::window);
    if (mango::shouldQuit) {
        mango::~mango();
    }
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(mango::window);
}

mango::~mango() {glfwDestroyWindow(mango::window);}
void mango::quit() {mango::~mango(); glfwTerminate();}