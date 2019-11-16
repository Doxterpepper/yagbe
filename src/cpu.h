#ifndef __YAGBE_CPU
#define __YAGBE_CPU

class Cpu {
  char* rom_buffer;
  public:
    Cpu(const char* rom_buffer);
};

#endif
