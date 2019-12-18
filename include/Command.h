#ifndef COMMAND_H
#define COMMAND_H

#include "Processor.h"
#include <cmath>

class Command
{
    friend Processor;
    public:
        Command();
        virtual ~Command();
        virtual void operator()(Processor& cpu){};
    protected:
    private:
};

class SETH : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SETMH : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SETML : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SETL : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class INCH : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class INCMH : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class INCML : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class INCL : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDW : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDO : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDBI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDWI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDTI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDOI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDHT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class LDHTI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STW : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STO : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STBI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STWI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STTI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STOI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STHT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STHTI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STCO : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STCOI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ADD : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ADDI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ADDU : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ADDUI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SUB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SUBI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SUBU : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class SUBUI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class MUL : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class MULI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class DIV : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class DIVI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class NEG : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class NEGI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CMP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CMPI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSN : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSZ : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSZI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSPI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSOD : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSODI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSEV : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSEVI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNN : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNNI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNZ : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNZI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class CSNPI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSN : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSZ : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSZI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSPI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSOD : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSODI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSEV : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSEVI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNN : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNNI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNZ : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNZI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class ZSNPI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FADD : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FSUB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FMUL : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FDIV : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FSQRT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FINT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FCMP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FIX : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FLOT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class FLOTI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class JMP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class JMPB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class GO : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class GOI : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BN : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BZ : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BZB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BPB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BOD : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BODB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNN : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNNB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNZ : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNZB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BNPB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BEV : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class BEVB : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class GET : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class PUT : public Command
{
    public: virtual void operator()(Processor& cpu);
};

class STOP : public Command
{
    public: virtual void operator()(Processor& cpu);
};

#endif // COMMAND_H
