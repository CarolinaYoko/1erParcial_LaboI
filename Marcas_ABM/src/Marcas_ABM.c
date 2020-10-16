/*
 ============================================================================
 Name        : Marcas_ABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "electrodomestico.h"
#include "reparacion.h"
#include "servicio.h"
#include "marca.h"
#include "UTN.h"

int main(void) {

	setbuf(stdin, NULL);
	eServicio servicio[] = { { 20000, "Garantia", 250 }, { 20001,
			"Mantenimiento", 500 }, { 20002, "Repuestos", 400 }, { 20003,
			"Refaccion", 600 } };
	eMarca marcas[] = { { 1000, "Wirpool" }, { 1001, "Sony" },
			{ 1002, "Liliana" }, { 1003, "Gafa" }, { 1004, "Philips" } };
	eElectrodomestico lista[TAM];
	eReparacion reparaciones[TAM];

	int idElectrodomestico = 0;
	int idReparaciones = 0;
	int opcion;
	int respuestaMenu;
	char respuestaContinuar = 's';


	initElectrodomestico(lista, TAM);
	initReparacion(reparaciones, TAM);

	//harcodeoDatosElectrodomestico (lista,TAM, &idElectrodomestico);
	//harcodeoDatosReparacion(reparaciones,TAM,&idReparaciones);

	do {
		system("cls");
		respuestaMenu = utn_getNumeroInt(&opcion, "\nMENU DE OPCIONES: \n\n"
				"1.ALTA ELECTRODOMESTICO \n"
				"2.MODIFICAR ELECTRODOMESTICO \n"
				"3.BAJA ELECTRODOMESTICO \n"
				"4.LISTAR ELECTRODOMESTICOS \n"
				"5.LISTAR MARCAS \n"
				"6.LISTAR SERVICIOS \n"
				"7.ALTA REPARACION \n"
				"8.LISTAR REPARACIONES \n"
				"9.SALIR\n"
				"Ingrese una opcion: ",
				"\nLa opcion no es valida. Reingrese \n", 1, 9, 2);

		if (!respuestaMenu) {
			system("cls");

			switch (opcion) {
			case 1:
				printf("----ALTA ELECTRODOMESTICO----\n\n");
				idElectrodomestico++;
				if (addElectrodomestico(lista, TAM, idElectrodomestico) == 0) {
					printf("\nAlta exitosa \n\n");
				} else {
					printf("\nError. Reintente\n");
				}
				system("pause");

				break;
			case 2:
				if (hayAltasElectrodomesticos(lista, TAM) == 1) {
					printf("----MODIFICAR ELECTRODOMESTICO----\n\n");

					printElectrodomesticos(lista, TAM);

					if (updateElectrodomestico(lista, TAM) == 0) {
						printf("\n\nModificacion exitosa \n\n");
						system("pause");
					} else {
						printf("\nError. Reintente\n");
					}
					system("cls");
				} else {
					printf(
							"\nNo hay electrodomesticos a modificar. Ingrese en Opcion 1. \n");
				}
				break;
			case 3:
				if (hayAltasElectrodomesticos(lista, TAM) == 1) {
					printf("----BAJA ELECTRODOMESTICO----\n\n");
					printElectrodomesticos(lista, TAM);
					if (removeElectrodomestico(lista, TAM) == 0) {
						printf("\nBaja exitosa \n\n");
						system("pause");
					} else {
						printf("\nError. Reintente\n");
					}
					system("cls");
				} else {
					printf(
							"\nNo hay electrodomesticos a bajar. Ingrese en Opcion 1. \n");
				}
				break;
			case 4:
				if (hayAltasElectrodomesticos(lista, TAM) == 1) {
					printf("----LISTAR ELECTRODOMESTICOS----\n\n");
					sortElectrodomestico(lista, TAM, 0);
					printElectrodomesticos(lista, TAM);
					system("pause");
				} else {
					printf(
							"\nNo hay electrodomesticos a listar. Ingrese en Opcion 1. \n");
				}
				break;
			case 5:
				printf("----LISTAR MARCAS----\n\n");
				printMarcas(marcas, TAM);
				system("pause");
				break;
			case 6:
				printf("----LISTAR SERVICIOS----\n\n");
				printServicios(servicio, TAM);
				system("pause");
				break;

			case 7:
				/*if (hayAltasElectrodomesticos(lista, TAM) == 1) {
					printf("----ALTA REPARACIONES----\n\n");
					idReparaciones++;
					if (addReparacion(reparaciones, TAM, idReparaciones, lista, TAM, servicio) == 0) {
						printf("\nAlta exitosa \n\n");
					} else {
						printf("\nError. Reintente\n");
					}
					system("pause");
				} else {
					printf(
							"\nNo hay electrodomesticos cargados. Ingrese en Opcion 1. \n");
				}
				break;*/

			case 8:
				printf("----LISTAR REPARACIONES----\n\n");
				printReparaciones(reparaciones, TAM);
				system("pause");
				break;

			case 9:
				printf("¿Esta seguro que desea salir?: s/n");
				fflush(stdin);
				scanf("%c", &respuestaContinuar);
				break;
			}
		} else {
			printf("Se terminaron los intentos. Reinicie");
		}
	} while (respuestaContinuar == 's');

	return EXIT_SUCCESS;
}
