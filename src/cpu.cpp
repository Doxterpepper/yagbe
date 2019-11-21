#include "cpu.h"

Cpu::Cpu(char* memory) {
  this->memory = memory;
  this->initialize_registers();
}

void Cpu::initialize_registers() {
  reg.af = 0x0001;
  reg.f = 0x00B0;
  reg.bc = 0x0013;
  reg.de = 0x00D8;
  reg.hl = 0x014D;
  reg.sp = 0xFFFE;
  reg.pc = 0x0100;
}

void Cpu::execute() {
  short opcode = reg.pc;
}
