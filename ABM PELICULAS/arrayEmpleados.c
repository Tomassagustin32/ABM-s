#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "arrayEmpleados.h"
#include "BibliotecaGetsComprobaciones.h"

int inicializarPeliculas(ePeliculas listaPeliculas[], int tam)
{
    int bandera = -1;
    int i;
    for(i = 0 ; i < tam; i++)
    {
        listaPeliculas[i].isEmpty = LIBRE;
        bandera = 0;
    }

    return bandera;
}

int inicializarActores(eActores listaActores[], int tam)
{
    int bandera = -1;
    int i;
    for(i = 0 ; i < tam; i++)
    {
        listaActores[i].isEmpty = LIBRE;
        bandera = 0;
    }

    return bandera;
}

int agregarPelicula(ePeliculas listaPeliculas[])
{
    int bandera;
    int indexLugarLibre;

    indexLugarLibre = encontrarLugarLibre(listaPeliculas, TAM_EMP);
    if(indexLugarLibre == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        bandera = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listaPeliculas[indexLugarLibre] = conjuntoPelicula(listaPeliculas);
    bandera = 0;

    return bandera;
}

int agregarActor(eActores listaActores[])
{
    int bandera;
    int indexLugarLibre;

    indexLugarLibre = encontrarLugarLibre(listaActores, TAM_EMP);
    if(indexLugarLibre == -1)
    {
        printf("\nNo quedan espacios libres.\n");
        bandera = -1;
    }
    system("cls");
    printf("ALTA\n\n");
    listaActores[indexLugarLibre] = conjuntoActores(listaActores);
    bandera = 0;

    return bandera;
}

ePeliculas conjuntoPelicula(ePeliculas listaPeliculas[], eActores listaActores[])
{
    ePeliculas pelicula;

    pelicula.id = siguienteId(listaPeliculas, TAM_EMP);

    fflush(stdin);
    //getStringOnly("Ingrese el codigo: ", pelicula.codigo);
    getIntOnlyTres("Ingrese el codigo: ", pelicula.codigo);

    fflush(stdin);
    getStringOnly("Ingrese el titulo: ", pelicula.titulo);

    fflush(stdin);
    getString("Ingrese la fecha de estreno: ", pelicula.fecha);

    printf("1.Accion || 2.Comedio || 3.Terror || 4.Otro\n");
    fflush(stdin);
    getStringOnly("Ingrese el genero: ", pelicula.genero);

    mostrarActores(listaActores, 5);
    fflush(stdin);
    getStringOnly("Ingrese el actor principal: ", pelicula.actor);

    pelicula.isEmpty = OCUPADO;

    return pelicula;
}

eActores conjuntoActores(eActores listaActores[])
{
    eActores actor;

    actor.idActor = siguienteIdActor(listaActores, TAM_EMP);

    fflush(stdin);
    getStringOnly("Ingrese el nombre: ", actor.nombre);

    fflush(stdin);
    getStringOnly("Ingrese la nacionalidad: ", actor.nacionalidad);

    actor.isEmpty = OCUPADO;

    return actor;
}

int encontrarLugarLibre(ePeliculas listaPeliculas[], int tam)
{
    int index = -1;
    int i;
    for(i = 0; i < tam; i ++)
    {
        if(listaPeliculas[i].isEmpty == LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int siguienteId(ePeliculas listaPeliculas[],int tam)
{
    int valor = 0;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaPeliculas[i].isEmpty== OCUPADO)
        {
            if(listaPeliculas[i].id > valor)
            {
                valor = listaPeliculas[i].id;
            }
        }
    }
    return valor + 1;
}

int siguienteIdActor(eActores listaActores[],int tam)
{
    int valor = 0;
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaActores[i].isEmpty== OCUPADO)
        {
            if(listaActores[i].idActor > valor)
            {
                valor = listaActores[i].idActor;
            }
        }
    }
    return valor + 1;
}

/*int modificarPelicula(ePeliculas listaPeliculas[])
{
    int auxId;
    int indexPosicion;
    int bandera;

    system("cls");
    printf("MODIFICAR\n\n");
    mostrarPeliculas(listaPeliculas, TAM_EMP);
    auxId = getIntOnly("Ingrese el Id a modificar: ");
    indexPosicion = encontrarPeliculaPorId(listaPeliculas, TAM_EMP, auxId);
    if(indexPosicion == -1)
    {
        printf("\nLa Id no existe.\n");
        system("pause");
        bandera = -1;
    }
    else
    {
        modificarMenu(listaPeliculas, indexPosicion);
        bandera = 0;
    }

    return bandera;
}
*/
void mostrarUnaPelicula(ePeliculas listaPeliculas[], int index)
{
    if(listaPeliculas[index].isEmpty == OCUPADO)
    {
        printf("Id: %5d | Codigo: %d  | Titulo: %8s | Fecha: %5s | Genero: %6s  | Actor: %8s \n", listaPeliculas[index].id, listaPeliculas[index].codigo,
               listaPeliculas[index].titulo, listaPeliculas[index].fecha, listaPeliculas[index].genero, listaPeliculas[index].actor);
    }
}

void mostrarPeliculas(ePeliculas listaPeliculas[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaPeliculas[i].isEmpty != LIBRE)
        {
            mostrarUnaPelicula(listaPeliculas, i);
        }
    }
}

void mostrarUnActor(eActores listaActores[], int index)
{
    if(listaActores[index].isEmpty == OCUPADO)
    {
        printf("Id: %5d | Nombre: %8s  | Nacionalidad: %8s  \n", listaActores[index].idActor, listaActores[index].nombre,
               listaActores[index].nacionalidad);
    }
}

void mostrarActores(eActores listaActores[], int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        if(listaActores[i].isEmpty != LIBRE)
        {
            mostrarUnActor(listaActores, i);
        }
    }
}

int encontrarPeliculaPorId(ePeliculas listaPeliculas[], int tam, int id)
{
    int index = -1;
    int i;
    for(i = 0; i < tam; i ++)
    {
        if(listaPeliculas[i].isEmpty != LIBRE && listaPeliculas[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void hardcodearActores(eActores listaActores[],int tam)
{

    int idActor[5]={1,2,3,4,5};
    char nombre[5][50]={"julieta roberto","Roberto deniro","Richar darin","tita merelo","sandro"};
    //char fecha[3][50]={"09/03/1998","23/09/2013","09/05/2019"};

    //char genero[3][13]={"Terror","Comedia","Drama"};

    char nacionalidad[5][50]={"EEUU","EEUU","Argentina","Argentina","Argentina"};

    int i;

    for(i=0;i<5;i++)
    {
        listaActores[i].idActor= idActor[i];
        strcpy(listaActores[i].nombre,nombre[i]);
        strcpy(listaActores[i].nacionalidad, nacionalidad[i]);
        //strcpy(listaActores[i].genero, genero[i]);
        //strcpy(listaActores[i].actor,actor[i]);
        listaActores[i].isEmpty = OCUPADO;
    }



}

/*void modificarMenu(ePeliculas listaPeliculas[], int posicion)
{
    int opcion;

    do
    {
        system("cls");
        opcion = getIntOnly("MODIFICAR\n\n1.Codigo \n2.Titulo \n3.Fecha \n4.Genero \n5.Actor \n6.Regresar Ingrese una opcion: ");
        switch(opcion)
        {
        case 1: //modificar codigo
            modificarCodigo(listaPeliculas, posicion);
            break;
        case 2: //modificar titulo
            modificarTitulo(listaPeliculas, posicion);
            break;
        case 3: //modificar fecha
            modificarFecha(listaPeliculas, posicion);
            break;
        case 4: //modificar genero
            modificarGenero(listaPeliculas, posicion);
            break;
        case 5://modificar actor
            modificarActor(listaPeliculas, posicion);
            break;
        case 6://regresar
            opcion = 5;
            break;
        default:
            system("cls");
            printf("No es una opcion valida.");
        }
    }
    while(opcion != 5);
}

void modificarCodigo(ePeliculas listaPeliculas[], int posicion)
{
    char auxCodigo[100];
    system("cls");
    printf("Modificacion del nombre\n\n");
    mostrarUnaPelicula(listaPeliculas, posicion);
    getStringOnly("\nIngrese el nuevo nombre: ", auxCodigo);
    printf("\nEsta seguro que desea cambiar el nombre?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listaPeliculas[posicion].codigo, auxCodigo);
    }
}

void modificarTitulo(ePeliculas listaPeliculas[], int posicion)
{
    char auxApellido[100];
    system("cls");
    printf("Modificacion del apellido\n\n");
    mostrarUnaPelicula(listaPeliculas, posicion);
    getStringOnly("\nIngrese el nuevo apellido: ", auxApellido);
    printf("\nEsta seguro que desea cambiar el apellido?(s/n): ");
    if(getch() == 's')
    {
        strcpy(listaPeliculas[posicion].apellido, auxApellido);
    }
}

void modificarFecha(ePeliculas listaPeliculas[], int posicion)
{
    float auxSalario;
    system("cls");
    printf("Modificacion del salario\n\n");
    mostrarUnaPelicula(listaPeliculas, posicion);
    auxSalario = getFloatOnly("\nIngrese el nuevo salario: ");
    printf("\nEsta seguro que desea cambiar el salario?(s/n): ");
    if(getch() == 's')
    {
        listaPeliculas[posicion].salario = auxSalario;
    }
}

void modificarGenero(ePeliculas listaPeliculas[], int posicion)
{
    int auxSector;
    system("cls");
    printf("Modificacion del sector\n\n");
    mostrarUnaPelicula(listaPeliculas, posicion);
    auxSector = getIntOnly("\nIngrese el nuevo sector: ");
    printf("\nEsta seguro que desea cambiar el sector?(s/n): ");
    if(getch() == 's')
    {
        listaPeliculas[posicion].sector = auxSector;
    }
}

int borrarEmpleado(ePeliculas listaPeliculas[], int tam)
{
    int auxId;
    int index;
    int bandera;

    system("cls");
    printf("BAJA\n\n");
    mostrarPeliculas(listaPeliculas, tam);
    auxId = getIntOnly("\nIngrese el numero de Id a dar de baja: ");
    index = encontrarPeliculaPorId(listaPeliculas, tam, auxId);
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
            listaPeliculas[index].isEmpty = LIBRE;
            bandera = 0;
        }
    }
    return bandera;
}
*/
/*int ordenarPeliculas(ePeliculas listaPeliculas[], int tam, int orden)
{
    int bandera = 0;
    if(orden == 1)//ascendente
    {
        ordenAscendente(listaPeliculas, tam);
        bandera = 1;
    }
    else//descendente
    {
        ordenDescendente(listaPeliculas, tam);
        bandera = 1;
    }
    system("cls");
    mostrarPeliculas(listaPeliculas, tam);
    system("pause");

    return bandera;
}

void ordenarMenu(ePeliculas listaPeliculas[], int tam)
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
            bandera = ordenarPeliculas(listaPeliculas, tam, 1);
            if (bandera == 0)
            {
                printf("Se ordeno correctamente");
            }
            break;
        case 2://descendente
            bandera = ordenarPeliculas(listaPeliculas, tam, 0);
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
*/
void informarMenu(ePeliculas listaPeliculas[], int tam)
{
    int opcion;

    do
    {
        system("cls");
        opcion = getIntOnly("Informes\n\n1.Ordenar listado\n\n3.Regresar\nIngrese una opcion: ");
//2.Datos de salarios
        switch(opcion)
        {
        case 1://odernamiento
           // ordenarMenu(listaPeliculas, tam);
            break;
        //case 2://salarios
          //  informeSalario(listaPeliculas, tam);
          //  break;
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

/*
void ordenDescendente(ePeliculas listaPeliculas[], int tam)
{
    ePeliculas empleadoAux;
    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        if(listaPeliculas[i].isEmpty == LIBRE)
        {
            continue;
        }
        for(j = i + 1; j < tam; j++)
        {
            if(listaPeliculas[j].isEmpty == LIBRE)
            {
                continue;
            }
            if(strcmp(listaPeliculas[j].apellido, listaPeliculas[i].apellido) > 0)
            {
                empleadoAux = listaPeliculas[j];
                listaPeliculas[j] = listaPeliculas[i];
                listaPeliculas[i] = empleadoAux;
            }
            else if(strcmp(listaPeliculas[j].apellido, listaPeliculas[i].apellido) == 0)
            {
                if(listaPeliculas[i].sector < listaPeliculas[j].sector)
                {
                    empleadoAux = listaPeliculas[j];
                    listaPeliculas[j] = listaPeliculas[i];
                    listaPeliculas[i] = empleadoAux;
                }
            }
        }
    }
}

void ordenAscendente(ePeliculas listaPeliculas[], int tam)
{
    ePeliculas empleadoAux;
    int i;
    int j;

    for(i = 0; i < tam - 1; i++)
    {
        if(listaPeliculas[i].isEmpty == LIBRE)
        {
            continue;
        }
        for(j = i + 1; j < tam; j++)
        {
            if(listaPeliculas[j].isEmpty == LIBRE)
            {
                continue;
            }
            if(strcmp(listaPeliculas[j].apellido, listaPeliculas[i].apellido) < 0)
            {
                empleadoAux = listaPeliculas[j];
                listaPeliculas[j] = listaPeliculas[i];
                listaPeliculas[i] = empleadoAux;
            }
            else if(strcmp(listaPeliculas[j].apellido, listaPeliculas[i].apellido) == 0)
            {
                if(listaPeliculas[i].sector > listaPeliculas[j].sector)
                {
                    empleadoAux = listaPeliculas[j];
                    listaPeliculas[j] = listaPeliculas[i];
                    listaPeliculas[i] = empleadoAux;
                }
            }
        }
    }
}

void informeSalario(ePeliculas listaPeliculas[], int tam)
{
    float salarioTotal;
    float salarioPromedio;
    int cantEmpleadosSalarioPromedio = 0;
    int cantDePeliculass = 0;
    int i;

    for(i = 0; i < tam; i++)
    {
        if(listaPeliculas[i].isEmpty == OCUPADO)
        {
            salarioTotal = salarioTotal + listaPeliculas[i].salario;
            cantDePeliculass++;
        }
    }

    salarioPromedio = salarioTotal / cantDePeliculass;

    for(i = 0; i < tam; i++)
    {
        if(listaPeliculas[i].isEmpty == OCUPADO)
        {
            if(listaPeliculas[i].salario > salarioPromedio)
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
*/
void abmPeliculas(void)
{
    ePeliculas listaPeliculas[TAM_EMP];
    eActores listaActores[TAM_EMP];
    int opcion;
    int esError;
    int esErrorAgregar;
    int esErrorAgregarActor;
    int esErrorModificar;
    int esErrorBorrar;
    int banderaCargada = 0;
    do
    {
        esError = inicializarPeliculas(listaPeliculas, TAM_EMP);
    }while(esError == -1);

    do
    {
        opcion = getIntOnly(" Nomina de peliculas.\n\n1. Dar de alta una pelicula.\n\n2. Dar de alta un actor \n"
                            "4. Informes. \n5. Salir. \nIngrese una opcion: ");
//\n2. Modificar datos de un empleado. \n3. Dar de baja un empleado.
        switch(opcion)
        {
            case 1: //Alta
                esErrorAgregar = agregarPelicula(listaPeliculas);
                if(esErrorAgregar == 0)
                {
                    banderaCargada = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido cargar la pelicula.\n");
                }
                break;
 /*case 2: //Modificar
                if(banderaCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado peliculas.\n");
                    break;
                }
                esErrorModificar = modificarPelicula(listaPeliculas);
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
               esErrorBorrar = borrarEmpleado(listaPeliculas, TAM_EMP);
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
                break;*/

            case 2:
                esErrorAgregarActor = agregarActor(listaActores);
                if(esErrorAgregarActor == 0)
                {
                    banderaCargada = 1;
                    system("cls");
                    printf("\nSe cargo correctamente.\n");
                }
                else
                {
                    system("cls");
                    printf("\n No se ha podido cargar el actor.\n");
                }
                break;
            case 4: //Informar
                hardcodearActores(listaActores, 5);
                /*if(banderaCargada != 1)
                {
                    system("cls");
                    printf("\n\nAun no se han cargado peliculas.\n");
                    break;
                }*/
                mostrarActores(listaActores, 5);
                //informarMenu(listaPeliculas, TAM_EMP);
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
