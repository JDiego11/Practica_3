#include "Method2.h"
string ConvertirABinario(const string& texto) {
    string binario;

    for (char caracter : texto) {
        int asciiValue = caracter;

        // Limitar el valor ASCII a 8 bits
        if (asciiValue > 255) {
            asciiValue = 255;
        } else if (asciiValue < 0) {
            asciiValue = 0;
        }

        // Algoritmo para convertir a binario
        for (int i = 7; i >= 0; i--) {
            int bit = (asciiValue >> i) & 1;
            binario += to_string(bit);
        }
    }

    return binario;
}

string Codificacion(const string& binario) {
    string codigo;
    int tamano = binario.length();

    // Separar en bloques de n bits (ajusta n según tus necesidades)
    int n = 4; // Número de bits por bloque

    for (int i = 0; i < tamano; i += n) {
        string bloque = binario.substr(i, n);

        // Aplicar la codificación a cada bloque
        for (int j = n - 1; j >= 0; j--) {
            codigo += bloque[j];
        }
    }

    return codigo;
}

string Decodificacion(const string& codigo) {
    string binario;
    int tamano = codigo.length();

    // Separar en bloques de n bits
    int n = 4; // Número de bits por bloque
    for (int i = 0; i < tamano; i += n) {
        string bloque = codigo.substr(i, n);

        // Aplicar la decodificación a cada bloque
        for (int j = n - 1; j >= 0; j--) {
            binario += bloque[j];
        }
    }

    return binario;
}

void CrearArchivoDat(const string& contenido_decodificado, const string& nombre_archivo) {
    ofstream outfile(nombre_archivo.c_str(), ios::out | ios::binary);
    if (outfile.is_open()) {
        // Convierte la cadena decodificada en una secuencia de bytes
        const char* decodificado_chars = contenido_decodificado.c_str();
        size_t decodificado_size = contenido_decodificado.size();
        outfile.write(decodificado_chars, decodificado_size);
        outfile.close();
        cout << "El archivo " << nombre_archivo << " se ha creado correctamente." << endl;
    } else {
        cerr << "No se pudo crear el archivo " << nombre_archivo << "." << endl;
    }
}
