/*
 * notebook.c
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#include "notebook.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs_validaciones.h"


int InicializarNotebooks(eNotebook vec[], int tam)
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

int MostrarNotebook(eNotebook notebook,int tam, eMarca marca[], eTipo tipo[], eCliente clientes[])
{
	int retorno = 0;
	char descMarca[20];
	char descTipo[20];
	char nombre[20];

	if(marca != NULL && tam >0 && tipo != NULL)
	{
		CargarDescripcionMarca(marca, tam, notebook.idMarca, descMarca);
		CargarDescripcionTipo(tipo, tam, notebook.idTipo, descTipo);
		CargarCliente(clientes, tam, notebook.idCliente, nombre);

		printf("%4d	          %15s             %10s  	     %10s         %10.2f           %10s\n",notebook.id, notebook.modelo, descMarca, descTipo, notebook.precio, nombre);

		retorno = 1;
	}
	return retorno;
}

int CargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[])
{
	int retorno = 0;

	if(marcas != NULL && tam > 0 && id >= 1000 && id <= 1003 && descripcion != NULL)
	{
		for(int i = 0; i < tam ; i++)
		{
			if(marcas[i].id == id)
			{
				strcpy(descripcion, marcas[i].descripcion);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int CargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[])
{
	int retorno = 0;

	if(tipos != NULL && tam > 0 && id >= 5000 && id <= 5003 && descripcion != NULL)
	{
		for(int i = 0; i < tam ; i++)
		{
			if(tipos[i].id == id)
			{
				strcpy(descripcion, tipos[i].descripcion);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int BuscarNotebookLibre(eNotebook vec[], int tam, int* pIndex)
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

int AltaNotebook(eNotebook vec[], int tam, int* pId, eCliente cliente[])
{
	int retorno = 0;
	int indice;
	char auxCadena[100];
	eNotebook auxNuevaNotebook;
	eCliente auxCliente;

	if(vec !=NULL && tam>0 && pId !=NULL)
	{
		if(BuscarNotebookLibre(vec, tam, &indice))
		{
			if(indice == -1)
			{
				printf("no hay lugar en el sistema\n");
			}
			else //aca se cae cuando haya lugar en el sistema para cargar empleado
			{

				PedirCadena(auxCadena, "Ingrese modelo: ", 100);
				strcpy(auxNuevaNotebook.modelo, auxCadena);

				PedirNumeroEntero("Ingrese marca:\n"
						"1000- para Compaq\n"
						"1001- para Asus\n"
						"1002- para Acer\n"
						"1003- para HP\n", 1000, 1003, &auxNuevaNotebook.idMarca);

				PedirNumeroEntero("Ingrese un Tipo:\n"
						"5000- para Gamer\n"
						"5001- para Disenio\n"
						"5002- para Ultrabook\n"
						"5003- para Normalita", 5000, 5003, &auxNuevaNotebook.idTipo);

				PedirFloatP("Ingrese un precio: \n", &auxNuevaNotebook.precio, 999999, 1);

				PedirCadena(auxCliente.nombre, "Ingrese nombre de cliente: \n", tam);
				PedirCadena(auxCliente.sexo, "Ingrese sexo: \n", tam);

				auxCliente.isEmpty = 0;
				auxNuevaNotebook.isEmpty = 0;
				auxNuevaNotebook.id = *pId;
				*pId = *pId +1;
				vec[indice] = auxNuevaNotebook;
				cliente[indice] = auxCliente;
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

int BuscarNotebook(eNotebook vec[], int tam, int id, int* pIndex)
{
	int retorno = -1;

	if(vec!=NULL && tam>0 && pIndex!=NULL && id >0)
	{
		*pIndex=-1; //no hay lugar, se precarga

		for(int i = 0; i<tam; i++)
		{
			if(vec[i].isEmpty == 0 && vec[i].id == id) //is.empty = notebook activa
			{
				*pIndex = i;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}

int ListarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
	   int retorno = 0;
	   int flag =0;
	    if(vec != NULL && tam > 0)
	    {
	        printf("                 *** Listado de notebooks ***\n");
	        printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("  ID\t\t         Modelo \t        Marca\t             Tipo\t            Precio            cliente.Nombre\n");
	        printf("----------------------------------------------------------------------------------------------------------------------------------------------\n");
	        for(int i=0; i < tam; i++)
	        {
	        	if(!vec[i].isEmpty)
	        	{

	        		MostrarNotebook(vec[i],tam, marcas, tipos, clientes);
	        		flag++;
	        	}

	        }
	        if(flag==0)
	        {
	        	printf("no hay notebooks en el sistema\n");
	        }
	        printf("\n\n");

	        retorno = 1;
	    }
	    return retorno;
}

int BajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes)
{
	int retorno = -1;
	int indice;
	int id;
	char confirma;

	if(vec!=NULL && tam>0)
	{
		ListarNotebooks(vec, tam, marcas, tamMarca, tipos, tamTipos, clientes, tamClientes);
		PedirNumeroEntero("Ingrese ID: ", 1, 99999, &id);
		if(BuscarNotebook(vec, tam, id, &indice)== 1)//si es igual a 1, encontro el empleado
		{
			if(indice == -1) //no existe ese num de legajo
			{
				printf("No hay una notebook con id: %d\n", id);
			}
			else
			{
				MostrarNotebook(vec[indice], tam, marcas,tipos, clientes);
				printf("Confirma baja?: s/n");
				fflush(stdin);
				scanf("%c", &confirma);

				if(confirma != 'S' && confirma != 's')
				{
					printf("Baja cancelada por el usuario\n");
				}
				else
				{
					vec[indice].isEmpty = 1; //baja logica
					printf("baja realizada con exito\n");
					retorno = 1;
				}
			}
		}
		else
		{
			printf("ocurrio un problema al buscar la notebook.\n");
		}
		retorno = 1;
	}
	return retorno;
}

int ModificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamClientes)
{
	int retorno = -1;
	int indice;
	int id;
	int opcion;
	char salir = 'n';

	if(vec!=NULL && tam>0)
	{
		ListarNotebooks(vec, tam, marcas, tamMarca, tipos, tamTipo, clientes, tamClientes);
		PedirNumeroEntero("Ingrese id: ", 100, 99999, &id);
		if(BuscarNotebook(vec, tam, id, &indice)== 1)//si es igual a 1, encontro la notebook
		{
			if(indice == -1) //no existe ese num de id
			{
				printf("No hay una notebook con id: %d\n", id);
			}
			else
			{
				MostrarNotebook(vec[indice], tam, marcas, tipos, clientes);
				do
				{
					PedirNumeroEntero("Ingrese 1 para modificar precio: \n"
							"Ingrese 2 para modificar tipo: \n"
							"Ingrese 3 para salir: \n", 1, 3, &opcion);

					switch(opcion)
					{
						case 1:
							PedirFloatP("Ingrese nuevo precio: \n", &vec[indice].precio, 999999, 1);
							break;
						case 2:
							PedirNumeroEntero("Ingrese un Tipo: \n"
									"5000- para Gamer\n"
									"5001- para Disenio\n"
									"5002- para Ultrabook\n"
									"5003- para Normalita", 5000, 5003, &vec[indice].idTipo);
							break;
						case 3:
							printf("finaliza la modificacion.\n");
							salir = 's';
							break;
					}
				}while(salir !='s');

			}
		}
		else
		{
			printf("ocurrio un problema al buscar el empleado.\n");
		}
		retorno = 1;
	}
	return retorno;
}

int OrdenarNotebooksPorMarcaYPrecio(eNotebook vec[], int tam, eMarca vecMarca[], int tamMarca)
{
	int retorno = 0;
	eNotebook auxNotebook; //aux para swapear
	//eMarca auxMarca;

	if(vec != NULL && tam >0)
	{
		for(int i=0; i <tam-1; i++)
		{
			for(int j= i+1 ; j<tam; j++)
			{

				if(vec[i].idMarca == vec[j].idMarca && vec[i].precio < vec[j].precio)
				{
					auxNotebook = vec[i];
					vec[i] = vec[j];
					vec[j] = auxNotebook;
				}
				else
				{
					if(vec[i].idMarca != vec[j].idMarca && vec[i].idMarca < vec[j].idMarca)
					{
						auxNotebook = vec[i];
						vec[i] = vec[j];
						vec[j] = auxNotebook;
					}
				}
			}
		}
		retorno = 1;
	}
	return retorno;
}

int ListarMarcas(eMarca marcas[], int tamMarca)
{
	int retorno = 0;

	if(marcas != NULL && tamMarca > 0)
	{
		printf("Lista de Marcas\n");
		printf("   id      descripcion\n");
		printf("-------------------------------------\n");

		for(int i=0; i<tamMarca; i++)
		{
			printf("    %4d       %10s\n",marcas[i].id, marcas[i].descripcion);
		}
		printf("\n\n");
		retorno = 1;

	}
	return retorno;
}

int ListarTipos(eTipo tipos[], int tamTipo)
{
	int retorno = 0;

	if(tipos != NULL && tamTipo > 0)
	{
		printf("Lista de Tipos\n");
		printf("   id      descripcion\n");
		printf("-------------------------------------\n");

		for(int i=0; i<tamTipo; i++)
		{
			printf("    %4d       %10s\n",tipos[i].id, tipos[i].descripcion);
		}
		printf("\n\n");
		retorno = 1;
	}
	return retorno;
}

int HardcodearNotebooks(eNotebook vec[], int tam, int cantidad, int* pId)
{
	int retorno = -1;
	eNotebook suplentes[] =
	{
			{0,"victus",1000,5003,70000,0000,0},
			{0,"amdgamer",1001,5000,120000,0000,0},
			{0,"IntelHp",1003,5001,90000,0000,0},
			{0,"ultra2000",1002,5002,87000,0000,0},
			{0,"blue",1000,5002,60000,0000,0},
			{0,"red",1003,5000,110000,0000,0},
			{0,"green",1000,5002,60000,0000,0},
			{0,"yellow",1001,5001,134000,0000,0},
			{0,"hp1000",1003,5000,98000,0000,0},
			{0,"PcNasa",1001,5000,250000,0000,0}
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

int CargarCliente(eCliente clientes[], int tam, int id, char nombre[])
{

	int retorno = 0;

	if(clientes != NULL && tam > 0 && id >= 50 && id <= 60 && nombre != NULL)
	{
		for(int i = 0; i < tam ; i++)
		{
			if(clientes[i].id == id)
			{
				strcpy(nombre, clientes[i].nombre);
				break;
			}
		}
		retorno = 1;
	}
	return retorno;
}

int MostrarNotebookUnTipo(eNotebook notebook[],int tam, eMarca marca[], eTipo tipo[], eCliente clientes[])
{
	int retorno = 0;
	int auxTipo;
	int indice;

	if(BuscarNotebookLibre(notebook, tam, &indice))
	{
		if(notebook!=NULL && tam>0)
		{


	    	PedirNumeroEntero("Ingrese un Tipo: \n"
	    			"5000- para Gamer\n"
	    			"5001- para Disenio\n"
	    			"5002- para Ultrabook\n"
	    			"5003- para Normalita\n", 5000, 5003, &auxTipo);

	        printf("                 *** Listado de notebooks de un tipo***\n");
	        printf("---------------------------------------------------------------------------------------------------\n");
	        printf("  ID\t\t         Modelo \t        Marca\t             Tipo\t            Precio            cliente\n");
	        printf("---------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i<tam; i++)
			{
				if(!notebook[i].isEmpty && notebook[i].idTipo == auxTipo)
				{
					MostrarNotebook(notebook[i], tam, marca, tipo, clientes);
				}
			}
			retorno = 1;
		}
	}
	return retorno;

}

int MostrarNotebookUnaMarca(eNotebook notebook[],int tam, eMarca marca[], eTipo tipo[], eCliente clientes[])
{
	int retorno = 0;
	int auxMarca = 1001;
	int indice;

	if(BuscarNotebookLibre(notebook, tam, &indice))
	{
		if(notebook!=NULL && tam>0)
		{

	        printf("                 *** Listado de notebooks de una marca***\n");
	        printf("--------------------------------------------------------------------------------------------------------------------------\n");
	        printf("  ID\t\t         Modelo \t        Marca\t             Tipo\t            Precio            cliente\n");
	        printf("--------------------------------------------------------------------------------------------------------------------------\n");
			for(int i = 0; i<tam; i++)
			{
				if(!notebook[i].isEmpty && notebook[i].idMarca == auxMarca)
				{
					MostrarNotebook(notebook[i], tam, marca, tipo, clientes);
				}
			}
			retorno = 1;
		}
	}
	return retorno;
}

int InformarNotebooksMasBaratas(eNotebook notebook[],int tam, eMarca marca[], eTipo tipo[], eCliente clientes[])
{
	int retorno = -1;
	float menorPrecio;
	int flag = 0;

	if(notebook!=NULL && tam>0 && marca != NULL && tipo != NULL && clientes != NULL)
	{

		for(int i = 0; i<tam; i++)
		{
			if(!notebook[i].isEmpty && (notebook[i].precio < menorPrecio || flag == 0)) //siempre se pregunta isEmpty
			{
				menorPrecio = notebook[i].precio;
				flag = 1;
			}
			retorno = 1;
		}


        printf("                 *** Listado de notebooks de un tipo***\n");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
        printf("  ID\t\t         Modelo \t        Marca\t             Tipo\t            Precio            cliente\n");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
		for(int i = 0; i<tam; i++)
		{
			if(!notebook[i].isEmpty && notebook[i].precio == menorPrecio)
			{
				MostrarNotebook(notebook[i], tam, marca, tipo, clientes);
			}
		}
		retorno = 1;

	}


	return retorno;
}

int ListadoCantNotebooksTipoYMarca(eNotebook notebook[],int tam)
{
	int retorno = -1;
	int contadorMarcaAsus= 0;

	if(notebook!=NULL && tam>0)
	{

		for(int i = 0; i<tam; i++)
		{
			if(!notebook[i].isEmpty)
			{
				switch(notebook[i].idMarca)
				{

					case 1001:
						switch(notebook[i].idTipo)
						{
							case 5000:
								contadorMarcaAsus++;
								break;
						}
						break;
				}
			}
			retorno = 1;
		}


        printf("                 *** Listado de notebooks de una marca***\n");
        printf("--------------------------------------------------------------------------------------------------------------------------\n");
        printf("marca: Asus\nTipo: Gamer\ncantidad: %d\n", contadorMarcaAsus);
        printf("--------------------------------------------------------------------------------------------------------------------------\n");

		retorno = 1;

	}


	return retorno;
}

int HardcodearClientes(eCliente vec[], int tam, int cantidad, int* pId)
{
	int retorno = -1;
	eCliente suplentes[] =
	{
			{0,"nicolas","m",0},
			{0,"ariana","f",0},
			{0,"ruben","m",0},
			{0,"miguel","m",0},
			{0,"paula","f",0},
			{0,"maria","f",0},
			{0,"antonella","f",0},
			{0,"juan","m",0},
			{0,"daniel","m",0},
			{0,"jessica","f",0}
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

int InicializarCliente(eCliente vec[], int tam)
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

