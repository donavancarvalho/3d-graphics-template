#pragma once
#include "SharedLib/Platform/Window.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace SharedLib
{
    class Win32Window : public Window
    {
    public:
        Win32Window(const WindowInfo &info);
        ~Win32Window();
        virtual void Initialize() override;
        virtual void PollEvents() override;
        virtual void SwapBuffers() override;
        virtual bool CloseRequested() const override;
        virtual std::string GetTitle() const override { return m_Info.Title; };
        virtual uint32_t GetWidth() const override { return m_Width; };
        virtual uint32_t GetHeight() const override { return m_Height; };
        virtual void *GetHandle() const override { return m_Handle; };

    private:
        GLFWwindow *m_Handle;
        WindowInfo m_Info;
        uint32_t m_Width;
        uint32_t m_Height;
    };
}