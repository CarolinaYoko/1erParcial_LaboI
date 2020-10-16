
#ifndef ELECTRODOMESTICO_H_
#define ELECTRODOMESTICO_H_

#define TAM 5
#define LEN 51
#define TRUE 0
#define FALSE 1
#define UP 1
#define DOWN 0

struct{

	int id;
	int serie;
	int idMarca;
	int modelo;
	int isEmpty;

}typedef eElectrodomestico;

int initElectrodomestico(eElectrodomestico*list, int len);
void harcodeoDatosElectrodomestico (eElectrodomestico* list,int tam,int* idElectrodomesticos);
int findElectrodomesticoById(eElectrodomestico *list, int len, int id);
int printElectrodomesticos(eElectrodomestico *list, int len);
int printElectrodomestico(eElectrodomestico *list, int len, int id);
int addElectrodomestico(eElectrodomestico *list, int len, int id);
int updateElectrodomestico(eElectrodomestico *list, int len);
int removeElectrodomestico(eElectrodomestico *list, int len);
int sortElectrodomestico(eElectrodomestico *list, int len, int order);
int hayAltasElectrodomesticos(eElectrodomestico *list, int len);
#endif /* ELECTRODOMESTICO_H_ */
