# PracticaFinal3

Realizar un sistema que permita gestionar las raparaciones de productos a una empresa de electrodomésticos, el mismo deberá ser capaz de resguardar su información en archivos binarios (clientes.bin y servicios.bin), por lo cual al iniciar, el programa se deberá crear una lista de clientes y una de servicios, leyendo los datos de los archivos para luego permitir realizar tanto como la administración de clientes como la de operaciones dee servicio técnico e informes.

MENÚ DE LA APLICACIÓN:

1. ALTA DE CLIENTE: (Se le pedirá nombre, apellido y DNI). Se generará un ID automáticamente
2. MODIFICACIÓN DE CLIENTE: Se ingresa el ID y se permite cambiar el resto de los campos.
3. BAJA DE CIENTE: Se ingresa el ID y el cliente se eliminará. No se permite esta acción si hay ventas asociadas al cliente.
4. LISTAR CLIENTES: Se imprimirá por pantalla las lista de clientes ordenados por Apellido.
5. IMPORTAR CLIENTES DESDE CVS: Se ingresará el path de un archivo cvs, se leerá el mismo y se copiarán los datos de los clientes al sistema en e caso de que el cliente no exista. Verifcar si el cliente existe por el DNI.
