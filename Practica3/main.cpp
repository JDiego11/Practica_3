//#include "ManejoArchivos.h"
#include "Method1.h"

int main()
{
    char *Info, *Binario, *Code, *Decode;
    int seed=4;

    //Tamaño del texto
    unsigned long long a = File_Lenght("Information.txt");
    cout << a << endl;

    //Texto original
    Info = ReadFile_Method1("Information.txt");
    for(unsigned long long i=0; i<a; i++) cout << Info[i];
    cout << endl;

    //Texto en binario sin codificar
    Binario = Text2Bin("Information.txt");
    for(unsigned long long i=0; i<(a*8); i++) {
        cout << Binario[i];
        if((i+1)%seed == 0) cout << " ";
    }
    cout << endl;

    //Texto en binario codificado
    Code = Code_1("Information.txt", seed);
    for(unsigned long long i=0; i<(a*8); i++) {
        cout << Code[i];
        if((i+1)%seed == 0) cout << " ";
    }
    cout << endl;

    //Escribir el nuevo archivo
    WriteFIle_Method1("Information.txt", "Code.txt", seed);

    //Texto en binario decodificado
    Decode = DeCode_1("Code.txt", seed);
    for(unsigned long long i=0; i<(a*8); i++) {
        cout << Decode[i];
        if((i+1)%seed == 0) cout << " ";
    }
    cout << endl;


    /*char inputChar;

    cout << "Ingresa un carácter: ";
    cin >> inputChar;

    int asciiValue = static_cast<int>(inputChar);
    cout << "El valor ASCII de '" << inputChar << "' es: " << asciiValue << endl;*/


    return 0;
}
