import matplotlib.pyplot as plt

# Para replicar el experimento, ingrese los datos en las tuplas correspondientes en las siguientes líneas:
# Líneas 4, 5, 6 y 7.
entradas = [("", ""), ("cpp", "csv"), ("sooool", "soolool"), ("algoritmo", "aglotirmo"), ("hiperdivergente", "megaconvergente")]
tamanos = [(0, 0), (3, 3), (6, 7), (9, 9), (15, 15)]
tiempos_fuerza_bruta = [0, 3.30, 3.00, 120.70, 1632.60]
tiempos_programacion_dinamica = [5.60, 7.10, 10.00, 14.70, 44.20]

tamanos_totales = [sum(tamano) for tamano in tamanos]

plt.figure(figsize=(8,6))

plt.scatter(tamanos_totales, tiempos_fuerza_bruta, color='blue', label='Fuerza Bruta', marker='o')
plt.scatter(tamanos_totales, tiempos_programacion_dinamica, color='red', label='Programación Dinámica', marker='x')

plt.xlabel('Tamaño de Entrada (|s1| + |s2|)', fontsize=12)
plt.ylabel('Tiempo Promedio (µs)', fontsize=12)
plt.title('Tiempo vs. Tamaño de entrada DMEE ', fontsize=14)

plt.legend()

plt.grid(True)


plt.savefig('grafico_tiempovslargo.png', format='png')

plt.show()
