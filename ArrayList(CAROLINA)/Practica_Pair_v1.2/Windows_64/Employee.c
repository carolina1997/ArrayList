#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{

    return 0;
}


void employee_print(Employee* this)
{
    if(this!=NULL)
    {
        printf("%d--%s--%s--%d\n", this->id, this->name, this->lastName, this->isEmpty);
    }

}


Employee* employee_new(void)
{

   Employee* returnAux = (Employee*) malloc(sizeof(Employee));

    return returnAux;

}

void employee_delete(ArrayList* lista,Employee* this,int index)

{
    lista->remove(lista,index);
    free(this);
}

int employee_setId(Employee* this, int id)
{

   if(this != NULL)
   {
    this->id = id; //toma el id con el que va a trabajar la funcion
   }
    return 0;

}

int employee_getId(Employee* this)
{
    int returnAux;

    if(this != NULL)
    {
        returnAux = this->id;
    }

    return returnAux;

}


