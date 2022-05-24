/*
 * viviendas.h
 *
 *  Created on: 24 may. 2022
 *      Author: ogfri
 */

#ifndef VIVIENDAS_H_
#define VIVIENDAS_H_
#include "censistas.h"


typedef struct
{
	int idVivienda;
	char calle[25];
	int cantidadDePersonas;
	int cantidadDeHabitaciones;
	int tipoVivienda;
	sCensista legajoCensista;
	int isEmpty;

}sVivienda;

#endif /* VIVIENDAS_H_ */

int inicializarArray(sVivienda* list, int tam);
int buscarEspacio(sVivienda* list, int len, int* lugar);
int addVivienda(sVivienda* list,int tam, int id);
void mostrarVivienda(sVivienda list);
void mostrarViviendas(sVivienda* list, int tam);
int modificarVivienda(sVivienda* list, int tam);
int findById(sVivienda* list, int tam, int id);
int removeVivienda(sVivienda* list, int tam, int id);
int listarViviendas(sVivienda* list, int tam);
int ordenarViviendas(sVivienda* list, int tam);

