/*
 * inputs_validaciones.h
 *
 *  Created on: 23 may. 2022
 *      Author: Usuario
 */

#ifndef INPUTS_VALIDACIONES_H_
#define INPUTS_VALIDACIONES_H_



#endif /* INPUTS_VALIDACIONES_H_ */




/// @param mensaje
/// @param minimo
/// @param maximo
/// @param pNumero
/// @return
int PedirNumeroEntero(char mensaje[100], int minimo, int maximo, int *pNumero);

/// @param cadena
/// @param mensaje
/// @param tam
/// @return
int PedirCadena(char cadena[], char mensaje[], int tam);

/// @param mensaje
/// @param numeroF
/// @param max
/// @param min
/// @return
int PedirFloatP(char mensaje[], float* numeroF, float max, float min);

/// @param cadena
/// @return
int ValidarEntero(char* cadena);

/// @param stringRecibido
/// @return
int ValidarFloat(char* stringRecibido);
