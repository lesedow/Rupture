#include "Precompiled.hh"
#include "Platform/WinApiConsole.hh"
#include "Utils/Macros/WinAPIMacros.hh"

namespace Rupture::Platform
{
    WinApiConsole::WinApiConsole()
    {
        // Allocating a console
        BOOL allocedConsole = AllocConsole();
        RP_CLWINAPI(!allocedConsole);

        FILE* stream{ nullptr };
        freopen_s(&stream, "CONOUT$", "w", stdout);
        freopen_s(&stream, "CONOUT$", "w", stderr);
        freopen_s(&stream, "CONIN$", "r", stdin);

        StdOut_ = GetStdHandle(STD_OUTPUT_HANDLE);
        RP_CLWINAPI(StdOut_ == INVALID_HANDLE_VALUE);

        // Enabling VTS
        DWORD mode{};
        BOOL succesGetMode = GetConsoleMode(StdOut_, &mode);
        RP_CLWINAPI(!succesGetMode);
        mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING; 

        BOOL succesSetMode = SetConsoleMode(StdOut_, mode);
        RP_CLWINAPI(!succesSetMode);
    }

    WinApiConsole::~WinApiConsole() {};

    void WinApiConsole::WriteImplementation(std::wstring_view message) const
    {
        WriteConsole(StdOut_, message.data(), message.size(), nullptr, nullptr);
    }

    void WinApiConsole::WriteImplementation(std::string_view message) const
    {
        // Convert from utf-8 to utf-16
        std::wstring convertedMessage(message.size(), L'\0');

        MultiByteToWideChar(
            CP_ACP, MB_PRECOMPOSED, 
            message.data(), 
            message.size(), 
            convertedMessage.data(), 
            convertedMessage.size());
            
        WriteConsole(StdOut_, convertedMessage.data(), convertedMessage.size(), nullptr, nullptr);
    }

    void WinApiConsole::SetTitle(std::string_view title) const
    {
        Write("\x1B]0;{}\x1B\\", title);
    }
}