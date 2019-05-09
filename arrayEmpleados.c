#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmpleados.h"
#include "BibliotecaGetsComprobaciones.h"

int inicializarEmpleados(eEmpleado listaEmpleados[], int tam)
{
    int bandera = -1;
    int i;
    for(i = 0 ; i < tam; i++)
    {
        listaEmpleados[i].isEmpty = LIBRE;
        bandera = 0;
    }

    return bandera;
}

int agregarEmpleado(eEmpleado listaEmpleados[])
{
    int bandera;
    int indexLugarLibre;

    indexLugarLibre = encontrarLugarLibre(listaEmpleados, TAM_EMP);
    if(indexLugarLibre == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        bandera = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listaEmpleados[indexLugarLibre] = conjuntoEmpleado(listaEmpleados);
    bandera = 0;

    return bandera;
}

eEmpleado conjuntoEmpleado(eEmpleado listaEmpleados[])
{
    eEmpleado empleado;

    empleado.id = siguienteId(listaEmpleados, TAM_EMP);

    fflush(stdin);
    getStringOnly("Ingrese el nombre: ", empleado.nombre);

    fflush(stdin);
    getStringOnly("Ingrese el apellido: ", empleado.apellido);

    empleado.salario = getFloatOnly("Ingrese el salario: ");

    empleado.sector = getIntOnly("Ingrese el sector: ");

    empleado.isEmpty = OCUPADO;

    return empleado;
}

int encontrarLugarLibre(eEmpleado listaEmpleados[], int tam)
{
    int index = -1;
    int i;
    for(i = 0; i < tam; i ++)
    {
        if(listaEmpleados[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int siguienteId(eEmpleado listaEmpleados[],int tam)
{
    int valor = 0;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaEmpleados[i].isEmpty== OCUPADO)
        {
            if(listaEmpleados[i].id > valor)
            {
                valor = listaEmpleados[i].id;
            }
        }
    }
    return valor + 1;
}

int modificarEmpleado(eEmpleado listaEmpleados[])
{
    int auxId;
    int indexPosicion;
    int bandera;

    system("cls");
    printf("MODIFICAR\n\n");
    mostrarEmpleados(listaEmpleados, TAM_EMP);
    auxId = getIntOnly("Ingrese el Id a modificar: ");
    indexPosicion = encontrarEmpleadoPorId(listaEmpleados, TAM_EMP, auxId);
    if(indexPosicion == -1)
    {
        printf("\nLa Id no existe.\n");
        system("pause");
        bandera = -1;
    }
    else
    {
        modificarMenu(listaEmpleados, indexPosicion);
        bandera = 0;
    }

    return bandera;
}

void mostrarUnEmpleado(eEmpleado listaEmpleados[], int index)
{
    if(listaEmpleados[index].isEmpty == OCUPADO)
    {
        printf("Id: %5d | Nombre: %-8s , %-8s | Salario: %6.2f | Sector: %d\n", listaEmpleados[index].id, listaEmpleados[index].nombre,
               listaEmpleados[index].apellido, listaEmpleados[index].salario, listaEmpleados[index].sector);
    }
}

void mostrarEmpleados(eEmpleado listaEmpleados[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaEmpleados[i].isEmpty != LIBRE)
        {
            mostrarUnEmpleado(listaEmpleados, i);
        }
    }
}

int encontrarEmpleadoPorId(eEmpleado listaEmpleados[], int tam, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < tam; i ++)
    {
        if(listaEmpleados[i].isEmpty != LIBRE && listaEmpleados[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void modificarMenu(eEmpleado listaEmpleados[], int posicion)
{
    int opcion;

    do
    {
        system("cls");
        opcion = getIntOnly("MODIFICAR\n\n1.Nombre \n2.Apellido \n3.Salario \n4.Sector \n5.Regresar \n Ingrese una opcion: ");
        switch(opcion)
        {
        case 1: //modificar nombre
            modificarNombre(listaEmpleados, posicion);
            break;
        case 2: //modificar apellido
            modificarApellido(listaEmpleados, posicion);
            break;
        case 3: //modificar salario
            modificarSalario(listaEmpleados, posicion);
            break;
        case 4: //modificar sector
            modificarSector(listaEmpleados, posicion);
            break;
        case 5://regresar
            opcion = 5;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
    }
    while(opcion != 5);
}

void modificarNombre(eEmpleado listaEmpleados[], int posicion)
{
    char auxNombre[100];
    system("cls");
    printf("Modificacion del nombre\n\n");
    mostrarUnEmpleado(listaEmpleados, posicion);
    getStringOnly("\nIngrese el nuevo nombre: ", auxNombre);
    printf("\nEsta seguro que desea cambiar el nombre?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listaEmpleados[posicion].nombre, auxNombre);
    }
}

void modificarApellido(eEmpleado listaEmpleados[], int posicion)
{
    char auxApellido[100];
    system("cls");
    printf("Modificacion del apellido\n\n");
    mostrarUnEmpleado(listaEmpleados, posicion);
    getStringOnly("\nIngrese el nuevo apellido: ", auxApellido);
    printf("\nEsta seguro que desea cambiar el apellido?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listaEmpleados[posicion].apellido, auxApellido);
    }
}

void modificarSalario(eEmpleado listaEmpleados[], int posicion)
{
    float auxSalario;
    system("cls");
    printf("Modificacion del salario\n\n");
    mostrarUnEmpleado(listaEmpleados, posicion);
    auxSalario = getFloatOnly("\nIngrese el nuevo salario: ");
    printf("\nEsta seguro que desea cambiar el salario?(s/n): ");
    if(getch() == 's')
    {
        listaEmpleados[posicion].salario = auxSalario;
    }
}

void modificarSector(eEmpleado listaEmpleados[], int posicion)
{
    int auxSector;
    system("cls");
    printf("Modificacion del sector\n\n");
    mostrarUnEmpleado(listaEmpleados, posicion);
    auxSector = getIntOnly("\nIngrese el nuevo sector: ");
    printf("\nEsta seguro que desea cambiar el sector?(s/n): ");
    if(getch() == 's')
    {
        listaEmpleados[posicion].sector = auxSector;
    }
}

int borrarEmpleado(eEmpleado listaEmpleados[], int tam)
{
    int auxId;
    int index;
    int bandera;

    system("cls");
    printf("BAJA\n\n");
    mostrarEmpleados(listaEmpleados, tam);
    auxId = getIntOnly("\nIngrese el numero de Id a dar de baja: ");
    index = encontrarEmpleadoPorId(listaEmpleados, tam, auxId);
    if(index == -1)
    {
        printf("No se encuentra ese Id.\n");
        system("pause");
        bandera = -1;
    }
    else
    {
        printf("\nEsta seguro que desea dar de baja?(s/n): ");
        if(getch() == 's')
        {
            listaEmpleados[index].isEmpty = LIBRE;
            bandera = 0;
        }
    }
    return bandera;
}

int ordenarEmpleados(eEmpleado listaEmpleados[], int tam, int orden)
{
    int bandera = 0;
    if(orden == 1)//ascendente
    {
        ordenAscendente(listaEmpleados, tam);
        bandera = 1;
    }
    else//descendente
    {
        ordenDescendente(listaEmpleados, tam);
        bandera = 1;
    }
    system("cls");
    mostrarEmpleados(listaEmpleados, tam);
    system("pause");

    return bandera;
}

void ordenarMenu(eEmpleado listaEmpleados[], int tam)
{
    int opcion;
    int bandera;

    do
    {
        system("cls");
        opcion = getIntOnly("Menu de ordenamiento\n\n1.Ascendente\n2.Descendente\n3.Regresar\nIngrese una opcion: ");
        switch(opcion)
        {
        case 1://ascendente
            bandera = ordenarEmpleados(listaEmpleados, tam, 1);
            if (bandera == 0)
            {
                printf("Se ordeno correctamente");
            }
            break;
        case 2://descendente
            bandera = ordenarEmpleados(listaEmpleados, tam, 0);
            if (bandera == 0)
            {
                printf("Se ordeno correctamente");
            }
            break;
        case 3:
            opcion = 3;
            break;
        default:
            system("cls");
            printf("\nNo es una opcion correcta.\n");
        }
    }
    while(opcion != 3);

}

void informarMenu(eEmpleado listaEmpleados[], int tam)
{
    int opcion;

    do
    {
        system("cls");
        opcion = getIntOnly("Informes\n\n1.Ordenar listado\n2.Datos de salarios\n3.Regresar\nIngrese una opcion: ");

        switch(opcion)
        {
        case 1://odernamiento
            ordenarMenu(listaEmpleados, tam);
            break;
        case 2://salarios
            informeSalario(listaEmpleados, tam);
            break;
        case 3:
            opcion = 3;
            break;
        default:
            system("cls");
            printf("\nNo es una opcion correcta.\n");
        }
        system("cls");
    }
    while(opcion != 3);
}

void ordenDescendente(eEmpleado listaEmpleados[], int tam)
{
    eEmpleado empleadoAux;
    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        if(listaEmpleados[i].isEmpty == LIBRE)
        {
            continue;
        }
        for(j = i + 1; j < tam; j++)
        {
            if(listaEmpleados[j].isEmpty == LIBRE)
            {
                continue;
            }
            if(strcmp(listaEmpleados[j].apellido, listaEmpleados[i].apellido) > 0)
            {
                empleadoAux = listaEmpleados[j];
                listaEmpleados[j] = listaEmpleados[i];
                listaEmpleados[i] = empleadoAux;
            }
            else if(strcmp(listaEmpleados[j].apellido, listaEmpleados[i].apellido) == 0)
            {
                if(listaEmpleados[i].sector < listaEmpleados[j].sector)
                {
                    empleadoAux = listaEmpleados[j];
                    listaEmpleados[j] = listaEmpleados[i];
                    listaEmpleados[i] = empleadoAux;
                }
            }
        }
    }
}

void ordenAscendente(eEmpleado listaEmpleados[], int tam)
{
    eEmpleado empleadoAux;
    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        if(listaEmpleados[i].isEmpty == LIBRE)
        {
            continue;
        }
        for(j = i + 1; j < tam; j++)
        {
            if(listaEmpleados[j].isEmpty == LIBRE)
            {
                continue;
            }
            if(strcmp(listaEmpleados[j].apellido, listaEmpleados[i].apellido) < 0)
            {
                empleadoAux = listaEmpleados[j];
                listaEmpleados[j] = listaEmpleados[i];
                listaEmpleados[i] = empleadoAux;
            }
            else if(strcmp(listaEmpleados[j].apellido, listaEmpleados[i].apellido) == 0)
            {
                if(listaEmpleados[i].sector > listaEmpleados[j].sector)
                {
                    empleadoAux = listaEmpleados[j];
                    listaEmpleados[j] = listaEmpleados[i];
                    listaEmpleados[i] = empleadoAux;
                }
            }
        }
    }
}

void informeSalario(eEmpleado listaEmpleados[], int tam)
{
    float salarioTotal;
    float salarioPromedio;
    int cantEmpleadosSalarioPromedio = 0;
    int cantDeEmpleados = 0;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(listaEmpleados[i].isEmpty == OCUPADO)
        {
            salarioTotal = salarioTotal + listaEmpleados[i].salario;
            cantDeEmpleados++;
        }
    }

    salarioPromedio = salarioTotal / cantDeEmpleados;

    for(i = 0; i < tam; i++)
    {
        if(listaEmpleados[i].isEmpty == OCUPADO)
        {
            if(listaEmpleados[i].salario > salarioPromedio)
            {
                cantEmpleadosSalarioPromedio++;
            }
        }
    }
    system("cls");
    printf("El salario total es de: %.2f\nEl salario promedio es de: %.2f\nLa cantidad de empleados que superan "
            "el salario promedio son: %d\n", salarioTotal, salarioPromedio, cantEmpleadosSalarioPromedio);
    system("pause");
}

void abmEmpleados(void)
{
    eEmpleado listaEmpleados[TAM_EMP];
    int opcion;
    int esError;
    int esErrorAgregar;
    int esErrorModificar;
    int esErrorBorrar;
    int banderaCargada = 0;
    do
    {
        esError = inicializarEmpleados(listaEmpleados, TAM_EMP);
    }while(esError == -1);

    do
    {
        opcion = getIntOnly(" Nomina de empleados.\n\n1. Dar de alta un empleado. \n2. Modificar datos de un empleado. \n3. Dar de baja un empleado. \n"
                            "4. Informes. \n5. Salir. \nIngrese una opcion: ");

        switch(opcion)
        {
            case 1: //Alta
                esErrorAgregar = agregarEmpleado(listaEmpleados);
                if(esErrorAgregar == 0)
                {
                    banderaCargada = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido cargar el empleado.\n");
                }
                break;
            case 2: //Modificar
                if(banderaCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
                esErrorModificar = modificarEmpleado(listaEmpleados);
                if(esErrorModificar == 0)
                {
                    system("cls");
                    printf("\nSe modifico correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido modificar el empleado.\n");
                }
                break;
            case 3: //Baja
                if(banderaCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
               esErrorBorrar = borrarEmpleado(listaEmpleados, TAM_EMP);
               if(esErrorBorrar == 0)
                {
                    system("cls");
                    printf("\nSe dio de baja correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido dar de baja al empleado.\n");
                }
                break;
            case 4: //Informar
                if(banderaCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado empleados.\n");
                    break;
                }
                informarMenu(listaEmpleados, TAM_EMP);
                break;
            case 5:
                opcion = 5;
                break;
            default:
                system("cls");
                printf("No es una opcion valida.");
        }
        system("pause");
        system("cls");
    }
    while(opcion != 5);
}
