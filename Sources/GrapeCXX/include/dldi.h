#ifndef DLDI_H
#define DLDI_H

#include <cstdint>
#include <cstdio>

class Core;

enum DldiFunc {
    DLDI_START = 0xF0000000,
    DLDI_INSERT,
    DLDI_READ,
    DLDI_WRITE,
    DLDI_CLEAR,
    DLDI_STOP
};

class Dldi {
public:
    Dldi(Core *core) : core(core) {}

    ~Dldi();

    void patchRom(uint8_t *rom, size_t offset, size_t size);

    bool isPatched() { return patched; }

    int startup();

    int isInserted();

    int readSectors(bool cpu, int sector, int numSectors, uint32_t buf);

    int writeSectors(bool cpu, int sector, int numSectors, uint32_t buf);

    int clearStatus();

    int shutdown();

private:
    Core *core;

    bool patched = false;
    FILE *sdImage = nullptr;
};

#endif // DLDI_H
