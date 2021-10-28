/*
 * Informes.h
 *
 *  Created on: 19 oct. 2021
 *      Author: quisp
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Salas.h"
#include "Arcade.h"

int listarSalonesMinCuatroArc(Sala listaSala[], int lonSala, Arcade listaArcade[], int lonArc);
int listarArcadesMinDosJugadores(Arcade listaArcade[], int lonArc, Sala listaSala[], int lonSala);
int listarSalonEsp(Arcade listaArcade[], int lonArc, Sala* pSala, int idSalon);
int listarArcadesDeUnSalon(Arcade listaArcade[], int lonArc, int idSalon, Sala* pSala);
int imprimirSalonMaxArcades(Sala listaSala[], int lonSala, Arcade listaArcade[], int lonArc);
int montoMaxDeUnSalon(Arcade listaArcade[], int lonArc, int idSalon, Sala* pSala, float monto);
int imprimirArcadesPorJuego(Arcade listaArcade[], int lonArc, char nombreJuego[]);
int salonEquipado(Sala listaSala[], int lonSala, Arcade listaArcade[], int lonArc);
int contarJugPorArcade(int id, Arcade listaArcade[], int lonArc);
int imprimirPromedio(Sala listaSala[], int lonSala, Arcade listaArcade[], int lonArc);


#endif /* INFORMES_H_ */
