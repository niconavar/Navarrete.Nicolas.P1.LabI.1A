/*
 * trabajo.c
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "notebook.h"
#include "inputs_validaciones.h"

int InicializarTrabajo(eTrabajo vec[], int tam)
{
	int retorno = 0;

	if(vec != NULL && tam >0)
	{
		for(int i=0; i <tam; i++)
		{
				vec[i].isEmpty = 1;
		}
	}

	return retorno;
}

int BuscarTrabajolibre(eTrabajo vec[], int tam, int* pIndex)
{
	int retorno = -1;

	if(vec!=NULL && tam>0 && pIndex!=NULL)
	{
		*pIndex=-1; //no hay lugar

		for(int i = 0; i<tam; i++)
		{
			if(vec[i].isEmpty == 1)
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;

}

int CargarServicio(eServicio servicios[], int tam, int id, char descripcion[], float* precio)
{
	int retorno = 0;

	if(servicios != NULL && tam > 0 && id >= 20000 && id <= 20003 && descripcion != NULL)
	{
		for(int i = 0; i < tam ; i++)
		{
			if(servicios[i].id == id)
			{
				strcpy(descripcion, servicios[i].descripcion);
				*precio = servicios[i].precio;
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int CargarNotebook(eNotebook notebooks[], int tam, int id, char descripcion[])
{
	int retorno = 0;

	if(notebooks != NULL && tam > 0 && id >= 100 && id <= 900 && descripcion != NULL)
	{
		for(int i = 0; i < tam ; i++)
		{
			if(notebooks[i].id == id)
			{
				strcpy(descripcion, notebooks[i].modelo);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int MostrarTrabajo(eTrabajo trabajo,int tam, eServicio servicio[], eNotebook notebooks[])
{
	int retorno = 0;
	char descServicio[20];
	char descNotebooks[20];
	float PrecioServicio;

	if(servicio != NULL && tam >0)
	{
		CargarServicio(servicio, tam, trabajo.idServicio, descServicio, &PrecioServicio);
		CargarNotebook(notebooks, tam, trabajo.idNotebook, descNotebooks);

		printf("%4d	             %10s               %10s  	          %02d/%02d/%2dn      %9.2f\n", trabajo.id, descNotebooks, descServicio, trabajo.fecha.dia,
				trabajo.fecha.mes, trabajo.fecha.anio, PrecioServicio);
	}
	return retorno;
}

int AltaTrabajo(eTrabajo trabajos[], int tam, int* pId)
{
	int retorno = 0;
	int indice;
	eTrabajo auxTrabajoNuevo;

	if(trabajos !=NULL && tam>0 && pId !=NULL)
	{
		if(BuscarTrabajolibre(trabajos, tam, &indice))
		{
			if(indice == -1)
			{
				printf("no hay lugar en el sistema\n");
			}
			else
			{
				PedirNumeroEntero("Ingrese ID de notebook:\n", 100, 1000, &auxTrabajoNuevo.idNotebook);

				PedirNumeroEntero("Ingrese ID de servicio:\n"
						"20000- para Bateria\n"
						"20001- para Display\n"
						"20002- para Mantenimiento\n"
						"20003- para Fuente", 20000, 20003, &auxTrabajoNuevo.idServicio);

				PedirNumeroEntero("Ingrese dia: \n", 1, 31, &auxTrabajoNuevo.fecha.dia);
				PedirNumeroEntero("Ingrese mes: \n", 1, 12, &auxTrabajoNuevo.fecha.mes);
				PedirNumeroEntero("Ingrese año: \n", 1950, 2022, &auxTrabajoNuevo.fecha.anio);

				auxTrabajoNuevo.isEmpty = 0;
				auxTrabajoNuevo.id = *pId;
				*pId = *pId +1;
				trabajos[indice] = auxTrabajoNuevo;
				retorno = 1;
			}
		}
		else
		{
			printf("ocurrio un error con los parametros\n");
		}
	}
	return retorno;

}

int ListarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamServicios, eNotebook notebooks[])
{
	   int retorno = 0;
	   int flag =0;
	    if(vec != NULL && tam > 0)
	    {
	        printf("                 *** Listado de trabajos ***\n");
	        printf("------------------------------------------------------------------------------------------------------------\n");
	        printf("  ID\t\t         notebook \t        servicio\t          fecha\t            Precio\n");
	        printf("------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!vec[i].isEmpty)
	        	{

	        		MostrarTrabajo(vec[i], tam, servicios, notebooks);
	        		flag++;
	        	}

	        }
	        if(flag==0)
	        {
	        	printf("no hay trabajos en el sistema\n");
	        }
	        printf("\n\n");

	        retorno = 1;
	    }
	    return retorno;
}

int ListarServicios(eServicio servicios[], int tamServicio)
{
	int retorno = 0;

	if(servicios != NULL && tamServicio > 0)
	{
		printf("Lista de servicios\n");
		printf("   id      descripcion        precio\n");
		printf("-------------------------------------\n");

		for(int i=0; i<tamServicio; i++)
		{
			printf("    %4d       %18s      %9.2f\n",servicios[i].id, servicios[i].descripcion, servicios[i].precio);
		}
		printf("\n\n");
		retorno = 1;

	}
	return retorno;
}

int HardcodearTrabajos(eTrabajo vec[], int tam, int cantidad, int* pId)
{
	/*	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int isEmpty;

			{20000, "Bateria", 2250},
			{20001, "Display", 10300},
			{20002, "Mantenimiento", 4400},
			{20003, "Fuente", 5600}

	*/
	int retorno = -1;
	eTrabajo suplentes[] =
	{
			{0,100,20000,{5/12/2021},0},
			{0,100,20001,{5/12/2021},0},
			{0,101,20002,{5/12/2021},0},
			{0,102,20003,{5/12/2021},0},
			{0,103,20002,{5/12/2021},0},
			{0,104,20001,{5/12/2021},0},
			{0,105,20003,{5/12/2021},0},
			{0,106,20000,{5/12/2021},0},
			{0,107,20000,{5/12/2021},0},
			{0,105,20000,{5/12/2021},0}
	}; //hardcodeo

	if(vec!=NULL && tam>0 && pId!=NULL && cantidad >0 && cantidad <=tam)
	{

		for(int i = 0; i<cantidad; i++)
		{
			vec[i] = suplentes[i];
			vec[i].id = *pId;
			*pId = *pId+ 1;

		}
		retorno = 1;
	}

	return retorno;
}

int InformarTrabajosHechos(eNotebook notebook[],int tam, eServicio servicios[], eTrabajo trabajos[])
{
	int retorno = -1;
	int idNotebook;
	int flag = 0;
	char descNotebooks[20];

	if(notebook!=NULL && tam>0 && servicios != NULL)
	{
		PedirNumeroEntero("ingrese id de notebook", 1, 111, &idNotebook);
		CargarNotebook(notebook, tam, trabajos->idNotebook, descNotebooks);

		for(int i = 0; i<tam; i++)
		{
			if(!trabajos[i].isEmpty && (trabajos[i].idNotebook == idNotebook || flag == 0)) //siempre se pregunta isEmpty
			{
				idNotebook = trabajos[i].idServicio;
				flag = 1;
			}
			retorno = 1;
		}


        printf("                 *** Listado de trabajos hechos a la notebook***\n");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
        printf("  ID\t\t         Modelo \t        Marca\t             Tipo\t            Precio            cliente\n");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i<tam; i++)
		{
			if(!trabajos[i].isEmpty && trabajos[i].idNotebook == idNotebook)
			{
				MostrarTrabajo(trabajos[i], tam, servicios, notebook);
			}
		}
		retorno = 1;

	}


	return retorno;
}
