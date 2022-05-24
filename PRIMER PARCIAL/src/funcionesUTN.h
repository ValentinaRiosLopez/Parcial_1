

#ifndef FUNCIONESUTN_H_
#define FUNCIONESUTN_H_

//int
int utn_getNumero(char* mensaje, char* mensajeError, int minimo, int maximo);
//char
char utn_getChar(char* mensaje, char* mensajeError, char maximo, char minimo);
//float
float utn_getFloat(char* mensaje, char* mensajeError, int minimo, int maximo);
float utn_sumarFloat(float numeroUno, float numeroDos);
float utn_restarFloat(float numeroUno, float numeroDos);
float utn_dividirFloat(float numeroUno, float numeroDos);
float utn_multiplicarFloat(float numeroUno, float numeroDos);
float utn_porcentajeFloat(float numero, int porcentaje);
//string
int utn_getString(char* cadena, char* mensaje, char* mensajeError, int min, int max);
int utn_getStringSoloLetras(char* cadena, char* mensaje, char* mensajeError, int min, int max);
int utn_validarCadena(char* cadena);
void utn_convertirUpper(char* cadena);
void utn_convertirFirstUpper(char* cadena);
void separadorMenu();
void limpiarConsola();

#endif /* FUNCIONESUTN_H_ */
