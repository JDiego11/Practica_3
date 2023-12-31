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
    ///Variables que usaremos para la conversión a binario del texto
    unsigned long long Text_Size, Bin_Txt_Size;     //Tamaño del texto original / tamaño del texto en binario
    Text_Size = File_Lenght(File_Name);             //Con la función File_Length tenemos el tamaño del texto original
    Bin_Txt_Size = Text_Size * 8;                   //Al multiplicar el tamaño del texto por 8, tendremos el tamaño del arreglo de la conversión
    char *Text;// = new char[Text_Size];               //Arreglo para el texto original
    char *CharInBin = new char[8];
    char *TextInBin = new char[Bin_Txt_Size];       //Arreglo para el texto en binario
    int pos;
    Text = ReadFile_Method1(File_Name);

    ///Ciclo para guardar en un arreglo el texto pero en binario
    for(unsigned long long i=0; i<Text_Size; i++) {
        CharInBin = Char2Bin(Text[i]);          //Llamamos la func. que convierte un caracter en binario y almacenamos ese binario
        for (int j=0; j<8; j++) {
            pos = (i*8) + j;                    //Posición que tendrá el arreglo con el texto en binario
            TextInBin[pos] = CharInBin[j];      //Almacenamos el cada carac. (en binario) en el arreglo del texto (en binario)
        }
    }

    ///Liberamos la memoria ocupada por el texto original ya que no la usaremos más
    delete[] Text;
    delete[] CharInBin;

    ///Retorno de la función
    return TextInBin;
}

char *Code_1(string File_Name, int seed) {
    unsigned long long Text_Size;       //Tamaño del texto original
    Text_Size = File_Lenght(File_Name);
    char *TextInBin;                    //Texto en binario
    TextInBin = Text2Bin(File_Name);
    int cont0=0, cont1=0, cont_aux;

    char *Code_Text = new char[Text_Size * 8];

    for (int i=0; i<seed; i++) {
        if(TextInBin[i] == '0') Code_Text[i] = '1';
        else Code_Text[i] = '0';
    }

    for(unsigned long long i=seed; i<(Text_Size*8); i+=seed) {
        cont0 = 0;
        cont1 = 0;
        /*Ciclo para contar la cantidad de 0 y 1 que hay en cada grupo del tamaño de la semilla*/
        for (unsigned long long j=(i-seed); j<i; j++) {
            if (TextInBin[j] == '0') cont0++;
            else cont1++;
        }

        /*Guardar la continuación de la codificación*/
        cont_aux=0;                 //Contador para saber en qué bit hacer el cambio
        for (unsigned long long j=i; j<(i+seed); j++) {
            /*Comparaciones para verificar que paso sigue en la codificación*/
            ///Si hay igual cantidad de 0 y 1
            if (cont0 == cont1) {
                if(TextInBin[j] == '0') Code_Text[j] = '1';
                else Code_Text[j] = '0';
            }
            ///Si hay más 0 que 1
            else if (cont0 > cont1) {
                cont_aux++;
                if (cont_aux == 2) {
                    if(TextInBin[j] == '0') Code_Text[j] = '1';
                    else Code_Text[j] = '0';
                    cont_aux = 0;
                }
                else Code_Text[j] = TextInBin[j];
            }
            ///Si hay más 1 que 0
            else {
                cont_aux++;
                if (cont_aux == 3) {
                    if(TextInBin[j] == '0') Code_Text[j] = '1';
                    else Code_Text[j] = '0';
                    cont_aux = 0;
                }
                else Code_Text[j] = TextInBin[j];
            }
        }
    }

    delete[] TextInBin;
    return Code_Text;
}

char *DeCode_1(string File_Name, int seed)
{
    unsigned long long Text_Size;       //Tamaño del texto original
    Text_Size = File_Lenght(File_Name);
    char *Code_Text;                    //Texto en codificado
    Code_Text = ReadFile_Method1(File_Name);
    int cont0=0, cont1=0, cont_aux=0;

    char *Decode_Text = new char[Text_Size * 8];

    for (int i=0; i<seed; i++) {
        if(Code_Text[i] == '0') Decode_Text[i] = '1';
        else Decode_Text[i] = '0';
    }

    for(unsigned long long i=(seed); i<(Text_Size*8); i+=seed) {
        cont0 = 0;
        cont1 = 0;
        cont_aux=0;                 //Contador para saber en qué bit hacer el cambio
        /*Ciclo para contar la cantidad de 0 y 1 que hay en cada grupo del tamaño de la semilla*/
        for (unsigned long long j=(i-seed); j<i; j++) {
            ///A diferencia de la función para codificar, aquí comparamos con el grupo de bits
            ///anterior pero del arreglo ya decodificado para que se cumpla la misma recla usada
            ///al momento de codificar
            if (Decode_Text[j] == '0') cont0++;
            else cont1++;
        }

        /*Guardar la continuación de la codificación*/
        for (unsigned long long j=i; j<(i+seed); j++) {
            /*Comparaciones para verificar que paso sigue en la codificación*/
            ///Si hay igual cantidad de 0 y 1
            if (cont0 == cont1) {
                if(Code_Text[j] == '0') Decode_Text[j] = '1';
                else Decode_Text[j] = '0';
            }
            ///Si hay más 0 que 1
            else if (cont0 > cont1) {
                cont_aux++;
                if (cont_aux == 2) {
                    if(Code_Text[j] == '0') Decode_Text[j] = '1';
                    else Decode_Text[j] = '0';
                    cont_aux = 0;
                }
                else Decode_Text[j] = Code_Text[j];
            }
            ///Si hay más 1 que 0
            else {
                cont_aux++;
                if (cont_aux == 3) {
                    if(Code_Text[j] == '0') Decode_Text[j] = '1';
                    else Decode_Text[j] = '0';
                    cont_aux = 0;
                }
                else Decode_Text[j] = Code_Text[j];
            }
        }
    }

    delete[] Code_Text;
    return Decode_Text;
}
