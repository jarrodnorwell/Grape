#ifndef DIV_SQRT_H
#define DIV_SQRT_H

#include <cstdint>

class Core;

class DivSqrt {
public:
    DivSqrt(Core *core) : core(core) {}

    uint16_t readDivCnt() { return divCnt; }

    uint32_t readDivNumerL() { return divNumer; }

    uint32_t readDivNumerH() { return divNumer >> 32; }

    uint32_t readDivDenomL() { return divDenom; }

    uint32_t readDivDenomH() { return divDenom >> 32; }

    uint32_t readDivResultL() { return divResult; }

    uint32_t readDivResultH() { return divResult >> 32; }

    uint32_t readDivRemResultL() { return divRemResult; }

    uint32_t readDivRemResultH() { return divRemResult >> 32; }

    uint16_t readSqrtCnt() { return sqrtCnt; }

    uint32_t readSqrtResult() { return sqrtResult; }

    uint32_t readSqrtParamL() { return sqrtParam; }

    uint32_t readSqrtParamH() { return sqrtParam >> 32; }

    void writeDivCnt(uint16_t mask, uint16_t value);

    void writeDivNumerL(uint32_t mask, uint32_t value);

    void writeDivNumerH(uint32_t mask, uint32_t value);

    void writeDivDenomL(uint32_t mask, uint32_t value);

    void writeDivDenomH(uint32_t mask, uint32_t value);

    void writeSqrtCnt(uint16_t mask, uint16_t value);

    void writeSqrtParamL(uint32_t mask, uint32_t value);

    void writeSqrtParamH(uint32_t mask, uint32_t value);

private:
    Core *core;

    uint16_t divCnt = 0;
    int64_t divNumer = 0;
    int64_t divDenom = 0;
    int64_t divResult = 0;
    int64_t divRemResult = 0;

    uint16_t sqrtCnt = 0;
    uint32_t sqrtResult = 0;
    uint64_t sqrtParam = 0;

    void divide();

    void squareRoot();
};

#endif // DIV_SQRT_H
