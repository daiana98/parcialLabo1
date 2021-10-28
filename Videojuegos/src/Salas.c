/*
 * Salas.c
 *
 *  Created on: 15 oct. 2021
 *      Author: quisp
 */
#include "Salas.h"

static int buscarEspacioLibre(Sala* lista, int lon);

//devuelve Null si no se pudo y sino devuelve el puntero de la estructura sala
Sala* crearUnaSala(void)
{
	Sala* pSala;
	pSala = malloc(sizeof(Sala));

	return pSala;
}
/*------*/
int iniSalas(Sala lista[], int lon)
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

int agregarSala(Sala lista[], int lon, int id, char nombre[], char direccion[], int tipo)
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
			strcpy(lista[posicion].nombre, nombre);
			strcpy(lista[posicion].direccion, direccion);
		    lista[posicion].tipo = tipo;
			lista[posicion].estaVacio = LLENO;
		}
	}
	return estado;
}

int obtenerIdSala(void)
{
	static int contador = 0;
	contador++;

	return contador;
}

static int buscarEspacioLibre(Sala lista[], int lon)
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

int buscarSalaPorId(Sala lista[], int lon,int id)
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
//Se ingresa un ID y la misma generará la baja del salón, junto con todos los arcades que lo componen.
int eliminarSalon(Sala lista[], int lon, int id)
{
	int estado;
	int posicion;

	estado = -1;

	if(lista != NULL && lon>0)
	{
		posicion = buscarSalaPorId(lista, lon, id);
		if(posicion != -1)
		{
			estado = 0;
			lista[posicion].estaVacio = VACIO;
			//desde la main llamo a esta funcion y tambien llamo a la funcion para eliminar el arcade desde arcade.c
		}
	}
	return estado;
}

int imprimirSalones(Sala lista[], int lon)
{
	int estado;
	estado = -1;

	if(lista != NULL && lon > 0)
	{
		for (int i = 0; i < lon; ++i) {
			if(lista[i].estaVacio == LLENO)
			{
				imprimirSala(&lista[i]);
				estado = 0;
			}
		}
	}
	return estado;
}

void imprimirSala(Sala* unaSala)
{
	printf("\n\tID: %d\n\tNombre del Salon: %s \n\tDireccion: %s", unaSala->id, unaSala->nombre, unaSala->direccion);
	if(unaSala->tipo == LOCAL)
	{
		printf("\n\tTipo de Salon: Local\n");
	}
	else
		printf("\n\tTipo de Salon: Shopping\n");
}

void cargarSalas(Sala lista[], int lon)
{
	agregarSala(lista, lon, obtenerIdSala(), "La casa de los Juegos", "Calle Falsa 123", 0);
	agregarSala(lista, lon, obtenerIdSala(), "La casita del miedo", "Av. Siempreviva 123", 1);
	agregarSala(lista, lon, obtenerIdSala(), "El hueco", "Calle Falsa 123", 0);
	agregarSala(lista, lon, obtenerIdSala(), "El barco de la diversion", "Av. rivadavi 2342", 1);
	agregarSala(lista, lon, obtenerIdSala(), "El rincon de los deseos", "Moron 543", 1);
	agregarSala(lista, lon, obtenerIdSala(), "El banco de diversion", "mozart 677", 0);
	agregarSala(lista, lon, obtenerIdSala(), "Llendo a la diversion", "Av. alberdi 4587", 0);
	agregarSala(lista, lon, obtenerIdSala(), "Divertite con amigos", "Azul 123", 1);
}
