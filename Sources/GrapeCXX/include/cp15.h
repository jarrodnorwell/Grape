#ifndef CP15_H
#define CP15_H

#include <cstdint>

class Core;

class Cp15 {
public:
    Cp15(Core *core) : core(core) {}

    uint32_t read(int cn, int cm, int cp);

    void write(int cn, int cm, int cp, uint32_t value);

    uint32_t getExceptionAddr() { return exceptionAddr; }

    bool getDtcmReadEnabled() { return dtcmReadEnabled; }

    bool getDtcmWriteEnabled() { return dtcmWriteEnabled; }

    bool getItcmReadEnabled() { return itcmReadEnabled; }

    bool getItcmWriteEnabled() { return itcmWriteEnabled; }

    uint32_t getDtcmAddr() { return dtcmAddr; }

    uint32_t getDtcmSize() { return dtcmSize; }

    uint32_t getItcmSize() { return itcmSize; }

private:
    Core *core;

    uint32_t ctrlReg = 0x00000078;
    uint32_t dtcmReg = 0x00000000;
    uint32_t itcmReg = 0x00000000;

    uint32_t exceptionAddr = 0;
    bool dtcmReadEnabled = false, dtcmWriteEnabled = false;
    bool itcmReadEnabled = false, itcmWriteEnabled = false;
    uint32_t dtcmAddr = 0, dtcmSize = 0;
    uint32_t itcmSize = 0;
};

#endif // CP15_H
