#define LIBRE 1
#define OCUPADO 0
#define TAM_EMP 1000
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int isEmpty;
}eEmpleado;

/** \brief Inicializa todas las banderas(isEmpty) en true
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return int  Return (-1) if Error - (0) if Ok
 *
 */
int inicializarEmpleados(eEmpleado listaEmpleados[], int tam);
/** \brief carga informacion acerca del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \return eEmpleado data set of employee
 *
 */
eEmpleado conjuntoEmpleado(eEmpleado listaEmpleados[]);

/** \brief encuentra bandera libre(isEmpty)
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return int index si hay lugar libre
 *
 */
int encontrarLugarLibre(eEmpleado listaEmpleados[], int tam);
/** \brief agrega empleado en array de empleados
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \return int return (-1) if error, (0) if ok
 *
 */
int agregarEmpleado(eEmpleado listaEmpleados[]);

/** \brief encuentra el siguiente id para el empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return int value para siguiente id
 *
 */
int siguienteId(eEmpleado listaEmpleados[],int tam);

/** \brief modifica la informacion acerca del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \return int (-1) if error, (0) if ok
 *
 */
int modificarEmpleado(eEmpleado listaEmpleados[]);

/** \brief muestra la informacion de un empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param index int posicion de empleado
 * \return void
 *
 */
void mostrarUnEmpleado(eEmpleado listaEmpleados[], int index);

/** \brief muestra el array de empleados
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return void
 *
 */
void mostrarEmpleados(eEmpleado listaEmpleados[], int tam);

/** \brief encuentra al empleado por el id y retorna la posicion en el array
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \param id int id para buscar
 * \return int (-1) if error o empleado index posicion
 *
 */
int encontrarEmpleadoPorId(eEmpleado listaEmpleados[], int tam, int id);

/** \brief menu para modificar informacion del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param posicion int posicion de empleado
 * \return void
 *
 */
void modificarMenu(eEmpleado listaEmpleados[], int posicion);

/** \brief modifica el nombre del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param posicion int posicion de empleado
 * \return void
 *
 */
void modificarNombre(eEmpleado listaEmpleados[], int posicion);

/** \brief modifica el apellido del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param posicion int posicion de empleado
 * \return void
 *
 */
void modificarApellido(eEmpleado listaEmpleados[], int posicion);

/** \brief modifica el salario del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param posicion int posicion de empleado
 * \return void
 *
 */
void modificarSalario(eEmpleado listaEmpleados[], int posicion);

/** \brief modifica el sector del empleado
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param posicion int posicion de empleado
 * \return void
 *
 */
void modificarSector(eEmpleado listaEmpleados[], int posicion);

/** \brief  Borra al empleado por id (isEmpty Flag in 1)
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return int (-1) if error, (0) if ok
 *
 */
int borrarEmpleado(eEmpleado listaEmpleados[], int tam);

/** \brief  Ordena los elementos en el array de empleados, el orden del argumento indica orden hacia arriba o abajo
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \param orden int [1] indica ARRIBA, [0] indica ABAJO
 * \return int (-1) if error, (0) if ok
 *
 */
int ordenarEmpleados(eEmpleado listaEmpleados[], int tam, int orden);

/** \brief menu para seleccionar si desea ordenar hacia arriba o hacia abajo
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return void
 *
 */
void ordenarMenu(eEmpleado listaEmpleados[], int tam);

/** \brief menu para informar
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return void
 *
 */
void informarMenu(eEmpleado listaEmpleados[], int tam);

/** \brief empleados de orden descendente
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return void
 *
 */
void ordenDescendente(eEmpleado listaEmpleados[], int tam);

/** \brief empleados de orden ascendente
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return void
 *
 */
void ordenAscendente(eEmpleado listaEmpleados[], int tam);

/** \brief calcula el salario total y promedio, y cuántos empleados exceden el salario promedio
 *
 * \param listaEmpleados eEmpleado array de empleados
 * \param tam int tamaño array
 * \return void
 *
 */
void informeSalario(eEmpleado listaEmpleados[], int tam);
/** \brief inicializa ABM de empleados
 *
 * \param void
 * \return void
 *
 */
void abmEmpleados(void);

