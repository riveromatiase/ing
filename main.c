#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



void imprimirMenu(void);

int main()
{
	setbuf(stdout, NULL);
    int option;
    int flagAdd = 0, flagText = 0, flagBin = 0;
//    Passenger pasajero;
    LinkedList* listapasajeros = ll_newLinkedList();

    imprimirMenu();
    do{
    	//utn_getInt(&option,"\nIngrese opcion","\nError",1,10,2);
    	utn_getInt(&option, "Ingrese la opcion\n", "Error\n", 1, 10, 2);
        switch(option)
        {
            case 1://Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
            	if(flagText==0 && flagBin==0)
            	{
            		if(controller_loadFromText("data.csv",listapasajeros)==0)
            		{
            			printf("\nCargado en modo Texto con exito");
            			flagText++;
            		}
            		else
            		{
            			printf("\nError al cargar");
            		}
            	}
            	else
            	{
            		printf("\nLa lista ya fue cargada");
            	}
            	imprimirMenu();
                break;

            case 2://Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
            	if(flagText==0 && flagBin==0)
                {
            		if(controller_loadFromBinary("data_prueba.bin",listapasajeros)==0)
                    {
                    	printf("\nCargado en modo Binario con exito");
                    	flagBin++;
                    }
                    else
                    {
                    	printf("\nError al cargar");
                    }
               	}
                else
                {
                	printf("\nLa lista ya fue cargada");
                }
            	imprimirMenu();
                break;

            case 3://Alta de pasajero
            	if(flagText==1 || flagBin==1)
            	{
            		if(controller_addPassenger(listapasajeros)==0)
            		{
            			printf("\npasajero dado de alta");
            			flagAdd++;
            		}
            		else
            		{
            			printf("\nError al dar de alta");
            		}
            	}
            	else
            	{
            		printf("\nTodavia hay informacion que no fue cargada");
            	}
            	imprimirMenu();
                break;

            case 4://Modificar datos de pasajero
            	if(flagText==1 || flagBin==1 || flagAdd>0)
            	{
            		if(controller_editPassenger(listapasajeros)==0)
            		{
            			printf("\npasajero modificado");
            		}
            		else
            		{
            			printf("\nError al modificar");
            		}
            	}
            	else
            	{
            		printf("\nNo hay datos para modificar");
            	}
            	imprimirMenu();
            	break;

            case 5://Baja de pasajero
            	if(flagText==1 || flagBin==1 || flagAdd>0)
            	{
            		if(controller_removePassenger(listapasajeros)==0)
            		{
            			printf("\npasajero dado de baja");
            		}
            		else
            		{
            			printf("\nError al dar de baja");
            		}
            	}
            	else
            	{
            		printf("\nNo hay datos para dar de baja");
            	}
            	imprimirMenu();
            	break;

            case 6://Listar pasajeros
            	if(flagText==1 || flagBin==1)
            	{
            		controller_ListPassenger(listapasajeros);
            	}
            	else
            	{
            		printf("\nNo hay datos para listar");
            	}
            	imprimirMenu();
                break;

            case 7://Ordenar pasajeros
            	if(flagText==1 || flagBin==1)
            	{
            		controller_sortPassenger(listapasajeros);
            	}
            	else
            	{
            		printf("\nNo hay datos para ordenar");
            	}
            	imprimirMenu();
                break;

            case 8://Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
            	if(flagText==1 || flagBin==1)
            	{
            		controller_saveAsText("data_prueba.csv",listapasajeros);
            	}
            	else
            	{
            		printf("\nNo hay datos para guardar en archivo");
            	}
            	imprimirMenu();
            	break;

            case 9://Guardar los datos de los pasajeros en el archivo data.csv (modo texto)
            	if(flagText==1 || flagBin==1)
            	{
            		controller_saveAsBinary("data_prueba.bin",listapasajeros);
            	}
            	else
            	{
            		printf("\nNo hay datos para guardar en archivo");
            	}
            	imprimirMenu();
            	break;

            case 10://Salir
            	printf("\nSalir");
            	break;
        }
    }while(option != 10);

    return 0;
}

void imprimirMenu (void)
{
	printf("\nMenu:"
     "\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)."
     "\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)."
     "\n3. Alta de pasajero"
     "\n4. Modificar datos de pasajero"
     "\n5. Baja de pasajero"
     "\n6. Listar pasajeros"
     "\n7. Ordenar pasajeros"
     "\n8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)."
     "\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)."
     "\n10. Salir");
}

