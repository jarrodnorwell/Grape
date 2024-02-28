#ifndef INPUT_H
#define INPUT_H

#include <cstdint>

class Core;

class Input {
public:
    Input(Core *core) : core(core) {}

    void pressKey(int key);

    void releaseKey(int key);

    void pressScreen();

    void releaseScreen();

    uint16_t readKeyInput() { return keyInput; }

    uint16_t readExtKeyIn() { return extKeyIn; }

private:
    Core *core;

    uint16_t keyInput = 0x03FF;
    uint16_t extKeyIn = 0x007F;
};

#endif // INPUT_H
