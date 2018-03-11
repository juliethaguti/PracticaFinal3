#ifndef VISTA_H_INCLUDED
#define VISTA_H_INCLUDED

#endif // VISTA_H_INCLUDED

#define VISTA_IDIOMA_ES 0
#define VISTA_IDIOMA_EN 1

#define MENU_PPAL_ES "\n\n1. Alta de Cliente\n2. Modificacion del Cliente\n3.Baja de Cliente\n4. Listar Clientes\n5. Importar Clientes desde CSV\
\n6. Ingresar un servicio tecnico \n7. Exportar servicios tecnicos de fecha\n8. Exportar servicios tecnicos por producto\n9. Imformar\n10. Salir\n"
#define MENU_PPAL_ERROR_ES "\nOPCION INVALIDA\n"

#define MENU_PUNTO9 "\na. Producto con mayor numero de servicios tecnicos pendientes\nb. Cliente con mayor deuda de servicios técnicos pendientes\n"


int vista_init (int idioma);
int vista_mostrarMenu();
void mostrarError(char * mensaje);
void vista_mostrarCliente(ArrayList* pListaSocios);
void vista_mostrarServicio(ArrayList* pListaServicios);




