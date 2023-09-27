#include "Method1.h"

char *Char2Bin(int Char)            //Recibimos el entero ASCII correspondiente al caracter a convertir
{
    int aux;                        //Auxiliar que guarda 1 o 0
    char *CharInBin = new char[8];  //Arreglo de 8 bits que tendrá el caracter en su representación binaria
    for(int i=0; i<8; i++) {
        aux = Char % 2;             //Hacemos las divisones entre 2 y los residuos serán los bits 1 o 0
        if (aux == 1) CharInBin[7-i] = '1';     //En el caso que el residuo sea 1, lo guardará como caracter
                                                //en la pisición (bit menos significativo) - i del arreglo
        else CharInBin[7-i] = '0';              //En el caso que el residuo sea 0 hará lo mismo solo que guardando
                                                //un 0 en vez de 1
        Char /= 2;                              //Divide el número original para así conseguir el siguiente bit
    }
    return CharInBin;
}

char *Text2Bin(string File_Name)
{
    /*Variables que usaremos para la conversión a binario del texto*/
    unsigned long long Text_Size, Bin_Txt_Size;     //Tamaño del texto original / tamaño del texto en binario
    Text_Size = File_Lenght(File_Name);     //Con la función File_Length tenemos el tamaño del texto original
    Bin_Txt_Size = Text_Size * 8;       //Al multiplicar el tamaño del texto por 8, tendremos el tamaño del arreglo de la conversión
    char *Text; //= new char[Text_Size];       //Arreglo para el texto original
    char *CharInBin = new char[8];
    char *TextInBin = new char[Bin_Txt_Size];       //Arreglo para el texto en binario
    Text = ReadFile_Method1(File_Name);



    //delete Text;      //Liberamos la memoria ocupada por el texto original ya que no la usaremos más
    delete[] CharInBin;
    return TextInBin;
}
