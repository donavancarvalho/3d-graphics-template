#include "Win32Window.h"
#include "SharedLib/Core/Log.h"
#include "SharedLib/Core/Assert.h"

namespace SharedLib
{
    Win32Window::Win32Window(const WindowInfo &info)
        : m_Info(info), m_Handle(nullptr),
          m_Width(info.Width), m_Height(info.Height)
    {
    }

    Win32Window::~Win32Window()
    {
        if (m_Handle)
        {
            glfwDestroyWindow(m_Handle);
            m_Handle = nullptr;
        }

        glfwTerminate();
    }

    void Win32Window::Initialize()
    {
        DC_INFO("Window({0}:{1}) \"{2}\"", m_Width, m_Height, m_Info.Title);

        DC_ASSERT(glfwInit(), "{0}", "Failed to initialize window");

        glfwSetErrorCallback([](int errorCode, const char *description)
                             { DC_ASSERT(false, description); });

        // Render context settings (opengl 4.5)
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        m_Handle = glfwCreateWindow(m_Info.Width, m_Info.Height, m_Info.Title.c_str(), nullptr, nullptr);

        if (m_Handle == nullptr)
        {
            glfwTerminate();
            DC_ASSERT(false, "Failed to create window");
        }

        // Render context initializing
        glfwMakeContextCurrent(m_Handle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            glfwDestroyWindow(m_Handle);
            glfwTerminate();
            DC_ASSERT(false, "Failed to initialize render context");
        }
    }

    void Win32Window::PollEvents()
    {
        glfwPollEvents();
    }

    void Win32Window::SwapBuffers()
    {
        glfwSwapBuffers(m_Handle);
    }

    bool Win32Window::CloseRequested() const
    {
        return glfwWindowShouldClose(m_Handle);
    }

}