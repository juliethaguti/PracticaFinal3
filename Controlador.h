void cont_init();
int cont_altaCliente (char* nombre,char* apellido,char* dni);
int cont_bajaCliente (int id);
int cont_modificarCliente (int id, char* nombre,char* apellido,char* dni);
int cont_listarCliente ();
int cont_ordenarCliente ();
int cont_ImportarClientesCSV();

int cont_altaServicio(int idCliente,char* codigoProducto,float costoReparacion,char* fechaIgreso);
int cont_exportarServicios(char* fechaIngreso);
int cont_serviciosPorProducto();
