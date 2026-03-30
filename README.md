# ChordBuilder

A simple console-based C++ chord generator using interval arithmetic and a 12-tone chromatic system.

---

## 📌 Overview

ChordBuilder generates chords from a given root note using predefined chord formulas.

Chromatic scale:

```
C, C#, D, D#, E, F, F#, G, G#, A, A#, B
```

---

## 🎼 Supported Chords

### Triads

* maj
* min
* dim
* aug
* sus2
* sus4

### 6th Chords

* 6
* m6

### 7th Chords

* 7 (dominant)
* maj7
* m7
* m(maj7)
* dim7
* m7b5 (half-diminished)
* 7#5
* maj7#5
* 7b5

### Add Chords

* add9
* madd9
* add11
* add13

### 9th Chords

* 9
* maj9
* m9
* m(maj9)
* 7b9
* 7#9

### 11th Chords

* 11
* maj11
* m11
* 7#11

### 13th Chords

* 13
* maj13
* m13
* 7b13

### Suspended Extensions

* 7sus4
* 9sus4
* 13sus4

### Altered Dominants

* 7alt
* 7b9#11
* 7#9#11

---

## ⚙️ How It Works

Each chord is built by mapping the root note to a chromatic index and applying semitone offsets.

### Core formula

```
notes[(index + interval) % 12]
```

Example (C major):

* C = index 0
* E = +4
* G = +7

Result:

```
C - E - G
```

---


## 🖥️ User Flow

1. Start program
2. Enter root note
3. Select chord type
4. Program outputs chord tones

---

## 📦 Build Instructions

### Windows

```bash
clang++ -std=c++17 -fuse-ld=lld main.cpp centered.cpp -o main.exe
```
