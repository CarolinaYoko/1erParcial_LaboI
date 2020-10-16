
#ifndef SERVICIO_H_
#define SERVICIO_H_

struct{

	int id;
	char descripcion[26];
	float precio;


}typedef eServicio;

int findServicioById(eServicio *list, int len, int id);

int printServicios(eServicio *list, int len);

int printServicio(eServicio *list, int len, int id);

int validarIdServicio(eServicio *list, int len, int id);

int pedirServicioporId(int *id, char *mensaje, char *mensajeError,
		eServicio *list, int len, int reintentos);

int cargarDescServicio(int id, eServicio *list, int len, char *desServicio);

#endif /* SERVICIO_H_ */
