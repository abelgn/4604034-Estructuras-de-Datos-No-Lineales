#include <limits>

void merge(int A[], int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    
    int *L = new int[n1+1];
    int *R = new int[n2+1];
    for (int i = 0; i < n1; i++)
        L[i] = A[inicio+i];
    for (int j = 0; j < n2; j++)
        R[j] = A[medio+1+j];
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    
    int i = 0;
    int j = 0;
    for (int k = inicio; k <= fin; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
    }
    delete [] L;
    delete [] R;
}

void merge_sort(int A[], int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        merge_sort(A, inicio, medio);
        merge_sort(A, medio + 1, fin);
        merge(A, inicio, medio, fin);
    }
}





void intercambiar(int A[], int x, int y) {
    int aux = A[x];
    A[x] = A[y];
    A[y] = aux;
}

int partition(int A[], int p, int r) {
    // A[r] es el registro elegido cuya llave será el pivote
    int pivote = A[r];
    
    // Indica el índice del último registro cuyo valor
    // es menor a pivote
    int ultimo = p - 1;

    // Se agrupan los elementos menores a pivote en las primeras
    // posiciones de A
    for (int i = p; i < r; i++) {
        if (A[i] < pivote) {
            ultimo += 1;
            intercambiar(A, ultimo, i);
        }
    }

    // Y se mueve al pivote a su posición correcta
    intercambiar(A, ultimo + 1, r);
    return ultimo + 1;
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q - 1);
        quicksort(A, q + 1, r);
    }
}



void bubbleDown(int A[], int i, int n) {
    int hijo = 2 * i + 1;
    if (hijo <= n) {
        if ((hijo + 1 <= n) && (A[hijo + 1] > A[hijo]))
            hijo += 1;
        if (A[hijo] > A[i]) {
            intercambiar(A, i, hijo);
            bubbleDown(A, hijo, n);
        }
    }
}


void heapify(int A[], int n) {
    for(int i = (n - 1) / 2; i >= 0; i--)
        bubbleDown(A, i, n);
}


void eliminar_maximo(int A[], int n) {
    intercambiar(A, 0, n);
    bubbleDown(A, 0, n-1);
}

void heap_sort(int A[], int n) {
    heapify(A, n);
    while (n > 0) {
        eliminar_maximo(A, n);
        n--;
    }
}
