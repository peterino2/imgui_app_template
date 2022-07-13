#pragma once

class GLFWwindow;

class CoreApp {

public:
    double engineTime = 0.0;
    GLFWwindow* window = nullptr;
    bool shouldExit = false;

    // Interface
    virtual const char* GetAppName() = 0;
    virtual void init() = 0;
    virtual void tick(double deltaTime) = 0;
    virtual void on_exit() = 0;
    virtual void drawCanvas() = 0;
    // Interface

    // run this to run the application
    int run_app();

    // setup

    void CreateMainDockSpace();
};
