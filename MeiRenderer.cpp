// MeiRenderer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//ImGUI-> GUI
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

//Glad-> Provides OpenGL bindings
//GLFW-> for providing rendering windows
#include <glad/glad.h>
#include <GLFW/glfw3.h>



//iostream-> IO and error logging
#include <iostream>


const char* GLSLVersion = "#version 330";


void RenderGUI(ImVec4* clear_color)
// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
{
    static float f = 0.0f;
    static int counter = 0;

    ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.
    ImGui::ColorEdit3("clear color", (float*)clear_color); // Edit 3 floats representing a color
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
    ImGui::Render();
}

void errorCallback(int error, const char* description)
{
    //Print error to standard error stdderr
    std::cerr << "Error: " << description << std::endl;
}


//Allows for window to be resized during runtime
void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{ 
    //Width and height of window and framebuffer
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
    glfwSwapInterval(1); // Enable vsync

        // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
 
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(GLSLVersion);
    ImVec4 ColorVector = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) << std::endl;
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        RenderGUI(&ColorVector);
        glClearColor(ColorVector.x * ColorVector.w, ColorVector.y * ColorVector.w, ColorVector.z * ColorVector.w, ColorVector.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();




}
