#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
es un mes*/

#define ANIO 5 //filas
#define MES 12 //columnas

int main(){
    int matriz[ANIO][MES];
    srand(time(NULL)); // inicializar el generador de números aleatorios
    
    //a) cargar la matriz con valores aleatorios entre 10000 y 50000
    for (int i=0; i<ANIO; i++){
        for (int j=0; j<MES; j++){
            matriz[i][j] = rand() % 40001 + 10000; //generar números aleatorios entre 10000 y 50000
            //b) mostrar por pantalla los valores cargados
            printf("%d  ", matriz[i][j]);
        }
        printf("\n"); //salto de línea para separar las filas
    }
    
    //c) Saque el promedio de ganancia por año y muestrelos por pantalla
    printf("\nPromedio de ganancia por año:\n");
    for (int i=0; i<ANIO; i++){
        int suma=0;
        for (int j=0; j<MES; j++) {
            suma += matriz[i][j];
        }
        double promedio = (double)suma/MES;
        printf("Año %d: %.2f\n", i+1, promedio);
    }

    //d) Obtenga el valor máximo y mínimo obtenido informando año y mes de cuándo ocurrio
    int maximo = matriz[0][0]; 
    int minimo = matriz[0][0];
    int max_anio=0, max_mes=0;
    int min_anio=0, min_mes=0;

    for (int i=0; i<ANIO; i++) {
        for (int j=0; j<MES; j++) {
            if (matriz[i][j]>maximo){
                maximo = matriz[i][j];
                max_anio = i;
                max_mes = j;
            }
            if (matriz[i][j]<minimo){
                minimo = matriz[i][j];
                min_anio = i;
                min_mes = j;
            }
        }
    }
    
    printf("\nEl valor máximo es %d, obtenido en el mes %d del año %d.\n", maximo, max_mes+1, max_anio+1);
    printf("\nEl valor mínimo es %d, obtenido en el mes %d del año %d.\n", minimo, min_mes+1, min_anio+1);

    return 0;
}