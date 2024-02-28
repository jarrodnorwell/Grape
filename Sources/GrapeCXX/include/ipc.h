#ifndef IPC_H
#define IPC_H

#include <cstdint>
#include <queue>

class Core;

class Ipc {
public:
    Ipc(Core *core) : core(core) {}

    uint16_t readIpcSync(bool cpu) { return ipcSync[cpu]; }

    uint16_t readIpcFifoCnt(bool cpu) { return ipcFifoCnt[cpu]; }

    uint32_t readIpcFifoRecv(bool cpu);

    void writeIpcSync(bool cpu, uint16_t mask, uint16_t value);

    void writeIpcFifoCnt(bool cpu, uint16_t mask, uint16_t value);

    void writeIpcFifoSend(bool cpu, uint32_t mask, uint32_t value);

private:
    Core *core;

    std::queue<uint32_t> fifos[2];

    uint16_t ipcSync[2] = {};
    uint16_t ipcFifoCnt[2] = {0x0101, 0x0101};
    uint32_t ipcFifoRecv[2] = {};
};

#endif // IPC_H
