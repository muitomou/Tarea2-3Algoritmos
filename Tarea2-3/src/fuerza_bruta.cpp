#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "costos.h"  
using namespace std;


// Función recursiva para calcular la distancia mínima de edición.
// Parámetros:
// − i: índice en la cadena S1
// − j: índice en la cadena S2
// − S1: primera cadena
// − S2: segunda cadena
// Retorno: distancia mínima de edición entre S1 y S2 considerando las operaciones
int fb_minDisEdicion(int i, int j, string& S1, string& S2) {
    if (i == 0) return j;
    if (j == 0) return i;

    if (S1[i - 1] == S2[j - 1]) {
        return fb_minDisEdicion(i - 1, j - 1, S1, S2);
    }

    int costo_min = INT_MAX;

    if (i > 1 && j > 1 && S1[i - 2] == S2[j - 1] && S1[i - 1] == S2[j - 2]) {
        costo_min = min(costo_min, fb_minDisEdicion(i - 2, j - 2, S1, S2) + getCostoTransposicion(S1[i - 2], S1[i - 1]));
    }

    costo_min = min({
    costo_min,
    fb_minDisEdicion(i - 1, j, S1, S2) + getCostoEliminacion(S1[i - 1]),
    fb_minDisEdicion(i, j - 1, S1, S2) + getCostoInsercion(S2[j - 1]),
    fb_minDisEdicion(i - 1, j - 1, S1, S2) + getCostoSustitucion(S1[i - 1], S2[j - 1])
});
    return costo_min;
}

// Función para calcular la distancia mínima de edición entre dos cadenas.
// Parámetros:
// − S1: primera cadena
// − S2: segunda cadena
// Retorno: distancia mínima de edición entre S1 y S2
int obtenerMinDisEdicionFB(string& S1, string& S2) {
    return fb_minDisEdicion(S1.size(), S2.size(), S1, S2);
}

/* int main() {
    // Cargar las tablas de costos
    cargarTablasCostos();

    // Leer las cadenas
    string S1, S2;
    getline(cin, S1);
    getline(cin, S2);

    // Calcular y mostrar el resultado
    int resultado = obtenerMinDisEdicionFB(S1, S2);
    cout << resultado;

    return 0;
} */
