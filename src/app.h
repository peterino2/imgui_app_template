#pragma once

#include "core.h"

class GLFWwindow;

class App: public CoreApp {

public:

    virtual const char* GetAppName() override;
    virtual void init() override;
    virtual void tick(double deltaTime) override;
    virtual void on_exit() override;
    virtual void drawCanvas() override;
};
