#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Vista.h"
#include "Cliente.h"
#include "Servicio.h"

static ArrayList* nominaCliente;
static ArrayList* nominaServicio;
static int proximoIdCliente = 0;
static int getNewIdCliente();
static int setNewIdCliente(int id);

void cont_init()
{
    nominaCliente = al_newArrayList();
    nominaServicio = al_newArrayList();
    setNewIdCliente(dm_readAllCliente(nominaCliente) + 1);
    dm_readAllServicio(nominaServicio);
    vista_init(VISTA_IDIOMA_ES);
    vista_mostrarMenu();
}

int cont_altaCliente (char* nombre,char* apellido,char* dni)
{
    Cliente* cliente = cliente_new(nombre,apellido,dni,getNewIdCliente(),ESTADO_CLIENTE_ACTIVO);

    if(cliente != NULL)
    {
        al_add(nominaCliente,cliente);
    }

    dm_saveAllCliente(nominaCliente);

    return 0;
}

int cont_bajaCliente (int id)
{
    Cliente* auxCliente = cliente_findByIdCliente(nominaCliente,id);
    //Servicio* auxServicio = servicio_findByEstadoServicio()

    if(auxCliente != NULL)
    {
        cliente_setEstadoCliente(auxCliente, ESTADO_CLIENTE_INACTIVO);

    }

    dm_saveAllCliente(nominaCliente);

    return 0;
}


int cont_modificarCliente (int id, char* nombre,char* apellido,char* dni)
{
    int retorno = -1;
    Cliente* auxCliente = cliente_findByIdCliente(nominaCliente,id);

    if(auxCliente != NULL)
    {
        cliente_setNombre(auxCliente,nombre);
        cliente_setApellido(auxCliente,apellido);
        cliente_setDni(auxCliente,dni);
        retorno = 0;

        dm_saveAllCliente(nominaCliente);
    }

    return retorno;
}

int cont_listarCliente ()
{
    vista_mostrarCliente(nominaCliente);
    return 0;
}

int cont_ordenarCliente ()
{
    al_sort(nominaCliente,cliente_compareByApellido,1);

    return 0;
}

static int getNewIdCliente()
{
    return proximoIdCliente++;
}

static int setNewIdCliente(int id)
{
    proximoIdCliente = id;
    return 0;
}

int cont_ImportarClientesCSV()
{
    setNewIdCliente(dm_readAllClienteArchivo(nominaCliente,getNewIdCliente()) + 1);
    dm_saveAllCliente(nominaCliente);
}

//SERVICIO

int cont_altaServicio(int idCliente,char* codigoProducto,float costoReparacion,char* fechaIgreso)
{
    Cliente* cliente = cliente_findByIdCliente(nominaCliente,idCliente);

    if(cliente != NULL)
    {
        if(strcmp(codigoProducto,cod1) == 0  || strcmp(codigoProducto,cod2) == 0 || strcmp(codigoProducto,cod3) == 0)
        {
             Servicio* servicio = servicio_new(codigoProducto,costoReparacion,fechaIgreso,idCliente,ESTADO_SERVICIO_PENDIENTE);

            if(servicio != NULL)
            {
                al_add(nominaServicio,servicio);
            }

            dm_saveAllServicio(nominaServicio);
        }
        else
        {
            printf("\n\nCodigo del producto invalido!!\n");
        }
    }
    else
    {
        mostrarError("\n\nId invalido!!\n");
    }
    vista_mostrarServicio(nominaServicio);
    return 0;
}

int cont_exportarServicios(char* fechaIngreso)
{
    dm_saveServicioPorFecha(nominaServicio,nominaCliente,fechaIngreso);
}

int cont_serviciosPorProducto()
{

}
