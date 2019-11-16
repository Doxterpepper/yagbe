#include <iostream>
#include <fstream>
#include <SDL.h>

#include "cpu.h"

using namespace std;

// Seeks to the end of a file and sees how many bytes
// that was. Then returns the length of the file.
// Resets the file position to the beginning
unsigned int file_length(ifstream* open_file) {
  if (!open_file->is_open()) {
    return 0;
  }

  open_file->seekg(0, open_file->end);
  int length = open_file->tellg();
  open_file->seekg(0, open_file->beg);

  return length;
}

int main(int argc, char* argv[]) {
  cout << "Yet Another Gameboy Emulator" << endl;

  if (argc < 2) {
    cout << "Please specify a rom" << endl;
    return 1;
  }

  ifstream rom_file(argv[1], ifstream::binary);

  if (!rom_file.is_open()) {
    cout << "Could not open rom file " << argv[1] << endl;
    return 1;
  }

  unsigned int length = file_length(&rom_file);

  cout << "Reading ROM: " << argv[1] << endl;
  cout << "file size: " << length << endl;

  // Read the entire file and store in rom_file
  char rom_buffer[length];
  rom_file.read(rom_buffer, length);
  rom_file.close();

  Cpu gb_cpu(rom_buffer);

  return 0;
}
