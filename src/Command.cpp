#include "Command.h"
#include "Processor.h"

Command::Command()
{
    //ctor
}

Command::~Command()
{
    //dtor
}

void SETH::operator()(Processor& cpu)
{
    //cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7] = cpu.memory[cpu.IP+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6] = cpu.memory[cpu.IP+3];
}

void SETMH::operator()(Processor& cpu)
{
    //cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5] = cpu.memory[cpu.IP+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4] = cpu.memory[cpu.IP+3];
}

void SETML::operator()(Processor& cpu)
{
    //cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3] = cpu.memory[cpu.IP+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2] = cpu.memory[cpu.IP+3];
}

void SETL::operator()(Processor& cpu) // установить в регистре младший вайд ($X, YZ)
{
    //cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[cpu.IP+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[cpu.IP+3];
}

void INCH::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[7] = cpu.memory[cpu.IP+2];
    octabyte.octa[6] = cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 += octabyte.uint64;
}

void INCMH::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[5] = cpu.memory[cpu.IP+2];
    octabyte.octa[4] = cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 += octabyte.uint64;
}

void INCML::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[3] = cpu.memory[cpu.IP+2];
    octabyte.octa[2] = cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 += octabyte.uint64;
}

void INCL::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[1] = cpu.memory[cpu.IP+2];
    octabyte.octa[0] = cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 += octabyte.uint64;
}

void LDB::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address];
}

void LDW::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_WYDE(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address+1];
}

void LDT::operator()(Processor& cpu) // загрузить в регистр тетрабайт из памяти ($X, $Y, $Z)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_TETRA(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2] = cpu.memory[address+1];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[address+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address+3];
}

void LDO::operator()(Processor& cpu) // загрузить в регистр октобайт из памяти ($X, $Y, $Z)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_OCTA(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6] = cpu.memory[address+1];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5] = cpu.memory[address+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4] = cpu.memory[address+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3] = cpu.memory[address+4];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2] = cpu.memory[address+5];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[address+6];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address+7];
}

void LDBI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address];
}

void LDWI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_WYDE(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address+1];
}

void LDTI::operator()(Processor& cpu) // загрузить в регистр октобайт из памяти ($X, $Y, Z)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_TETRA(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2] = cpu.memory[address+1];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[address+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address+3];
}

void LDOI::operator()(Processor& cpu) // загрузить в регистр октобайт из памяти ($X, $Y, Z)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_OCTA(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6] = cpu.memory[address+1];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5] = cpu.memory[address+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4] = cpu.memory[address+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3] = cpu.memory[address+4];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2] = cpu.memory[address+5];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1] = cpu.memory[address+6];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0] = cpu.memory[address+7];
}

void LDHT::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_TETRA(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6] = cpu.memory[address+1];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5] = cpu.memory[address+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4] = cpu.memory[address+3];
}

void LDHTI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_TETRA(address);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64=0;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7] = cpu.memory[address];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6] = cpu.memory[address+1];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5] = cpu.memory[address+2];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4] = cpu.memory[address+3];
}

void STB::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STW::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_WYDE(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STT::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_TETRA(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2];
    cpu.memory[address+2] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1];
    cpu.memory[address+3] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STO::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_OCTA(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6];
    cpu.memory[address+2] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5];
    cpu.memory[address+3] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4];
    cpu.memory[address+4] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3];
    cpu.memory[address+5] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2];
    cpu.memory[address+6] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1];
    cpu.memory[address+7] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STBI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STWI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_WYDE(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STTI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_TETRA(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2];
    cpu.memory[address+2] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1];
    cpu.memory[address+3] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STOI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_OCTA(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6];
    cpu.memory[address+2] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5];
    cpu.memory[address+3] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4];
    cpu.memory[address+4] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[3];
    cpu.memory[address+5] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[2];
    cpu.memory[address+6] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[1];
    cpu.memory[address+7] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[0];
}

void STHT::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_TETRA(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6];
    cpu.memory[address+2] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5];
    cpu.memory[address+3] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4];
}

void STHTI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_TETRA(address);
    cpu.memory[address] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[7];
    cpu.memory[address+1] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[6];
    cpu.memory[address+2] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[5];
    cpu.memory[address+3] = cpu.commonRegisters[cpu.memory[cpu.IP+1]].octa[4];
}

void STCO::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    address = ADDR_OCTA(address);
    cpu.memory[address+7] = cpu.memory[cpu.IP+1];
}

void STCOI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (int)cpu.memory[cpu.IP+3];
    address = ADDR_OCTA(address);
    cpu.memory[address+7] = cpu.memory[cpu.IP+1];
}

void ADD::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void ADDI::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 + (__int64)cpu.memory[cpu.IP+3];
}

void ADDU::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
}

void ADDUI::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (unsigned long long)cpu.memory[cpu.IP+3];
}

void SUB::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 - cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void SUBI::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 - (__int64)cpu.memory[cpu.IP+3];
}

void SUBU::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 - cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
}

void SUBUI::operator()(Processor& cpu) // сложить регистр и число ($X, $Y, Z)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].uint64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 - (unsigned long long)cpu.memory[cpu.IP+3];
}

void MUL::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 * cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void MULI::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 * (__int64)cpu.memory[cpu.IP+3];
}

void DIV::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64 != 0)
    {
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 / cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
        cpu.specialRegisters[6].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    }
    else
    {
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
        cpu.specialRegisters[6].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64;
    }

}

void DIVI::operator()(Processor& cpu)
{
    if((__int64)cpu.memory[cpu.IP+3] != 0)
    {
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 / (__int64)cpu.memory[cpu.IP+3];
        cpu.specialRegisters[6].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % (__int64)cpu.memory[cpu.IP+3];
    }
    else
    {
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
        cpu.specialRegisters[6].int64 = (__int64)cpu.memory[cpu.IP+3];
    }

}

void NEG::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+2] + cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void NEGI::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+2] + (__int64)cpu.memory[cpu.IP+3];
}

void CMP::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 > cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64) - (cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 < cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64);
}

void CMPI::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 > cpu.memory[cpu.IP+3]) - (cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 < cpu.memory[cpu.IP+3]);
}

void CSN::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 < 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSNI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 < 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSZ::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSZI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSP::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 > 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSPI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 > 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSOD::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 1)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSODI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 1)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSEV::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSEVI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSNN::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 >= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSNNI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 >= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSNZ::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 != 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSNZI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 != 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void CSNP::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 <= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void CSNPI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 <= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
}

void ZSN::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 < 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 < 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSZ::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSZI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSP::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 > 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSPI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 > 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSOD::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 1)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSODI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 1)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSEV::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSEVI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 % 2 == 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNN::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 >= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNNI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 >= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNZ::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 != 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNZI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 != 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNP::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 <= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void ZSNPI::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+2]].int64 <= 0)
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (__int64)cpu.memory[cpu.IP+3];
    else
        cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = 0;
}

void FADD::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = cpu.commonRegisters[cpu.memory[cpu.IP+2]].db + cpu.commonRegisters[cpu.memory[cpu.IP+3]].db;
}

void FSUB::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = cpu.commonRegisters[cpu.memory[cpu.IP+2]].db - cpu.commonRegisters[cpu.memory[cpu.IP+3]].db;
}

void FMUL::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = cpu.commonRegisters[cpu.memory[cpu.IP+2]].db * cpu.commonRegisters[cpu.memory[cpu.IP+3]].db;
}

void FDIV::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = cpu.commonRegisters[cpu.memory[cpu.IP+2]].db / cpu.commonRegisters[cpu.memory[cpu.IP+3]].db;
}

void FSQRT::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = sqrt(cpu.commonRegisters[cpu.memory[cpu.IP+3]].db);
}

void FINT::operator()(Processor& cpu)
{
    modf(cpu.commonRegisters[cpu.memory[cpu.IP+3]].db, &cpu.commonRegisters[cpu.memory[cpu.IP+1]].db);
}

void FCMP::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = (cpu.commonRegisters[cpu.memory[cpu.IP+2]].db > cpu.commonRegisters[cpu.memory[cpu.IP+3]].db) - (cpu.commonRegisters[cpu.memory[cpu.IP+2]].db < cpu.commonRegisters[cpu.memory[cpu.IP+3]].db);
}

void FIX::operator()(Processor& cpu)
{
    double intpart;
    modf(cpu.commonRegisters[cpu.memory[cpu.IP+3]].db, &intpart);
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = intpart;
}

void FLOT::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = cpu.commonRegisters[cpu.memory[cpu.IP+3]].int64;
}

void FLOTI::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[1] = cpu.memory[cpu.IP+2];
    octabyte.octa[0] = cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].db = octabyte.int64;
}

void JMP::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[2] = cpu.memory[cpu.IP+1];
    octabyte.octa[1] = cpu.memory[cpu.IP+2];
    octabyte.octa[0] = cpu.memory[cpu.IP+3];
    cpu.IP += octabyte.uint64;
}

void JMPB::operator()(Processor& cpu)
{
    Octabyte octabyte;
    octabyte.octa[2] = cpu.memory[cpu.IP+1];
    octabyte.octa[1] = cpu.memory[cpu.IP+2];
    octabyte.octa[0] = cpu.memory[cpu.IP+3];
    cpu.IP -= octabyte.uint64;
}

void GO::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + cpu.commonRegisters[cpu.memory[cpu.IP+3]].uint64;
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.IP + 4;
    cpu.IP = address;
}

void GOI::operator()(Processor& cpu)
{
    unsigned long long address = cpu.commonRegisters[cpu.memory[cpu.IP+2]].uint64 + (__int64)cpu.memory[cpu.IP+3];
    cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 = cpu.IP + 4;
    cpu.IP = address;
}

void BN::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 < 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 < 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BZ::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 == 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BZB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 == 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BP::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 > 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BPB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 > 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BOD::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 % 2 == 1)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BODB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 % 2 == 1)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BEV::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 % 2 == 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BEVB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 % 2 == 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNN::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 >= 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNNB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 >= 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNZ::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 != 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNZB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 != 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNP::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 <= 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP += octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void BNPB::operator()(Processor& cpu)
{
    if(cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 <= 0)
    {
        Octabyte octabyte;
        octabyte.octa[1] = cpu.memory[cpu.IP+2];
        octabyte.octa[0] = cpu.memory[cpu.IP+3];
        cpu.IP -= octabyte.int64;
    }
    else
        cpu.IP += 4;
}

void GET::operator()(Processor& cpu)
{
    cpu.commonRegisters[cpu.memory[cpu.IP+1]] = cpu.specialRegisters[cpu.memory[cpu.IP+3]];
}

void PUT::operator()(Processor& cpu)
{
    Octabyte &reg = cpu.specialRegisters[cpu.memory[cpu.IP+1]];
    if(reg.int64 > 255 || reg.int64 < 32 || reg.int64 < cpu.specialRegisters[20].int64 || (cpu.memory[cpu.IP+1] >= 8 && cpu.memory[cpu.IP+1] <= 18)) return;
    if(cpu.memory[cpu.IP+1] == 20 && cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 > reg.int64) return;
    if(cpu.memory[cpu.IP+1] == 21 && cpu.commonRegisters[cpu.memory[cpu.IP+1]].int64 > 262143) return;

    cpu.specialRegisters[cpu.memory[cpu.IP+1]] = cpu.commonRegisters[cpu.memory[cpu.IP+3]];
}

void STOP::operator()(Processor& cpu)
{

}
