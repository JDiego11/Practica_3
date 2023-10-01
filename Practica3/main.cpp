//#include "ManejoArchivos.h"
#include "Method1.h"

int main()
{
    char *Info, *Binario;
    unsigned long long a = File_Lenght("Information.txt") * 8;
    Info = ReadFile_Method1("Information.txt");
    cout << Info << endl;
    cout << File_Lenght("Information.txt") << endl;

    Binario = Text2Bin("Information.txt");
    for(unsigned long long i=0; i<a; i++) cout << Binario[i];
    cout << endl;

    return 0;
}
