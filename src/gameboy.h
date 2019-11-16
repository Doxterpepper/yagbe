#ifndef __YAGBE_CPU
#define __YAGBE_CPU

#include "registers.h"

class Gameboy {
  char* rom_buffer;
  cpu_registers registers;

  public:
    Gameboy(const char* rom_buffer);

  private:
    // Initialize registers of the CPU
    void initialize_registers();
};

#endif
