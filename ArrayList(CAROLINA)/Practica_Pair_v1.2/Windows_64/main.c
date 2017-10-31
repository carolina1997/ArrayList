#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"
#include <string.h>

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
   ArrayList* lista = al_newArrayList();
   Employee* aux;
   int i;
   int* ids= (int*) malloc(sizeof(int)*3);
   int id = 0;

   Employee* e1= employee_new();
   Employee* e2= employee_new();

   e1->id= 2;
   strcpy(e1->name, "aldana");
   strcpy(e1->lastName, "salvatierra");
   e1->isEmpty=1;

   e2->id= 5;
   strcpy(e2->name, "carolina");
   strcpy(e2->lastName, "ojeda");
   e2->isEmpty=1;

  lista->add(lista,e1);
lista->add(lista,e2);//LE PASO LA LISTA Y EL EMPLEADO

   printf("la cantidad de elementos mostrados a traves de AL_LEN son: %d\n\n", al_len(lista));

   for(i=0;i<al_len(lista);i++)
   {
       aux=al_get(lista, i);
       employee_print(aux);
   }
       for(i=0; i<lista->len(lista) ; i++)
    {
        aux = lista->get(lista,i);

        employee_print(aux);
    }

    printf("\nObtiene el id por employee_getId():\n\n");
    for(i=0; i<lista->len(lista) ; i++)
    {
        aux = lista->get(lista,i);

        *(ids+i) = employee_getId(aux);

        printf("el ID del empleado es: %d\n\n",*(ids+i));
    }

     printf("Setea los IDs de los empleados por employee_setId(): \n\n");

    for(i=0; i<lista->len(lista) ; i++)
    {
        aux = lista->get(lista,i);

        if(employee_setId(aux,id))
        {
           employee_print(aux);
        }
        else
        {
            printf("no se pudo realizar esta operacion.\n");
        }


    }


    printf("\nEliminar un empleado con la funcion employee_delete():\n\n");

    employee_delete(lista,e2,1);
    for(i=0; i<lista->len(lista) ; i++)
    {
        aux = lista->get(lista,i);

        employee_print(aux);
    }

    return 0;
}
