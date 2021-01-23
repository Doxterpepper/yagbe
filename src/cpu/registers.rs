/// Registers for the CPU.
pub struct Registers {
    // 8 bit registers.
    pub a: u8,
    b: u8,
    c: u8,
    d: u8,
    e: u8,
    h: u8,
    l: u8,

    // Gameboy registers can be grouped to make effectively 16 bit registers.
    // For simplicity we will just maintain a seperate set of 16 bit registers.
    // Some memory is wasted, but it's pretty small in the modern age.
    af: u16,
    bc: u16,
    de: u16,
    hl: u16,

    // Flag registers
    // +-+-+-+-+-+-+-+-+
    // |7|6|5|4|3|2|1|0|
    // |Z|N|H|C|0|0|0|0|
    // +-+-+-+-+-+-+-+-+
    flags: u8,
    pub sp: u16, // Stack Pointer
    pc: u16, // Program counter
}

impl Registers {
    pub fn init() -> Registers {
        Registers {
            a: 0,
            b: 0,
            c: 0,
            d: 0,
            e: 0,
            h: 0,
            l: 0,
            af: 0,
            bc: 0,
            de: 0,
            hl: 0,
            flags: 0,
            sp: 0x100,
            pc: 0,
        }
    }
}