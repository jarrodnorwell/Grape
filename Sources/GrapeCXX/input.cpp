#include "input.h"
#include "core.h"

void Input::pressKey(int key) {
    // Clear key bits to indicate presses
    if (key < 10) // A, B, select, start, right, left, up, down, R, L
        keyInput &= ~BIT(key);
    else if (key < 12) // X, Y
        extKeyIn &= ~BIT(key - 10);
}

void Input::releaseKey(int key) {
    // Set key bits to indicate releases
    if (key < 10) // A, B, select, start, right, left, up, down, R, L
        keyInput |= BIT(key);
    else if (key < 12) // X, Y
        extKeyIn |= BIT(key - 10);
}

void Input::pressScreen() {
    // Clear the pen down bit to indicate a touch press
    extKeyIn &= ~BIT(6);
}

void Input::releaseScreen() {
    // Set the pen down bit to indicate a touch release
    extKeyIn |= BIT(6);
}
