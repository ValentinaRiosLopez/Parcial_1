#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "censistas.h"
#include "funcionesUTN.h"

/**
 * MUESTRA LOS DATOS DE UN CENSISTA POR COSOLA
 * @param list
 */
void mostrarCensista(sCensista list)
{
	printf("ID: %d NOMBRE: %s EDAD:%d TELEFONO: %li\n", list.legajoCensista, list.nombre, list.edad, list.telefono);
}

/**
 * MUESTRA LOS DATOS DE TODOS LOS CENSISTAS POR CONSOLA
 * @param list
 * @param tam
 */
void mostrarCensistas(sCensista* list, int tam)
{
	int i;
		for(i = 0;i < tam; i++)
		{

			mostrarCensista(list[i]);

		}
}


