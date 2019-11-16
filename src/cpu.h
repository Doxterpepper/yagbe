#ifndef __YAGBE_CPU
#define __YAGBE_CPU

struct cpu_registers {
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;
  unsigned char e;
  unsigned char f;
  unsigned char h;
  unsigned char l;
  unsigned char flags;
  unsigned char sp;
  unsigned char pc; // Program counter
} extern registers;

class Cpu {
  // Pointer to the rom data. This could change as I learn more about
  // how the gameboy works
  char* rom_buffer;
  cpu_registers registers;

  public:
    // Good old constructor. Takes an array of rom data
    Cpu(const char* rom_buffer);

  private:
};

#endif
