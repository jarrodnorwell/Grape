#ifndef SPI_H
#define SPI_H

#include <cstdint>
#include <mutex>

class Core;

class Spi {
public:
    Spi(Core *core) : core(core) {}

    ~Spi();

    bool loadFirmware();

    void directBoot();

    void setTouch(int x, int y);

    void clearTouch();

    void sendMicData(const int16_t *samples, size_t count, size_t rate);

    uint16_t readSpiCnt() { return spiCnt; }

    uint8_t readSpiData() { return spiData; }

    void writeSpiCnt(uint16_t mask, uint16_t value);

    void writeSpiData(uint8_t value);

private:
    Core *core;

    uint8_t *firmware = nullptr;
    size_t firmSize = 0;

    int16_t *micBuffer = nullptr;
    size_t micBufSize = 0;
    uint32_t micCycles = 0;
    uint32_t micStep = 0;
    uint16_t micSample = 0;
    std::mutex mutex;

    unsigned int writeCount = 0;
    uint32_t address = 0;
    uint8_t command = 0;

    uint16_t touchX = 0x000, touchY = 0xFFF;
    uint16_t spiCnt = 0;
    uint8_t spiData = 0;

    static uint16_t crc16(uint32_t value, uint8_t *data, size_t size);
};

#endif // SPI_H
