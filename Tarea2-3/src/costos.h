#ifndef COSTOS_H
#define COSTOS_H

extern int costos_insert[26];
extern int costos_delete[26];
extern int costos_sustitucion[26][26];
extern int costos_transposicion[26][26];

int getCostoInsercion(char b);
int getCostoEliminacion(char a);
int getCostoSustitucion(char a, char b);
int getCostoTransposicion(char a, char b);
void cargarTablasCostos();

#endif // COSTOS_H
