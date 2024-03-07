import java.util.Random;

/**
 * Clase para crear una serie de experimentos. Cada experimento genera un ABB de
 * un tamaño fijo n de números enteros. Se buscan m números en el ABB y se registra
 * la cantidad de llamadas recursivas realizadas. Al final, calcula el promedio y
 * desviación estándar del número de llamadas recursivas.
 */
public class AppABB {
    
    private static int n;
    private static int maximo;
    private static int m;
    private static int llamadas[];
    private static float promedio;
    private static float desv;
    private static Random aleat;
    
    
    /**
     * Método constructor que fija el tamaño del ABB (n), el valor máximo que
     * almacenará el ABB y el número de búsquedas que realizará (m).
     */
    public AppABB(int n, int factor, int m) {
        this.n = n;
        maximo = n * factor;
        this.m = m;
        llamadas = new int[m];
        promedio = 0.0f;
        desv = 0.0f;
        aleat = new Random();
    }

    
    /**
     * Genera un ABB de tamaño n de números enteros aleatorios.
     */
    private ArbolBinarioBusqueda generarArbol() {
        ArbolBinarioBusqueda abb = new ArbolBinarioBusqueda();
        for (int i = 1; i <= n; i++) {
            int num;
            do {
                // Se genera un número aleatorio entre 1 y máximo
                num = aleat.nextInt(maximo);
                
            // Se sigue intentando la inserción mientras ya exista
            // el número en el árbol.
            } while (!abb.insertar(num));
        }
        return abb;
    }
    

    /**
     * Calcula la desviación estándar del número de llamadas recursivas que se realizaron.
     */
    private float desvst() {
        float dif = 0.0f;
        for (int i = 0; i < m; i++)
            dif += (llamadas[i] - promedio) * (llamadas[i] - promedio);
        return (float) Math.sqrt(dif / m);
    }


    /**
     * Ejecuta m veces una búsquede en un ABB de tamaño n.
     */
    private void iniciar() {
        promedio = 0.0f;
        desv = 0.0f;
        ArbolBinarioBusqueda abb = generarArbol();
        for (int i = 1; i <= m; i++) {
            // Se genera un número aleatorio entre 1 y máximo
            int num = aleat.nextInt(maximo);
            System.out.print("Buscando: " + num + "\t");
            
            // Busca el número en el ABB y recupera la cantidad de llamadas
            // recursivas que se hicieron durante la búsqueda.
            llamadas[i-1] = abb.buscar(num);
            System.out.println("Llamadas recursivas: " + llamadas[i-1]);
            
            promedio += llamadas[i-1];
        }
        promedio /= m;
        desv = desvst();
    }
    
    
    public static void main (String[] args) {
        if (args.length == 2) {
            AppABB miApp = new AppABB(Integer.valueOf(args[0]), 10, Integer.valueOf(args[1]));
            miApp.iniciar();
            System.out.println("Resumen:");
            System.out.println("Promedio de llamadas recursivas: " + promedio);
            System.out.println("Desviación estándar: " + desv);
        }
        else {
            System.out.println("Sintaxis: AppABB <n> <m>");
            System.out.println("n: tamaño del árbol");
            System.out.println("m: cantidad de números a buscar");
        }
    }
}
