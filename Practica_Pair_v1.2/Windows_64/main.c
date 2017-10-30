#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

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
   Employee* borrar;
   int i;

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

   al_add(lista, e1);
   al_add(lista,e2);

   printf("la cantidad de elementos son: %d\n\n", al_len(lista));

   for(i=0;i<al_len(lista);i++)
   {
       aux=al_get(lista, i);
       employee_print(aux);
   }

    return 0;
}
