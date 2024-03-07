/**
 CLASE NodoBinario
 */

typedef int T;


class NodoBinario {
private:
    T datos;
    NodoBinario* hijoIzquierdo;
    NodoBinario* hijoDerecho;

public:
    NodoBinario(T datos, NodoBinario* hijoIzquierdo,
                NodoBinario* hijoDerecho);
    NodoBinario* getHijoIzquierdo();
    void setHijoIzquierdo(NodoBinario* hijoIzquierdo);
    NodoBinario* getHijoDerecho();
    void setHijoDerecho(NodoBinario* hijoDerecho);
    T getDatos();
    void setDatos(T datos);
};


NodoBinario::NodoBinario(T d, NodoBinario* hi,
            NodoBinario* hd) {
    datos = d;
    hijoIzquierdo = hi;
    hijoDerecho = hd;
}


NodoBinario* NodoBinario::getHijoIzquierdo() {
    return hijoIzquierdo;
}


void NodoBinario::setHijoIzquierdo(NodoBinario* hi) {
    hijoIzquierdo = hi;
}


NodoBinario* NodoBinario::getHijoDerecho() {
    return hijoDerecho;
}


void NodoBinario::setHijoDerecho(NodoBinario* hd) {
    hijoDerecho = hd;
}


T NodoBinario::getDatos() {
    return datos;
}


void NodoBinario::setDatos(T d) {
    datos = d;
}





/**
 CLASE ArbolBinarioBusqueda
 */


class ArbolBinarioBusqueda {
private:
    NodoBinario* raiz;
    void recuperar(NodoBinario* r);
    int buscar(T elem, NodoBinario* r);
    bool insertar(T elem, NodoBinario* r);

public:
    ArbolBinarioBusqueda();
    ~ArbolBinarioBusqueda();
    int buscar(T elem);
    bool insertar(T elem);
};


ArbolBinarioBusqueda::ArbolBinarioBusqueda() {
    raiz = NULL;
}


ArbolBinarioBusqueda::~ArbolBinarioBusqueda() {
    recuperar(raiz);
}


void ArbolBinarioBusqueda::recuperar(NodoBinario* r) {
    if (r != NULL) {
        recuperar(r->getHijoIzquierdo());
        recuperar(r->getHijoDerecho());
        delete r;
    }
}


int ArbolBinarioBusqueda::buscar(T elem, NodoBinario* r) {
    if (r == NULL) {
        return 0;
    } else if (elem == r->getDatos()) {
        return 0;
    } else if (elem < r->getDatos()) {
        return 1 + buscar(elem, r->getHijoIzquierdo());
    } else {
        return 1 + buscar(elem, r->getHijoDerecho());
    }
}


int ArbolBinarioBusqueda::buscar(T elem) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + buscar(elem, raiz);
    }
}


bool ArbolBinarioBusqueda::insertar(T elem, NodoBinario* r) {
    if (elem == r->getDatos()) {
        return false;
    } else if (elem < r->getDatos()) {
        if (r->getHijoIzquierdo() != NULL) {
            return insertar(elem, r->getHijoIzquierdo());
        } else {
            r->setHijoIzquierdo(new NodoBinario(elem, NULL, NULL));
            return true;
        }
    } else {
        if (r->getHijoDerecho() != NULL) {
            return insertar(elem, r->getHijoDerecho());
        } else {
            r->setHijoDerecho(new NodoBinario(elem, NULL, NULL));
            return true;
        }
    }
}


bool ArbolBinarioBusqueda::insertar(T elem) {
    if (raiz == NULL) {
        raiz = new NodoBinario(elem, NULL, NULL);
        return true;
    } else {
        return insertar(elem, raiz);
    }
}
