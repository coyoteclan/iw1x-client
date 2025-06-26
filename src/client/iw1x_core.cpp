#include "pch.h"
#include "iw1x_core.h"

extern "C" IW1X_API DWORD address_cgame_mp = 0;
extern "C" IW1X_API DWORD address_ui_mp = 0;

void MSG_ERR(const char* msg)
{
    MessageBox(NULL, msg, MOD_NAME, MB_ICONERROR | MB_SETFOREGROUND);
}

bool RunningUnderWine() {
    HMODULE hNtdll = GetModuleHandleW(L"ntdll.dll");
    if (!hNtdll)
        return false;

    // Look for wine_get_version export
    FARPROC fn = GetProcAddress(hNtdll, "wine_get_version");
    return (fn != nullptr);
}

// Convert a wide Unicode string (UTF-16) to a UTF-8 std::string
std::string utf8_encode(const std::wstring& wstr)
{
    if (wstr.empty())
        return {};

    // 1) Ask for the required buffer size (in bytes)
    int size_needed = WideCharToMultiByte(
        CP_UTF8,                // convert to UTF-8
        0,                      // no special flags
        wstr.data(),            // input wide-char string
        (int)wstr.size(),       // length of wstr
        nullptr,                // no output buffer yet
        0,                      // request size only
        nullptr, nullptr        // default replacement chars
    );                                                    
    if (size_needed == 0)
        return {};  // conversion error

    // 2) Perform the actual conversion
    std::string result(size_needed, '\0');
    WideCharToMultiByte(
        CP_UTF8,
        0,
        wstr.data(),
        (int)wstr.size(),
        result.data(),         // output buffer
        size_needed,
        nullptr, nullptr
    );
    return result;
}

std::wstring get_font_path_w(const wchar_t* fontName)
{
    HKEY hKey;
    if (RegOpenKeyExW(
            HKEY_LOCAL_MACHINE,
            L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Fonts",
            0, KEY_READ, &hKey) != ERROR_SUCCESS)
        return {};

    DWORD size = 0;
    // Query required buffer size
    RegGetValueW(hKey, nullptr, fontName, RRF_RT_REG_SZ, nullptr, nullptr, &size);
    if (size == 0) {
        RegCloseKey(hKey);
        return {};
    }
    // Read the actual data
    std::wstring data(size / sizeof(wchar_t), L'\0');
    RegGetValueW(hKey, nullptr, fontName, RRF_RT_REG_SZ, nullptr,
                 data.data(), &size);
    RegCloseKey(hKey);

    // Trim any trailing null
    if (!data.empty() && data.back() == L'\0')
        data.pop_back();

    return data;
}

std::string get_font_path(const wchar_t* fontName)
{
    std::wstring widePath = get_font_path_w(fontName);
    return utf8_encode(widePath);
}

// on windows, the registery usually holds the filenames only
// this should get us the absolute path to the font file
const char* validate_font_path(std::string path)
{
    if(path.at(1) != ':')
    {
        std::string fontPath = "C:\\Windows\\Fonts\\" + path;
        return fontPath.c_str();
    }

    return path.c_str();
}