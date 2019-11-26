#include <iostream>
#include <fstream>
#include <SDL.h>

#include "gameboy.h"
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

int initialize_window() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    cout << "SDL_Init Error: " << SDL_GetError() << endl;
    return 1;
  }

  SDL_Window* win = SDL_CreateWindow("YAGBE", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

  if (win == nullptr) {
    cout << "SDL_CreateWindow Error: " << SDL_GetError() << endl;
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == nullptr){
    SDL_DestroyWindow(win);
    std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return 1;
  }

  return 0;
}

int main(int argc, char* argv[]) {
  cout << "+------------------------------+" << endl;
  cout << "| Yet Another Gameboy Emulator |" << endl;
  cout << "+------------------------------+" << endl;
  cout << endl;

  if (argc < 2) {
    cout << "Please specify a rom" << endl;
    return 1;
  }
  
  // argv[1] should be a path to the rom file we want to load
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

  Cpu processor(rom_buffer);
  Gameboy gameboy(&processor);

  SDL_Quit();

  return 0;
}
