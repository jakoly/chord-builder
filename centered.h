#pragma once
#include <string>
#include <vector>
#include <iostream>

std::pair<int,int> getTerminalSize();
void setCursorPos(int x, int y);

// Mehrzeilig zentrieren
inline void printCenteredBlock(const std::vector<std::string>& lines) {
    auto [width, height] = getTerminalSize();

    int blockHeight = (int)lines.size();
    int startY = (height - blockHeight) / 2;

    for (int i = 0; i < blockHeight; ++i) {
        const std::string& line = lines[i];
        int x = (width - (int)line.size()) / 2;
        int y = startY + i;

        setCursorPos(x, y);
        std::cout << line;
    }

    std::cout << std::flush;
}