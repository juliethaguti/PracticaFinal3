#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "DataManager.h"
#include "Cliente.h"
#include "Servicio.h"
#include "Validaciones.h"
#include "string.h"

int dm_saveAllCliente(ArrayList* pArrayClientes)
{
    int i;
    int retorno=-1;

    FILE* pArchivoClientes=fopen(ARCHIVO_CLIENTES,"wb");
    void* pCliente=NULL;
    if(pArchivoClientes!=NULL)
    {
        for(i=0;i<al_len(pArrayClientes);i++)
        {
            pCliente=al_get(pArrayClientes,i);
            fwrite(pCliente,sizeof(Cliente),1,pArchivoClientes);
            retorno=0;
        }

    }
    fclose(pArchivoClientes);

    return retorno;
}

int dm_readAllCliente(ArrayList* pArrayClientes)
{
    int retorno=-1;

     Cliente auxCliente;
    int maxId=0;
    Cliente* pCliente=NULL;
    FILE* pArchivoClientes=fopen(ARCHIVO_CLIENTES,"rb");

    if(pArchivoClientes!=NULL)
    {
        do{
            if(fread(&auxCliente,sizeof(Cliente),1,pArchivoClientes)==1)
            {
                pCliente=cliente_new(auxCliente.nombre,auxCliente.apellido,auxCliente.dni,auxCliente.idCliente,auxCliente.estadoCliente);
                al_add(pArrayClientes,pCliente);
                if(auxCliente.idCliente > maxId)
                {
                    maxId=auxCliente.idCliente;
                }
                retorno=maxId;
            }
        }while(!feof(pArchivoClientes));
        fclose(pArchivoClientes);
    }

    return retorno;
}


int dm_readAllClienteArchivo(ArrayList* pArrayClientesArchivo,int idMayor)
{

    int retorno=-1;
    FILE *pFile;
	Cliente* auxCliente;

    char var1[50],var2[50],var3[50];

    pFile = fopen("clientes.csv","r");

	if(pFile!=NULL)
    {
		fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        do{
            if(fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3) >0)

			{
				if( val_validarString(var1)!=-1 && val_validarString(var2)!=-1 && val_validarUnsignedInt(var3)!=-1 )
				{
				    if(cliente_findByDni(pArrayClientesArchivo,var3) == NULL)
				    {
				        auxCliente=cliente_new(var1, var2, var3,idMayor,ESTADO_CLIENTE_ACTIVO);
                        al_add(pArrayClientesArchivo, auxCliente);
                        idMayor++;
                        retorno=idMayor;
				    }
				    else
                    {
                        printf("\n*****El dni: %s ya esta en la base de datos******\n",var3);
                    }
				}
			}
		}while(!feof(pFile));
        fclose(pFile);
	}

    return retorno;
}

//Servicio

int dm_saveAllServicio(ArrayList* pArrayServicios)
{
    int i;
    int retorno=-1;

    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"wb");
    void* pServicio=NULL;
    if(pArchivoServicios!=NULL)
    {
        for(i=0;i<al_len(pArrayServicios);i++)
        {
            pServicio=al_get(pArrayServicios,i);
            fwrite(pServicio,sizeof(Servicio),1,pArchivoServicios);
            retorno=0;
        }

    }
    fclose(pArchivoServicios);

    return retorno;
}


int dm_saveServicioPorFecha(ArrayList*nominaServicio,ArrayList* nominaCliente,char* fechaIngreso)
{
    int i,idCliente;
    int retorno=-1;
    char* auxFecha;
    FILE* pFile=fopen("clienteFecha.csv","w");
    void* pClientes=NULL;
    void* pServicios = NULL;

    if(pFile != NULL)
    {
		fprintf(pFile,"nombreCliente,apellidoCliente,dniCliente,codigoArticulo,costo\n");
        for(i=0;i<al_len(nominaServicio);i++)
        {
            pServicios = al_get(nominaServicio,i);
            auxFecha = servicio_getFecha(pServicios);

            if(strcmp(fechaIngreso,auxFecha) == 0)
            {
                idCliente = servicio_getIdCliente(pServicios);

                pClientes=cliente_findByIdCliente(nominaCliente,idCliente);

                if(cliente_getEstadoCliente(pClientes) == ESTADO_CLIENTE_ACTIVO)
                {
                    fprintf(pFile,"\n%s,%s,%s,%s,%f\n", cliente_getNombre(pClientes), cliente_getApellido(pClientes), cliente_getDni(pClientes),servicio_getCodigoProducto(pServicios),servicio_getCosto(pServicios));
                    printf("aaaaaa");
                }
            }

            retorno=0;
        }

    }
    fclose(pFile);
    return retorno;
}


int dm_readAllServicio(ArrayList* pArrayServicios)
{

    int retorno=-1;
    Servicio auxServicio;
    Servicio* pServicio=NULL;
    FILE* pArchivoServicios=fopen(ARCHIVO_SERVICIOS,"rb");

    if(pArchivoServicios!=NULL)
    {
        do{
            if(fread(&auxServicio,sizeof(Servicio),1,pArchivoServicios)==1)
            {
                pServicio=servicio_new(auxServicio.codigoProducto,auxServicio.costo,auxServicio.fecha,auxServicio.idCliente,auxServicio.estadoServicio);
                al_add(pArrayServicios,pServicio);
            }
        }while(!feof(pArchivoServicios));
        fclose(pArchivoServicios);
    }

    return retorno;
}
