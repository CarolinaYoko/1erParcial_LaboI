
#ifndef REPARACION_H_
#define REPARACION_H_

struct{

	int dia;
	int mes;
	int anio;

}typedef eFecha;

struct{

	int id;
	int serie;
	int idServicio;
	eFecha fecha;
	int isEmpty;

}typedef eReparacion;

int initReparacion(eReparacion*list, int len);
void harcodeoDatosReparacion(eReparacion* list,int tam,int* idElectrodomesticos);
int findReparacionById(eReparacion *list, int len, int id);
int printReparaciones(eReparacion *list, int len);
int printReparacion(eReparacion *list, int len, int id);
int addReparacion(eReparacion *list, int len, int id, eElectrodomestico *lista,	int lenElec, eServicio *servicios, int lenServ);
int updateReparacion(eReparacion *list, int len);
int removeReparacion(eReparacion *list, int len);



#endif /* REPARACION_H_ */
