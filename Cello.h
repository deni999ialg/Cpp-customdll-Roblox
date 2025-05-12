// ControllerApp.cpp (optional controller)
#include <Windows.h>
#include <iostream>

typedef void (*ExecFunc)(const char*);

int main() {
    HMODULE hDLL = GetModuleHandleA("ArdentExec.dll");
    if (hDLL) {
        ExecFunc exec = (ExecFunc)GetProcAddress(hDLL, "Exec");
        if (exec) {
            exec("print('Hello from injected Lua!')");
        } else {
            std::cerr << "Exec function not found." << std::endl;
        }
    } else {
        std::cerr << "ArdentExec.dll not loaded in this process." << std::endl;
    }

    return 0;
}
