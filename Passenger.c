#include "Passenger.h"
#include "LinkedList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
static int isLetras(char*pBuffer);
static int isInt(char *pBuffer);
static int isValidId(int id);
static int isValidNombre(char* nombre);

/** \brief Crea un pasajero
 * \return this Passenger*
 */
Passenger* Passenger_new()
{
	Passenger* this;
	this=(Passenger*)malloc(sizeof(Passenger));
	return this;
}


Passenger* Passenger_newParametros(char* id,char* nombre,char* apellido,char*  estadoVuelo, char* CodigoVuelo)
{
	Passenger* this;

	this=Passenger_new();
	if( isInt(id)==0 &&
		isLetras(nombre)==0 &&
		isLetras(apellido)==0 &&
		isInt(estadoVuelo)==0 &&
	    Passenger_setId(this,atoi(id))==0 &&
		Passenger_setId(this,atoi(estadoVuelo))==0 &&
		 Passenger_setNombre(this,apellido)==0)
	{
		return this;
	}
	else
	{
		printf("\nNo se pudo crear el empleado con parametros");
		return NULL;
	}
}





/** \brief Elimina un empleado
 * \param this Passenger*
 * \return 0 todo bien -1 error
 */

int Passenger_delete(Passenger* this)
{
	int retorno=-1;

	if(this!=NULL)
	{
		free(this);
		retorno=0;
	}

	return retorno;
}

/** \brief Establece el ID de un empleado
 * \param this Passenger*
 * \param id int
 * \return 0 todo bien -1 error
 */
int Passenger_setId(Passenger* this,int id)
{
	int retorno=-1;
	static int proximoId=-1;

	if(this!=NULL && id==-1 && isValidId(id)==0)
	{
	   proximoId++;
	   this->id=proximoId;
	   retorno=0;
	}
	else
	{
	   this->id=id;
	   retorno=0;
	}

	if(id>proximoId)
	{
	   proximoId=id;
	   retorno=0;
	}
	return retorno;
}

/** \brief Devuelve el ID de un empleado
 * \param this Passenger*
 * \param id int*
 * \return 0 todo bien -1 error
 */
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/** \brief Establece el nombre de un empleado
 * \param this Passenger*
 * \param nombre char*
 * \return 0 todo bien -1 error
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && isValidNombre(nombre)==0)
	{
		strncpy(this->nombre,nombre,sizeof(this->nombre));
		retorno = 0;
	}
	else
	{
		printf("\nNo se pudo establecer el nombre");
	}
	return retorno;
}

/** \brief Devuelve el nombre de un empleado
 * \param this Passenger*
 * \param nombre char*
 * \return 0 todo bien -1 error
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL)
	{
	   strcpy(nombre,this->nombre);
	   retorno = 0;
	}
	return retorno;
}

/** \brief Establece el apellido de un pasajer
 * \param this Passenger*
 * \param nombre char*
 * \return 0 todo bien -1 error
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && isValidNombre(apellido)==0)
	{
		strncpy(this->nombre,apellido,sizeof(this->apellido));
		retorno = 0;
	}
	else
	{
		printf("\nNo se pudo establecer el apellido");
	}
	return retorno;
}

/** \brief Devuelve el apellido de un pasajero
 * \param this Passenger*
 * \param nombre char*
 * \return 0 todo bien -1 error
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL)
	{
	   strcpy(apellido,this->apellido);
	   retorno = 0;
	}
	return retorno;
}



/** \brief Establece el codigo de vuelo de un pasajer
 * \param this Passenger*
 * \param codigodevuelo char*
 * \return 0 todo bien -1 error
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && isValidNombre(codigoVuelo)==0)
	{
		strncpy(this->nombre,codigoVuelo,sizeof(this->codigoVuelo));
		retorno = 0;
	}
	else
	{
		printf("\nNo se pudo establecer el codigo de vuelo");
	}
	return retorno;
}

/** \brief Devuelve el codigo de vuelo de un pasajero
 * \param this Passenger*
 * \param codigodevuelo char*
 * \return 0 todo bien -1 error
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL)
	{
	   strcpy(codigoVuelo,this->codigoVuelo);
	   retorno = 0;
	}
	return retorno;
}




/** \brief Valida un numero entero
 * \param pBuffer char* cadena a validar
 * \return 0 todo bien -1 error
 */
static int isInt(char *pBuffer)
{
    int retorno=-1;

    for(int i=0;i<strlen(pBuffer);i++)
    {
        if(pBuffer[i]<'0' || pBuffer[i]>'9')
        {
        	printf("\nNo es un numero");
            break;
        }
        retorno = 0;
    }

    return retorno;
}
/** \brief Valida un nombre valido (acepta nombres compuestos)
 * \param pBuffer char* cadena a validar
 * \return 0 todo bien -1 error
 */
static int isLetras(char*pBuffer)
{
    int retorno=-1;

    for(int i=0;i<strlen(pBuffer);i++)
    {
        if((pBuffer[i]<'A' || pBuffer[i]>'Z') && (pBuffer[i]<'a' || pBuffer[i]>'z') && pBuffer[i]!=' ' && pBuffer[i]!='-')
        {
        	printf("\nNo son letras %d",i);
            break;
        }

        retorno = 0;
    }
    return retorno;
}
/** \brief Valida un nombre para guardar en el campo nombre
 * \param nombre char* cadena a validar
 * \return 0 todo bien -1 error
 */
static int isValidNombre(char* nombre)
{
    int retorno=-1;
    if(nombre!= NULL && strlen(nombre)<50 && strlen(nombre)>1)
    {
        retorno=0;
    }
    else
    {
    	printf("\nNombre supera los limites");
    }
    return retorno;
}


/** \brief Valida un id valido
 * \param id int
 * \return 0 todo bien -1 error
 */
static int isValidId(int id)
{
    int retorno=-1;
    if(id>0)
    {
        retorno=0;
    }
    return retorno;
}
