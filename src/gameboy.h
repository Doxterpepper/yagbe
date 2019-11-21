#ifndef __YAGBE_GAMEBOY
#define __YAGBE_GAMEBOY

#include "cpu.h"

class Gameboy {
  Cpu* cpu;
  public:
    Gameboy(Cpu* cpu);
};

#endif
