#pragma once

#include "Console.hh"

namespace Rupture::Platform
{
    class WinApiConsole : public Console
    {
    private:
        HANDLE StdOut_;
    public:
        WinApiConsole();
        ~WinApiConsole();
    public:
        void SetTitle(std::string_view title) const;
    private:
        void WriteImplementation(std::string_view message) const override;
        void WriteImplementation(std::wstring_view message) const override;
    };
}
