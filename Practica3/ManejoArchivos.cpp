#include "ManejoArchivos.h"
#include "Method1.h"

void CreateFile(string name/*, string path*/)                    //Creamos/abrimos el archivo en la carpeta del proyecto
{                                               //Porque no le dimos una dirección
    fstream file;
    file.open(/*path + "/" + */name, ios::out);
    file.close();                               //cerrar el archivo al dejar de usarlo
}

unsigned long long File_Lenght(string file_name)
{
    unsigned long long F_Size = 0;
    fstream File;
    File.open(file_name, ios::in | ios::ate | ios::binary);    //Abrimos el archivo con el cursor al final
    if(File.is_open()) {
        F_Size = File.tellg();          //Vemos la posición del cursor (dónde termina el archivo) y la guardamos como entero
        File.close();                   //Cerramos el archivo
    }
    else cout << "No se pudo abrir el archivo al momento de calcular la cantidad de caracteres." << endl;
    return F_Size;
}

char *ReadFile_Method1(string file_name)
{
    char *Text = NULL;                  //Arreglo donde se guardará la información del archivo
    unsigned long long Array_Size;
    fstream File;
    File.open(file_name, ios::in | ios::binary);    //Abrimos el archivo
    if(File.is_open()) {
        Array_Size = File_Lenght(file_name);    //Usamos la función de longitud de un archivo y lo guardamos en la variable
        Text = new char[Array_Size];            //Creamos el arreglo del tamaño que ocupará la info del archivo
        File.read(Text, Array_Size);            //Guardamos la data en el arreglo
        File.close();                           //Cerramos el archivo
    }
    else cout << "No se pudo abrir el archivo" << endl;

    File.close();
    return Text;
}

void WriteFIle_Method1(string Origin_File, string file_name, int seed)
{
    fstream File;
    File.open(file_name, ios::out);

    unsigned long long Cod_size;
    Cod_size = File_Lenght(Origin_File) * 8;

    char *info = Code_1(Origin_File, seed);

    for (unsigned long long i=0; i<Cod_size; i++) {
        File << info[i];
    }

    File.close();
}
