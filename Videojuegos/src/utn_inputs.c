/*
 * utn_inputs.c
 *
 *  Created on: 13 oct. 2021
 *      Author: quisp
 */

#include "utn_inputs.h"


static int esNumerica(char cadenaNumeros[]);
static int esNumericaFloat(char cadenaNumeros[]);
static int myGets(char pResultado[], int len);
int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos);
int esTexto(char cadena[]);
int utn_getNatu(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos);

static int esNumerica(char cadenaNumeros[])
{
    int i;
    int estado;

    i = 0;
    estado = -1;

    if(cadenaNumeros != NULL)
    {
        while(cadenaNumeros[i] != '\0')
        {
            estado = 0;
            if(cadenaNumeros[i] < '0' || cadenaNumeros[i] > '9')
            {
                //si esta mal
                estado = -1;
                break;
            }
            i++;
        }
    }
    return estado;
}

/*int esNumerica(char cadenaNumeros[])
{
    int i;
    int estado;

    estado = -1;

    if(cadenaNumeros != NULL && strlen(cadenaNumeros) > 0)
    {
        for(i = 0; cadenaNumeros[i] != '\0'; i++)//i<strlen(cadena)
        {
            estado = 0;
            if(cadenaNumeros[i] < '0' || cadenaNumeros > '9')
            {
                //si esta mal
                estado = -1;
                break;
            }
        }
    }
    return estado;
}
*/

static int esNumericaFloat(char cadenaNumeros[])
{
    int i;
    int estado;
    int contadorPuntos;

    i = 0;
    estado = -1;
    contadorPuntos = 0;

    if(cadenaNumeros != NULL)
    {
        while(cadenaNumeros[i] != '\0')
        {
            estado = 0;
            if(cadenaNumeros[i] < '0' || cadenaNumeros[i] > '9')
            {
                if(cadenaNumeros[i] == '.')
                {
                    contadorPuntos++;
                }
                else//no me encontre ni con numero ni con punto entonces es letra
                {
                    estado=-1;
                    break;
                }
                if(contadorPuntos >= 2)
                {
                    estado = -1;
                    break;
                }
            }
            i++;
        }
    }
    return estado;
}

int utn_getInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
		    fflush(stdin);

			//if(scanf("%d", &bufferInt)==1)
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esNumerica(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferInt = atoi(bufferCadenaAux);

					if(bufferInt >= minimo && bufferInt <= maximo){
						*pResultado = bufferInt;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
						fflush(stdin);
					}
				}
				else {
					printf("%s", mensajeError);
					fflush(stdin);
				}
			}
			else {
				printf("%s", mensajeError);
				fflush(stdin);
			}
		}
	}
	return retorno;
}

int utn_getNatu(int* pResultado, char* mensaje, char* mensajeError, int minimo, int reintentos)
{
	int retorno = -1;
	int bufferNatu;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo > 0 && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
		    fflush(stdin);

			//if(scanf("%d", &bufferInt)==1)
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esNumerica(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferNatu = atoi(bufferCadenaAux);

					if(bufferNatu >= minimo){
						*pResultado = bufferNatu;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
						fflush(stdin);
					}
				}
				else {
					printf("%s", mensajeError);
					fflush(stdin);
				}
			}
			else {
				printf("%s", mensajeError);
				fflush(stdin);
			}
		}
	}
	return retorno;
}

int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	int i;
	char bufferCadenaAux[64];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
		    fflush(stdin);

			//if(scanf("%d", &bufferInt)==1)
			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esNumericaFloat(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferFloat = atof(bufferCadenaAux);

					if(bufferFloat >= minimo && bufferFloat <= maximo){
						*pResultado = bufferFloat;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
						fflush(stdin);
					}
				}
				else {
					printf("%s", mensajeError);
					fflush(stdin);
				}
			}
			else {
				printf("%s", mensajeError);
				fflush(stdin);
			}
		}
	}
	return retorno;
}

int utn_getText(char pResultado[], int len, char* mensaje, char* mensajeError, int reintentos)
{
	int retorno = -1;
	int i;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
    	for(i=0; i<=reintentos; i++)//se pueden sacar los reintentos
    	{
    		printf("%s", mensaje);
    		fflush(stdin);
			if(myGets(pResultado, len) == 0)//stdin representa el archivo, dist de null pudo leer
			{
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				fflush(stdin);
			}
    	}
	}
	return retorno;
}

static int myGets(char pResultado[], int len)
{
	int retorno=-1;
	int indexFinal;

	//gets(pResultado); // NOOOOOOO
	//if(scanf("%s", pResultado)==1) // NOOOOOOO
	if(fgets(pResultado,len,stdin)!=NULL)
	{
		// borro el \n del final
		indexFinal = strlen(pResultado)-1;
		if(pResultado[indexFinal] == '\n')
		{
			pResultado[indexFinal] = '\0';
		}
		retorno = 0;
	}
	return retorno;
}

int esTexto(char cadena[])
{
    int retorno = 0;
    int i = 0;
    while(cadena[i] != '\0')
    {
        if(
                (cadena[i] < 'A') ||
                (cadena[i] > 'Z' && cadena[i] < 'a') ||
                (cadena[i] >'z')
            )
        {
            //Error
            retorno = -1;
            break;
        }
        i++;
    }
    return retorno;
}

int getEmployee(char name[], char lastName[], float* salary, int* sector)
{
	int status;

	status = -1;

	if (utn_getText(name, 51, "Ingrese el nombre\n", "Error ", 3) == 0)
	{
		if (utn_getText(lastName, 51, "Ingrese el apellido\n", "Error ", 3) == 0)
		{
			if (utn_getFloat(salary, "Ingrese el salario\n", "Error ", 0, 1000000000, 3) == 0)
			{
				if (utn_getNatu(sector, "Ingrese el sector\n", "Error ", 1, 3) == 0)
				{
					status = 0;
				}
			}
		}
	}
	return status;
}

int obtenerSala(char nombre[], char direccion[], int* tipo)
{
	int status;

	status = -1;

	if (utn_getText(nombre, 128, "Ingrese el nombre\n", "Error ", 3) == 0)
	{
		if (utn_getText(direccion, 128, "Ingrese la direccion\n", "Error ", 3) == 0)
		{
			if (utn_getInt(tipo, "Ingrese el tipo de salon\n\tSHOPPING->1 \n\tLOCAL->0\n", "Error ", 0, 1, 3) == 0)
			{
				status = 0;
			}
		}
	}
	return status;
}

int obtenerArcade(char nacionalidad[], char nombreJuego[], int* tipoSonido, int* cantJugadores, int* capMaxFichas, int* idSalon)
{
	int status;

	status = -1;

	if (utn_getText(nacionalidad, 128, "Ingrese la nacionalidad\n", "Error ", 3) == 0)
	{
		if (utn_getText(nombreJuego, 63, "Ingrese el nombre\n", "Error ", 3) == 0)
		{
			if (utn_getInt(tipoSonido, "Ingrese el tipo de Sonido\n\tMONO->1 \n\tESTEREO->0\n", "Error ", 0, 1, 3) == 0)
			{
				if (utn_getNatu(cantJugadores, "Ingrese la cantidad de jugadores\n", "Error ", 1, 3) == 0) {
					if (utn_getNatu(capMaxFichas, "Ingrese la capacidad maxima de fichas\n", "Error ", 1, 3) == 0) {
						if(utn_getNatu(idSalon, "Ingrese el id del salon\n", "Error ", 1, 3) == 0)
						{
							status = 0;
						}
					}
				}
			}
		}
	}
	return status;
}
