//#include "ManejoArchivos.h"
#include "Method1.h"

int main()
{
    char *Info, *Binario;
    Info = ReadFile_Method1("Information.txt");
    cout << Info << endl;
    cout << File_Lenght("Information.txt") << endl;

    Binario = Text2Bin("Information.txt");
    cout << Binario << endl;
    return 0;
}
