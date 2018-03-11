#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "ArrayList.h"
#include "Vista.h"
#include "Controlador.h"
#include "Servicio.h"
#include "Cliente.h"


static void opcionAltaCliente();
static void opcionBajaCliente();
static void opcionModificacionCliente();
static void opcionListadoCliente();
static void opcionOrdenarCliente();
static int idiomaVista;
static void opcionImportarClientesCSV();
static void opcionIngresarServicio();
static void opcionExportarServicios();
static void opcionMostrarServiciosPorProducto();


int vista_init (int idioma)
{
    idiomaVista = idioma;
    return 0;
}

int vista_mostrarMenu()
{
    char buffer[10];
    int option=0;

    while(option != 10)
    {
        val_getInt(buffer, MENU_PPAL_ES, MENU_PPAL_ERROR_ES,2,5);
        option = atoi(buffer);

        switch(option)
        {
            case 1:
                opcionAltaCliente();
                break;
            case 2:
                opcionModificacionCliente();
                break;
            case 3:
                opcionBajaCliente();
                break;
            case 4:
                opcionListadoCliente();
                break;
            case 5:
                opcionImportarClientesCSV();
                break;
            case 6:
                opcionIngresarServicio();
                break;
            case 7:
                opcionExportarServicios();
                break;
            case 8:
                opcionMostrarServiciosPorProducto();
                break;
        }
    }

    return 0;
}

void vista_mostrarCliente(ArrayList* pListaSocios)
{
    Cliente* auxCliente;
    int i;

    cont_ordenarCliente();

    for( i = 0; i< al_len(pListaSocios); i++)
    {
        auxCliente = al_get(pListaSocios,i);
        printf("\nID: %d - NOMBRE: %s - APELLIDO: %s - DNI: %s",cliente_getIdCliente(auxCliente),cliente_getNombre(auxCliente),cliente_getApellido(auxCliente),cliente_getDni(auxCliente));

    }
}


void mostrarError(char * mensaje)
{

    printf("\n%s\n",mensaje);

}

static void opcionAltaCliente()
{
    char nombre[50];
    char apellido[50];
    char dni[20];
    if(val_getString(nombre, "Nombre? ", "Error",2,50) == 0 &&
       val_getString(apellido, "Apellido? ", "Error",2,50) == 0 &&
       val_getInt(dni, "Dni? ", "Error",2,20) == 0)
    {
        cont_altaCliente(nombre,apellido,dni);
    }


}

static void opcionBajaCliente()
{
    char auxId[10];
    int id;

    if((val_getUnsignedInt(auxId,"Id a dar de baja" , "Error",2,10)==0))
    {
        id = atoi(auxId);
        cont_bajaCliente(id);
    }

}

static void opcionModificacionCliente()
{
    char auxId[10];
    int id;
    char nombre[50];
    char apellido[50];
    char dni[50];
    int retorno;

    if((val_getUnsignedInt(auxId,"Id a modificar: " , "Error",2,10)==0))
    {
        id = atoi(auxId);
        if(val_getString(nombre, "\nNombre? ", "Error",2,50) == 0 &&
           val_getString(apellido, "\nApellido? ", "Error",2,50) == 0 &&
           val_getInt(dni, "\nDNI? ", "Error",2,50) == 0)
        {
            retorno = cont_modificarCliente(id,nombre,apellido,dni);
            if(retorno != 0)
            {
                printf("El cliente no existe");
            }
        }
    }
}

static void opcionListadoCliente()
{
    cont_listarCliente();
}

static void opcionOrdenarCliente()
{
    cont_ordenarCliente();
}

static void opcionImportarClientesCSV()
{

    cont_ImportarClientesCSV();
}


//SERVICIO


static void opcionIngresarServicio()
{

    char idCliente[50];
    char codigoProducto[50];
    char costoReparacion[20];
    char fechaIngreso[20];

    if(val_getInt(idCliente, "id del cliente? ", "Error",2,50) == 0 &&
       val_getDescripcion(codigoProducto, "Codigo del producto? ", "Error",2,50) == 0 &&
       val_getFloat(costoReparacion, "Costo de la reparacion? ", "Error",2,20) == 0 &&
       val_getDate(fechaIngreso,"Fecha q ingresa el producto?","Error",2,20) == 0)
    {
        cont_altaServicio(atoi(idCliente),codigoProducto,atof(costoReparacion),fechaIngreso);
    }
}

void vista_mostrarServicio(ArrayList* pListaServicios)
{
    Servicio* auxServicio;
    int i;

//    cont_ordenarServicio();

    for( i = 0; i< al_len(pListaServicios); i++)
    {
        auxServicio = al_get(pListaServicios,i);
        printf("\nIDCLIENTE: %d - CODIGO PRODUCTO: %s - COSTO: %f - FECHA INGRESO: %s",servicio_getIdCliente(auxServicio),servicio_getCodigoProducto(auxServicio),
               servicio_getCosto(auxServicio),servicio_getFecha(auxServicio));

    }
}

static void opcionExportarServicios()
{
    char fechaIngreso[20];

    if(val_getDate(fechaIngreso,"Fecha?","Error",2,20) == 0)
    {
        cont_exportarServicios(fechaIngreso);
    }
}

static void opcionMostrarServiciosPorProducto()
{
    cont_serviciosPorProducto();
}
