
/*
 * Rios Lopez, Valentina
 * 1D
 * LABORATORIO DE PROGRAMACION
 * PRIMER PARCIAL 2022
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesUTN.h"
#include "viviendas.h"
#include "censistas.h"
#define TAM 100



int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	sVivienda auxVivienda[TAM];
	sCensista auxCensista[] = {{100, "Ana", 34, 12032345},
							  {101, "Juan", 24, 430154678},
							  {102, "Sol", 47, 590237487}};
	int idVivienda = 20000;
	int id;


	inicializarArray(auxVivienda, TAM);





	do{
		separadorMenu();
		opcion = utn_getNumero("\n==========MENU==========\n"
								  "1)ALTA VIVIENDA.\n"
								  "2)MODIFICAR VIVIENDA.\n"
								  "3)BAJA VIVIENDA.\n"
								  "4)LISTAR VIVIENDAS.\n"
								  "5)LISTAR CENSISTAS.\n"
								  "6)Salir.\n"
								  "ELIJA UNA OPCION...\n","ERROR ELIJA UNA OPCION ENTRE 1 Y 6...",1,6);
		switch(opcion)
		{
		case 1:
			if(addVivienda(auxVivienda, TAM, idVivienda)==0)
			{
				idVivienda++;
				printf("Vivienda agregada exitosamente...\n\n");


			}
			else
			{
				printf("ERROR No se pudo agregar la vivienda...\n\n");
			}
			system("pause");
			break;
		case 2:
			if(idVivienda != 20000)
			{
				if(modificarVivienda(auxVivienda, TAM)== 0)
				{
					printf("Vivienda modificada con exito...\n\n");
				}
				else
				{
					printf("No se pudo modificar la vivienda...\n\n");
				}
			}
			else
			{
				printf("ERROR Primero debe ingresar una vivienda.\n\n");
			}
			system("pause");
			break;
		case 3:
			if(idVivienda != 20000)
			{
				id = utn_getNumero("Ingrese el numero de ID de la vivienda que desea eliminar: ",
									"ERROR ingrese un ID valido (desde 20000 hasta 20100)", 20000, 20100);

				removeVivienda(auxVivienda, TAM, id);
			}
			else
			{
				printf("ERROR Primero debe ingresar una vivienda.\n\n");
			}
			system("pause");
			break;
		case 4:
			if(idVivienda != 20000)
			{
				printf("---INICIO DE LISTADO---\n");
				ordenarViviendas(auxVivienda, TAM);
				mostrarViviendas(auxVivienda, TAM);
				printf("----FIN DEL LISTADO----\n\n");
			}
			else
			{
				printf("ERROR Primero debe ingresar una vivienda.\n\n");
			}
			system("pause");
			break;
		case 5:

			printf("---Listado Censistas---\n");

			mostrarCensistas(auxCensista, 3);

			system("pause");
			break;

		}

	}while(opcion !=6);

	if(opcion == 6)
	{
		printf("\n====FIN DEL PROGRAMA====\n");
	}

	return EXIT_SUCCESS;
}


