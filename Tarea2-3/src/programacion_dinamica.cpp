#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "costos.h"  

using namespace std;

// Función para calcular la distancia mínima de edición entre dos cadenas usando programación dinámica
// Parámetros:
// − S1: primera cadena
// − S2: segunda cadena
// Retorno: distancia mínima de edición entre S1 y S2
int obtenerMinDisEdicionDP(string& S1, string& S2) {
    int m = S1.size();
    int n = S2.size();
    
    // Crear una matriz dp de dimensiones (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Inicializar la primera fila y columna
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    // Llenar la matriz dp calculando los costos de edición
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Si los caracteres son iguales, no se necesita costo
            } else {
                dp[i][j] = min({dp[i - 1][j] + getCostoEliminacion(S1[i - 1]),  // Costo por eliminación
                                dp[i][j - 1] + getCostoInsercion(S2[j - 1]),    // Costo por inserción
                                dp[i - 1][j - 1] + getCostoSustitucion(S1[i - 1], S2[j - 1])});  // Costo por sustitución

                // Verificar transposición de caracteres adyacentes
                if (i > 1 && j > 1 && S1[i - 1] == S2[j - 2] && S1[i - 2] == S2[j - 1]) {
                    dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + getCostoTransposicion(S1[i - 2], S1[i - 1]));
                }
            }
        }
    }

    return dp[m][n];
}
