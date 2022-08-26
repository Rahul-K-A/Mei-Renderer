// MeiRenderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void errorCallback(int error, const char* description)
{
    //Print error to standard error stdderr
    std::cerr << "Error: " << description << std::endl;
}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{ 
    GLint FrameWidth= 640, FrameHeight= 480;

    if (!glfwInit())
    {
        std::cout << "GLFW Init failed!";
    }
    else {
        std::cout << "GLFW enabled\n";
    }
    //Set window context GLFW version 3.3.8, core profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwSetErrorCallback(errorCallback);
    
  



    GLFWwindow* window = glfwCreateWindow(FrameWidth,FrameHeight , "My Title", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create window!\n";
        glfwTerminate();
        return 0;
    }
    std::cout << "Window created!\n";

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) << std::endl;
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();




}
