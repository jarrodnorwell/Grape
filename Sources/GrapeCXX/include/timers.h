#ifndef TIMERS_H
#define TIMERS_H

#include <cstdint>
#include <functional>

class Core;

class Timers {
public:
    Timers(Core *core, bool cpu);

    void resetCycles();

    uint16_t readTmCntH(int timer) { return tmCntH[timer]; }

    uint16_t readTmCntL(int timer);

    void writeTmCntL(int timer, uint16_t mask, uint16_t value);

    void writeTmCntH(int timer, uint16_t mask, uint16_t value);

private:
    Core *core;
    bool cpu;

    uint16_t timers[4] = {};
    uint8_t shifts[4] = {};
    uint32_t endCycles[4] = {};

    uint16_t tmCntL[4] = {};
    uint16_t tmCntH[4] = {};

    std::function<void()> overflowTask[4];

    void overflow(int timer);
};

#endif // TIMERS_H
