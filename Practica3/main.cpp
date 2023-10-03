//#include "ManejoArchivos.h"
#include "Method1.h"
#include "Method2.h"


int main() {
    bool salir = false;

    while (!salir) {
        int opcion;
        cout << "Selecciona una opcion:" << endl;
        cout << "1. Metodo 1" << endl;
        cout << "2. Metodo 2" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
            char *Info, *Binario;
            unsigned long long a = File_Lenght("Information.txt") * 8;
            Info = ReadFile_Method1("Information.txt");
            cout << Info << endl;
            cout << File_Lenght("Information.txt") << endl;

            Binario = Text2Bin("Information.txt");
            for(unsigned long long i = 0; i < a; i++) cout << Binario[i];
            cout << endl;
        } else if (opcion == 2) {
            string file_name = "Information.txt"; // Nombre del archivo de entrada
            string file_contents = ReadFile_Method2(file_name);

            if (!file_contents.empty()) {
                cout << "Contenido del archivo:" << endl;
                cout << file_contents << endl;

                string binario = ConvertirABinario(file_contents);
                string codigo = Codificacion(binario);
                string decodificado = Decodificacion(codigo);

                cout << "Representacion binaria: " << binario << endl;
                cout << "Codigo binario codificado: " << codigo << endl;
                cout << "Código binario decodificado: " << decodificado << endl;

                            // Llamar a la función para crear el archivo .dat
                            CrearArchivoDat(decodificado, "Decodificado.dat");
            }
        } else if (opcion == 3) {
            salir = true; // Establecer salir a true para terminar el ciclo
            cout << "Saliendo del programa." << endl;
        } else {
            cout << "Opcion no valida." << endl;
        }
    }

    return 0;
}
