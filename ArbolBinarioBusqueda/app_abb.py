import sys
import random
from abb import ArbolBinarioBusqueda as ABB
from math import floor
from statistics import stdev


class AppABB:
    """
    Clase para crear una serie de experimentos. Cada experimento genera un ABB de
    un tamaño fijo n de números enteros. Se buscan m números en el ABB y se registra
    la cantidad de llamadas recursivas realizadas. Al final, calcula el promedio y
    desviación estándar del número de llamadas recursivas.
    """


    def __init__(self, n = 1000, factor = 10, m = 10):
        """
        Método constructor que fija el tamaño del ABB (n), el valor máximo que
        almacenará el ABB y el número de búsquedas que realizará (m).
        """
    
        self.__n = n
        self.__maximo = factor * self.__n
        self.__m = m


    def __generarArbol(self):
        """
        Genera un ABB de tamaño n de números enteros aleatorios.
        """
    
        abb = ABB()
        i = 1
        while i < self.__n:
            # Se genera un número aleatorio entre 1 y máximo
            dato = floor(random.random() * self.__maximo) + 1
            
            # Se intenta insertar el número generado, si ya existe, no se
            # incrementa el contador del tamaño.
            if abb.insertar(dato):
                i = i + 1

        return abb


    def iniciar(self):
        """
        Ejecuta m veces una búsquede en un ABB de tamaño n.
        """
    
        abb = self.__generarArbol()
        llamadas = [None] * self.__m

        for i in range(self.__m):
            # Se genera un número aleatorio entre 1 y máximo
            num = floor(random.random() * self.__maximo) + 1
            print("Buscando: ", num,  end = ";\t")
            
            # Busca el número en el ABB y recupera la cantidad de llamadas
            # recursivas que se hicieron durante la búsqueda.
            llamadas[i] = abb.buscar(num)
            print("Número de llamadas recursivas: ", llamadas[i])
            
        return llamadas



def main(argv):
    miApp = AppABB(int(argv[0]), 10, int(argv[1]))
    llamadas = miApp.iniciar();
    prom = sum(llamadas)/len(llamadas)
    desv = stdev(llamadas)
    print("Resumen:")
    print("Promedio del número de llamadas recursivas:", prom)
    print("Desviación estándar:", desv)


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Sintaxis: app_abb.py <n> <m>")
        print("n: tamaño del árbol")
        print("m: cantidad de números a buscar")
    else:
        main(sys.argv[1:])
