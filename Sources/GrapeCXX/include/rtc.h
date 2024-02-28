#ifndef RTC_H
#define RTC_H

#include <cstdint>

#include "defines.h"

class Core;

class Rtc {
public:
    Rtc(Core *core) : core(core) {}

    void enableGpRtc() { gpRtc = true; }

    void reset();

    uint8_t readRtc();

    uint16_t readGpData();

    uint16_t readGpDirection() { return gpDirection; }

    uint16_t readGpControl() { return gpControl; }

    void writeRtc(uint8_t value);

    void writeGpData(uint16_t value, uint16_t mask);

    void writeGpDirection(uint16_t value, uint16_t mask);

    void writeGpControl(uint16_t value, uint16_t mask);

private:
    Core *core;
    bool gpRtc = false;

    bool csCur = false;
    bool sckCur = false;
    bool sioCur = false;

    uint8_t writeCount = 0;
    uint8_t command = 0;
    uint8_t control = 0;
    uint8_t dateTime[7] = {};

    uint8_t rtc = 0;
    uint16_t gpDirection = 0;
    uint16_t gpControl = 0;

    void updateRtc(bool cs, bool sck, bool sio);

    void updateDateTime();

    bool readRegister(uint8_t index);

    void writeRegister(uint8_t index, bool value);
};

#endif // RTC_H
