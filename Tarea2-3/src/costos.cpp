#include "costos.h"
#include <iostream>
#include <fstream>

using namespace std;

// Tablas de costos globales
int costos_insert[26];
int costos_delete[26];
int costos_sustitucion[26][26];
int costos_transposicion[26][26];

// Función para obtener el costo de inserción de un carácter
// Parámetros:
// − b: carácter a insertar
// Retorno: costo de insertar el carácter b
int getCostoInsercion(char b) {
    return costos_insert[b - 'a'];
}

// Función para obtener el costo de eliminación de un carácter
// Parámetros:
// − a: carácter a eliminar
// Retorno: costo de eliminar el carácter a
int getCostoEliminacion(char a) {
    return costos_delete[a - 'a'];
}

// Función para obtener el costo de sustitución entre dos caracteres
// Parámetros:
// − a: primer carácter
// − b: segundo carácter
// Retorno: costo de sustituir el carácter a por b
int getCostoSustitucion(char a, char b) {
    return costos_sustitucion[a - 'a'][b - 'a'];
}

// Función para obtener el costo de transposición entre dos caracteres
// Parámetros:
// − a: primer carácter
// − b: segundo carácter
// Retorno: costo de transponer los caracteres a y b
int getCostoTransposicion(char a, char b) {
    return costos_transposicion[a - 'a'][b - 'a'];
}

// Función para cargar las tablas de costos desde archivos
void cargarTablasCostos() {
    ifstream archivoInsert("../data/cost_insert.txt");
    ifstream archivoDelete("../data/cost_delete.txt");
    ifstream archivoSustitucion("../data/cost_replace.txt");
    ifstream archivoTransposicion("../data/cost_transpose.txt");

    // Verificar si los archivos se abrieron correctamente
    if (!archivoInsert.is_open()) {
        cout << "Error al abrir cost_insert.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!archivoDelete.is_open()) {
        cout << "Error al abrir cost_delete.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!archivoSustitucion.is_open()) {
        cout << "Error al abrir cost_replace.txt\n";
        exit(EXIT_FAILURE);
    }
    if (!archivoTransposicion.is_open()) {
        cout << "Error al abrir cost_transpose.txt\n";
        exit(EXIT_FAILURE);
    }

    // Cargar los valores de costo de inserción
    int valor, i = 0;
    while (archivoInsert >> valor) {
        costos_insert[i] = valor;
        i++;
    }
    archivoInsert.close();

    // Cargar los valores de costo de eliminación
    i = 0;
    while (archivoDelete >> valor) {
        costos_delete[i] = valor;
        i++;
    }
    archivoDelete.close();

    // Cargar los valores de costo de sustitución
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            archivoSustitucion >> costos_sustitucion[i][j];
        }
    }
    archivoSustitucion.close();

    // Cargar los valores de costo de transposición
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            archivoTransposicion >> costos_transposicion[i][j];
        }
    }
    archivoTransposicion.close();
}
