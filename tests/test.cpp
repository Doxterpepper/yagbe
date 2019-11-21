#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "cpu.h"

TEST_CASE("ld_b_n should load 8 bytes into the register b of the CPU", "[CPU]") {
  // Initialize an array of chars all initialized as 0
  char* rom = new char[0x103]();

  // Rom starts at 0x100 for the CPU.
  rom[0x100] = 0x06;
  rom[0x101] = 0x13;

  Cpu cpu(rom);

  delete rom;
}
