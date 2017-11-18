#pragma once

#include <iostream>
#include <string>

void MarshalString(System::String ^ s, std::string& os) {
    using namespace System::Runtime::InteropServices;
    if (nullptr == s) {
        std::cerr << "Input System::String is empty!" << std::endl;
        return;
    }
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(System::IntPtr((void*)chars));
}