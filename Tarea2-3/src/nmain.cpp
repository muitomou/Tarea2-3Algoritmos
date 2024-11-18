#include <iostream>
#include <string>
#include <chrono>  // Para medir el tiempo de ejecución
#include "costos.h"  // Incluir las definiciones de las funciones y variables globales
#include "fuerza_bruta.h"  // Para la función de Fuerza Bruta
#include "programacion_dinamica.h"  // Para la función de Programación Dinámica

using namespace std;
using namespace chrono;

// Función para ejecutar el algoritmo de Fuerza Bruta y medir el tiempo de ejecución
// Parámetros:
// − S1: primera cadena
// − S2: segunda cadena
// Retorno: ninguno
void ejecutarFuerzaBruta(string& S1, string& S2) {
    auto inicio = high_resolution_clock::now();  // Medir el tiempo al inicio
    
    int resultado = obtenerMinDisEdicionFB(S1, S2);  // Llamada a la función de Fuerza Bruta
    
    auto fin = high_resolution_clock::now();  // Medir el tiempo al final
    auto duracion = duration_cast<microseconds>(fin - inicio);  // Calcular la duración
    
    cout << "Resultado (Fuerza Bruta): " << resultado << endl;
    cout << "Tiempo de ejecución (Fuerza Bruta): " << duracion.count() << " microsegundos" << endl;
}

// Función para ejecutar el algoritmo de Programación Dinámica y medir el tiempo de ejecución
// Parámetros:
// − S1: primera cadena
// − S2: segunda cadena
// Retorno: ninguno
void ejecutarProgramacionDinamica(string& S1, string& S2) {
    auto inicio = high_resolution_clock::now();  // Medir el tiempo al inicio
    
    int resultado = obtenerMinDisEdicionDP(S1, S2);  // Llamada a la función de Programación Dinámica
    
    auto fin = high_resolution_clock::now();  // Medir el tiempo al final
    auto duracion = duration_cast<microseconds>(fin - inicio);  // Calcular la duración
    
    cout << "Resultado (Programación Dinámica): " << resultado << endl;
    cout << "Tiempo de ejecución (Programación Dinámica): " << duracion.count() << " microsegundos" << endl;
}

int main() {
    // Leer las cadenas
    string S1, S2;
    cout << "Ingrese la primera cadena: ";
    getline(cin, S1);
    cout << "Ingrese la segunda cadena: ";
    getline(cin, S2);

    // Cargar las tablas de costos (deben estar definidas en costos.cpp)
    cargarTablasCostos();

    // Ejecutar los algoritmos y medir su tiempo de ejecución
    cout << "\nEjecutando el algoritmo de Fuerza Bruta...\n";
    ejecutarFuerzaBruta(S1, S2);

    cout << "\nEjecutando el algoritmo de Programación Dinámica...\n";
    ejecutarProgramacionDinamica(S1, S2);

    return 0;
}


// Compilar : g++ nmain.cpp fuerza_bruta.cpp programacion_dinamica.cpp costos.cpp -o tester