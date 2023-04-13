#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Escriba un programa que solicite un numero fijo de nombres, los cargue en un vector de punteros char y una
vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria)*/


//#define NOMBRES 5
#define LONGITUD 20

int main(){
    int max_nombres;  

    printf("Ingrese la cantidad de nombres a listar: ");
    scanf("%d", &max_nombres);

    char *nombres[max_nombres]; //Vector de punteros para los nombres
    int i;
    
    //Reservar memoria para cada nombre
    for(i=0; i<max_nombres; i++){
        nombres[i] = (char*)malloc(LONGITUD*sizeof(char));
    }
    
    // Solicitar los nombres al usuario
    printf("Ingrese los nombres a listar:\n");
    for(i=0; i<max_nombres; i++){
        scanf("%s", nombres[i]);
    }
    
    // Mostrar los nombres almacenados
    printf("\nLos nombres ingresados son:\n");
    for(i=0; i<max_nombres; i++){
        printf("%s\n", nombres[i]); //forma 1 de listar los nombres
        //puts(nombres[i]);  //forma 2 de listar los nombres
    }
    
    // Liberar memoria reservada
    for(i=0; i<max_nombres; i++){
        free(nombres[i]);
    }
    
    return 0;
}

