

#ifndef CENSISTAS_H_
#define CENSISTAS_H_

typedef struct
{
	int legajoCensista;
	char nombre[25];
	int edad;
	long int telefono;
}sCensista;

#endif /* CENSISTAS_H_ */

void mostrarCensista(sCensista list);
void mostrarCensistas(sCensista* list, int tam);
