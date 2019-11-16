#ifndef __YAGBE_CPU
#define __YAGBE_CPU

struct cpu_registers {
  // The gameboy can combine specific registers into one 16 bit
  // register, AF, BC, and DE. By using anonymous structs and unions
  // we can emulate this behavior in c++. This lets us access base
  // regusters as register.a, or register.f, but also assign AF and
  // BC like register.af or register.bc.
  union {
    struct {
      unsigned char a;
      unsigned char f;
    };
    unsigned short af;
  };
  union {
    struct {
      unsigned char b;
      unsigned char c;
    };
    unsigned short bc;
  };
  union {
    struct {
      unsigned char d;
      unsigned char e;
    };
    unsigned short de;
  };
  unsigned char h;
  unsigned char l;
  unsigned char flags; // Flags are assigned on a per bit basis
  unsigned short sp;
  unsigned short pc; // Program counter
} extern registers;

class Cpu {
  char* rom_buffer;
  cpu_registers registers;

  public:
    Cpu(const char* rom_buffer);

  private:
    // Initialize registers of the CPU
    void initialize_registers();
};

#endif
