#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Función que crea un archivo
void CreateFile(string) ;

//Funciones para leer el archivo y traer su contenido en un arreglo char para el método 1
unsigned long long File_Lenght(string);         //Almacena la longitud de un archivo
char *ReadFile_Method1(string);

//Función para leer el archivo y traer su contenido en un string para el método 2
//string ReadFile_Method2(string);

//Función para escribir en un archivo
void WriteFIle_Method1(string, string, int);

#endif // MANEJOARCHIVOS_H
