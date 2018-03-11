#include "ArrayList.h"

#include "ArrayList.h"

#ifndef _SERVICIO_H
#define _SERVICIO_H
typedef struct
{
        char codigoProducto[10];
        float costo;
        char fecha[10];
        int idCliente;
        int estadoServicio;
}Servicio;
#endif// _SERVICIO_H
#define ESTADO_SERVICIO_CANCELADO 0
#define ESTADO_SERVICIO_PENDIENTE 1

#define cod1 "TV_LG_32"
#define cod2 "PS4"
#define cod3 "IPHONE7"

Servicio* servicio_new(char* codigoProducto,float costo,char* fecha,int idCliente,int estadoServicio);
void servicio_delete(Servicio* this);
int servicio_setCodigoProducto(Servicio* this,char* codigoProducto);
int servicio_setCosto(Servicio* this,float costo);
int servicio_setFecha(Servicio* this,char* fecha);
int servicio_setIdCliente(Servicio* this,int idCliente);
int servicio_setEstadoServicio(Servicio* this,int estadoServicio);
char* servicio_getCodigoProducto(Servicio* this);
float servicio_getCosto(Servicio* this);
char* servicio_getFecha(Servicio* this);
int servicio_getIdCliente(Servicio* this);
int servicio_getEstadoServicio(Servicio* this);
Servicio* servicio_findByCodigoProducto(ArrayList* pArray,char* codigoProducto);
Servicio* servicio_findByCosto(ArrayList* pArray,float costo);
Servicio* servicio_findByFecha(ArrayList* pArray,char* fecha);
Servicio* servicio_findByIdCliente(ArrayList* pArray,int idCliente);
Servicio* servicio_findByEstadoServicio(ArrayList* pArray,int estadoServicio);
int servicio_compareByCodigoProducto(void* pA ,void* pB);
int servicio_compareByCosto(void* pA ,void* pB);
int servicio_compareByFecha(void* pA ,void* pB);
int servicio_compareByIdCliente(void* pA ,void* pB);
int servicio_compareByEstadoServicio(void* pA ,void* pB);
