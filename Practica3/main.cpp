#include "ManejoArchivos.h"

int main()
{
    char *Info;
    Info = ReadFile_Method1("Information.txt");
    cout << Info << endl;
    cout << File_Lenght("Information.txt") << endl;
    return 0;
}
