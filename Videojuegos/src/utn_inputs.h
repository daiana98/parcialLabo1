/*
 * utn_inputs.h
 *
 *  Created on: 13 oct. 2021
 *      Author: quisp
 */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#ifndef UTN_INPUTS_H_
#define UTN_INPUTS_H_

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int esTexto(char cadena[]);
int utn_getNatu(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos);
int getEmployee(char name[], char lastName[], float* salary, int* sector);
int obtenerSala(char nombre[], char direccion[], int* tipo);
int obtenerArcade(char nacionalidad[], char nombreJuego[], int* tipoSonido, int* cantJugadores, int* capMaxFichas, int* idSalon);
#endif /* UTN_INPUTS_H_ */
