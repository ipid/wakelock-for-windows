#include <iostream>
#include <conio.h>
#include <windows.h>

const char* prompt =
"Wakelock acquired.\n"
"\n"
"While this program is running, your computer:\n"
"  - Won't sleep or turn the monitor off automatically.\n"
"  - Will be prevented from shutting down.\n"
"  - Won't go to sleep or hibernate.\n"
"\n"
"Press Ctrl+C to unlock...\n"
;

BOOL WINAPI CtrlHandler(DWORD fdwCtrlType) {
    return true;
}

int main() {
    // Stop system from sleeping or turning off monitor
    SetThreadExecutionState(
        ES_CONTINUOUS | ES_AWAYMODE_REQUIRED | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);

    // Block shutting down procedure
    SetConsoleCtrlHandler(CtrlHandler, true);

    std::cout << prompt << std::endl;

    while (true) {
        // Wait until Ctrl-C is pressed
        if (_getch() == 3) {
            break;
        }
    }

    return 0;
}
