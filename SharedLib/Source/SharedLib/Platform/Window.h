#pragma once
#include <cstdint>
#include <memory>
#include <string>

namespace SharedLib
{
    struct WindowInfo
    {
        std::string Title = "Untitled window";
        uint32_t Width = 800;
        uint32_t Height = 600;
    };

    class Window
    {
    public:
        virtual ~Window() = default;
        virtual void Initialize() = 0;
        virtual void PollEvents() = 0;
        virtual void SwapBuffers() = 0;
        virtual bool CloseRequested() const = 0;
        virtual std::string GetTitle() const = 0;
        virtual uint32_t GetWidth() const = 0;
        virtual uint32_t GetHeight() const = 0;
        virtual void *GetHandle() const = 0;

        static std::unique_ptr<Window> Create(const WindowInfo &info);
    };
}