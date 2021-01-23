/**
 * Yet Another Gameboy Emulator
 * Author: Dock O'Neal
 * Email: mail@dockoneal.com
 * 
 * Implements yet another gameboy emulator in rust.
 */

use std::fs::File;
use std::io::prelude::*;

mod cpu;

fn main() -> std::io::Result<()> {
    // TODO: Add clap to read allow passing file as argument.
    let mut file = File::open("pokemon-red.gb")?;
    let mut rom_buffer = Vec::new();
    file.read_to_end(&mut rom_buffer)?;

    let mut cpu = cpu::Cpu::new(rom_buffer);
    loop {
        cpu.compute();
    }

    Ok(())
}