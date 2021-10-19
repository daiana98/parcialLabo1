/*
 ============================================================================
 Name        : Videojuegos.c
 Author      : Quispe Daiana Violeta
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Salas.h"
#include "Arcade.h"
#include "Informes.h"
#include "utn_inputs.h"

#define LON_SALAS 100
#define LON_ARC 1000
#define REINTENTOS 3

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int subOption;
	char nombreSala[LON_C];
	char direccionSala[LON_C];
	int tipoSala;
	int idSala;
	int ind;
	int idArcade;
	char nacionalidad[LON_C];
	char nombreJuego[63];
	int tipoSonido;
	int cantJugadores;
	int capMaxFichas;
	float montoFicha;
	int indJuego;
	Sala listaSalas[LON_SALAS];
	Arcade listaArcades[LON_ARC];
	char juegos[1000][63];
	char juegosAux[1000][63];
	iniSalas(listaSalas, LON_SALAS);
	iniArcade(listaArcades, LON_ARC);

	cargarSalas(listaSalas, LON_SALAS);
	cargarArcade(listaArcades, LON_ARC, juegos);
	do {
		printf("\nMenu de opciones: \n\t1- ALTA DE SALON\n\t2- ELIMINAR SALON\n\t3- IMPRIMIR SALONES\n\t4- INCORPORAR ARCADE\n\t5- MODIFICAR ARCADE\n\t6- ELIMINAR ARCADE\n\t7- IMPRIMIR ARCADES\n\t8- IMPRIMIR JUEGOS\n\t9- INFORMES\n\t10- SALIR\n");
		utn_getInt(&opcion, "\nPor favor ingrese una opcion ", "\nError.", 1, 10, REINTENTOS);

		switch (opcion) {
			case 1:
				if (obtenerSala(nombreSala, direccionSala, &tipoSala) == 0)
 	 	 	 	{
	 	 	 	 	 idSala = obtenerIdSala();
	 	 	 	 	 if(agregarSala(listaSalas, LON_SALAS, idSala, nombreSala, direccionSala, tipoSala) == 0)
	 	 	 	 	 {
	 	 	 	 		 printf("\nEl salon se ha agregado correctamente");
	 	 	 	 		 ind = buscarSalaPorId(listaSalas, LON_SALAS, idSala);
	 	 	 	 		 imprimirSala(&listaSalas[ind]);
	 	 	 	 	 }else
	 	 	 	 		 printf("\nError en el alta");
 	 	 	 	}else
 	 	 	 		printf("\nError en el ingreso de datos");
				break;
			case 2:
				if(imprimirSalones(listaSalas, LON_SALAS) == 0)
				{
					if(utn_getNatu(&idSala, "\nPor favor ingrese el id del Salon que desea eliminar", "\Error.", 1, REINTENTOS) == 0)
					{
						if(buscarSalaPorId(listaSalas, LON_SALAS, idSala) != -1)
						{
							if(eliminarSalon(listaSalas, LON_SALAS, idSala) == 0 && eliminarArcadesPorIdSalon(listaArcades, LON_ARC, idSala) == 0)
							{
								printf("\nEl salon se ha eliminado correctamente");
							}
						}
						else
							printf("\nError, el id ingresado no existe.");
					}
					else
						printf("\nError en el ingreso de datos");
				}
				break;
			case 3:
				imprimirSalones(listaSalas, LON_SALAS);
				break;
			case 4:
				if(obtenerArcade(nacionalidad, nombreJuego, &tipoSonido, &cantJugadores, &capMaxFichas, &idSala) == 0)
				{
					ind = buscarSalaPorId(listaSalas, LON_SALAS, idSala);
					if(ind != -1)
					{
						idArcade = obtenerIdArcade();
						if(agregarArcade(listaArcades, LON_ARC, idArcade, nacionalidad, nombreJuego, tipoSonido, cantJugadores, capMaxFichas, idSala) == 0)
						{
							printf("\nEl arcade se ha agregado correctamente");
							indJuego = obtenerIdJuego();
							strncpy(juegos[indJuego], nombreJuego, 63);
						}
						else
							printf("\nError en el alta");
					}
					else
						printf("\nError, el id del salon no existe");
				}
				else
					printf("\nError en el ingreso de datos");
				break;
			case 5:
				if (imprimirArcades(listaArcades, LON_ARC) == 0)
				{
					if(utn_getNatu(&idArcade, "\nIngrese el id del arcade que desea modificar", "Error", 1, REINTENTOS) == 0)
					{
						ind = buscarArcadePorid(listaArcades, LON_ARC, idArcade);
						if(ind != -1)
						{
							if(utn_getInt(&subOption, "\nIngrese la opcion que desea modificar: \n\t1- Cantidad de jugadores \n\t2- Juego que contiene\n", "Error, por favor reingrese la opcion.", 1, 2, REINTENTOS) == 0)
							{
								switch (subOption) {
									case 1:
										if(utn_getNatu(&cantJugadores, "\nPor favor ingrese la cantidad de jugadores: ", "Error.", 1, REINTENTOS) == 0)
										{
											if(modificarArcade(listaArcades, LON_ARC, idArcade, listaArcades[ind].nombreJuego, cantJugadores) == 0)
											{
												printf("\nLa cantidad de jugadores del arcade se ha modificado correctamente. ");
											}
											else
												printf("\nError al modificar. ");
										}
										else
											printf("\nError en el ingreso de datos");
										break;
									case 2:
										if (generarListaJuegos(listaArcades, LON_ARC, juegosAux) >= 0) {
											if(imprimirJuegosEnUso(juegosAux, LON_ARC) == 0)
											{
												if(utn_getText(nombreJuego, 63, "\nIngrese el nombre del juego", "Error", REINTENTOS) == 0)
												{//VALIDAR QUE EL NOMBRE INGRESADO PERTENECE A LA LISTA
													if(modificarArcade(listaArcades, LON_ARC, idArcade, nombreJuego, listaArcades[ind].cantJugadores) == 0)
													{
														printf("\nEl nombre del juego del arcade se ha modeificado correctamente");
													}
													else
														printf("Error al modificar");
												}
												else
													printf("\nError en el ingreso de datos");
											}
										}//no existen juegos
										break;
								}
							}
							else
								printf("\nLa opcion ingresada es incorrecta.");
						}
						else
							printf("\nError, el id del arcade no existe");
					}
					else
						printf("\nError en el ingreso de datos");
				}
				break;
			case 6:
				if (imprimirArcades(listaArcades, LON_ARC) == 0)
				{
					if(utn_getNatu(&idArcade, "\nIngrese el id del arcade que desea modificar", "Error", 1, REINTENTOS) == 0)
					{
						ind = buscarArcadePorid(listaArcades, LON_ARC, idArcade);
						if(ind != -1)
						{
							if(utn_getInt(&subOption, "\n¿Esta seguro que desea eliminar el arcade?\n\t1- Si.\n\t2- No.\nIngrese la opcion: ", "Error", 1, 2, REINTENTOS) == 0)
							{
								if(subOption == 1)
								{
									if(eliminarArcade(listaArcades, LON_ARC, idArcade) == 0)
									{
										printf("\nEl arcade se ha eliminado correctamente. ");
									}
									else
										printf("\nError al eliminar. ");
								}
								else
									printf("\nHasta Luego.");
							}
							else
								printf("\nError, la opcion ingresada es incorrecta.");
						}
						else
							printf("\nError, el id del arcade no existe. ");
					}
					else
						printf("\nError, en el ingreso de datos. ");
				}
				break;
			case 7:
				if(imprimirArcades(listaArcades, LON_ARC) == -1)
				{
					printf("Error, al imprimir los arcades. ");
				}
				break;
			case 8:
				if(generarListaJuegos(listaArcades, LON_ARC, juegosAux) >= 0)
				{
					if(imprimirJuegosEnUso(juegosAux, LON_ARC) == -1)
					{
						printf("Error, al imprimir los juegos. ");
					}
				}
				else
					printf("\nError al generar la lista de juegos");
				break;
			case 9:
				if(utn_getInt(&subOption, "\nSUBMENU DE OPCIONES:\n\t1-  Listar los salones con más de 4 arcades.\n\t2- Listar los arcades para más de 2 jugadores."
						"\n\t3- Listar toda la información de un salón.\n\t4- Listar todos los arcades de un salón\n\t5- Imprimir el salón con más cantidad de arcades\n\t6- Imprimir el monto máximo que puederecaudar el salón"
						"\n\t7- Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen", "Error.", 1, 7, REINTENTOS) == 0)
				{
					switch (subOption) {
						case 1:
							if(listarSalonesMinCuatroArc(listaSalas, LON_SALAS, listaArcades, LON_ARC) == -1)
							{
								printf("\nError, al listar los salones con mas de 4 arcades");
							}
							break;
						case 2:
							if(listarArcadesMinDosJugadores(listaArcades, LON_ARC, listaSalas, LON_SALAS) == -1)
							{
								printf("\nError, al listar los arcades para más de 2 jugadores");
							}
							break;
						case 3:
							if(utn_getNatu(&idSala, "\nIngrese el id: ", "Error", 1, REINTENTOS) == 0)
							{
								ind = buscarSalaPorId(listaSalas, LON_SALAS, idSala);
								if(ind != -1)
								{
									if(listarSalonEsp(listaArcades, LON_ARC, &listaSalas[ind], idSala) == -1)
									{
										printf("\nError, al listar un salon en especifico");
									}
								}
								else
									printf("Error, el id del salon no existe");
							}
							else
								printf("\nError, en el ingreso de datos. ");
							break;
						case 4:
							if(utn_getNatu(&idSala, "\nIngrese el id: ", "Error", 1, REINTENTOS) == 0)
							{
								ind = buscarSalaPorId(listaSalas, LON_SALAS, idSala);
								if(ind != -1)
								{
									if(listarArcadesDeUnSalon(listaArcades, LON_ARC, idSala, &listaSalas[ind]) == -1)
									{
										printf("\nError, al listar todos los arcades de un salon");
									}
								}
								else
									printf("Error, el id del salon no existe");
							}
							else
								printf("\nError, en el ingreso de datos. ");
							break;
						case 5:
							ind = imprimirSalonMaxArcades(listaSalas, LON_SALAS, listaArcades, LON_ARC);
							if(ind >= 0)
							{
								if(listarSalonEsp(listaArcades, LON_ARC, &listaSalas[ind], listaSalas[ind].id) == -1)
								{
									printf("\nError, al imprimir el salón con más cantidad de arcades.");
								}
							}
							else
								printf("Error, no hay Salas");
							break;
						case 6:
							if(utn_getNatu(&idSala, "\nIngrese el id: ", "Error. ", 1, REINTENTOS) == 0)
							{
								ind = buscarSalaPorId(listaSalas, LON_SALAS, idSala);
								if(ind != -1)
								{
									if(utn_getFloat(&montoFicha, "\nIngrese el monto en pesos de la ficha", "Error. ", 1, 10000, REINTENTOS) == 0)
									{
										if(montoMaxDeUnSalon(listaArcades, LON_ARC, idSala, &listaSalas[ind], montoFicha) == -1)
										{
											printf("\nError, al imprimir el monto máximo en pesos ");
										}
									}
									else
										printf("\nError, en el ingreso del monto de ficha. ");
								}
								else
									printf("Error, el id del salon no existe");
							}
							else
								printf("\nError, en el ingreso de datos del id. ");
							break;
						case 7:
							if(utn_getText(nombreJuego, 63, "\nIngrese el nombre del juego", "\nError. ", REINTENTOS) == 0)
							{
								imprimirArcadesPorJuego(listaArcades, LON_ARC, nombreJuego);
							}
							break;
					}
				}
				else
					printf("\nError, en el ingreso de datos. ");
				break;
			case 10:
				printf("\nGracias por usar nuestros servicios, hasta luego");
				break;
			default:
				break;
		}

	} while (opcion != 10);

	return EXIT_SUCCESS;
}
