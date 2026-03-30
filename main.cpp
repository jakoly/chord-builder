#include <iostream>
#include <cstdlib>

void clear() {
    #ifdef _WIN32
    std::system("cls");
    #else
        std::system("clear");
    #endif
}

int main() {
    clear();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}