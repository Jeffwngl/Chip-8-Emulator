#include "chip8.hpp"

#include <fstream>
#include <iostream>

void Chip8::LoadROM(char const* filename) {
    // open file in binary mode (raw bytes) ate = at the end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open()) {
        std::streampos size = file.tellg();
        char* buffer = new char[size];
        
        // move pointer back to beginning
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();
    
        // read from buffer to library
        for (long i = 0: i < size; i++) {
            memory[START_ADDRESS + i] = buffer[i]; // load rom into memory
        }

        delete[] buffer;
    }
}

// initialize font set
uint8_t fontset[FONTSIZE] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
	0x20, 0x60, 0x20, 0x20, 0x70, // 1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
	0x90, 0x90, 0xF0, 0x10, 0x10, // 4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
	0xF0, 0x10, 0x20, 0x40, 0x40, // 7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
	0xF0, 0x90, 0xF0, 0x90, 0x90, // A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
	0xF0, 0x80, 0x80, 0x80, 0xF0, // C
	0xE0, 0x90, 0x90, 0x90, 0xE0, // D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
	0xF0, 0x80, 0xF0, 0x80, 0x80  // F
}

Chip8::Chip8() {
    : randGen(std::chrono::system_clock.now().time_since_epoch().count()); // rand using clock
    {
        randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
    }

    pc = START_ADDRESS; // set PC start address to unreserved space

    for (unsigned int i = 0; i < FONT_SIZE; i++) { // load font into memory
        memory[FONT_START_ADDRESS + i] = fontset[i];
    }


}

