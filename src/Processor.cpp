#include "Processor.h"
#include "Command.h"

#include <algorithm>

using namespace std;

Processor::Processor()
{
    IP = 0;
    commands[_FCMP] = new FCMP();
    commands[_FADD] = new FADD();
    commands[_FIX] = new FIX();
    commands[_FSUB] = new FSUB();
    commands[_FLOT] = new FLOT();
    commands[_FLOTI] = new FLOTI();
    commands[_FMUL] = new FMUL();
    commands[_FDIV] = new FDIV();
    commands[_FSQRT] = new FSQRT();
    commands[_FINT] = new FINT();
    commands[_MUL] = new MUL();
    commands[_MULI] = new MULI();
    commands[_DIV] = new DIV();
    commands[_DIVI] = new DIVI();
    commands[_ADD] = new ADD();
    commands[_ADDI] = new ADDI();
    commands[_ADDU] = new ADDU();
    commands[_ADDUI] = new ADDUI();
    commands[_SUB] = new SUB();
    commands[_SUBI] = new SUBI();
    commands[_SUBU] = new SUBU();
    commands[_SUBUI] = new SUBUI();
    commands[_CMP] = new CMP();
    commands[_CMPI] = new CMPI();
    commands[_NEG] = new NEG();
    commands[_NEGI] = new NEGI();
    commands[_BN] = new BN();
    commands[_BNB] = new BNB();
    commands[_BZ] = new BZ();
    commands[_BZB] = new BZB();
    commands[_BP] = new BP();
    commands[_BPB] = new BPB();
    commands[_BOD] = new BOD();
    commands[_BODB] = new BODB();
    commands[_BNN] = new BNN();
    commands[_BNNB] = new BNNB();
    commands[_BNZ] = new BNZ();
    commands[_BNZB] = new BNZB();
    commands[_BNP] = new BNP();
    commands[_BNPB] = new BNPB();
    commands[_BEV] = new BEV();
    commands[_BEVB] = new BEVB();
    commands[_CSN] = new CSN();
    commands[_CSNI] = new CSNI();
    commands[_CSZ] = new CSZ();
    commands[_CSZI] = new CSZI();
    commands[_CSP] = new CSP();
    commands[_CSPI] = new CSPI();
    commands[_CSOD] = new CSOD();
    commands[_CSODI] = new CSODI();
    commands[_CSNN] = new CSNN();
    commands[_CSNNI] = new CSNNI();
    commands[_CSNZ] = new CSNZ();
    commands[_CSNZI] = new CSNZI();
    commands[_CSNP] = new CSNP();
    commands[_CSNPI] = new CSNPI();
    commands[_CSEV] = new CSEV();
    commands[_CSEVI] = new CSEVI();
    commands[_ZSN] = new ZSN();
    commands[_ZSNI] = new ZSNI();
    commands[_ZSZ] = new ZSZ();
    commands[_ZSZI] = new ZSZI();
    commands[_ZSP] = new ZSP();
    commands[_ZSPI] = new ZSPI();
    commands[_ZSOD] = new ZSOD();
    commands[_ZSODI] = new ZSODI();
    commands[_ZSNN] = new ZSNN();
    commands[_ZSNNI] = new ZSNNI();
    commands[_ZSNZ] = new ZSNZ();
    commands[_ZSNZI] = new ZSNZI();
    commands[_ZSNP] = new ZSNP();
    commands[_ZSNPI] = new ZSNPI();
    commands[_ZSEV] = new ZSEV();
    commands[_ZSEVI] = new ZSEVI();
    commands[_LDB] = new LDB();
    commands[_LDBI] = new LDBI();
    commands[_LDW] = new LDW();
    commands[_LDWI] = new LDWI();
    commands[_LDT] = new LDT();
    commands[_LDTI] = new LDTI();
    commands[_LDO] = new LDO();
    commands[_LDOI] = new LDOI();
    commands[_LDHT] = new LDHT();
    commands[_LDHTI] = new LDHTI();
    commands[_GO] = new GO();
    commands[_GOI] = new GOI();
    commands[_STB] = new STB();
    commands[_STBI] = new STBI();
    commands[_STW] = new STW();
    commands[_STWI] = new STWI();
    commands[_STT] = new STT();
    commands[_STTI] = new STTI();
    commands[_STO] = new STO();
    commands[_STOI] = new STOI();
    commands[_STHT] = new STHT();
    commands[_STHTI] = new STHTI();
    commands[_STCO] = new STCO();
    commands[_STCOI] = new STCOI();
    commands[_SETH] = new SETH();
    commands[_SETMH] = new SETMH();
    commands[_SETML] = new SETML();
    commands[_SETL] = new SETL();
    commands[_INCH] = new INCH();
    commands[_INCMH] = new INCMH();
    commands[_INCML] = new INCML();
    commands[_INCL] = new INCL();
    commands[_JMP] = new JMP();
    commands[_JMPB] = new JMPB();
    commands[_PUT] = new PUT();
    commands[_STOP] = new STOP();
    commands[_GET] = new GET();

    memory = new byte[65536]();
    memset(commonRegisters, 0, sizeof(commonRegisters)); // обнуляем мессивы регистров
    memset(specialRegisters, 0, sizeof(specialRegisters));
    //fill(commonRegisters, commonRegisters+sizeof(commonRegisters), 0);
    //fill(specialRegisters, specialRegisters+sizeof(specialRegisters), 0);
}

Processor::~Processor()
{
    delete memory;
}

void Processor::reset()
{
    IP = 0;
    memory = new byte[65536];
    memset(commonRegisters, 0, sizeof(commonRegisters)); // обнуляем мессивы регистров
    memset(specialRegisters, 0, sizeof(specialRegisters));
}

void Processor::interpretator()
{
    while(memory[IP] != _STOP)
    {
        bool flag = memory[IP] != _JMP && memory[IP] != _JMPB && memory[IP] != _GO && memory[IP] != _GOI && (memory[IP] <= 0x40 || memory[IP] >= 0x4F);
        commands[memory[IP]]->operator()(*this);
        if(flag) // если нет перехода
            IP += 4;
    }
}
