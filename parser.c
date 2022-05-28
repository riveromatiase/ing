#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	Passenger* pasajero;
	char id;
	char nombre[50];
	char apellido[50];
	char codigoDeVuelo[10];
	char tipoPasajero;
	char estadoVuelo;
	int isEmpty;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,tipoPasajero,estadoVuelo, codigoDeVuelo);
	while(!feof(pFile))
	{
		isEmpty = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,tipoPasajero,estadoVuelo, codigoDeVuelo);

	    if(isEmpty == 4)
	    {

	    	pasajero =  Passenger_newParametros(id,nombre,apellido,tipoPasajero,estadoVuelo, codigoDeVuelo);
	       if(pasajero!=NULL)
	       {
	    	   ll_add(pArrayListPassenger,pasajero);
	       }
	       else
	       {
	    	   printf("\nNo se pudo crear empleado");
	    	   retorno = -1;
	    	   break;
	       }

	    }
	    else
	    {
	    	printf("\nNo se pudo leer empleado correctamente");
	        retorno = -1;
	        break;
	    }
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
