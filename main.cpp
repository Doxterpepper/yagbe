#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
  cout << "Yet Another Gameboy Emulator" << endl;

  if (argc < 2) {
    cout << "Please specify a rom" << endl;
    return 1;
  }

  ifstream rom_file(argv[1], ifstream::binary);
  char* rom_buffer;

  // Read rom file to rom_buffer
  if (rom_file.is_open()) {
    // Get length of the file.
    rom_file.seekg(0, rom_file.end);
    int length = rom_file.tellg();
    rom_file.seekg(0, rom_file.beg);

    cout << "Reading ROM: " << argv[1] << endl;
    cout << "file size: " << length << endl;

    // Read the entire file and store in rom_file
    rom_buffer = new char[length];
    rom_file.read(rom_buffer, length);
    rom_file.close();
  }

  delete rom_buffer;

  return 0;
}
