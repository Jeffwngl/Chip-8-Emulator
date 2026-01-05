#pragma once

#include <array>
#include <string>
#include <iostream>
#include <cstdint>
#include <random>

using namespace std;

class Chip8 {
    public:
        constexpr uint16_t START_ADDRESS = 0x200;
        const unsigned int FONTSET_SIZE = 80;
        const unsigned int FONT_START_ADDRESS = 0x50;

        uint8_t registers[16]{};
        uint8_t memory[4096]{};
        uint16_t index{};
        uint16_t pc{};
        uint16_t stack[16]{};
        uint8_t sp{};
        uint8_t delayTimer{};
        uint8_t soundTimer{};
        uint8_t keypad[16]{};
        uint32_t video[64 * 32]{};
        uint16_t opcode;
};
