#include "Window.h"
#include "SharedLib/Platform/Windows/Win32Window.h"

namespace SharedLib
{
    std::unique_ptr<Window> Window::Create(const WindowInfo &info)
    {
        return std::make_unique<Win32Window>(info);
    }
}