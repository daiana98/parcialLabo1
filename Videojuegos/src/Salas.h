/*
 * Salas.h
 *
 *  Created on: 15 oct. 2021
 *      Author: quisp
 */

#ifndef SALAS_H_
#define SALAS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHOPPING 1
#define LOCAL 0

#define LON_C 128

#define VACIO 1
#define LLENO 0

typedef struct{
	int id;
	char nombre[LON_C];
	char direccion[LON_C];
	int tipo;
	int estaVacio;
}Sala;

int iniSalas(Sala lista[], int lon);
int agregarSala(Sala lista[], int lon, int id, char nombre[], char direccion[], int tipo);
int obtenerIdSala(void);
int buscarSalaPorId(Sala lista[], int lon,int id);
int imprimirSalones(Sala lista[], int lon);
void imprimirSala(Sala* unaSala);
int eliminarSalon(Sala lista[], int lon, int id);
void cargarSalas(Sala lista[], int lon);

/*--------*/
Sala* crearUnaSala(void);
#endif /* SALAS_H_ */
