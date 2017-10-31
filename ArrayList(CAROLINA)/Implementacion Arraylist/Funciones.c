#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Arraylist.h"
#include "Funciones.h"
#define MAXINT 2147483644


int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int respuesta=1;
    int i;
    if(input==NULL)
    {
        printf("ERROR el puntero no apunta a ninguna direccion!!\n");
        respuesta=0;
    }
    else
    {
        printf("%s",message);
        i=scanf("%d",input);
        if(i==0||*input<lowLimit||*input>hiLimit)
        {
            printf("%s",eMessage);
            respuesta=0;
        }
    }
    return respuesta;
}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int respuesta=1;
    int i;
    if(input==NULL)
    {
        printf("ERROR el puntero no apunta a ninguna direccion!!\n");
        respuesta=0;
    }
    else
    {
        printf("%s",message);
        i=scanf("%f",input);
        if(i==0||*input<lowLimit||*input>hiLimit)
        {
            printf("%s",eMessage);
            respuesta=0;
        }
    }
    return respuesta;
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int respuesta=1;
    int i;
    if(input==NULL)
    {
        printf("ERROR el puntero no apunta a ninguna direccion!!\n");
        respuesta=0;
    }
    printf("%s",message);
    fflush(stdin);
    i=scanf("%c",input);
    if(i==0||*input<lowLimit||*input>hiLimit)
    {
        printf("%s",eMessage);
        respuesta=0;
    }
    return respuesta;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int respuesta=1;
    int tam;
    char auxiliar[1000000];
    if(input==NULL)
    {
        printf("ERROR el puntero no apunta a ninguna direccion!!\n");
        respuesta=0;
    }
    printf("%s",message);
    fflush(stdin);
    gets(auxiliar);
    tam=strlen(auxiliar);
    if(tam<lowLimit||tam>hiLimit)
    {
        printf("%s",eMessage);
        respuesta=0;
    }
    else
    {
        strcpy(input,auxiliar);
    }
    return respuesta;
}



Eusuario* newUsuario(void)
{
    Eusuario* usuario;
    usuario=(Eusuario*)malloc(sizeof(Eusuario));
    return usuario;
}

Eusuario* newUsuarioPar(int id, char* password, char* name)
{
    Eusuario* usuario;
    usuario=newUsuario();
    if(usuario!=NULL)
    {
        usuario->id=id;
        strcpy(usuario->name,name);
        strcpy(usuario->password,password);
    }
    return usuario;
}

void mostrarUsuario(Eusuario* usuario)
{
    printf("Id: %d\t",usuario->id);
    printf("Name: %s\t",usuario->name);
    printf("Pass: %s\n",usuario->password);
}

void altaUsuario(ArrayList* listaUsuarios)
{
    int id;
    char password[20];
    char name[30];
    Eusuario* usuario;
    int logro=0;
    system("cls");
    do
    {
        logro=getInt(&id,"Ingrese id:\n","ID invalido\n",0,MAXINT);
    }
    while(logro==0);
    do
    {
        logro=getString(name,"Ingrese nombre:\n","Ingrese nombre de entre 2 y 30 caracteres\n",2,30);
    }
    while(logro==0);
    do
    {
        logro=getString(password,"Ingrese clave:\n","Ingrese clave de entre 4 y 30 caracteres\n",4,30);
    }
    while(logro!=1);

    usuario=newUsuarioPar(id,password,name);
    if(usuario!=NULL)
    {
        al_add(listaUsuarios,usuario);
    }
    system("pause");
    system("cls");
}

void mostrarListaUsu(ArrayList* listaUsuarios)
{
    int i;
    Eusuario* aux;
    system("cls");
    printf("LISTA DE USUARIOS\n\n");
    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        aux=listaUsuarios->get(listaUsuarios,i);
        mostrarUsuario(aux);
    }
}

void harcodeoUsuario (ArrayList* lista)
{
    Eusuario* usuario1=newUsuarioPar(01,"11111","Juan");
    Eusuario* usuario2=newUsuarioPar(02,"22222","Rama");
    Eusuario* usuario3=newUsuarioPar(03,"33333","Mica");
    Eusuario* usuario4=newUsuarioPar(04,"44444","Marcos");
    Eusuario* usuario5=newUsuarioPar(05,"55555","Pepe");

    lista->add(lista,usuario1);
    lista->add(lista,usuario2);
    lista->add(lista,usuario3);
    lista->add(lista,usuario4);
    lista->add(lista,usuario5);
}

void bajaUsuario(ArrayList* listaUsuarios, ArrayList* listaProductos)
{
    int auxId;
    int logro;
    char resp;
    int i,j,flag=0,entro;
    Eusuario* auxUsuario;
    Eproducto* auxProducto;
    system("cls");
    mostrarListaUsu(listaUsuarios);
    do
    {
        logro=getInt(&auxId,"Ingrese ID del usuario que desea borrar:\n","Id invalido\n",0,MAXINT);
    }
    while(logro==0);

    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        auxUsuario=listaUsuarios->get(listaUsuarios,i);
        if(auxUsuario->id==auxId)
        {
            flag=1;
            while(resp!='s'&&resp!='n')
            {
                printf("Seguro desea eliminar a: ID: %d\tNOMBRE: %s s/n\n",auxUsuario->id,auxUsuario->name);
                fflush(stdin);
                scanf("%c",&resp);
            }
            if(resp=='s')
            {
                do
                {
                    entro=0;
                    for(j=0; j<listaProductos->len(listaProductos); j++)
                    {
                        auxProducto=listaProductos->get(listaProductos,j);

                        if(auxUsuario->id==auxProducto->idUsuario)
                        {
                            listaProductos->remove(listaProductos,j);
                            entro=1;
                        }
                    }
                }
                while(entro==1);
                listaUsuarios->remove(listaUsuarios,i);
                printf("Usuario eliminado\n");
            }
            else
            {
                printf("Operacion cancelada\n");
            }
            break;
        }
    }
    if(flag==0)
    {
        printf("El Id no pertenece a ningun usuario\n");
    }
    system("pause");
    system("cls");
}

Eproducto* newProducto(void)
{
    Eproducto* producto;
    producto=(Eproducto*)malloc(sizeof(Eproducto));
    return producto;
}

Eproducto* newProductoPar(int idUsuario,int id,char* nombre,float precio,int stock,int ventas)
{
    Eproducto* producto;
    producto=newProducto();
    if(producto!=NULL)
    {
        producto->idUsuario=idUsuario;
        producto->id=id;
        producto->stock=stock;
        producto->ventas=ventas;
        producto->precio=precio;
        strcpy(producto->nombre,nombre);
    }
    return producto;
}

void harcodeoProducto(ArrayList* lista)
{
    Eproducto* producto1=newProductoPar(01,100,"Escoba",30.50,100,10);//usuario id nombre precio stock ventas
    Eproducto* producto2=newProductoPar(01,101,"Tijeras",10,150,20);
    Eproducto* producto3=newProductoPar(03,102,"Vasos",50,200,200);
    Eproducto* producto4=newProductoPar(04,103,"Samsung",10000,1,1);
    Eproducto* producto5=newProductoPar(03,104,"Estufa",250,25,0);

    lista->add(lista,producto1);
    lista->add(lista,producto2);
    lista->add(lista,producto3);
    lista->add(lista,producto4);
    lista->add(lista,producto5);
}
void mostrarListaPro(ArrayList* lista)
{
    int i;
    Eproducto* aux;
    system("cls");
    printf("LISTA DE PRODUCTOS\n\n");
    for(i=0; i<lista->len(lista); i++)
    {
        aux=lista->get(lista,i);
        printf("%d)",i);
        mostrarProducto(aux);
    }
}
void mostrarProducto(Eproducto* producto)
{
    printf("ID:%d\tNOMBRE:%s\tPRECIO:%.2f\tSTOCK:%d\n",producto->id,producto->nombre,producto->precio,producto->stock);
}

void mostrarProductosDeUsuarios(ArrayList* listaProductos,ArrayList* listaUsuarios)
{
    int i,j;
    Eusuario* auxUsuario;
    Eproducto* auxProducto;
    system("cls");
    printf("LISTA DE PRODUCTOS DE USUARIO\n\n");

    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        auxUsuario=listaUsuarios->get(listaUsuarios,i);
        printf("USUARIO:%s\n\n",auxUsuario->name);
        for(j=0; j<listaProductos->len(listaProductos); j++)
        {
            auxProducto=listaProductos->get(listaProductos,j);
            if(auxUsuario->id==auxProducto->idUsuario)
            {
                mostrarProductoSinID(auxProducto);
            }
        }
        printf("-----------------------------------------------------------------\n");
    }
    system("pause");
    system("cls");
}

void mostrarProductoSinID(Eproducto* producto)
{
    printf("\tID:%d\tNOMBRE:%s\tPRECIO:%.2f\tVENTAS:%d\tSTOCK:%d\n",producto->id,producto->nombre,producto->precio,producto->ventas,producto->stock);
}

int altaProducto(ArrayList* listaUsuarios,ArrayList* listaProductos)
{
    int i;
    int idUsuario;
    int logro,flag=0,cargo=0;
    int id;
    char password[40];
    char nombre[10000];
    int stock;
    float precio;
    Eproducto* producto;
    Eproducto* aux;
    Eusuario* usuario;
    system("cls");
    do
    {
        logro=getInt(&idUsuario,"Ingrese ID de usuario:\n","Ingrese numero valido\n",0,MAXINT);
    }
    while(logro==0);
    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        usuario=listaUsuarios->get(listaUsuarios,i);
        if(usuario->id==idUsuario)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        do
        {
            logro=getString(password,"Ingrese clave:\n","Ingrese clave de entre 4 y 30 caracteres\n",4,30);
        }
        while(logro!=1);
        if(strcmp(password,usuario->password)==0)
        {
            do
            {
                do
                {
                    logro=getInt(&id,"Ingrese ID del producto:\n","ID invalido\n",0,MAXINT);
                }
                while(logro==0);
                for(i=0; i<listaProductos->len(listaProductos); i++)
                {
                    aux=listaProductos->get(listaProductos,i);
                    if(aux->id==id)
                    {
                        printf("Ya existe un producto con esa ID\n");
                        logro=0;
                    }
                }
            }
            while(logro==0);
            do
            {
                logro=getString(nombre,"Ingrese NOMBRE del producto:\n","Ingrese nombre de entre 2 y 10000 caracteres\n",2,10000);
            }
            while(logro==0);
            do
            {
                logro=getInt(&stock,"Ingrese STOCK del producto:\n","STOCK invalido\n",1,MAXINT);
            }
            while(logro==0);
            do
            {
                logro=getFloat(&precio,"Ingrese PRECIO del producto\n","PRECIO incorrecto\n",1,MAXINT);
            }
            while(logro==0);
            producto=newProductoPar(idUsuario,id,nombre,precio,stock,0);
            if(producto!=NULL)
            {
                listaProductos->add(listaProductos,producto);
                cargo=1;
            }
        }
        else
        {
            printf("Contrase%ca incorrecta\n",164);
        }
    }
    else
    {
        printf("El usuario no existe\n");
    }
    system("pause");
    system("cls");
    return cargo;
}

void borrarPublicacion(ArrayList* listaUsuarios, ArrayList* listaProductos)
{
    int auxId,idProducto;
    int logro;
    int i,j;
    int flag=0;
    Eusuario* usuario;
    Eproducto* producto;
    mostrarListaUsu(listaUsuarios);
    do
    {
        logro=getInt(&auxId,"Ingrese ID de usuario:\n","Ingrese numero valido\n",0,MAXINT);
    }
    while(logro==0);
    system("cls");
    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        usuario=listaUsuarios->get(listaUsuarios,i);
        if(auxId==usuario->id)
        {
            flag=1;
            printf("Productos de %s\n",usuario->name);
            for(j=0; j<listaProductos->len(listaProductos); j++)
            {
                producto=listaProductos->get(listaProductos,j);
                if(producto->idUsuario==auxId)
                {
                    mostrarProducto(producto);
                }
            }
            do
            {
                logro=getInt(&idProducto,"Ingrese ID del producto que desea dar de baja:\n","Ingrese numero valido\n",0,MAXINT);
            }
            while(logro==0);
            for(j=0; j<listaProductos->len(listaProductos); j++)
            {
                producto=listaProductos->get(listaProductos,j);
                if(producto->id==idProducto)
                {
                    listaProductos->remove(listaProductos,j);
                    printf("Publicacion borrada\n");
                    break;
                }
            }
            break;
        }
    }
    if(!flag)
    {
        printf("El ID no pertenece a ningun usuario\n");
    }
    system("pause");
    system("cls");
}

void modificarUsuario(ArrayList* listaUsuarios,ArrayList* listaProductos)
{
    int logro;
    int auxInt;
    int auxId;
    int i,j;
    char password[30];
    char name[30];
    Eusuario* usuario;
    Eproducto* producto;
    system("cls");
    mostrarListaUsu(listaUsuarios);
    do
    {
        logro=getInt(&auxId,"Ingrese ID del Usuario que desea modificar:\n","Ingrese numero valido\n",0,MAXINT);
    }
    while(logro==0);
    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        usuario=listaUsuarios->get(listaUsuarios,i);
        if(auxId==usuario->id)
        {
            do
            {
                logro=getString(password,"Ingrese clave:\n","Ingrese clave de entre 4 y 30 caracteres\n",4,30);
            }
            while(logro!=1);
            if(strcmp(password,usuario->password)==0)
            {
                do
                {
                    logro=getInt(&auxInt,"Que desea modificar?\n\n1-ID\n2-NOMBRE\n3-PASSWORD\n","Ingrese numero valido\n",1,3);
                }
                while(logro==0);
                switch(auxInt)
                {
                case 1:
                    do
                    {
                        logro=getInt(&auxId,"Ingrese nuevo ID :\n","Ingrese numero valido\n",0,MAXINT);
                    }
                    while(logro==0);
                    for(j=0; j<al_len(listaProductos); j++)
                    {
                        producto=al_get(listaProductos,j);
                        if(usuario->id==producto->idUsuario)
                        {
                            producto->idUsuario=auxId;
                            al_set(listaProductos,j,producto);
                        }
                    }
                    usuario->id=auxId;
                    al_set(listaUsuarios,i,usuario);
                    break;
                case 2:
                    do
                    {
                        logro=getString(name,"Ingrese nuevo nombre:\n","Ingrese nombre de entre 2 y 30 caracteres\n",2,30);
                    }
                    while(logro!=1);
                    strcpy(usuario->name,name);
                    al_set(listaUsuarios,i,usuario);
                    break;
                case 3:
                    do
                    {
                        logro=getString(password,"Ingrese nueva clave:\n","Ingrese clave de entre 4 y 30 caracteres\n",4,30);
                    }
                    while(logro!=1);
                    strcpy(usuario->password,password);
                    al_set(listaUsuarios,i,usuario);
                    break;
                }
                break;
            }
            else
            {
                printf("Contrase%ca incorrecta\n",164);
                break;
            }
        }
    }
    system("pause");
    system("cls");
}

void modificarPublicacion(ArrayList* listaUsuarios,ArrayList* listaProductos)
{
    int logro,opcion,auxId,idProducto,i,j,flagUsuario=0,flagProducto=1;
    int auxStock;
    float auxPrecio;
    char password[30];
    Eusuario* usuario;
    Eproducto* producto;
    system("cls");
    mostrarListaUsu(listaUsuarios);//muestra lista de usuarios
    do
    {
        logro=getInt(&auxId,"Ingrese ID de usuario:\n","Ingrese numero valido\n",0,MAXINT);
    }
    while(logro==0);
    for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
    {
        usuario=listaUsuarios->get(listaUsuarios,i);
        if(usuario->id==auxId)
        {
            flagUsuario=1;
            system("cls");
            do
            {
                logro=getString(password,"Ingrese clave:\n","Ingrese clave de entre 4 y 30 caracteres\n",4,30);
            }
            while(logro!=1);
            if(strcmp(password,usuario->password)==0)
            {
                system("cls");
                flagProducto=0;
                printf("PRODUCTOS DE %s\n\n",usuario->name);
                mostrarProductosDe1usuario(auxId,listaProductos);
                do
                {
                    logro=getInt(&idProducto,"Ingrese ID de la publicacion que desea modificar:\n","Ingrese numero valido\n",0,MAXINT);
                }
                while(logro==0);
                for(j=0; j<al_len(listaProductos); j++)
                {
                    producto=al_get(listaProductos,j);
                    if(producto->id==idProducto&&producto->idUsuario==usuario->id)
                    {
                        flagProducto=1;
                        system("cls");
                        mostrarProducto(producto);
                        printf("\nQue desea modificar?:\n1-PRECIO\n2-STOCK\n3-Cancelar\n");
                        scanf("%d",&opcion);
                        switch(opcion)
                        {
                        case 1:
                            do
                            {
                                logro=getFloat(&auxPrecio,"Ingrese nuevo PRECIO del producto:\n","Ingrese numero valido\n",0,MAXINT);
                            }
                            while(logro==0);
                            producto->precio=auxPrecio;
                            al_set(listaProductos,j,producto);
                            break;
                        case 2:
                            do
                            {
                                logro=getInt(&auxStock,"Ingrese nuevo STOCK del producto:\n","Ingrese numero valido\n",0,MAXINT);
                            }
                            while(logro==0);
                            producto->stock=auxStock;
                            al_set(listaProductos,j,producto);
                            break;
                        case 3:
                            printf("Operacion cancelada\n");
                            break;
                        }
                        break;
                    }
                }
                break;
            }
            else
            {
                printf("Contrase%ca incorrecta\n",164);
            }
            break;
        }
    }
    if(!flagUsuario)
    {
        printf("El ID no pertenece a ningun usuario\n");
    }
    if(!flagProducto)
    {
        printf("El producto no pertenece al usuario\n");
    }
    system("pause");
    system("cls");
}
/*
int verificarUsuario(ArrayList* listaUsuarios,void* dato,int opcion,int* i)
{
    int logro;
    int flag=0;

    Eusuario* usuario;
    switch(opcion)
    {
    case 1:
        dato=(int*) dato;

        do
        {
            logro=getInt(&dato,"Ingrese ID de usuario:\n","Ingrese numero valido\n",0,MAXINT);
        }
        while(logro==0);
        for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
        {
            usuario=listaUsuarios->get(listaUsuarios,i);
            if(usuario->id==dato)
            {
                flag=1;
                break;
            }
        }
        break;
    case 2:
        dato=(char*) dato;
        do
        {
            logro=getString(dato,"Ingrese clave:\n","Ingrese clave de entre 4 y 30 caracteres\n",4,30);
        }
        while(logro!=1);
        for(i=0; i<listaUsuarios->len(listaUsuarios); i++)
        {
            usuario=listaUsuarios->get(listaUsuarios,i);
            if(strcmp(dato,usuario->password)==0)
            {
                flag=1;
                break;
            }
        }
        break;
    }
    return flag;
}
*/
void mostrarProductosDe1usuario(int idUsuario,ArrayList* listaProductos)
{
    int i;
    Eproducto* producto;
    for(i=0; i<listaProductos->len(listaProductos); i++)
    {
        producto=al_get(listaProductos,i);
        if(producto->idUsuario==idUsuario)
        {
            mostrarProducto(producto);
        }
    }
}
void comprar(ArrayList* listaProductos)
{
    int logro,idProducto,i,flagId=0;
    Eproducto* producto;

    system("cls");
    mostrarListaPro(listaProductos);
    do
    {
        logro=getInt(&idProducto,"Ingrese ID de la publicacion que desea comprar:\n","Ingrese numero valido\n",0,MAXINT);
    }
    while(logro==0);
    for(i=0; i<al_len(listaProductos); i++)
    {
        producto=al_get(listaProductos,i);
        if(producto->id==idProducto)
        {
            flagId=1;
            if(producto->stock>0)
            {
                producto->stock--;
                producto->ventas++;
                al_set(listaProductos,i,producto);
            }
            else
            {
                printf("Stock agotado\n");
            }
            break;
        }
    }
    if(!flagId)
    {
        printf("El ID no pertenece a ningun usuario\n");
    }
    system("pause");
    system("cls");
}

void mostrar(ArrayList* listaProductos)//muestra solo los productos pero ordenados
{
    int opcion;
    ArrayList* lista;
    int seguir=1;
    lista=al_clone(listaProductos);
    system("cls");
    do
    {
        printf("Ver lista ordenada por:\n1-Nombre\n2-Precio\n3-Id\n4-Volver\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("Por nombre\n1)A-Z\n2)Z-A\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                al_sort(lista,compareName,1);
                mostrarListaPro(lista);
                system(("pause"));
                break;
            case 2:
                al_sort(lista,compareName,0);
                mostrarListaPro(lista);
                system(("pause"));
                break;
            default:
                printf("Ingrese opcion valida\n");
                break;
            }
            break;
        case 2:
            system("cls");
            printf("Por precio\n1)Menor a mayor\n2)Mayor a menor\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                al_sort(lista,comparePrice,1);
                mostrarListaPro(lista);
                system(("pause"));
                break;
            case 2:
                al_sort(lista,comparePrice,0);
                mostrarListaPro(lista);
                system(("pause"));
                break;
            default:
                printf("Ingrese opcion valida\n");
                break;
            }
            break;
        case 3:
            system("cls");
            printf("Por Id\n1)Menor a mayor\n2)Mayor a menor\n");
            scanf("%d",&opcion);
            switch(opcion)
            {
            case 1:
                al_sort(lista,compareId,1);
                mostrarListaPro(lista);
                system(("pause"));
                break;
            case 2:
                al_sort(lista,compareId,0);
                mostrarListaPro(lista);
                system(("pause"));
                break;
            default:
                printf("Ingrese opcion valida\n");
                break;
            }
            break;
        case 4:
            seguir=0;
            break;
        default:
            printf("Ingrese opcion correcta\n");
            system("pause");
            system("cls");
            break;
        }
        system("cls");
    }
    while(seguir);
}

void leerArchivoUsuarios(ArrayList* listaUsuarios)
{
    FILE* aUsuarios;
    Eusuario* usuario;
    int auxInt;

    if((aUsuarios=fopen("Usuarios.dat","rb"))==NULL)
    {
        if((aUsuarios=fopen("Usuarios.dat","wb"))==NULL)
        {
            printf("No se creo el archivo\n");
            exit(0);
        }
    }
    else
    {
        while(!feof(aUsuarios))
        {
            usuario=newUsuario();
            if(usuario==NULL)
            {
                printf("El puntero apunta a nulo");
                system("pause");
                exit(0);
            }
            auxInt=fread(usuario,sizeof(Eusuario),1,aUsuarios);
            if(auxInt!=1)
            {
                break;
            }
            auxInt=listaUsuarios->add(listaUsuarios,usuario);
            if(auxInt==-1)
            {
                printf("El programa no funciona correctamente\n");
                system("pause");
                exit(0);
            }
        }
    }
    fclose(aUsuarios);
}

void leerArchivoProductos(ArrayList* listaProductos)
{
    FILE* aProductos;
    Eproducto* producto;
    int auxInt;

    if((aProductos=fopen("Productos.dat","rb"))==NULL)
    {
        if((aProductos=fopen("Productos.dat","wb"))==NULL)
        {
            printf("No se creo el archivo\n");
            exit(0);
        }
    }
    else
    {
        while(!feof(aProductos))
        {
            producto=newProducto();
            if(producto==NULL)
            {
                printf("El puntero apunta a nulo");
                system("pause");
                exit(0);
            }
            auxInt=fread(producto,sizeof(Eproducto),1,aProductos);
            if(auxInt!=1)
            {
                break;
            }
            auxInt=listaProductos->add(listaProductos,producto);
            if(auxInt==-1)
            {
                printf("El programa no funciona correctamente\n");
                system("pause");
                exit(0);
            }
        }
    }
    fclose(aProductos);
}

void cargarArchivo(ArrayList* listaUsuarios,ArrayList* listaProductos)
{
    FILE* aUsuarios;
    FILE* aProductos;
    int auxInt;
    int i;
    aUsuarios=fopen("Usuarios.dat","wb");
    for(i=0; i<al_len(listaUsuarios); i++)
    {
        auxInt=fwrite(listaUsuarios->get(listaUsuarios,i),sizeof(Eusuario),1,aUsuarios);
        if(auxInt<1)
        {
            printf("error al escribir\n");
        }
    }
    aProductos=fopen("Productos.dat","wb");
    for(i=0; i<al_len(listaProductos); i++)
    {
        auxInt=fwrite(al_get(listaProductos,i),sizeof(Eproducto),1,aProductos);
        if(auxInt<1)
        {
            printf("error al escribir\n");
        }
    }
    fclose(aUsuarios);
    fclose(aProductos);
}

int compareName(void* productoA,void* productoB)
{
    int retorno=0;
    if(strcmp(((Eproducto*)productoA)->nombre,((Eproducto*)productoB)->nombre)==1)
    {
        retorno=1;
    }
    if(strcmp(((Eproducto*)productoA)->nombre,((Eproducto*)productoB)->nombre)==-1)
    {
        retorno=-1;
    }
    return retorno;
}

int comparePrice(void* productoA,void* productoB)
{
    int retorno=0;
    if(((Eproducto*)productoA)->precio<((Eproducto*)productoB)->precio)
    {
        retorno=1;
    }
    if(((Eproducto*)productoA)->precio>((Eproducto*)productoB)->precio)
    {
        retorno=-1;
    }
    return retorno;
}

int compareId(void* productoA,void* productoB)
{
    int retorno=0;
    if(((Eproducto*)productoA)->id<((Eproducto*)productoB)->id)
    {
        retorno=1;
    }
    if(((Eproducto*)productoA)->id>((Eproducto*)productoB)->id)
    {
        retorno=-1;
    }
    return retorno;
}
