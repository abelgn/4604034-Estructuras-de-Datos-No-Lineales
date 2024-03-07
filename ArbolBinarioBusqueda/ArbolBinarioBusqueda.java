/*
 * Autor: Abel Garcia Najera
 * Fecha de creacion: 7 / 09 / 2012
 * Fecha de ultima modificacion: 26 / 05 / 2020
 */

/**
 * Clase ArbolBinarioBusqueda hereda la clase Arbol e implementa la interfaz
 * IArbolBinarioBusqueda.
 *
 * @author abel
 */
public class ArbolBinarioBusqueda {
    
    private NodoBinario raiz;
    
    public ArbolBinarioBusqueda() {
        raiz = null;
    }


    private int buscar(Object elem, NodoBinario r) {
        if (r == null) {
            return 0;
        } else if (((Comparable) elem).compareTo(r.getDatos()) == 0) {
            return 0;
        } else if (((Comparable) elem).compareTo(r.getDatos()) < 0) {
            return 1 + buscar(elem, r.getHijoIzquierdo());
        } else {
            return 1 + buscar(elem, r.getHijoDerecho());
        }
    }


    public int buscar(Object elem) {
        if (raiz == null) {
            return 0;
        } else {
            return 1 + buscar(elem, raiz);
        }
    }

    private boolean insertar(Object elem, NodoBinario r) {
        if (((Comparable) elem).compareTo(r.getDatos()) == 0) {
            return false;
        } else if (((Comparable) elem).compareTo(r.getDatos()) < 0) {
            if (r.getHijoIzquierdo() != null) {
                return insertar(elem, r.getHijoIzquierdo());
            } else {
                r.setHijoIzquierdo(new NodoBinario(elem, null, null));
                return true;
            }
        } else {
            if (r.getHijoDerecho() != null) {
                return insertar(elem, r.getHijoDerecho());
            } else {
                r.setHijoDerecho(new NodoBinario(elem, null, null));
                return true;
            }
        }
    }


    public boolean insertar(Object elem) {
        if (raiz == null) {
            raiz = new NodoBinario(elem, null, null);
            return true;
        } else {
            return insertar(elem, raiz);
        }
    }

}
