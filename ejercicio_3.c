#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria)*/


#define NOMBRES 5
#define LONGITUD 20

int main(){
    char *nombres[NOMBRES]; // Vector de punteros
    int i;
    
    //Reservar memoria para cada nombre
    for(i=0; i<NOMBRES; i++){
        nombres[i] = (char*)malloc(LONGITUD*sizeof(char));
    }
    
    // Solicitar los nombres al usuario
    printf("Ingrese 5 nombres:\n");
    for(i=0; i<NOMBRES; i++){
        scanf("%s", nombres[i]);
    }
    
    // Mostrar los nombres almacenados
    printf("\nLos nombres ingresados son:\n");
    for(i=0; i<NOMBRES; i++){
        printf("%s\n", nombres[i]); //forma 1
        puts(nombres[i]);  //forma 2
    }
    
    // Liberar memoria reservada
    for(i=0; i<NOMBRES; i++){
        free(nombres[i]);
    }
    
    return 0;
}
