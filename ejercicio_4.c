#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Usted forma parte del equipo de programación que se encargará de hacer el módulo para los preventistas:
//Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo puede pedir hasta 10 productos

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct Producto{
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

struct Cliente{
    int ClienteID; //Numerado en el ciclo iterativo
    char *NombreCliente; //Ingresado por usuario
    int CantidadProductosAPedir; //(aleatorio entre 1 y 5)
    struct Producto *Productos; //El tamaño de este arreglo depende de la variable
    //“CantidadProductosAPedir”
};

float costoTotal(struct Producto Producto);

int main(){
    int cantClientes;
    struct Cliente *clientes; //arreglo clientes
    float costoTotalCliente=0;

    //i)solicite al usuario la cantidad de clientes.
    printf("\nIngrese la cantidad de clientes (hasta 5): \n");
    scanf("%d", &cantClientes);
    fflush(stdin);

    if(cantClientes>0 && cantClientes<=5){
        clientes = malloc(sizeof(struct Cliente) * cantClientes);

        //ii)Solicitar al usuario la carga de los clientes creados dinámicamente
        for (int i = 0; i < cantClientes; i++){
            
            printf("\n-----------Cliente[%i]----------", i+1);
            clientes[i].ClienteID = i+1;
            printf("\nIngrese nombre del cliente: ");
            fflush(stdin);
            clientes[i].NombreCliente = (char *)malloc(sizeof(char)*100);
            gets(clientes[i].NombreCliente);
            fflush(stdin);

            srand(time(NULL)); // Inicialo la semilla para poder generar numeros aleatorios

            //iii) Generar aleatoriamente la cantidad de productos asociados al cliente y sus características
            clientes[i].CantidadProductosAPedir = rand() % 5 + 1; //cantidad de productos aleatoriamente
            
            clientes[i].Productos = (struct Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(struct Producto));//Reservo memoria dinamicamente para Productos
            for (int j=0; j<clientes[i].CantidadProductosAPedir; j++){
               clientes[i].Productos[j].ProductoID = j + 1;
               clientes[i].Productos[j].Cantidad = rand() % 10 + 1;
               clientes[i].Productos[j].TipoProducto = TiposProductos[rand()%5]; 
               clientes[i].Productos[j].PrecioUnitario = rand() % 91 + 10;
            }
        }
    }else{
        printf("\nCantidad de clientes no valida\n");
    }
    
    //v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar 
    //por cliente (sumatoria del costo de todos los productos)
    for (int i=0; i<cantClientes; i++){
        printf("\n-----------Datos Cliente %d----------\n", i+1);
        printf("\nClienteID: %d", clientes[i].ClienteID);
        printf("\nNombre Cliente: %s", clientes[i].NombreCliente);
        printf("\nCantidad de Productos: %d", clientes[i].CantidadProductosAPedir);
        for (int j=0; j<clientes[i].CantidadProductosAPedir; j++){
            printf("\nProductoID: %d\n", clientes[i].Productos[j].ProductoID);
            printf("\nCantidad: %d",  clientes[i].Productos[j].Cantidad);
            printf("\nTipo de Producto: %s", clientes[i].Productos[j].TipoProducto);
            printf("\nPrecio unitario: %.2f",clientes[i].Productos[j].PrecioUnitario);
            costoTotalCliente = costoTotalCliente + costoTotal(clientes[i].Productos[j]);
        }
        printf("\nTotal a Pagar: %.2f\n", costoTotalCliente);
        costoTotalCliente = 0;
    }

    //libero memoria
    for (int i = 0; i < cantClientes; i++){
        free(clientes[i].NombreCliente);
    }
    
    free(clientes);
    
    return 0;
}

//iv) Implemente una función que calcule el costo total de un producto. 
//Esta función debe recibir como parámetro el producto y devolver el resultado 
//de calcular la Cantidad por el PrecioUnitario.

float costoTotal(struct Producto Producto){
    float costo;
    costo = Producto.Cantidad * Producto.PrecioUnitario;
    return costo;
}