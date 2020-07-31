#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "UTN.h"
#include "Pais.h"
#include "parser.h"
#include <ctype.h>




/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListePais)
{
    int todoOk=-1;

    FILE* f = fopen(path,"r");

    if(path!=NULL && pArrayListePais!=NULL && f!=NULL)
    {
        if(parser_paisFromText(f,pArrayListePais)==0)
        {
            todoOk=0;
        }
    }

    fclose(f);

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_ListPais(LinkedList* pArrayListePais)
{
    int todoOk=-1;
    int len=ll_len(pArrayListePais);
    ePais* pAuxPais;

    if(pArrayListePais!=NULL)
    {
        printf("|  Id  |          Pais          |Curados| Infec |Muertos|\n");
        for(int i=0 ; i<len ; i++)
        {
            pAuxPais = (ePais*) ll_get(pArrayListePais,i);

            if(pAuxPais!=NULL)
            {
                todoOk=0;
                printfPais(pAuxPais);
            }
        }
    }

    return todoOk;
}

/** \brief Ordenar paises
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_sortPais(LinkedList* pArrayListePais)
{
    int todoOk=-1;

    if(pArrayListePais!=NULL)
    {
       ll_sort(pArrayListePais,pais_ordenarInfecionDecendente,0);
       todoOk=0;
    }
    else
    {
        printf("Ocurrio un erro al cargar lista (lista =NULL)\n");
    }

    return todoOk;
}

/** \brief Guarda los datos de los paises en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListePais)
{
    int todoOk=-1;
    FILE* f = fopen(path,"w");
    ePais* pAuxPais;

    char auxNombre[20];
    char pasajeIdString[20];
    char pasajeCuradosString[20];
    char pasajeInfecString[20];
    char pasajeMuertosString[20];
    int len=ll_len(pArrayListePais);
    char encabezado[5][20]={ "Id","Pais","curados","infec","muertos" };

    system("pause");

    if( f!=NULL && pArrayListePais!=NULL )
    {

        fprintf(f,"%s,%s,%s,%s,%s\n",encabezado[0],encabezado[1],encabezado[2],encabezado[3],encabezado[4]);
        printf("| %s  |        %s          | %s |  %s  | %s |\n",encabezado[0],encabezado[1],encabezado[2],encabezado[3],encabezado[4]);

        for(int i=-1; i<len ; i++)
        {
            pAuxPais = (ePais*)ll_get(pArrayListePais,i);

            if(pAuxPais != NULL)
            {

                strcpy(auxNombre,pAuxPais->pais);
                itoa(pAuxPais->id,pasajeIdString,10);
                itoa(pAuxPais->curados,pasajeCuradosString,10);
                itoa(pAuxPais->infectados,pasajeInfecString,10);
                itoa(pAuxPais->muertos,pasajeMuertosString,10);

                fprintf(f,"%s,%s,%s,%s,%s\n",pasajeIdString,auxNombre,pasajeCuradosString,pasajeInfecString,pasajeMuertosString);
                printf("| %3s | %20s | %7s | %7s | %7s |\n",pasajeIdString,auxNombre,pasajeCuradosString,pasajeInfecString,pasajeMuertosString);
                todoOk=0;
            }
        }
    }
    free(pAuxPais);

    fclose(f);
    return todoOk;

}

/** \brief llama a la funcion ll_map (generany cargan datos aleatorios)
 *
 * \param this LinkedList*
 * \param this2 LinkedList*
 * \return int
 *
 */
int controller_cargarDataEnElemento(LinkedList* this,LinkedList* this2)
{
    int okey = -1;

    if(this != NULL )
    {
        this2= ll_map(this,addInfoRandom);
        okey=0;
    }

    return okey;
}

/** \brief llama a la funcion pais_masCastigado (imprime  los paises con mayor cantidad de muertos)
 *
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int controller_mostrarPaisesCastigados(LinkedList* pArrayListePais)
{
    int okey= -1;

    if(pArrayListePais!= NULL)
    {
        printf(" Id  Pais Curados Infectados Muertos\n");
        pais_masCastigado(pArrayListePais);
        okey=0;
    }

    return okey;
}

/** \brief llama a la funcion ll_filter() y retorna una lista nueva
 *
 * \param pLista LinkedList*
 * \return LinkedList*
 *
 */
LinkedList* controller_paisExitoso(LinkedList* pLista)
{
    LinkedList* pAuxLista=NULL;

    if(pLista != NULL)
    {
        pAuxLista = ll_filter(pLista,pais_exitosos);
    }

    return pAuxLista;
}

/** \brief genera una nueva lista con los paises con una cantidad tripre de infectados contra los curados
 *
 * \param pLista LinkedList*
 * \return LinkedList*
 *
 */
LinkedList* controller_paisMayorInfeccion(LinkedList* pLista)
{
    LinkedList* pAuxLista=NULL;

    if(pLista != NULL)
    {
        pAuxLista = ll_filter(pLista,pais_infeccion);
    }

    return pAuxLista;
}


/** \brief crea un path con el nobre de l archivo ingresado
 *
 * \param array char*
 * \param pathRelativ char*
 * \return int
 *
 */
int controller_createPath(char* array,char* pathRelativ)
{
    int ok=-1;
    char nameFile[50];

    if(utn_getString(nameFile,"Ingrese Nombre de archivo: ","Error file\n",50,-1)==0)
    {
        ok=0;
        sprintf(array,"%s%s.csv",pathRelativ,nameFile);
    }

    return ok;
}
