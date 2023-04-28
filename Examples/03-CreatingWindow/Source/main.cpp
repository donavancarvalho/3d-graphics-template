#include "SharedLib/Core/Log.h"
#include "SharedLib/Platform/Windows/Win32Window.h"

int main()
{
    std::unique_ptr<SharedLib::Log> logSystem = std::make_unique<SharedLib::Log>();
    logSystem->Initialize();

    SharedLib::WindowInfo info{};
    info.Width = 1280;
    info.Height = 720;
    info.Title = "My window";

    std::unique_ptr<SharedLib::Window> window = SharedLib::Window::Create(info);
    window->Initialize();

    while (!window->CloseRequested())
    {
        window->PollEvents();

        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        window->SwapBuffers();
    }
}