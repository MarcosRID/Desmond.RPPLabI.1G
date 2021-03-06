#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED

int utn_validarFecha(int dia,int mes,int anio);

int esBisiesto(int anio);

/** \brief Solicita un string limitado solo a letras y escapcios
 *
 * \param pResultado char* array donde guardar el dato
 * \param mensaje char* , mensaje inicial
 * \param mensajeError char* , mensaje de error
 * \param maximo cantidad de caracteres a ingresar
 * \param numero de reintento mayores o igual a 0 (cero) o de forma ilimitada usar el -1
 * \return int
 *
 */
int utn_getString(char* pResultado,char* mensaje,char* mensajeError,char maximo,int reintentos);

/** \brief obtiene una cadena de caracteres
 *
 * \param pCadena char* , donde se guardara el dato
 * \param len int , longitur del array a donde se guardara el dato
 * \return 0 [OK] � -1 [ERROR]
 *
 */
int getString(char* pCadena,int len);

/** \brief Verificar string entre letras y espacios
 *
 * \param cadena char* , array a analizar
 * \param len int , longitud a analizar
 * \return 0 [OK] � -1 [ERROR]
 *
 */
int esString(char* cadena,int len);

/** \brief Calcula el mayor entre 2 numeros y devuelve el resultado por referencia
 *
 * \param Direccion de memoria donde se guardara (en el caso de que exista un mayor) el numero mayor.
 * \param valor del primero numero.
 * \param valor del segundo numero.
 * \return -1 = Error , 0 = si existe paridad , 1 = si el 1� numero es mayor , 2 = si el 2� numero es mayor
 *
 */
int calcularMayor(int* pResultado,int num1,int num2);

/** \brief Carga por referencia el con contenido de STDIN.
 *
 * \param puntero a char(se cargar lo del buffer de entrada)
 * \param tama�o limite maximo de char.
 * \return -1 ERROR � 0 si se realizo la tarea con exito.
 *
 */
int myGets(char* cadena,int len);

/** \brief obtiene un char en un rando estimado, validando que sea char.
 *
 * \param Requiere una direccion de memoria en donde se gruardara el dato. (char)
 * \param Mensaje principal (dando una breve instruccion).
 * \param Mensaje de eRror.
 * \param Limite Minimo del caracter aceptado.
 * \param Limite Maximo del caracter aceptado.
 * \param cantidad de reintentos. Con -1 los reintentos son ilimitados.
 * \return -1 en caso de eRror � cero (0) si realizo todo con exito.
 *
 */
 int utn_getCaracter( char * pResultado,char * mensaje,char * mensajeError,char minimo,char maximo,int reintentos);


/** \brief Obtiene un numero validando entre el rango estimado.
 *
 * \param Requiere una direccion de memoria en donde se gruardara el dato. (int)
 * \param Mensaje principal (dando una breve instruccion).
 * \param Mensaje de eRror.
 * \param Limite Minimo del numero aceptado.
 * \param Limite Maximo del numero aceptado.
 * \param cantidad de reintentos. Con -1 los reintentos son ilimitados.
 * \return -1 en caso de eRror � cero (0) si realizo todo con exito
 *
 */
int utn_getNumero( int * pResultado,char * mensaje,char * mensajeError,int minimo,int maximo,int reintentos);

/** \brief verifica que el dato ingresado corresponda a un valor numerico en ASCII.
 *
 * \param cadena de caracteres a evaluar.
 * \return 0 (cero)= dato invalido.  1 (uno)= dato valido.
 *
 */
int esNumerica(char* cadena);

/** \brief Toma un un valor y lo combiente de char a int.
 *
 * \param Direccion de memoria en donde se guardara dicho valor.
 * \return -1 eRror � 0 si logro realizar la operaxion con exito.
 *
 */
int getInt(int* pResultado);

/** \brief  imprime un array de enteros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tama�o del array. (parametro en entero)
 * \return -1 Error � 0 realizo la tarea con exito;
 *
 */
int imprimirNumeros(int* arrayInt,int len);

/** \brief  carga un array de enteros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tama�o del array. (parametro en entero para no sobreescribir fuera del array);
 * \return -1 Error � 0 realizo la tarea con exito;
 *
 */
int cargarArrayInt(int* arrayInt,int len);

/** \brief  Modifica el array dejando solo los numeros pares y reemplazando los impares por ceros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tama�o del array. (parametro en entero );
 * \return -1 Error � 0 realizo la tarea con exito;
 *
 */
int borrarInpares(int* arrayInt,int len);

/** \brief  Modifica el array dejando solo los numeros pares y reemplazando los pares por ceros.
 *
 * \param puntero a entero (vector/array de interos);
 * \param Tama�o del array. (parametro en entero );
 * \return -1 Error � 0 realizo la tarea con exito;
 *
 */
int borrarPares(int* arrayInt,int len);

/** \brief Obtiene un numero flotante validando entre el rango estimado.
 *
 * \param Requiere una direccion de memoria en donde se gruardara el dato. (float)
 * \param Mensaje principal (dando una breve instruccion).
 * \param Mensaje de eRror.
 * \param Limite Minimo del numero aceptado.
 * \param Limite Maximo del numero aceptado.
 * \param cantidad de reintentos. Con -1 los reintentos son ilimitados.
 * \return -1 en caso de eRror � cero (0) si realizo todo con exito
 *
 */
int utn_getNumeroFlotante( float * pResultado,char * mensaje,char * mensajeError,float minimo,float maximo,int reintentos);

/** \brief verifica si su equivalente en ASCII es valido para su combercion a flotante
 *
 * \param cadena char*
 * \return -1 = Error � 0 = se logro realizar con exito.
 *
 */
int esFlotante(char* cadena);

/** \brief obtiene un string y lo combiente a flotante
 *
 * \param retorna por referencia el dato.
 * \return -1 = Error � 0 = se logro realizar con exito.
 *
 */
int getFloat(float* pResultado);

