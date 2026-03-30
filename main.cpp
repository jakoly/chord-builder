#include "centered.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <limits>

// -------------------------
// NOTES
// -------------------------
std::vector<std::string> notes = {
    "C", "C#", "D", "D#", "E", "F",
    "F#", "G", "G#", "A", "A#", "B"
};

// -------------------------
// CHORD DATABASE
// -------------------------
std::map<std::string, std::vector<int>> chords = {

    {"maj",  {0, 4, 7}},
    {"min",  {0, 3, 7}},
    {"dim",  {0, 3, 6}},
    {"aug",  {0, 4, 8}},

    {"sus2", {0, 2, 7}},
    {"sus4", {0, 5, 7}},

    {"6",  {0, 4, 7, 9}},
    {"m6", {0, 3, 7, 9}},

    {"7",        {0, 4, 7, 10}},
    {"maj7",     {0, 4, 7, 11}},
    {"m7",       {0, 3, 7, 10}},
    {"m(maj7)",  {0, 3, 7, 11}},
    {"dim7",     {0, 3, 6, 9}},
    {"m7b5",     {0, 3, 6, 10}},

    {"9",    {0, 4, 7, 10, 14}},
    {"maj9", {0, 4, 7, 11, 14}},
    {"m9",   {0, 3, 7, 10, 14}},

    {"11",   {0, 4, 7, 10, 14, 17}},
    {"13",   {0, 4, 7, 10, 14, 17, 21}}
};

// -------------------------
// CHORD BUILDER
// -------------------------
std::vector<std::string> buildChord(
    const std::string& root,
    const std::vector<int>& intervals)
{
    auto it = std::find(notes.begin(), notes.end(), root);
    if (it == notes.end()) return {"Invalid root"};

    int rootIndex = static_cast<int>(it - notes.begin());

    std::vector<std::string> result;
    result.reserve(intervals.size());

    for (int interval : intervals) {
        int noteIndex = (rootIndex + interval) % 12;
        if (noteIndex < 0) noteIndex += 12;
        result.push_back(notes[noteIndex]);
    }

    return result;
}

// -------------------------
void clearConsole() {
    std::system("cls"); // Linux/macOS: "clear"
}

// -------------------------
// PRINT IN COLUMNS
// -------------------------
void printInColumns(const std::vector<std::string>& items, int columns) {

    int colWidth = 20;

    for (size_t i = 0; i < items.size(); i++) {

        std::string text =
            std::to_string(i + 1) + ". " + items[i];

        std::cout << text;

        int padding = colWidth - (int)text.size();
        if (padding < 1) padding = 1;

        std::cout << std::string(padding, ' ');

        if ((i + 1) % columns == 0)
            std::cout << "\n";
    }

    std::cout << "\n";
}

// -------------------------
int main() {

    while (true) {
        clearConsole();

        printCenteredBlock({
            "ChordBuilder",
            "",
            "Enter root note (C, C#, D, ...):"
        });

        std::string rootNote;
        std::getline(std::cin, rootNote);

        clearConsole();

        // -------------------------
        // build key list
        // -------------------------
        std::vector<std::string> keys;
        for (auto& [name, _] : chords) {
            keys.push_back(name);
        }

        printCenteredBlock({
            "Choose chord type:",
            ""
        });

        // 4 columns layout
        printInColumns(keys, 4);

        std::cout << "Enter number: ";

        std::string input;
        std::getline(std::cin, input);

        int selected;
        try {
            selected = std::stoi(input) - 1;
        } catch (...) {
            continue;
        }

        if (selected < 0 || selected >= (int)keys.size())
            continue;

        std::string chordName = keys[selected];

        std::vector<std::string> chord =
            buildChord(rootNote, chords[chordName]);

        std::string chordText;
        for (size_t i = 0; i < chord.size(); i++) {
            chordText += chord[i];
            if (i < chord.size() - 1) chordText += " - ";
        }

        clearConsole();

        printCenteredBlock({
            "Chord result:",
            "",
            chordText,
            "",
            "Press ENTER..."
        });

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}