/*
 * trabajo.h
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "notebook.h"


typedef struct
{
	int dia;
	int mes;
	int anio;

}eFecha;

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
}eServicio; //hardcodear

typedef struct
{
	int id;
	int idNotebook;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}eTrabajo;
#endif /* TRABAJO_H_ */

int InicializarTrabajo(eTrabajo vec[], int tam);
int BuscarTrabajolibre(eTrabajo vec[], int tam, int* pIndex);
int MostrarTrabajo(eTrabajo trabajo,int tam, eServicio servicio[], eNotebook notebooks[]);

int AltaTrabajo(eTrabajo trabajos[], int tam, int* pId);
int ListarTrabajos(eTrabajo vec[], int tam, eServicio servicios[], int tamServicios, eNotebook notebooks[]);
int InformarTrabajosHechos(eNotebook notebook[],int tam, eServicio servicios[], eTrabajo trabajos[]);

int CargarServicio(eServicio servicios[], int tam, int id, char descripcion[], float* precio);
int CargarNotebook(eNotebook notebooks[], int tam, int id, char descripcion[]);
int ListarServicios(eServicio servicios[], int tamServicio);

int HardcodearTrabajos(eTrabajo vec[], int tam, int cantidad, int* pId);
