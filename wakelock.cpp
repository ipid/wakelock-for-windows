#include <iostream>
#include <conio.h>
#include <windows.h>

int main() {
    // Stop system from sleeping or turning off monitor
    SetThreadExecutionState(
        ES_CONTINUOUS | ES_AWAYMODE_REQUIRED | ES_DISPLAY_REQUIRED | ES_SYSTEM_REQUIRED);

    std::cout << "Wakelock acquired..." << std::endl;
    
    while (true) {
        // Wait until key C is pressed
        if (_getch() == 3) {
            break;
        }
    }

    return 0;
}
