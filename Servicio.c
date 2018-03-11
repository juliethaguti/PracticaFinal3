
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Servicio.h"

Servicio* servicio_new(char* codigoProducto,float costo,char* fecha,int idCliente,int estadoServicio)
{
        Servicio* this = malloc(sizeof(Servicio));

        if(this != NULL)
        {

                servicio_setCodigoProducto(this,codigoProducto);
                servicio_setCosto(this,costo);
                servicio_setFecha(this,fecha);
                servicio_setIdCliente(this,idCliente);
                servicio_setEstadoServicio(this,estadoServicio);
        }
        return this;
}

void servicio_delete(Servicio* this)
{
        free(this);
}

int servicio_setCodigoProducto(Servicio* this,char* codigoProducto)
{
        strcpy(this->codigoProducto,codigoProducto);
        return 0;
}

int servicio_setCosto(Servicio* this,float costo)
{
        this->costo = costo;
        return 0;
}

int servicio_setFecha(Servicio* this,char* fecha)
{
        strcpy(this->fecha,fecha);
        return 0;
}

int servicio_setIdCliente(Servicio* this,int idCliente)
{
        this->idCliente = idCliente;
        return 0;
}

int servicio_setEstadoServicio(Servicio* this,int estadoServicio)
{
        this->estadoServicio = estadoServicio;
        return 0;
}

char* servicio_getCodigoProducto(Servicio* this)
{
        return this->codigoProducto;
}

float servicio_getCosto(Servicio* this)
{
        return this->costo;
}

char* servicio_getFecha(Servicio* this)
{
        return this->fecha;
}

int servicio_getIdCliente(Servicio* this)
{
        return this->idCliente;
}

int servicio_getEstadoServicio(Servicio* this)
{
        return this->estadoServicio;
}

Servicio* servicio_findByCodigoProducto(ArrayList* pArray,char* codigoProducto)
{

        int i;
        Servicio* aux;
        Servicio* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(codigoProducto,servicio_getCodigoProducto(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Servicio* servicio_findByCosto(ArrayList* pArray,float costo)
{

        int i;
        Servicio* aux;
        Servicio* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(costo == servicio_getCosto(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Servicio* servicio_findByFecha(ArrayList* pArray,char* fecha)
{

        int i;
        Servicio* aux;
        Servicio* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(strcmp(fecha,servicio_getFecha(aux))==0)
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Servicio* servicio_findByIdCliente(ArrayList* pArray,int idCliente)
{

        int i;
        Servicio* aux;
        Servicio* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(idCliente == servicio_getIdCliente(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

Servicio* servicio_findByEstadoServicio(ArrayList* pArray,int estadoServicio)
{

        int i;
        Servicio* aux;
        Servicio* retorno=NULL;
        for(i=0;i<al_len(pArray);i++)
        {
                aux = al_get(pArray,i);
                if(estadoServicio == servicio_getEstadoServicio(aux))
                {
                        retorno = aux;
                        break;
                }
        }
        return retorno;
}

int servicio_compareByCodigoProducto(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(servicio_getCodigoProducto(pA),servicio_getCodigoProducto(pB));

        return retorno;
}

int servicio_compareByCosto(void* pA ,void* pB)
{

        int retorno = 0;

        if(servicio_getCosto(pA) > servicio_getCosto(pB))
                retorno = 1;
        else if(servicio_getCosto(pA) < servicio_getCosto(pB))
                retorno = -1;

        return retorno;
}

int servicio_compareByFecha(void* pA ,void* pB)
{

        int retorno;

        retorno = strcmp(servicio_getFecha(pA),servicio_getFecha(pB));

        return retorno;
}

int servicio_compareByIdCliente(void* pA ,void* pB)
{

        int retorno = 0;

        if(servicio_getIdCliente(pA) > servicio_getIdCliente(pB))
                retorno = 1;
        else if(servicio_getIdCliente(pA) < servicio_getIdCliente(pB))
                retorno = -1;

        return retorno;
}

int servicio_compareByEstadoServicio(void* pA ,void* pB)
{

        int retorno = 0;

        if(servicio_getEstadoServicio(pA) > servicio_getEstadoServicio(pB))
                retorno = 1;
        else if(servicio_getEstadoServicio(pA) < servicio_getEstadoServicio(pB))
                retorno = -1;

        return retorno;
}
