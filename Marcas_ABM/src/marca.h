/*
 * marca.h
 *
 *  Created on: 15 oct. 2020
 *      Author: Carolina
 */

#ifndef MARCA_H_
#define MARCA_H_

#define TAM 5
#define LEN 51
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 0

struct{

	int id;
	char descripcion [21];

}typedef eMarca;
int findMarcaById(eMarca *list, int len, int id);
int printMarcas(eMarca *list, int len);
int printMarca(eMarca *list, int len, int id);
int validarIdMarca(eMarca *list, int len, int id);
int pedirMarcaporId(int *id, char *mensaje, char *mensajeError,
		eMarca *list, int len, int reintentos);
int cargarDescMarca(int id, eMarca *list, int len, char *desMarca);


#endif /* MARCA_H_ */
