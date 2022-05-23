/*
 * notebook.h
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#ifndef NOTEBOOK_H_
#define NOTEBOOK_H_

typedef struct
{
	int id; //empieza en 1000
	char descripcion[20];

}eMarca; //hardcodear

typedef struct
{
	int id; //empieza en 5000
	char descripcion[20];
}eTipo; //hardcodear

typedef struct
{
	int id;
	char nombre[20];
	char sexo[2];
	int isEmpty;
}eCliente;

typedef struct
{
	int id;
	char modelo[20];
	int idMarca;
	int idTipo;
	float precio;
	int idCliente;
	int isEmpty;

}eNotebook;
#endif /* NOTEBOOK_H_ */

int InicializarNotebooks(eNotebook vec[], int tam);
int InicializarCliente(eCliente vec[], int tam);
int BuscarNotebookLibre(eNotebook vec[], int tam, int* pIndex);
int BuscarNotebook(eNotebook vec[], int tam, int id, int* pIndex);

int AltaNotebook(eNotebook vec[], int tam, int* pId, eCliente cliente[]);
int BajaNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);
int ModificarNotebook(eNotebook vec[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipo, eCliente clientes[], int tamClientes);

int ListarNotebooks(eNotebook vec[], int tam, eMarca marcas[], int tamMarca, eTipo tipos[], int tamTipos, eCliente clientes[], int tamClientes);
int OrdenarNotebooksPorMarcaYPrecio(eNotebook vec[], int tam, eMarca vecMarca[], int tamMarca);
int MostrarNotebook(eNotebook notebook,int tam, eMarca marca[], eTipo tipo[],eCliente clientes[]);
int MostrarNotebookUnTipo(eNotebook notebook[],int tam, eMarca marca[], eTipo tipo[], eCliente clientes[]);
int MostrarNotebookUnaMarca(eNotebook notebook[],int tam, eMarca marca[], eTipo tipo[], eCliente clientes[]);
int InformarNotebooksMasBaratas(eNotebook notebook[],int tam, eMarca marca[], eTipo tipo[], eCliente clientes[]);
int ListadoCantNotebooksTipoYMarca(eNotebook notebook[],int tam);

int CargarDescripcionMarca(eMarca marcas[], int tam, int id, char descripcion[]);
int CargarDescripcionTipo(eTipo tipos[], int tam, int id, char descripcion[]);
int CargarCliente(eCliente clientes[], int tam, int id, char nombre[]);
int ListarMarcas(eMarca marcas[], int tamMarca);
int ListarTipos(eTipo tipos[], int tamTipo);

int HardcodearNotebooks(eNotebook vec[], int tam, int cantidad, int* pId);
int HardcodearClientes(eCliente vec[], int tam, int cantidad, int* pId);
