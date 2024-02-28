#ifndef DMA_H
#define DMA_H

#include <cstdint>
#include <functional>

class Core;

class Dma {
public:
    Dma(Core *core, bool cpu);

    void trigger(int mode, uint8_t channels = 0x0F);

    uint32_t readDmaSad(int channel) { return dmaSad[channel]; }

    uint32_t readDmaDad(int channel) { return dmaDad[channel]; }

    uint32_t readDmaCnt(int channel);

    void writeDmaSad(int channel, uint32_t mask, uint32_t value);

    void writeDmaDad(int channel, uint32_t mask, uint32_t value);

    void writeDmaCnt(int channel, uint32_t mask, uint32_t value);

private:
    Core *core;
    bool cpu;

    uint32_t srcAddrs[4] = {};
    uint32_t dstAddrs[4] = {};
    uint32_t wordCounts[4] = {};

    uint32_t dmaSad[4] = {};
    uint32_t dmaDad[4] = {};
    uint32_t dmaCnt[4] = {};

    std::function<void()> transferTask[4];

    void transfer(int channel);
};

#endif // DMA_H
