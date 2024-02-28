#pragma once

#include <cstdint>
#include <cstdio>

#include <string>


class CARTRIDGE {
public:
    CARTRIDGE(std::string file_path);

private:
    std::string file_path;

public:
    uint32_t icon[1024];

    uint32_t* GetIcon();
};


class nds_icon {
public:
    nds_icon(std::string path);

    uint32_t *icon() {
        return ico;
    }

private:
    uint32_t ico[32 * 32];
};