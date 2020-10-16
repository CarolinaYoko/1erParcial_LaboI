#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "servicio.h"
#include "marca.h"
#include "UTN.h"

int findServicioById(eServicio *list, int len, int id) {
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

int printServicios(eServicio *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {

		printf("\n\t| %5s | %11s | %11s |\n", "ID", "Descripcion", "Precio");

		for (i = 0; i < len; i++) {

			printf("\t| %5d | %11s | %11f |\n", list[i].id, list[i].descripcion,
					list[i].precio);
		}
		retorno = 0;
	}

	return retorno;
}

int printServicio(eServicio *list, int len, int id) {

	int retorno = -1;
	int indice;
	if (list != NULL && len > 0) {

		indice = findServicioById(list, len, id);

		printf("\n\t| %5s | %11s | %11s |\n", "ID", "Descripcion", "Precio");

		printf("\t| %5d | %11s | %11f |\n", list[indice].id,
				list[indice].descripcion, list[indice].precio);

		retorno = 0;
	}
	return retorno;
}

int validarIdServicio(eServicio *list, int len, int id) {

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

int pedirServicioporId(int *id, char *mensaje, char *mensajeError,
		eServicio *list, int len, int reintentos) {
	int retorno = -1;
	int idBuffer;

	if (id != NULL && list != NULL && len > 0 && reintentos >= 0) {

		do {
			if (printServicios(list, len) == 0
					&& utn_getNumeroIntMin(&idBuffer, mensaje, mensajeError, 20000, 2)==0 && validarIdServicio(list, len, idBuffer)==0) {
				*id = idBuffer;
				retorno = 0;
				break;
			}
			reintentos--;

		} while (reintentos >= 0);
	}
	return retorno;
}

int cargarDescServicio(int id, eServicio *list, int len, char *desServicio) {

	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && desServicio != NULL) {

		for (i = 0; i < len; i++) {
			if (list[i].id == id) {
				strncpy(desServicio, list[i].descripcion, 26);
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
