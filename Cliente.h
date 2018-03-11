#include "ArrayList.h"

#ifndef _CLIENTE_H
#define _CLIENTE_H
typedef struct
{
        char nombre[50];
        char apellido[50];
        char dni[20];
        int idCliente;
        int estadoCliente;
}Cliente;
#endif// _CLIENTE_H

#define ESTADO_CLIENTE_INACTIVO 0
#define ESTADO_CLIENTE_ACTIVO 1

Cliente* cliente_new(char* nombre,char* apellido,char* dni,int idCliente,int estadoCliente);
void cliente_delete(Cliente* this);
int cliente_setNombre(Cliente* this,char* nombre);
int cliente_setApellido(Cliente* this,char* apellido);
int cliente_setDni(Cliente* this,char* dni);
int cliente_setIdCliente(Cliente* this,int idCliente);
int cliente_setEstadoCliente(Cliente* this,int estadoCliente);
char* cliente_getNombre(Cliente* this);
char* cliente_getApellido(Cliente* this);
char* cliente_getDni(Cliente* this);
int cliente_getIdCliente(Cliente* this);
int cliente_getEstadoCliente(Cliente* this);
Cliente* cliente_findByNombre(ArrayList* pArray,char* nombre);
Cliente* cliente_findByApellido(ArrayList* pArray,char* apellido);
Cliente* cliente_findByDni(ArrayList* pArray,char* dni);
Cliente* cliente_findByIdCliente(ArrayList* pArray,int idCliente);
Cliente* cliente_findByEstadoCliente(ArrayList* pArray,int estadoCliente);
int cliente_compareByNombre(void* pA ,void* pB);
int cliente_compareByApellido(void* pA ,void* pB);
int cliente_compareByDni(void* pA ,void* pB);
int cliente_compareByIdCliente(void* pA ,void* pB);
int cliente_compareByEstadoCliente(void* pA ,void* pB);
Cliente* cliente_newArchivo(char* nombre,char* apellido,char* dni);
