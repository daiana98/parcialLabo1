/*
 * Informes.c
 *
 *  Created on: 19 oct. 2021
 *      Author: quisp
 */

#include "Informes.h"


static int cantArcadesPorSalon(Sala* pSala, Arcade listaArcade[], int lonArc);
/*Listar los salones con más de 4 arcades. Indicando ID de salón, nombre, dirección y tipo de salón.*/

static int cantArcadesPorSalon(Sala* pSala, Arcade listaArcade[], int lonArc)
{
	int cant;
	int i;

	cant = -1;
	if(listaArcade != NULL && lonArc > 0)
	{
		for (i = 0; i < lonArc; ++i) {
			if(listaArcade[i].estaVacio == LLENO && pSala->id == listaArcade[i].idSalon)
			{
				cant++;
			}
		}
	}
	return cant;
}

int listarSalonesMinCuatroArc(Sala listaSala[], int lonSala, Arcade listaArcade[], int lonArc)
{
	int estado;
	int i;

	estado = -1;
	if(listaSala != NULL && lonSala > 0)
	{
		for (i = 0; i < lonSala; ++i)
		{
			estado = 0;
			if(listaSala[i].estaVacio == LLENO)
			{
				if(cantArcadesPorSalon(&listaSala[i], listaArcade, lonArc)+1 >= 4)
				{
					imprimirSala(&listaSala[i]);
					estado = 0;
				}
			}
		}
	}
	return estado;
}

/*Listar los arcades para más de 2 jugadores, indicando ID de arcade, cantidad de jugadores, nombre del juego y
nombre del salón al que pertenece.*/
void imprimirUnArcadeConNom(Sala listaSala[], int lonSala, int idSalon, Arcade* arcade)
{
	int i;

	printf("\n\tID: %d\n\tNombre del Juego: %s\n\tNacionalidad: %s\n\tTipo de Sonido: %d\n\tCantidad de Jugadores: %d\n\tCapacidad Maxima de Fichas %d",arcade->id, arcade->nombreJuego, arcade->nacionalidad, arcade->tipoSonido, arcade->cantJugadores, arcade->capMaxFichas);
	for (i = 0; i < lonSala; ++i) {
		if (listaSala[i].id == idSalon) {
			printf("\n\tNombre del Salon: %s\n", listaSala[i].nombre);
		}
	}

}

int listarArcadesMinDosJugadores(Arcade listaArcade[], int lonArc, Sala listaSala[], int lonSala)
{
	int estado;
	int i;

	estado = -1;
	if(listaArcade != NULL && listaSala != NULL && lonArc > 0 && lonSala > 0)
	{
		for (i = 0; i < lonArc; ++i) {
			estado = 0;
			if(listaArcade[i].estaVacio == LLENO && listaArcade[i].cantJugadores >= 2)
			{
				imprimirUnArcadeConNom(listaSala, lonSala, listaArcade[i].idSalon, &listaArcade[i]);
				estado = 0;
			}
		}
	}
	return estado;
}

/*Listar toda la información de un salón en específico ingresando su ID. Imprimir nombre, tipo y dirección y cantidad
de arcades que posee.*/

int listarSalonEsp(Arcade listaArcade[], int lonArc, Sala* pSala, int idSalon)
{
	int estado;
	int cantArcades;

	estado = -1;
	if(listaArcade != NULL && lonArc > 0)
	{
		cantArcades = cantArcadesPorSalon(pSala, listaArcade, lonArc)+1;
		estado = 0;
		printf("\n\tID: %d\n\tNombre del Salon: %s \n\tDireccion: %s \n\tCantidad de arcades: %d", pSala->id, pSala->nombre, pSala->direccion, cantArcades);
		if(pSala->tipo == LOCAL)
		{
			printf("\n\tTipo de Salon: Local\n");
		}
		else
			printf("\n\tTipo de Salon: Shopping\n");
	}
	return estado;
}

/* Listar todos los arcades de un salón determinado ingresando su ID. Informar nombre y tipo de salón, listar todos
los arcades con sus datos junto con el nombre del juego que lo compone.
 */
int pertenece(Arcade* pArcade, Sala* pSala)
{
	int estado;

	estado = -1;

	if(pArcade->estaVacio == LLENO && pArcade->idSalon == pSala->id)
	{
		estado = 0;
	}
	return estado;
}

int listarArcadesDeUnSalon(Arcade listaArcade[], int lonArc, int idSalon, Sala* pSala)
{
	int estado;
	int i;

	estado = -1;

	if (listaArcade != NULL && lonArc > 0) {
		listarSalonEsp(listaArcade, lonArc, pSala, idSalon);
		for (i = 0; i < lonArc; ++i) {
			if (pertenece(&listaArcade[i], pSala) == 0) {
				imprimirUnArcade(&listaArcade[i]);
				estado = 0;
			}
		}
	}
	return estado;
}

/*Imprimir el salón con más cantidad de arcades, indicando todos los datos del salón y la cantidad de arcades que
posee.*/

int imprimirSalonMaxArcades(Sala listaSala[], int lonSala, Arcade listaArcade[], int lonArc)
{
	int i;
	int indSalonMax;
	int maxArcadesPorSalon;
	int bandera;
	int cantArc;

	indSalonMax = -1;
	bandera = 0;
	if(listaArcade != NULL && listaSala != NULL && lonArc > 0 && lonSala > 0)
	{
		for (i = 0; i < lonSala; ++i)
		{
			indSalonMax = 0;
			if(listaSala[i].estaVacio == LLENO)
			{
				if(bandera == 0)
				{
					maxArcadesPorSalon = cantArcadesPorSalon(&listaSala[i], listaArcade, lonArc)+1;
					indSalonMax = 0;
				}
				else
				{
					cantArc = cantArcadesPorSalon(&listaSala[i], listaArcade, lonArc)+1;
					if(cantArc > maxArcadesPorSalon)
					{
						maxArcadesPorSalon = cantArc;
						indSalonMax = i;
					}
				}
			}
		}
	}
	return indSalonMax;
}

/* Ingresar el ID de un salón, y el valor en pesos de una ficha, e imprimir el monto máximo en pesos que puede
recaudar el salón (sumar cantidad de fichas máximo de cada arcade del salón y multiplicarla por el valor en pesos
ingresado)
 * */

int montoMaxDeUnSalon(Arcade listaArcade[], int lonArc, int idSalon, Sala* pSala, float monto)
{
	int estado;
	int i;
	int cantFichas;
	float montoTotal;

	estado = -1;
	montoTotal = 0;
	if (listaArcade != NULL && lonArc > 0) {
		cantFichas = 0;
		estado = 0;
		for (i = 0; i < lonArc; ++i)
		{
			if (pertenece(&listaArcade[i], pSala) == 0)
			{
				cantFichas+=listaArcade[i].capMaxFichas;
			}
		}
		montoTotal = cantFichas * monto;
		if(cantFichas > 0)
		{
			printf("\nEl monto máximo en pesos que puede recaudar el salón es %f", montoTotal);
		}
		else
			printf("\nLa Sala no posee fichas");


	}
	return estado;
}

/* Ingresar el nombre de un juego e imprimir cuantos arcades lo contienen.*/
int imprimirArcadesPorJuego(Arcade listaArcade[], int lonArc, char nombreJuego[])
{
	int i;
	int cantArcades;

	cantArcades = -1;
	if(listaArcade != NULL && lonArc > 0)
	{
		for (i = 0; i < lonArc; ++i) {
			if(listaArcade[i].estaVacio == LLENO)
			{
				if(strcmp(nombreJuego, listaArcade[i].nombreJuego) == 0)//iguales
				{
					imprimirUnArcade(&listaArcade[i]);
					cantArcades++;
				}
			}
		}
	}
	return cantArcades;
}
