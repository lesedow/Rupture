#pragma once

#include "Precompiled.hh"

namespace Rupture::Platform
{
    class Console
    {
    protected:
        Console() = default;
    public:
        template<class... Args>
        void Write(std::format_string<Args...> fmt, Args&&... args) const
        {
            WriteImplementation(std::format(fmt, std::forward<Args>(args)...));
        }
        virtual ~Console() = default;
    private:
        virtual void WriteImplementation(std::string_view message) const = 0;
        virtual void WriteImplementation(std::wstring_view message) const = 0;
    };
} 