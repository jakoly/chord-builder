#include "centered.h"
#include <vector>
#include <iostream>

std::vector<std::string> notes = {
    "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"
};

std::vector<std::string> finalChord(5);

void clearConsole() {
    std::system("cls");
}

void maj(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 4) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
}

void min(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 3) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
}

void dim(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 3) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 6) % 12];
}

void aug(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 4) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 8) % 12];
}

void sus2(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 2) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
}

void sus4(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 5) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
}

void six(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 4) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
    finalChord[3] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 9) % 12];
}

void m6(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 3) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
    finalChord[3] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 9) % 12];
}

void seven(const std::string& root) {
    finalChord[0] = root;
    finalChord[1] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 3) % 12];
    finalChord[2] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 7) % 12];
    finalChord[3] = notes[(std::find(notes.begin(), notes.end(), root) - notes.begin() + 9) % 12];
}

int main() {
    finalChord.clear();
    clearConsole();

    clearConsole();
    printCenteredBlock({
        "Welcome to ChordBuilder!",
        "",
        "A simple chord builder for musicians.",
        "",
        "Enter the root note (e.g., C, D#, F):"
    });

    std::string rootNote;
    rootNote = "";
    std::getline(std::cin, rootNote);

    clearConsole();

    printCenteredBlock({
        "You entered: " + rootNote,
        "",
        "What kind of chord would you like to build?",
        "1. " + rootNote + "maj",
        "2. " + rootNote + "min",
        "3. " + rootNote + "dim",
        "4. " + rootNote + "aug",
        "5. Exit"
        "","","",
    });
    std::string chordChoice;
    std::getline(std::cin, chordChoice);
    if (chordChoice == "1") {
        maj(rootNote);
    } else if (chordChoice == "2") {
        min(rootNote);
    } else if (chordChoice == "3") {
        dim(rootNote);
    } else if (chordChoice == "4") {
        aug(rootNote);
    } else {
        clearConsole();
        printCenteredBlock({
            "Thank you for using ChordBuilder!",
            "",
            "Goodbye!"
        });
        return 0;
    }

    clearConsole();
    printCenteredBlock({
        "The notes in the chord are:",
        "",
        chordChoice,
        "",
        finalChord[0] + " - " + finalChord[1] + " - " + finalChord[2],
        "", "", "",
        "Do you want to build another chord? (y/n)"
        "",
    });

    std::string againChoice;
    std::getline(std::cin, againChoice);
    if (againChoice == "y" || againChoice == "Y") {
        main(); // Restart the program
    } else {
        clearConsole();
        printCenteredBlock({
            "Thank you for using ChordBuilder!",
            "",
            "Goodbye!"
        });
    }


    std::cin.get();
    return 0;
}