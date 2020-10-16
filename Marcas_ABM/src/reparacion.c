#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "servicio.h"
#include "marca.h"
#include "UTN.h"

int initReparacion(eReparacion *list, int len) {
	int i;
	int retorno = -1;
	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}
	return retorno;
}

void harcodeoDatosReparacion(eReparacion *list, int tam,
		int *idElectrodomesticos) {

	*idElectrodomesticos = 2;
	int id[2] = { 1, 2 };
	int serie[2] = { 123456, 7891022 };
	int idServicio[2] = { 20000, 20003 };
	eFecha modelo[2] = { { 20, 03, 2019 }, { 20, 06, 2020 } };
	int isEmpty[2] = { 1, 1 };

	for (int i = 0; i < 2; ++i) {
		list[i].id = id[i];
		list[i].serie = serie[i];
		list[i].idServicio = idServicio[i];
		list[i].fecha = modelo[i];
		list[i].isEmpty = isEmpty[i];

	}

}

int findReparacionById(eReparacion *list, int len, int id) {
	int retorno = -1;
	int i;

	if (list != NULL && len > 0 && id > 0) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpty == TRUE) {
				continue;
			} else if (list[i].id == id) {
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int printReparaciones(eReparacion *list, int len) {
	int i;
	int retorno = -1;

	if (list != NULL && len > 0) {

		printf("\n\t| %5s | %11s | %11s | %10s |\n", "ID", "Serie",
				"ID-Servicio", "Fecha");

		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == FALSE) {

				printf("\t| %5d | %11d | %11d | %2d/%2d/%4d |\n", list[i].id,
						list[i].serie, list[i].idServicio, list[i].fecha.dia,
						list[i].fecha.mes, list[i].fecha.anio);
			}
		}
		retorno = 0;
	}

	return retorno;
}

int printReparacion(eReparacion *list, int len, int id) {

	int retorno = -1;
	int indice;
	if (list != NULL && len > 0) {
		indice = findReparacionById(list, len, id);
		printf("\n\t| %5s | %8s | %8s | %10s |\n", "ID", "Serie", "ID-Servicio",
				"Fecha");

		printf("\t| %5d | %8d | %8d | %2d/%2d/%4d |\n", list[indice].id,
				list[indice].serie, list[indice].idServicio,
				list[indice].fecha.dia, list[indice].fecha.mes,
				list[indice].fecha.anio);

		retorno = 0;
	}
	return retorno;
}

int addReparacion(eReparacion *list, int len, int id, eElectrodomestico *lista,
		int lenElec, eServicio *servicios, int lenServ) {
	int retorno = -1;
	int i = 0;

	if (list != NULL && len > 0) {

		printElectrodomesticos(lista, lenElec);
		printServicios(servicios, lenServ);
		for (i = 0; i < len; i++) {

			if (list[i].isEmpty == TRUE) {

				if (utn_getNumeroIntMin(&lista[i].id,
						"Ingrese el ID del electrodomestico: ",
						"El ID ingresado no es valido. Reingrese", 1, 2) == 0
						&& utn_getNumeroIntMin(&list[i].serie,
								"Ingrese la serie: ",
								"La serie ingresada no es valido. Reingrese", 1,
								2) == 0
						&& utn_getNumeroInt(&list[i].idServicio,
								"Ingrese el ID del servicio: ",
								"El ID ingresado no es valido. Reingrese",
								20000, 20003, 2) == 0
						&& utn_getFecha(&list[i].fecha.dia, &list[i].fecha.mes,
								&list[i].fecha.anio, "Ingrese una fecha: ",
								"La fecha ingresada no es valida. Reingrese", 2)
								== 0) {
					list[i].id = id;
					list[i].isEmpty = FALSE;
					retorno = 0;
					break;
				} else {
					printf("Error en la carga. Reintente \n");
					retorno = -1;
					system("pause");
				}
			}
		}
	}
	if (retorno == -1) {
		printf("No hay lugar disponible");
	}

	return retorno;
}

int updateReparacion(eReparacion *list, int len) {
	int retorno = -1;
	int resultado;
	int id;
	int menu;
	int indice;

	resultado = utn_getNumeroInt(&id, "Ingrese el ID de la reparacion: ",
			"El ID no es valido. Reingrese", 1, 99999, 2);
	indice = findReparacionById(list, len, id);

	if (list != NULL && len > 0 && resultado == 0 && indice != -1) {

		utn_getNumeroInt(&menu,
				"\nIngrese el campo a modificar: \n\n1-Serie \n2-IdServicio \n3-Fecha \n\nIngrese una opcion: ",
				"La opcion no es valida. Reingrese\n", 1, 3, 2);

		switch (menu) {
		case 1:
			if (utn_getNumeroInt(&list[indice].serie, "Ingrese la serie: ",
					"La serie ingresado no es valido. Reingrese", 100, 99999, 2)
					== 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 2:
			if (utn_getNumeroInt(&list[indice].idServicio,
					"Ingrese el ID del servicio: ",
					"La ID no es valido. Reingrese\n", 20000, 20003, 2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;
		case 3:
			if (utn_getFecha(&list[indice].fecha.dia, &list[indice].fecha.mes,
					&list[indice].fecha.anio, "Ingrese una fecha: ",
					"La fecha ingresada no es valida. Reingrese", 2) == 0) {
				retorno = 0;
			} else {
				retorno = -1;
			}
			break;

		}
		printReparacion(list, len, id);
		retorno = 0;
	}
	return retorno;
}

int removeReparacion(eReparacion *list, int len) {
	int retorno = -1;
	int id;
	int indice;

	utn_getNumeroInt(&id, "\nIngrese el ID a eliminar: ",
			"\nEl ID no es valido. Reingrese", 1, 99999, 2);
	indice = findReparacionById(list, len, id);

	if (list != NULL && len > 0 && indice > 0) {
		list[indice].isEmpty = TRUE;
		retorno = 0;
	}
	return retorno;
}

