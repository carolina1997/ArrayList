#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Arraylist.h"
#include "Funciones.h"

int main()
{
    int opcion;
    ArrayList* listaUsuarios;
    ArrayList* listaProductos;
    listaProductos=al_newArrayList();
    listaUsuarios=al_newArrayList();
    // harcodeoUsuario(listaUsuarios);
    // harcodeoProducto(listaProductos);
    leerArchivoUsuarios(listaUsuarios);
    leerArchivoProductos(listaProductos);

    do
    {
        char menu[200]="Elija una opcion\n1-Alta de usuario\n2-Modificar datos de usuario\n3-Baja de usuario\n4-Publicar producto\n5-Modificar publicacion\n6-Cancelar publicacion\n7-Comprar producto\n8-Siguiente pagina\n9-Salir";
        puts(menu);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            altaUsuario(listaUsuarios);
            break;
        case 2://modificar usuario
            modificarUsuario(listaUsuarios,listaProductos);
            break;
        case 3://borrar usuario y todo lo que tiene
            bajaUsuario(listaUsuarios,listaProductos);
            break;
        case 4:
            altaProducto(listaUsuarios,listaProductos);
            break;
        case 5://modificar publicacion
            modificarPublicacion(listaUsuarios,listaProductos);
            break;
        case 6://borrar publicacion
            borrarPublicacion(listaUsuarios,listaProductos);
            break;
        case 7://comprar
            comprar(listaProductos);
            break;
        case 8://la otra pagina para mostrar
            system("cls");
            do
            {
                strcpy(menu,"1-Listar publicaciones del usuario\n2-Listar publicaciones\n3-Listar usuarios\n4-Volver\n");
                puts(menu);
                scanf("%d",&opcion);
                switch(opcion)
                {
                case 1://todos los usuarios y sus publicaciones
                    mostrarProductosDeUsuarios(listaProductos,listaUsuarios);
                    break;
                case 2://productos sin el usuario opdenados
                    mostrar(listaProductos);
                    break;
                case 3://mostrar usuarios
                    mostrarListaUsu(listaUsuarios);
                    system("pause");
                    system("cls");
                    break;
                case 4://SALIR :D
                    break;
                default:
                    printf("Opcion incorrecta\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
            while(opcion!=4);

            system("cls");
            break;
        case 9://salir y cargar archivo
            cargarArchivo(listaUsuarios,listaProductos);
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opcion!=9);
    return 0;
}
