#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdlib.h>
#include <cstring>

typedef unsigned char byte;

// для нахождения адреса (подробнее у Кнута стр 12)
#define ADDR_WYDE(addr) (addr) - ((addr) % 2)
#define ADDR_TETRA(addr) (addr) - ((addr) % 4)
#define ADDR_OCTA(addr) (addr) - ((addr) % 8)

enum Opcode {
    _FCMP = 0x01, _FADD = 0x04, _FIX = 0x05, _FSUB = 0x06, _FLOT = 0x08, _FLOTI = 0x09,
    _FMUL = 0x10, _FDIV = 0x14, _FSQRT = 0x15, _FINT = 0x17, _MUL = 0x18, _MULI = 0x19, _DIV = 0x1C, _DIVI = 0x1D,
    _ADD = 0x20, _ADDI = 0x21, _ADDU = 0x22, _ADDUI = 0x23, _SUB = 0x24, _SUBI = 0x25, _SUBU = 0x26, _SUBUI = 0x27,
    _CMP = 0x30, _CMPI = 0x31, _NEG = 0x34, _NEGI = 0x35,
    _BN = 0x40, _BNB = 0x41, _BZ = 0x42, _BZB = 0x43, _BP = 0x44, _BPB = 0x45, _BOD = 0x46, _BODB = 0x47, _BNN = 0x48, _BNNB = 0x49, _BNZ = 0x4A, _BNZB = 0x4B, _BNP = 0x4C, _BNPB = 0x4D, _BEV = 0x4E, _BEVB = 0x4F,
    _CSN = 0x60, _CSNI = 0x61, _CSZ = 0x62, _CSZI = 0x63, _CSP = 0x64, _CSPI = 0x65, _CSOD = 0x66, _CSODI = 0x67, _CSNN = 0x68, _CSNNI = 0x69, _CSNZ = 0x6A, _CSNZI = 0x6B, _CSNP = 0x6C, _CSNPI = 0x6D, _CSEV = 0x6E, _CSEVI = 0x6F,
    _ZSN = 0x70, _ZSNI = 0x71, _ZSZ = 0x72, _ZSZI = 0x73, _ZSP = 0x74, _ZSPI = 0x75, _ZSOD = 0x76, _ZSODI = 0x77, _ZSNN = 0x78, _ZSNNI = 0x79, _ZSNZ = 0x7A, _ZSNZI = 0x7B, _ZSNP = 0x7C, _ZSNPI = 0x7D, _ZSEV = 0x7E, _ZSEVI = 0x7F,
    _LDB = 0x80, _LDBI = 0x81, _LDW = 0x84, _LDWI = 0x85, _LDT = 0x88, _LDTI = 0x89, _LDO = 0x8C, _LDOI = 0x8D,
    _LDHT = 0x92, _LDHTI = 0x93, _GO = 0x9E, _GOI = 0x9F,
    _STB = 0xA0, _STBI = 0xA1, _STW = 0xA4, _STWI = 0xA5, _STT = 0xA8, _STTI = 0xA9, _STO = 0xAC, _STOI = 0xAD,
    _STHT = 0xB2, _STHTI = 0xB3, _STCO = 0xB4, _STCOI = 0xB5,
    _SETH = 0xE0, _SETMH = 0xE1, _SETML = 0xE2, _SETL = 0xE3, _INCH = 0xE4, _INCMH = 0xE5, _INCML = 0xE6, _INCL = 0xE7,
    _JMP = 0xF0, _JMPB = 0xF1, _PUT = 0xF6, _STOP = 0xF9, _GET = 0xFE
};

union Octabyte
{
    Octabyte():int64(0){};
    byte octa[8];
    long long int64;
    unsigned long long uint64;
    double db;
};

class Command;

class Processor
{
    public:
        byte* memory;                   // указатель на память
        unsigned long long IP;          // указатель на инструкцию
        Octabyte commonRegisters[256];  // регистры общего назначения
        Octabyte specialRegisters[32];  // регистры специального назначения
        Command* commands[256];

        void interpretator();           // интерпретатор
        void reset();

        Processor();
        virtual ~Processor();
    protected:
    private:

};

#endif // PROCESSOR_H
