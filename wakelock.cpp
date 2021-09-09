#include <iostream>
#include <conio.h>
#include <windows.h>

const char* prompt =
"Wakelock acquired.\n"
"\n"
"While this program is running, your computer:\n"
"  - Won't sleep or turn the monitor off automatically.\n"
"  - If you forcibly make the computer sleep, then it won't actually sleep.\n"
"\n"
"Click Ctrl+C to unlock...\n"
;

int main() {
    // Stop system from sleeping or turning off monitor
    SetThreadExecutionState(
        ES_CONTINUOUS | ES_AWAYMODE_REQUIRED | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);

    std::cout << prompt << std::endl;

    while (true) {
        // Wait until key C is pressed
        if (_getch() == 3) {
            break;
        }
    }

    return 0;
}
