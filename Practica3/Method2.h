#ifndef METHOD2_H
#define METHOD2_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

unsigned long long File_Lenght(string);
string ReadFile_Method2(string file_name);
string ConvertirABinario(const string& texto);
string Codificacion(const string& binario);
string Decodificacion(const string& codigo);
void CrearArchivoDat(const string& contenido_decodificado, const string& nombre_archivo);

#endif // METHOD2_H
