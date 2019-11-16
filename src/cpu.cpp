#include "cpu.h"

Cpu::Cpu(const char* rom_buffer) {
  rom_buffer = rom_buffer;
  initialize_registers();
}

// Initialize all registers to their default values
void Cpu::initialize_registers() {
  registers.flags = 0;
  registers.sp = 0xFFFE; // default stack pointer value on a GB
  registers.pc = 0x100; // Initial place in rom to execute
}
