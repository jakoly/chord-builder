#include "centered.h"

#ifdef _WIN32
#include <windows.h>

std::pair<int,int> getTerminalSize() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int width  = csbi.srWindow.Right  - csbi.srWindow.Left + 1;
    int height = csbi.srWindow.Bottom - csbi.srWindow.Top  + 1;
    return {width, height};
}

void setCursorPos(int x, int y) {
    COORD pos = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

#else
#include <sys/ioctl.h>
#include <unistd.h>

std::pair<int,int> getTerminalSize() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return {w.ws_col, w.ws_row};
}

void setCursorPos(int x, int y) {
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}
#endif