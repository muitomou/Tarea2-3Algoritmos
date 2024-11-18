# Tarea2-3Algoritmos
La carpeta Tarea2-3 funciona como directorio central para el código trabajado.
En ella se encuentran los directorios 
\data\ : es el dir donde tienen que ir los archivos con los costos (cost_delete.txt, cost_insert.txt, cost_replace.txt, cost_transpose.txt)
\src\ : es el dir donde se encuentran los archivos .cpp y los headers
−‘costos.cpp‘ y ‘costos.h‘: Definen las funciones y constantes necesa-
rias para el cálculo de costos en 
−‘ fuerzabruta.cpp‘ y ‘fuerzabruta.h‘: Implementan el algoritmo de fuerza bruta para calcular la distancia de edición. 
-programaciondinamica.cpp‘ y ‘programaciondinami ca.h‘: Contienen la implementación del algoritmo de programación di-námica, que optimiza el cálculo de la distancia de edición mediante el uso de una tabla de cos-tos.
−‘graficosgenerator.py‘: Un script en Python utilizado para generar gráficos con los resultados
obtenidos
−‘tester‘: Archivo utilizado para realizar las pruebas deambos algoritmos y comparar sus tiempos de ejecución.

Como observacion los codigos se pueden probar mediante \.dpmin.exe para dinamica y \.fuerzabruta.exe en la terminal estando en \data\ se pueden probar individualmente y las instrucciones para compilar
el nmain.cpp estan en el pdf, pero basicamente es compilar : g++ nmain.cpp fuerza_bruta.cpp programacion_dinamica.cpp costos.cpp -o tester y luego ejecutando el tester mediante la terminal se introducen las palabras a evaluar y ese programa ya hace el calculo con ambos algoritmos y hace un display mediante la terminal de los tiempos y el resultado :)
