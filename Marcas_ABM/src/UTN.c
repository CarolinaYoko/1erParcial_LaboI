#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

static int myGets(char *cadena, int longitud) {
	int retorno = -1;

	if (cadena != NULL && longitud > 0
			&& fgets(cadena, longitud, stdin) == cadena) {
		fflush(stdin);
		if (cadena[strlen(cadena) - 1] == '\n') {
			cadena[strlen(cadena) - 1] = '\0';
			retorno = 0;
		}
	}
	return retorno;
}

static int esNumerica(char *cadena) {
	int retorno = 1;
	int i = 0;

	if (cadena[0] == '-') {
		i = 1;
	}
	for (; cadena[i] != '\0'; i++) {

		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int esNumeroDecimal(char *cadena) {
	int retorno = 1;
	int i = 0;
	int flagPunto = 0;

	if (cadena[0] == '-') {
		i = 1;
	}
	for (; cadena[i] != '\0'; i++) {
		if (cadena[i] == '.' && flagPunto == 0) {
			flagPunto = 1;
			continue;
		}

		if (cadena[i] > '9' || cadena[i] < '0') {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int esTexto(char *cadena) {
	int i;
	int retorno = 1;

	if (isspace(cadena[0])) {
		retorno = 0;
	}
	for (i = 0; cadena[i] != '\0'; i++) {

		if (!(isspace(cadena[i]) || isalpha(cadena[i]))) {
			retorno = 0;
			break;
		}
	}
	return retorno;
}

static int getInt(int *pResultado) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esNumerica(buffer)) {
		*pResultado = atoi(buffer);
		retorno = 0;
	}
	return retorno;
}

static int getFloat(float *pResultado) {
	int retorno = -1;
	char buffer[4096];

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esNumeroDecimal(buffer)) {
		*pResultado = atof(buffer);
		retorno = 0;
	}
	return retorno;
}

static int getString(char *pResultado) {
	int retorno = -1;
	char buffer[4096];

	fflush(stdin);

	if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
			&& esTexto(buffer)) {
		strcpy(pResultado, buffer);
		retorno = 0;
	}

	return retorno;

}

int utn_getNumeroInt(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			if (getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			fflush(stdin);
			printf("%s \n", mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}


int utn_getNumeroIntMin(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int reintentos) {

	int buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			 && reintentos >= 0) {

		do {
			printf("%s", mensaje);
			fflush(stdin);
			if (getInt(&buffer) == 0 && buffer >= minimo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			fflush(stdin);
			printf("%s \n", mensajeError);
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int utn_getCaracter(char *pResultado, char *mensaje, char *mensajeError,
		char minimo, char maximo, int reintentos) {

	char buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%c", &buffer);
			if (buffer >= minimo && buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}

			printf("%s \n", mensajeError);
			reintentos--;
		} while (reintentos >= 0);

	}

	return retorno;
}

int utn_getNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError,
		float minimo, float maximo, int reintentos) {

	float buffer; //espacios de intercambio con el usuario
	int retorno = -1;

	do {
		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& minimo <= maximo && reintentos >= 0) {
			printf("%s", mensaje);
			if (getFloat(&buffer) == 0 && buffer >= minimo
					&& buffer <= maximo) {
				*pResultado = buffer;
				retorno = 0;
				break;
			}
			printf("%s \n", mensajeError);
			reintentos--;
		}

	} while (reintentos >= 0);

	return retorno;
}

int utn_getTexto(char *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {
	char buffer[4096]; //espacios de intercambio con el usuario
	int retorno = -1;

	do {
		if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
				&& minimo <= maximo && reintentos >= 0) {

			printf("%s", mensaje);
			if (getString(buffer) == 0 && strlen(buffer) >= minimo
					&& strlen(buffer) <= maximo) {

				strcpy(pResultado, buffer);
				retorno = 0;
				break;

			}
			printf("%s \n", mensajeError);
			reintentos--;
		}

	} while (reintentos >= 0);

	return retorno;
}

static int esFecha(char *cadena, int *dia, int *mes, int *anio) {

	int vRetorno = 0;
	int i = 0;
	char vDia[3];
	char vMes[3];
	char vAnio[5];
	int numDia;
	int numMes;
	int numAnio;
	//char prueba;

	if (cadena != NULL && strlen(cadena) > 0) {

		while (cadena[i] != '\0') {

			if ((i != 2 && i != 5 && (cadena[i] < '0' || cadena[i] > '9'))
					|| (i > 10 || ((i == 2 || i == 5) && cadena[i] != '/'))) {
				vRetorno = -1;
				break;
			}


			switch (i) {
			case 0:
			case 1:
				vDia[i]= cadena[i];
				break;
			case 2:
				vDia[i]= '\0';
				break;
			case 3:
			case 4:
				vMes[i-3]= cadena[i];
				break;
			case 5:
				vMes[i-3]= '\0';
				break;
			case 6:
				strcpy(vAnio, &cadena[i]);
				break;
			}

			i++;
		}

		if (vRetorno == 0) {//si pasó la primer parte del control
			numDia = atoi(vDia);
			numMes = atoi(vMes);
			numAnio = atoi(vAnio);

			if (numMes >= 1 && numMes <= 12) {
				switch (numMes) {
				case 4:
				case 6:
				case 9:
				case 11:
					if (numDia < 1 && numDia > 30) {
						vRetorno = -1;
					}
					break;
				case 2:
					if (numAnio % 4 == 0 && numDia < 1 && numDia > 28) {
						vRetorno = -1;
					} else if (numAnio % 4 != 0 && numDia < 1 && numDia > 29) {
						vRetorno = -1;
					}
					break;
				default:
					if (numDia < 1 || numDia > 31) {
						vRetorno = -1;
					}
					break;

					if (vRetorno == 0) {
						*dia = numDia;
						*mes = numMes;
						*anio = numAnio;
					}
					printf("\n  %d",vRetorno);
					system("pause");
				}
			}
		}
	}

	return vRetorno;
}

static int getStringFecha(int *pResultadoDia, int *pResultadoMes,int *pResultadoAnio) {

	int vRetorno = -1;
	char vBuffer[4096];
	int vBufferDia;
	int vBufferMes;
	int vBufferAnio;

	if (pResultadoDia != NULL && pResultadoMes != NULL && pResultadoAnio != NULL) {
		if (myGets(vBuffer, sizeof(vBuffer)) == 0
				&& esFecha(vBuffer, &vBufferDia, &vBufferMes, &vBufferAnio) == 0
				&& strlen(vBuffer) < 11) {

			*pResultadoDia = vBufferDia;
			*pResultadoMes = vBufferMes;
			*pResultadoAnio = vBufferAnio;

			vRetorno = 0;

		}
	}

	return vRetorno;

}
int utn_getFecha(int *dia, int *mes, int *anio, char *mensaje,char *mensajeError, int reintentos) {

	int vRetorno = -1;
	int vBanderaReintentos = 1;

	if (reintentos == 0) {
		vBanderaReintentos = 0;
	}


	if (dia != NULL && mes != NULL && anio != NULL && mensaje != NULL
			&& mensajeError != NULL && reintentos >= 0) {

		do {
			printf(mensaje);
			if (vBanderaReintentos == 1) {

				printf(" (tiene %d intentos) ", reintentos);

			}

			if (getStringFecha(dia, mes, anio) == 0)
			{
				vRetorno = 0;
				break;
			}

			printf(mensajeError);
			reintentos--;

		} while (reintentos >= 0);

	}

	return vRetorno;

}

