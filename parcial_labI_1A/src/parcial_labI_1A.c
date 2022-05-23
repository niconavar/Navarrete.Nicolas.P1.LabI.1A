/*
 ============================================================================
 Alumno: Nicolas Navarrete
 Division: 1 A

Desarrollar en ANSI C:
Se necesita gestionar un Service de Notebooks y para eso se deberá desarrollar lo siguiente:
ENTIDADES:
Fecha:
• dia
• mes
• año
Marca:
• id (comienza en 1000)
• descripción (máx 20 caracteres)
Tipo:
• id (comienza en 5000)
• descripción (máx 20 caracteres)
Notebook:
• id
• modelo (máx 20 caracteres)
• idMarca Validar
• idTipo Validar
• precio
Servicio:
• id(comienza en 20000)
• descripción (máximo 25 caracteres)
• precio
Trabajo:
• id (autoincremental)
• idNotebook (debe existir) Validar
• idServicio (debe existir) Validar
• fecha (Validar día, mes y año)
DATOS PREVIOS:
Los arrays de marca, tipo y servicio deberán ser hardcodeados.
Marcas (Compaq, Asus, Acer, HP)
Tipos ( Gamer, Disenio, Ultrabook, Normalita)
Servicios (Bateria: $2250, Display: $10300, Mantenimiento: $4400, Fuente: $5600)

Los arrays de marca, tipo y servicio deberán ser hardcodeados.



este codigo no sirve, rompe, el error esta en la carga.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "inputs_validaciones.h"
#include "notebook.h"
#include "trabajo.h"


#define TAM 10
#define TAM_SEC 4



int Menu();

int main(void)
{
	setbuf(stdout,NULL);

	char salir = 'n';
	int proximoIdNotebook = 100;
	int proximoIdTrabajo = 1;
	int proximoIdCliente= 50;

	eNotebook lista[TAM];
	eTrabajo listaTrabajo[TAM];

	eMarca marca[TAM_SEC] =
	{
			{1000, "Compaq"},
			{1001, "Asus"},
			{1002, "Acer"},
			{1003, "HP"}
	};

	eTipo tipo[TAM_SEC] =
	{
			{5000, "Gamer"},
			{5001, "disenio"},
			{5002, "Ultrabook"},
			{5003, "Normalita"}
	};

	eServicio servicios[TAM_SEC] =
	{
			{20000, "Bateria", 2250},
			{20001, "Display", 10300},
			{20002, "Mantenimiento", 4400},
			{20003, "Fuente", 5600}
	};

	eCliente clientes[TAM];

	InicializarNotebooks(lista, TAM);
	InicializarTrabajo(listaTrabajo, TAM);
	InicializarCliente(clientes, TAM);
	HardcodearNotebooks(lista, TAM, 10, &proximoIdNotebook);
	HardcodearClientes(clientes, TAM, 10, &proximoIdCliente);
	HardcodearTrabajos(listaTrabajo, TAM, 10, &proximoIdTrabajo);

	do
	{
		switch(Menu())
		{
			case 1:
				if(AltaNotebook(lista, TAM, &proximoIdNotebook, clientes)==1)
				{
					printf("Notebook cargada con exito.\n");
				}
				else
				{
					printf("ocurrio un error.\n");
				}
				break;
			case 2:
				ModificarNotebook(lista, TAM, marca, TAM_SEC, tipo, TAM_SEC, clientes, TAM);
				break;
			case 3:
				if(BajaNotebook(lista, TAM, marca, TAM_SEC, tipo, TAM_SEC, clientes, TAM)==0)
				{
					printf("Ocurrio un error al dar de baja.\n");
				}
				break;
			case 4:
				OrdenarNotebooksPorMarcaYPrecio(lista, TAM, marca, TAM_SEC);
				ListarNotebooks(lista, TAM, marca, TAM_SEC, tipo, TAM_SEC, clientes, TAM);
				break;
			case 5:
				ListarMarcas(marca, TAM_SEC);
				break;
			case 6:
				ListarTipos(tipo, TAM_SEC);
				break;
			case 7:
				ListarServicios(servicios, TAM_SEC);
				break;
			case 8:
				if(AltaTrabajo(listaTrabajo, TAM, &proximoIdTrabajo)==1)
				{
					printf("trabajo cargado con exito\n");
				}
				else
				{
					printf("hubo un error\n");
				}
				break;
			case 9:
				ListarTrabajos(listaTrabajo, TAM, servicios, TAM_SEC, lista);
				break;
			case 10:
				MostrarNotebookUnTipo(lista, TAM, marca, tipo, clientes);
				break;
			case 11:
				MostrarNotebookUnaMarca(lista, TAM, marca, tipo, clientes);
				break;
			case 12:
				InformarNotebooksMasBaratas(lista, TAM, marca, tipo, clientes);
				break;
			case 13:

				break;
			case 14:
				ListadoCantNotebooksTipoYMarca(lista, TAM);
				break;
			case 15:
				InformarTrabajosHechos(lista, TAM, servicios, listaTrabajo);
				break;
			case 16:

				break;
			case 17:

				break;
			case 18:

				break;
			case 19:
				printf("fin del programa\n");
				salir = 's';
				break;
		}



	}while(salir != 's');




	return EXIT_SUCCESS;
}

int Menu()
{
	int opcion;

	printf("		***ABM Notebooks***			\n");
	printf("1- Alta notebook\n"
		   "2- Modificar Notebook\n"
		   "3- Baja Notebook\n"
		   "4- Listar Notebooks\n"
		   "5- Listar Marcas\n"
		   "6- Listar Tipos\n"
		   "7- Listar Servicios\n"
		   "8- Alta Trabajo\n"
		   "9- Listar trabajos\n"
		   "10- Mostrar notebooks de un solo tipo\n"
		   "11- Mostrar notebooks de la marca Asus\n"
		   "12- Informe de notebook mas barata o notebooks mas baratas\n"
		   "13- Listado de notebooks separadas por marcas\n"
		   "14- Listado de cantidad de notebooks de marca: Asus y tipo: \n"
		   "15- Informar trabajos Hechos a notebook\n"
		   "16-\n"
		   "17-\n"
		   "18-\n"
		   "19- salir\n");
	PedirNumeroEntero("Ingrese una opcion: \n", 1, 19, &opcion);

	return opcion;
}
