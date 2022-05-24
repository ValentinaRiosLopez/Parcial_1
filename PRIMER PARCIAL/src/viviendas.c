#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "viviendas.h"
#include "funcionesUTN.h"

#define LIBRE 1
#define OCUPADO 0

/**
 * PONE TODAS LAS POSICIONES DEL ARRAY EN 0
 * @param list
 * @param tam
 * @return 0 si tiene exito
 */

int inicializarArray(sVivienda* list, int tam)
{
	int retorno =-1;
		int i;
		if(list !=NULL && tam > 0)
		{
			for(i=0;i<tam;i++)
			{
				list[i].isEmpty = LIBRE;
			}

			retorno = 0;
		}

		return retorno;
}

/**
 * BUSCA ESPACIO PARA CARGAR DATOS
 * @param list
 * @param tam
 * @param lugar
 * @return 0 si tiene exito
 */
int buscarEspacio(sVivienda* list, int tam, int* lugar)
{
	int retorno = -1;
	int i;

	if(list != NULL && tam > 0)
	{

		for(i=0;i<tam;i++)
		{
			if(list[i].isEmpty==LIBRE)
			{
				*lugar = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * PIDE AL USUARIO LOS DATOS DE UNA VIVIENDA Y LOS CARGA AL SISTEMA
 * @param list
 * @param tam
 * @param id
 * @return 0 si tiene exito
 */
int addVivienda(sVivienda* list, int tam, int id)
{
	int retorno =-1;
	int indice;
	int legajo;

	if(list != NULL && tam > 0)
	{
		if(buscarEspacio(list, tam, &indice)==0)
		{
			list[indice].idVivienda = id;
			fflush(stdin);
			utn_getStringSoloLetras(list[indice].calle, "Ingrese el nombre de la calle: ",
									"ERROR Ingrese un nombre de menos de 25 caracteres que solo contenga letras: ",
									4,25);
			fflush(stdin);
			list[indice].cantidadDePersonas= utn_getNumero("Ingrese la cantidad de personas que residen en la vivienda: ",
											"ERROR Ingrese un numero de personas valido: ",1,10);
			fflush(stdin);
			list[indice].cantidadDeHabitaciones = utn_getNumero("Ingrese la cantidad de habitaciones que tiene la vivienda: ",
												"ERROR Ingrese un numero de habitaciones valido: ",1,10);
			fflush(stdin);
			list[indice].tipoVivienda= utn_getNumero("Seleccione el tipo de vivienda:\n"
													 "1)CASA\n"
													 "2)DEPARTAMENTO\n"
													 "3)CASILLA\n"
													 "4)RANCHO\n"
													 "Ingrese el numero: ",
													 "ERROR Ingrese una opcion valida: ",1,4);
			fflush(stdin);

			legajo = utn_getNumero("\nCensistas:\n"
								"1)Nombre: Ana, Legajo: 100\n"
								"2)Nombre: Juan, Legajo: 101\n"
								"3)Nombre: Sol, Legajo: 102\n"
								"Ingrese el numero de legajo del censista: ",
								"ERROR Ingrese un legajo existente: ",100,102);
			list[indice].legajoCensista.legajoCensista = legajo;
			fflush(stdin);

			list[indice].isEmpty = OCUPADO;

			mostrarVivienda(list[indice]);
			retorno = 0;
		}
		else
		{
			printf("No hay espacio para agregar mas viviendas...\n\n");
		}
	}


	return retorno;
}
/**
 * MUESTRA LOS DATOS DE UNA VIVIENDA POR CONSOLA
 * @param list
 */
void mostrarVivienda(sVivienda list)
{

	fflush(stdin);
	printf("ID de la vivienda: %d\n", list.idVivienda);
	utn_convertirFirstUpper(list.calle);
	printf("Calle: %s\n", list.calle);
	printf("Cantidad de personas: %d\n", list.cantidadDePersonas);
	printf("Cantidad de habitaciones: %d\n", list.cantidadDeHabitaciones);
	switch(list.tipoVivienda)
	{
	case 1:
		printf("Tipo de vivienda: Casa\n");
		break;
	case 2:
		printf("Tipo de vivienda: Departamento\n");
		break;
	case 3:
		printf("Tipo de vivienda: Casilla\n");
		break;
	case 4:
		printf("Tipo de vivienda: Rancho\n");
		break;

	}
	printf("Legajo del censista: %d\n", list.legajoCensista.legajoCensista);
}
/**
 * MUESTRA LOS DATOS DE TODAS LAS VIVIENDAS POR CONSOLA
 * @param list
 * @param tam
 */
void mostrarViviendas(sVivienda* list, int tam)
{
	int i;
	for(i = 0;i < tam; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("VIVIENDA %d:\n", i+1);
			mostrarVivienda(list[i]);
			separadorMenu();

		}
	}
}

/**
 * MODIFICA LOS DATOS DE UNA VIVIENDA Y LOS CARGA
 * @param list
 * @param tam
 * @return 0 si tiene exito
 */
int modificarVivienda(sVivienda* list, int tam)
{
	int retorno = -1;
	int idIngresada;
	int indice;
	int opcion;


	if(list != NULL && tam > 0)
	{
		idIngresada = utn_getNumero("Ingrese el numero de ID de la vivienda que desea modificar: ",
											"ERROR ingrese un ID valido (desde 20000 hasta 20100)", 20000, 20100);

		indice = findById(list, tam, idIngresada);

		if(indice != -1)
		{
			printf("Vivienda a modificar:\n\n");
			mostrarVivienda(list[indice]);
			do{
				opcion = utn_getNumero("\n---MENU DE MODIFICACION---\n"
									  "1)Modificar calle.\n"
									  "2)Modificar cantidad de personas.\n"
									  "3)Modificar cantidad de habitaciones.\n"
									  "4)Modificar tipo de vivienda.\n"
									  "5)Volver.\n"
									  "ELIJA UNA OPCION...\n","ERROR Elija una opcion valida: ", 1,5);

				switch(opcion)
				{
				case 1:
					fflush(stdin);
					utn_getStringSoloLetras(list[indice].calle, "Ingrese el nombre de la calle: ",
														"ERROR Ingrese un nombre de menos de 25 caracteres que solo contenga letras: ",
														4,25);
					retorno = 0;
					break;
				case 2:
					fflush(stdin);
					list[indice].cantidadDePersonas= utn_getNumero("Ingrese la cantidad de personas que residen en la vivienda: ",
																"ERROR Ingrese un numero de personas valido: ",1,10);
					retorno = 0;
					break;
				case 3:
					fflush(stdin);
					list[indice].cantidadDeHabitaciones = utn_getNumero("Ingrese la cantidad de habitaciones que tiene la vivienda: ",
																	"ERROR Ingrese un numero de habitaciones valido: ",1,10);

					retorno = 0;
					break;
				case 4:
					fflush(stdin);
					list[indice].tipoVivienda= utn_getNumero("Seleccione el tipo de vivienda:\n"
															 "1)CASA\n"
															 "2)DEPARTAMENTO\n"
															 "3)CASILLA\n"
															 "4)RANCHO\n"
															 "Ingrese el numero: ",
															 "ERROR Ingrese una opcion valida: ",1,4);
					retorno = 0;
					break;
				}

			}while(opcion != 5);

			if(retorno == 0)
			{
				mostrarVivienda(list[indice]);
			}

		}
		else
		{
			printf("No se ingreso una vivienda con ese ID.\n\n");
		}
	}

	return retorno;

}

/**
 * BUSCA LA POSICION DE UNA VIVIENDA SOLICITADA POR EL USUARIO MEDIANTE UN ID
 * @param list
 * @param tam
 * @param id
 * @return la posicion de la vivienda
 */

int findById(sVivienda* list, int tam, int id)
{
	int i;
	int indice = -1;

	for(i=0;i<tam;i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].idVivienda == id)
		{
			indice = i;
		}
	}

	return indice;
}

/**
 * HACE UNA BAJA LOGICA PARA PODER ELIMINAR UNA VIVIENDA
 * @param list
 * @param tam
 * @param id
 * @return 0 si tiene exito
 */

int removeVivienda(sVivienda* list, int tam, int id)
{
	int retorno = -1;
		int indice;
		char opcion;

		if(list != NULL && tam > 0)
		{


			indice = findById(list, tam, id);
			if(indice != -1)
			{
				printf("Vivienda a eliminar: \n");
				mostrarVivienda(list[indice]);
				opcion = utn_getRespuesta("Seguro que desea eliminar esta vivienda? (s/n):",
										"ERROR ingrese 's' para si o 'n' para no: ");
				if(opcion=='s')
				{
					list[indice].isEmpty = LIBRE;
					printf("Vivienda eliminada exitosamente...\n\n");
					retorno = 0;
				}
			}
			else
			{
				printf("ERROR No existe ninguna vivienda con ese ID\n\n");
			}


		}

		return retorno;
}

/**
 * ORDENA LOS DATOS ALFABETICAMENTE MEDIANTE EL NOMBRE DE LA CALLE
 * Y SI SON IGUALES ORDENA DE MAYOR A MENOR POR CANTIDAD DE HABTANTES
 * @param list
 * @param tam
 * @return 0 si tiene exito
 */
int ordenarViviendas(sVivienda* list, int tam)
{
	int i;
	int flagSwap;
	int retorno = -1;
	sVivienda auxVivienda;
	int nuevoLimite;

	if(list != NULL && tam > -1)
	{
		nuevoLimite = tam - 1;
		do{
			flagSwap = 0;
			for(i=0; i<nuevoLimite; i++)
			{
				if(strcmp(list[i].calle,list[i+1].calle)>0 || (strcmp(list[i].calle,list[i+1].calle)== 0
						&& list[i].cantidadDePersonas < list[i+1].cantidadDePersonas))
				{
					auxVivienda = list[i];
					list[i] = list[i+1];
					list[i+1] = auxVivienda;
					flagSwap = 1;
				}
			}
			nuevoLimite--;
		}while(flagSwap);
		retorno = 0;
	}

	return retorno;
}
