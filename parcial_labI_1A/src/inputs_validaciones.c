/*
 * inputs_validaciones.c
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_validaciones.h"


int PedirNumeroEntero(char mensaje[100], int minimo, int maximo, int *pNumero)
{
	int numero;
	char buffer[500];
	int retorno;
	retorno = -1;

	while(retorno==-1)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s", buffer);

		if(ValidarEntero(buffer)==1)
		{
			numero = atoi(buffer);

			if(numero <= maximo && numero >= minimo)
			{
				*pNumero = numero;
				retorno = 0;
			}
			else
			{
				printf("Error, ese numero no esta dentro de los parametros %d y %d.\n", minimo, maximo);
			}
		}
		else
		{
			printf("error: numero no valido, reingrese: \n");
		}

	}

	return retorno;
}

int ValidarEntero(char* cadena)
{
	int retorno;
	int i;
	retorno=1;

	for(i=0; cadena[i]!='\0';i++)
	{
		//detecta si esta fuera de rango, si es letra
		if(cadena[i]<'0' || cadena[i]>'9')
		{
			//no se está en el rango de los numeros
			if(cadena[i]=='.')// es un punto
			{
				retorno =0;
				break;
			}
			else
			{
				//hay algo que no es un punto ni numero
				if(i==0)
				{
					//si no es + y - dara error
					if(cadena[i]!='+' && cadena[i]!='-')
					{
						retorno=0;
						break;
					}
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}

	}

	return retorno;
}

int PedirCadena(char cadena[], char mensaje[], int tam)
{
	char auxiliarString[200];
	int retorno;

	retorno =0;

	if(cadena!=NULL && mensaje!=NULL)
	{
		retorno=1;
		printf(mensaje);
		fflush(stdin);
		gets(auxiliarString);
		while(strlen(auxiliarString)>tam)
		{
			printf("reingrese el nombre: \n");
			fflush(stdin);
			gets(auxiliarString);

		}
		strncpy(cadena, auxiliarString, tam);
	}


	return retorno;
}

int ValidarFloat(char* stringRecibido)
{
	int retorno=1;
	int i;
	int contadorPuntos;

	contadorPuntos=0;

	for(i=0; stringRecibido[i]!='\0';i++)
	{
		//detecta si esta fuera de rango, si es letra
		if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
		{
			//no se está en el rango de los numeros
			if(stringRecibido[i]=='.')// es un punto
			{
				contadorPuntos++;
				if(contadorPuntos>1)
				{
					//se encontró un segundo punto, da error
					retorno=0;
					break;
				}
			}
			else
			{
				//hay algo que no es un punto ni numero
				if(i==0)
				{
					//si no es + y - dara error
					if(stringRecibido[i]!='+' && stringRecibido[i]!='-')
					{
						retorno=0;
						break;
					}
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}

	return retorno;
}

int PedirFloatP(char mensaje[], float* numeroF, float max, float min)
{
	char buffer[500];
	int retorno = 1;
	float numero;

	while(retorno==1)
	{
		printf("%s",mensaje);

		fflush(stdin);

		scanf("%s", buffer);

		if(ValidarFloat(buffer)==1)
		{

			numero = atof(buffer);

			if(numero <= max && numero >= min)
			{
				*numeroF = numero;
				retorno = 0;
			}

			else
			{
				printf("Error, ese numero no esta dentro de los parametros %.2f y %.2f.\n", min, max);

			}
		}
		else
		{
			printf("numero no valido\n");

		}
	}

	return retorno;
}

