#ifndef METHOD1_H
#define METHOD1_H

#include "ManejoArchivos.h"

//Convertir la información a Binario
char *Char2Bin (int);                   //Recibe el valor ASCII de un caracter y lo convierte a binario
char *Text2Bin(string);                 //Esta función recibe el texto y lo convierte a binario

char *Code_1(string, int);              //Codifica el binario resultante de la función anterior
char *DeCode_1(string, int);            //Decodifica el texto

#endif // METHOD1_H
