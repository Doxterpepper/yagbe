#ifndef __YAGBE_CPU
#define __YAGBE_CPU

class Cpu {
  // Pointer to the rom data. This could change as I learn more about
  // how the gameboy works
  char* rom_buffer;

  // CPU registers
  // We will need a private method for setting registers because of the
  // 16 bit gameboy "hack".
  char registers[8] = {
    0, // register a
    0, // register b
    0, // register c
    0, // register d
    0, // register e
    0, // register f
    0, // register h
    0  // register l
  };

  public:
    // Good old constructor. Takes an array of rom data
    Cpu(const char* rom_buffer);
};

#endif
