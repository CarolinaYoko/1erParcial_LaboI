#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "servicio.h"
#include "marca.h"
#include "UTN.h"

int findMarcaById(eMarca *list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int printMarcas(eMarca *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {

		printf("\n\t| %5s | %11s | \n", "ID", "Descripcion");

		for (i = 0; i < len; i++) {

			printf("\t| %5d | %11s | \n", list[i].id, list[i].descripcion);
		}
		retorno = 0;
	}

	return retorno;
}

int printMarca(eMarca *list, int len, int id) {

	int retorno = -1;
	int indice;
	if (list != NULL && len > 0) {

		indice = findMarcaById(list, len, id);

		printf("\n\t| %5s | %11s | \n", "ID", "Descripcion");

		printf("\t| %5d | %11s | \n", list[indice].id, list[indice].descripcion);

		retorno = 0;
	}
	return retorno;
}

int validarIdMarca(eMarca *list, int len, int id) {

	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int pedirMarcaporId(int *id, char *mensaje, char *mensajeError,
		eMarca *list, int len, int reintentos) {
	int retorno = -1;
	int idBuffer;

	if (id != NULL && list != NULL && len > 0 && reintentos >= 0) {

		do {
			if (printMarcas(list, len) == 0
					&& utn_getNumeroIntMin(&idBuffer, mensaje, mensajeError, 1000, 2)==0 && validarIdMarca(list, len, idBuffer)==0) {
				*id = idBuffer;
				retorno = 0;
				break;
			}
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int cargarDescMarca(int id, eMarca *list, int len, char *desMarca) {

	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && desMarca != NULL) {

		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				strncpy(desMarca, list[i].descripcion, 21);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
