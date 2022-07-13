#include "core.h"
#include "style.h"
#include "app.h"
#include <imgui.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "imgui_notify.h"
#include "style.h"

const char* App::GetAppName() 
{
    return "Sample";
}

void App::init()
{
    SetEngineTime(&engineTime);
    AppStyle::SetupStyle();
}

void App::tick(double deltaTime)
{
    CreateMainDockSpace();

    ImGui::Begin("AppWindow", nullptr, ImGuiWindowFlags_NoResize|ImGuiWindowFlags_NoDecoration|ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoBackground|ImGuiWindowFlags_NoDocking);
    //ImGui::Begin("AppWindow");
    ImGui::SetWindowSize({ 300, 150 });

    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    ImGui::TextColored({ 0.5, 1.0, 0.5, 0.7f }, "Application average %.0f ms/frame (%.1f FPS)", 1000.0f * deltaTime, 1 / deltaTime);
    if(ImGui::Button("Press me", { 100, 30 }))
    {
        ImGui::InsertNotification({ ImGuiToastType_Warning, 3.0, "hello motherfucker. this is a warning" });

        ImGui::InsertNotification({ ImGuiToastType_Error, 3.0, "hello motherfucker. this is an error" });
    }
    ImGui::End();



    engineTime += deltaTime;
}

void App::on_exit()
{
}

void App::drawCanvas()
{
    auto r = ImGui::GetWindowPos();
    int x, y;
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

    glfwGetMonitorPhysicalSize(glfwGetPrimaryMonitor(), &x, &y);
	ImDrawList* draw_list = ImGui::GetWindowDrawList();

    draw_list->AddCircle({r.x + 520, r.y + 520}, 200, IM_COL32(255, 255, 64, 255));
    ImGui::RenderNotifications({1.0f * mode->width, 1.0f * mode->height - 50});
}


