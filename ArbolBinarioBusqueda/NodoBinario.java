/*
 * Autor: Abel Garcia Najera
 * Fecha de creacion: 6 / 09 / 2012
 * Fecha de ultima modificacion: 15 / 04 / 2021
 */

/**
 * Clase NodoBinario que implementa la interfaz INodoBinario.
 *
 * @author Abel
 */
public class NodoBinario {

    private Object datos;
    private NodoBinario hijoIzquierdo;
    private NodoBinario hijoDerecho;

    public NodoBinario(Object datos, NodoBinario hijoIzquierdo, 
            NodoBinario hijoDerecho) {
        this.datos = datos;
        this.hijoIzquierdo = hijoIzquierdo;
        this.hijoDerecho = hijoDerecho;
    }

    public NodoBinario getHijoIzquierdo() {
        return hijoIzquierdo;
    }

    public void setHijoIzquierdo(NodoBinario hijoIzquierdo) {
        this.hijoIzquierdo = hijoIzquierdo;
    }

    public NodoBinario getHijoDerecho() {
        return hijoDerecho;
    }

    public void setHijoDerecho(NodoBinario hijoDerecho) {
        this.hijoDerecho = hijoDerecho;
    }

    public Object getDatos() {
        return datos;
    }

}
