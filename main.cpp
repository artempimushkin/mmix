#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include "Processor.h"
#include "Command.h"

using namespace std;

union Tetrabyte
{
    Tetrabyte():int32(0){};
    byte tetra[4];
    int int32;
    unsigned int uint32;
    float fl;
};

bool loader(Processor &cpu, string filename)
{
    fstream file(filename);
    string str;
    if(!file.is_open()) return false;

    Tetrabyte tetrabyte;
    Octabyte octabyte;

    char tag;                   // сюда читаем тег - первый элемент строки
    unsigned long long address; // сюда читаем адрес €чейки, в которую загружаетс€ число
    int index=0;                // индекс массива пам€ти
    while(!file.eof())
    {
        getline(file, str);
        stringstream stream(str);

        stream >> tag;

        switch(tag)
        {
        case 'c':   // если команда
            stream >> hex >> tetrabyte.uint32; // читаем все в unsigned int, а потом побайтно размещаем
            cpu.memory[index] = tetrabyte.tetra[3];
            cpu.memory[index+1] = tetrabyte.tetra[2];
            cpu.memory[index+2] = tetrabyte.tetra[1];
            cpu.memory[index+3] = tetrabyte.tetra[0];
            index+=4;
            break;
        case 'i':   // если целое число
            stream >> dec >> address;  // читаем адрес €чейки пам€ти
            stream >> octabyte.int64;

            if(octabyte.int64>=-128 && octabyte.int64<128) // такое разбиение сделано дл€ экономии пам€ти, т.е. число умещаетс€ в байт, то зачем занимать и затирать в пам€ти целый октобайт
            {
                cpu.memory[address]=octabyte.octa[0];
            }
            else if(octabyte.int64>=-32768 && octabyte.int64<32768)
            {
                address = ADDR_WYDE(address);
                cpu.memory[address]=octabyte.octa[1];
                cpu.memory[address+1]=octabyte.octa[0];
            }
            else if(octabyte.int64>=-2147483648 && octabyte.int64<2147483648)
            {
                address = ADDR_TETRA(address);
                cpu.memory[address]=octabyte.octa[3];
                cpu.memory[address+1]=octabyte.octa[2];
                cpu.memory[address+2]=octabyte.octa[1];
                cpu.memory[address+3]=octabyte.octa[0];
            }
            else
            {
                address = ADDR_OCTA(address);
                cpu.memory[address]=octabyte.octa[7];
                cpu.memory[address+1]=octabyte.octa[6];
                cpu.memory[address+2]=octabyte.octa[5];
                cpu.memory[address+3]=octabyte.octa[4];
                cpu.memory[address+4]=octabyte.octa[3];
                cpu.memory[address+5]=octabyte.octa[2];
                cpu.memory[address+6]=octabyte.octa[1];
                cpu.memory[address+7]=octabyte.octa[0];
            }
            break;
        case 'f':   // если дробное число
            stream >> dec >> address;  // читаем адрес €чейки пам€ти
            stream >> octabyte.db;

            address = ADDR_OCTA(address);
            cpu.memory[address]=octabyte.octa[7];
            cpu.memory[address+1]=octabyte.octa[6];
            cpu.memory[address+2]=octabyte.octa[5];
            cpu.memory[address+3]=octabyte.octa[4];
            cpu.memory[address+4]=octabyte.octa[3];
            cpu.memory[address+5]=octabyte.octa[2];
            cpu.memory[address+6]=octabyte.octa[1];
            cpu.memory[address+7]=octabyte.octa[0];

            break;
        case 'a':
            stream >> dec >> cpu.IP; // программист «Ќј≈“ когда закончитс€ программа, поэтому написать конечное значение IP не особо сложно
            index = cpu.IP;
            break;
        }
    }
    file.close();
    return true;
}

int main()
{
    Processor cpu;

    cout<<"Write file name:  ";
    string filename;
    cin>>filename;

    if(!loader(cpu, filename))
    {
        cout<<"File doesn't exist\n";
        system("pause");
        return 0;
    }

    cpu.interpretator();

    cout<<"Result: "<<"\n(int) "<<cpu.commonRegisters[0].int64
    <<"\n(double) "<<fixed<<cpu.commonRegisters[0].db
    <<"\n(bytes) "<<hex<<(int)cpu.commonRegisters[0].octa[7]<<" "<<hex<<(int)cpu.commonRegisters[0].octa[6]<<" "
    <<hex<<(int)cpu.commonRegisters[0].octa[5]<<" "<<hex<<(int)cpu.commonRegisters[0].octa[4]<<" "
    <<hex<<(int)cpu.commonRegisters[0].octa[3]<<" "<<hex<<(int)cpu.commonRegisters[0].octa[2]<<" "
    <<hex<<(int)cpu.commonRegisters[0].octa[1]<<" "<<hex<<(int)cpu.commonRegisters[0].octa[0]<<endl;
    system("pause");

    return 0;
}
