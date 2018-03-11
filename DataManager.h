#define ARCHIVO_CLIENTES "cliente.bin"
#define ARCHIVO_SERVICIOS "servicio.bin"

int dm_saveAllCliente(ArrayList* pArrayClientes);
int dm_readAllCliente(ArrayList* pArrayCliente);
int dm_readAllClienteArchivo(ArrayList* pArrayClientesArchivo,int idMayor);

int dm_saveAllServicio(ArrayList* pArrayServicios);
int dm_saveServicioPorFecha(ArrayList*nominaServicio,ArrayList* nominaCliente,char* fechaIngreso);
int dm_readAllServicio(ArrayList* pArrayServicios);
