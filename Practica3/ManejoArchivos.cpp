#include "ManejoArchivos.h"

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
string ReadFile_Method2(string file_name) {
    string Text;
    unsigned long long Array_Size;
    ifstream File;
    File.open(file_name, ios::in | ios::binary);    // Abrimos el archivo
    if (File.is_open()) {
        File.seekg(0, ios::end);  // Colocamos el puntero al final del archivo para obtener el tamaño
        Array_Size = File.tellg(); // Obtenemos el tamaño del archivo
        File.seekg(0, ios::beg);  // Volvemos a colocar el puntero al principio del archivo
        Text.resize(Array_Size);  // Redimensionamos el string para acomodar los datos del archivo
        File.read(&Text[0], Array_Size); // Guardamos los datos en el string
        File.close();            // Cerramos el archivo
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
    return Text;
}
