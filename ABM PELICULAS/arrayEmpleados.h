#define LIBRE 1
#define OCUPADO 0
#define TAM_EMP 1000
typedef struct
{
    int idActor;
    char nombre[51];
    char nacionalidad[51];
    int isEmpty;
}eActores;

typedef struct
{
    int id;
    int codigo;
    char titulo[51];
    char fecha[51];
    char genero[51];
    //char actor[51];
    int isEmpty;
    eActores actor;

}ePeliculas;



/** \brief Inicializa todas las banderas(isEmpty) en true
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return int  Return (-1) if Error - (0) if Ok
 *
 */
int inicializarPeliculas(ePeliculas listaPeliculas[], int tam);
/** \brief carga informacion acerca del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \return ePeliculas data set of employee
 *
 */
int inicializarActores(eActores listaActores[], int tam);

ePeliculas conjuntoPelicula(ePeliculas listaPeliculas[], eActores listaActores[]);

/** \brief encuentra bandera libre(isEmpty)
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return int index si hay lugar libre
 *
 */
int encontrarLugarLibre(ePeliculas listaPeliculas[], int tam);
/** \brief agrega Pelicula en array de Peliculas
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \return int return (-1) if error, (0) if ok
 *
 */
int agregarPelicula(ePeliculas listaPeliculas[]);

/** \brief agrega Actor en array de actores
 *
 * \param listaActores eActores array de actores
 * \return int return (-1) if error, (0) if ok
 *
 */
int agregarActor(eActores listaActores[]);

/** \brief encuentra el siguiente id para el Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return int value para siguiente id
 *
 */
int siguienteId(ePeliculas listaPeliculas[],int tam);

/** \brief modifica la informacion acerca del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \return int (-1) if error, (0) if ok
 *
 */
int modificarPelicula(ePeliculas listaPeliculas[]);

/** \brief muestra la informacion de un Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param index int posicion de Pelicula
 * \return void
 *
 */
void mostrarUnaPelicula(ePeliculas listaPeliculas[], int index);

/** \brief muestra el array de Peliculas
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return void
 *
 */
void mostrarPeliculas(ePeliculas listaPeliculas[], int tam);

void mostrarUnActor(eActores listaActores[], int index);

void mostrarActores(eActores listaActores[], int tam);

/** \brief encuentra al Pelicula por el id y retorna la posicion en el array
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \param id int id para buscar
 * \return int (-1) if error o Pelicula index posicion
 *
 */
int encontrarPeliculaPorId(ePeliculas listaPeliculas[], int tam, int id);

/** \brief menu para modificar informacion del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param posicion int posicion de Pelicula
 * \return void
 *
 */
void modificarMenu(ePeliculas listaPeliculas[], int posicion);

/** \brief modifica el nombre del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param posicion int posicion de Pelicula
 * \return void
 *
 */
void modificarCodigo(ePeliculas listaPeliculas[], int posicion);

/** \brief modifica el apellido del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param posicion int posicion de Pelicula
 * \return void
 *
 */
void modificarTitulo(ePeliculas listaPeliculas[], int posicion);

/** \brief modifica el salario del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param posicion int posicion de Pelicula
 * \return void
 *
 */
void modificarFecha(ePeliculas listaPeliculas[], int posicion);

/** \brief modifica el sector del Pelicula
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param posicion int posicion de Pelicula
 * \return void
 *
 */
void modificarGenero(ePeliculas listaPeliculas[], int posicion);

/** \brief  Borra al Pelicula por id (isEmpty Flag in 1)
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return int (-1) if error, (0) if ok
 *
 */
int borrarPelicula(ePeliculas listaPeliculas[], int tam);

/** \brief modificar el actor de la pelicula
 *
 * \param listaPeliculas[] ePeliculas
 * \param posicion int
 * \return void
 *
 */
void modificarActor(ePeliculas listaPeliculas[], int posicion);


/** \brief  Ordena los elementos en el array de Peliculas, el orden del argumento indica orden hacia arriba o abajo
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \param orden int [1] indica ARRIBA, [0] indica ABAJO
 * \return int (-1) if error, (0) if ok
 *
 */
int ordenarPeliculas(ePeliculas listaPeliculas[], int tam, int orden);

/** \brief menu para seleccionar si desea ordenar hacia arriba o hacia abajo
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return void
 *
 */
void ordenarMenu(ePeliculas listaPeliculas[], int tam);

/** \brief menu para informar
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return void
 *
 */
void informarMenu(ePeliculas listaPeliculas[], int tam);

/** \brief Peliculas de orden descendente
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return void
 *
 */
void ordenDescendente(ePeliculas listaPeliculas[], int tam);

/** \brief Peliculas de orden ascendente
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return void
 *
 */
void ordenAscendente(ePeliculas listaPeliculas[], int tam);

/** \brief calcula el salario total y promedio, y cuántos Peliculas exceden el salario promedio
 *
 * \param listaPeliculas ePeliculas array de Peliculas
 * \param tam int tamaño array
 * \return void
 *
 */
void informePeliculas(ePeliculas listaPeliculas[], int tam);
/** \brief inicializa ABM de Peliculas
 *
 * \param void
 * \return void
 *
 */
void abmPeliculas(void);

int agregarActor(eActores []);

eActores conjuntoActores(eActores []);

