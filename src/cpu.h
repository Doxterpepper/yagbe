#ifndef __YAGBE_CPU
#define __YAGBE_CPU

#include <string>
#include "registers.h"

// Declare the class early because it's referenced in our instruction struct
class Cpu;

// Here we declare our instruction struct. The idea is going to be to have a big 'ol
// table of opcode information within our CPU class. This table will include:
// - std::string disassembly: The disassembly of the opcode for debugging purposes.
// - unsigned char operandLength: The number of bytes the opcode will consume.
// - void (Cpu::*execute)(short): This is a function pointer to the actual code to run for the commands.
struct instruction {
  std::string disassembly;
  unsigned char operandLength;
  void (Cpu::*execute)(short);
};

// Cpu class encapsulates all the internals of the gameboy CPU. Registers and the actual machine code
// functionality will be defined here.
class Cpu {
  char* memory;
  struct cpu_registers reg;
  const struct instruction instructions[256];

  public:
    Cpu(char* memory);
    void execute();

  private:
    void initialize_registers();
    void initialize_memory();

    void undefined(short);

    // Because c++ won't let us use a generic void* to hold all our function pointers, we have to
    // make every opcode implementation take a short even though not all will actually use a short.
    // Some may take no arguments, some may take only one, but a short will hold all of them
    void nop(short);

    // LD nn,n.
    // Put value nn into n.
    // nn = b, c, d, e, h, l
    // n = 8 bit immediate value.
    void ld_b_n(short);
    void ld_c_n(short);
    void ld_d_n(short);
    void ld_e_n(short);
    void ld_h_n(short);
    void ld_l_n(short);

    void ld_r1_r2(short);
};

#endif
