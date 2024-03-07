class NodoBinario:

    def __init__ (self, datos, hijoIzquierdo, hijoDerecho):
        self.__datos = datos
        self.__hijoIzquierdo = hijoIzquierdo
        self.__hijoDerecho = hijoDerecho


    def setHijoIzquierdo(self, nodo):
        self.__hijoIzquierdo = nodo


    def setHijoDerecho(self, nodo):
        self.__hijoDerecho = nodo


    def getDatos(self):
        return self.__datos


    def getHijoIzquierdo(self):
        return self.__hijoIzquierdo


    def getHijoDerecho(self):
        return self.__hijoDerecho
        



class ArbolBinarioBusqueda:

    def __init__ (self):
        self.__raiz = None


    def __buscar(self, elem, n):
        if n is None:
            return 0
        if elem == n.getDatos():
            return 0
        elif elem < n.getDatos():
            return 1 + self.__buscar(elem, n.getHijoIzquierdo())
        else:
            return 1 + self.__buscar(elem, n.getHijoDerecho())


    def buscar(self, elem):
        if self.__raiz is None:
            return 0
        else:
            return 1 + self.__buscar(elem, self.__raiz)


    def __insertar(self, elem, r):
        if elem == r.getDatos():
            return False
        elif elem < r.getDatos():
            if r.getHijoIzquierdo() is not None:
                return self.__insertar(elem, r.getHijoIzquierdo())
            else:
                r.setHijoIzquierdo(NodoBinario(elem, None, None))
                return True
        else:
            if r.getHijoDerecho() is not None:
                return self.__insertar(elem, r.getHijoDerecho())
            else:
                r.setHijoDerecho(NodoBinario(elem, None, None))
                return True


    def insertar(self, elem):
        if self.__raiz == None:
            self.__raiz = NodoBinario(elem, None, None)
            return True
        else:
            return self.__insertar(elem, self.__raiz)

