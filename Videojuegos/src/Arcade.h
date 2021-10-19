/*
 * Arcade.h
 *
 *  Created on: 18 oct. 2021
 *      Author: quisp
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MONO 1
#define ESTEREO 0

#define VACIO 1
#define LLENO 0

typedef struct{
	int id;
	char nacionalidad[128];
	char nombreJuego[63];
	int tipoSonido;
	int cantJugadores;
	int capMaxFichas;
	int idSalon;
	int estaVacio;
}Arcade;

int iniArcade(Arcade lista[], int lon);
int agregarArcade(Arcade lista[], int lon, int id, char nacionalidad[], char nombreJuego[], int tipoSonido, int cantJugadores, int capMaxFichas, int idSalon);
int obtenerIdArcade(void);
int buscarArcadePorid(Arcade lista[], int lon,int id);
int modificarArcade(Arcade lista[], int lon, int id, char nombreJuego[], int cantJugadores);
int eliminarArcade(Arcade lista[], int lon, int id);
int eliminarArcadesPorIdSalon(Arcade lista[], int lon, int idSalon);
void imprimirUnArcade(Arcade* arcade);
int imprimirArcades(Arcade lista[], int lon);
int generarListaJuegos(Arcade lista[], int lon, char juego[][63]);
int imprimirJuegosEnUso(char lista[][63], int lon);
int obtenerIdJuego(void);
void cargarArcade(Arcade lista[], int lon, char listaJuegos[][63]);
#endif /* ARCADE_H_ */
