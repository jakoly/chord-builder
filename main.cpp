#include "centered.h"
#include <vector>

void clearConsole() {
    std::system("cls");
}

int main() {
    clearConsole();

    printCenteredBlock({
        "Hallo Welt!",
        "",
        "Dies ist ein zentrierter Text.",
        "Mehrere Zeilen funktionieren jetzt."
    });

    std::cin.get();
    return 0;
}