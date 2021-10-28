/*
 * Arcade.c
 *
 *  Created on: 18 oct. 2021
 *      Author: quisp
 */

#include "Arcade.h"

static int buscarEspacioLibre(Arcade lista[], int lon);
void imprimirUnArcade(Arcade* arcade);

int iniArcade(Arcade lista[], int lon)
{
    int estado;

    estado = -1;
    if(lista != NULL && lon>0)
    {
    	estado = 0;//OK
        for (int i=0; i<lon ;i++)
        {
        	lista[i].estaVacio = VACIO;
        }
    }
    return estado;
}


int agregarArcade(Arcade lista[], int lon, int id, char nacionalidad[], char nombreJuego[], int tipoSonido, int cantJugadores, int capMaxFichas, int idSalon)
{
	int estado;
	int posicion;

	estado = -1;

	if(lista != NULL && lon > 0)
	{
		posicion = buscarEspacioLibre(lista, lon);
		if (posicion != -1) {
			estado = 0;
			lista[posicion].id = id;
			strcpy(lista[posicion].nacionalidad, nacionalidad);
			strcpy(lista[posicion].nombreJuego, nombreJuego);
			lista[posicion].tipoSonido = tipoSonido;
		    lista[posicion].cantJugadores = cantJugadores;
		    lista[posicion].capMaxFichas = capMaxFichas;
		    lista[posicion].idSalon = idSalon;
			lista[posicion].estaVacio = LLENO;
		}
	}
	return estado;
}

int obtenerIdArcade(void)
{
	static int contador = 0;
	contador++;

	return contador;
}

static int buscarEspacioLibre(Arcade lista[], int lon)
{
	int posicion;
	posicion = -1;

	for (int i = 0;  i < lon; ++ i)
	{
		if (lista[i].estaVacio == VACIO)
		{
			posicion = i;
			break;
		}
	}
	return posicion;
}

int buscarArcadePorid(Arcade lista[], int lon,int id)
{
	int posicion;

	posicion = -1;

	if(lista != NULL && lon>0)
	{
		for (int i = 0;  i < lon; ++ i)
		{
			if (lista[i].id == id && lista[i].estaVacio == LLENO)
			{
				posicion = i;
				break;
			}
		}
	}
	return posicion;
}

int modificarArcade(Arcade lista[], int lon, int id, char nombreJuego[], int cantJugadores)
{
	int estado;
	int posicion;

	estado = -1;

	if(lista != NULL && lon>0)
	{
		posicion = buscarArcadePorid(lista, lon, id);/*ACA ME QUEDE*/
		if (posicion != -1) {
			estado = 0;
			strcpy(lista[posicion].nombreJuego, nombreJuego);
			lista[posicion].cantJugadores = cantJugadores;
		}
	}
	return estado;
}



int eliminarArcade(Arcade lista[], int lon, int id)
{
	int estado;
	int indice;

	estado = -1;
	if(lista != NULL && lon>0)
	{
		indice=buscarArcadePorid(lista, lon, id);
		if(indice!=-1)
		{
			lista[indice].estaVacio=VACIO;
			estado=0;
		}
	}
	return estado;
	//arcade->estaVacio = VACIO;
}

int eliminarArcadesPorIdSalon(Arcade lista[], int lon, int idSalon)
{
	int estado;
	int i;

	estado = -1;
	if(lista != NULL && lon>0)
	{
		for (i = 0; i < lon; ++i) {
			if(lista[i].idSalon == idSalon)
			{
				eliminarArcade(lista, lon, lista[i].id);
			}
		}
	}
	return estado;
}

void imprimirUnArcade(Arcade* arcade)
{
	printf("\n\tID: %d\n\tNombre del Juego: %s\n\tNacionalidad: %s\n\tID del Salon: %d\n\tCantidad de Jugadores: %d\n\tCapacidad Maxima de Fichas %d",arcade->id, arcade->nombreJuego, arcade->nacionalidad, arcade->idSalon, arcade->cantJugadores, arcade->capMaxFichas);
	if(arcade->tipoSonido == MONO)
		{
			printf("\n\tTipo de Sonido: Mono\n");
		}
		else
			printf("\n\tTipo de Sonido: Estereo\n");
}

int imprimirArcades(Arcade lista[], int lon)
{
	int estado;
	estado = -1;

	if(lista != NULL && lon > 0)
	{
		for (int i = 0; i < lon; ++i) {
			if(lista[i].estaVacio == LLENO)
			{
				imprimirUnArcade(&lista[i]);
				estado = 0;
			}
		}
	}
	return estado;
}

//devuelve -> 0 encontre , -1 no encontre
int juegoEnArcade(char juego[][63], int lon, char nombreJuego[])
{
	int i;
	int estado;

	estado = -1;

	for (i = 0; i < lon; ++i) {
		//HAY UN JUEGO PARA COMPARAR
		if (strncmp(juego[i], nombreJuego,63) == 0) //iguales dev -> 0
		{
			//encontre juego
			estado = 0;
			break;
		}

	}
	return estado;
}

int generarListaJuegos(Arcade lista[], int lon, char juego[][63])
{
	int i;
	int indListaJuegos;

	indListaJuegos = -1;
	if(lista != NULL && lon > 0)
	{
		indListaJuegos = 0;
		for (i = 0; i < lon; ++i)
		{
			//hay un arcade
			if(juegoEnArcade(juego, lon, lista[i].nombreJuego) == -1)//CHAR, -1 no esta
			{
				//el juego del arcade i no esta entonces lo agrego
				strncpy(juego[indListaJuegos], lista[i].nombreJuego, 63);
				 //no es asi x q es char
				indListaJuegos++;
			}
		}
	}
	return indListaJuegos;
}

/*IMPRIMIR JUEGOS
Se imprime la lista de juegos que contienen todos los arcades sin repetir*/
//inicializarchar juegos[10][63]
int imprimirJuegosEnUso(char lista[][63], int lon)
{
	int estado = -1;
	int i;

	if(lista != NULL && lon > 0)
	{
		for (i = 0; i < lon; ++i) {
			if(strcmp(lista[i],"")!=0)
			{
				printf("\n\t%s", lista[i]);
				fflush(stdin);
				estado = 0;

			}
		}

	}
	return estado;
}

int obtenerIdJuego(void)
{
	static int contador = 0;
	contador++;

	return contador;
}

void cargarArcade(Arcade lista[], int lon, char listaJuegos[][63])
{
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Lolsito", 0, 10, 500, 7);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Wow", 1, 10, 1000, 7);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Lolsito", 1, 5, 800, 5);
	agregarArcade(lista, lon, obtenerIdArcade(), "Colombiana", "Warcraft", 0, 50, 550, 4);
	agregarArcade(lista, lon, obtenerIdArcade(), "Colombiana", "Mario Bross", 1, 4, 200, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Peruana", "Cell", 0, 6, 2000, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Boliviana", "Sonic", 0, 2, 690, 2);
	agregarArcade(lista, lon, obtenerIdArcade(), "Boliviana", "Mario Bross", 0, 8, 25000, 6);
	agregarArcade(lista, lon, obtenerIdArcade(), "Venezolana", "Magic Rush", 1, 1000, 4000, 6);
	agregarArcade(lista, lon, obtenerIdArcade(), "Venezolana", "Galaga", 1, 9, 810, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Uruguaya", "Galaga", 1, 6, 3200, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Paraguaya", "Asteroids", 0, 8, 4000, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Uruguaya", "Donkey Kong", 1, 20, 200, 2);
	agregarArcade(lista, lon, obtenerIdArcade(), "Paraguaya", "Donkey Kong", 1, 1, 1000, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Los Simpsons", 0, 30, 3000, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Boliviana", "Frogger", 1, 10, 2500, 5);

	agregarArcade(lista, lon, obtenerIdArcade(), "Uruguaya", "Asteroids", 1, 6, 3200, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Paraguaya", "Asteroids", 0, 8, 4000, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Uruguaya", "Donkey Kong", 1, 20, 200, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Paraguaya", "Donkey Kong", 1, 1, 1000, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Los Simpsons", 0, 30, 3000, 1);
	agregarArcade(lista, lon, obtenerIdArcade(), "Boliviana", "Simpsons", 1, 1, 2500, 1);

	agregarArcade(lista, lon, obtenerIdArcade(), "Uruguaya", "Asteroids", 1, 6, 3200, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Paraguaya", "Asteroids", 0, 8, 4000, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Uruguaya", "Donkey Kong", 1, 20, 200, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Paraguaya", "Donkey Kong", 1, 5, 1000, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Los Simpsons", 0, 30, 3000, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Boliviana", "Simpsons", 1, 7, 2500, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Lolsito", 0, 10, 500, 3);
	agregarArcade(lista, lon, obtenerIdArcade(), "Argentina", "Wow", 1, 10, 1000, 3);

	strncpy(listaJuegos[obtenerIdJuego()-1], "Lolsito", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Wow", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Lolsito", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Warcraft", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Mario Bross", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Cell", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Sonic", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Mario Bross", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Magic Rush", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Galaga", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Galaga", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Asteroids", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Donkey Kong", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Donkey Kong", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Los Simpsons", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Frogger", 63);

	strncpy(listaJuegos[obtenerIdJuego()-1], "Asteroids", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Asteroids", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Donkey Kong", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Donkey Kong", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Los Simpsons", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Simpsons", 63);

	strncpy(listaJuegos[obtenerIdJuego()-1], "Asteroids", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Asteroids", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Donkey Kong", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Donkey Kong", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Los Simpsons", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Simpsons", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Lolsito", 63);
	strncpy(listaJuegos[obtenerIdJuego()-1], "Wow", 63);



}
