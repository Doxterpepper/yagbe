mod registers;

pub struct Cpu {
    rom: Vec<u8>,
    pub registers: registers::Registers,
}

impl Cpu {
    pub fn new(rom: Vec<u8>) -> Cpu {
        Cpu {
            rom: rom,
            registers: registers::Registers::init(),
        }
    }

    pub fn compute(&mut self) {
        let op = self.rom[self.registers.sp as usize];
        match op {
            0xc3 => self.jump(),
            0x00 => self.nop(),
            _ => panic!("op code 0x{:x} not implemented!", op),
        };
    }

    fn jump(&mut self) {
        let first_byte: u16 = self.rom[(self.registers.sp+1) as usize].into();
        let second_byte: u16 = self.rom[(self.registers.sp+2) as usize].into();

        let jump_location: u16 = (first_byte << 8) | second_byte;

        println!("Jumping to 0x{:x}", jump_location);

        self.registers.sp = jump_location;
    }

    fn nop(&mut self) {
        println!("NOP");
        self.registers.sp += 1;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_jump() {
        let mut rom = vec![0;0x103];
        rom[0x100 as usize] = 0xc3;
        rom[0x101 as usize] = 0xff;
        rom[0x102 as usize] = 0xff;
        let mut cpu = Cpu::new(rom);

        cpu.compute();

        println!("{:x}", cpu.registers.sp);

        assert!(cpu.registers.sp == 0xffff);
    }
}