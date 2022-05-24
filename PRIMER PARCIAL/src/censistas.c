#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "censistas.h"
#include "funcionesUTN.h"


void mostrarCensista(sCensista list)
{
	printf("ID: %d Nombre: %s Edad:%d Telefono: %li\n", list.legajoCensista, list.nombre, list.edad, list.telefono);
}

void mostrarCensistas(sCensista* list, int tam)
{
	int i;
		for(i = 0;i < tam; i++)
		{

			mostrarCensista(list[i]);

		}
}


