#include <stdio.h>
#include <stdlib.h>
#include "Pais.h"
#include "LinkedList.h"
#include "UTN.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListePais LinkedList*
 * \return int
 *
 */
int parser_paisFromText(FILE* pFile, LinkedList* pArrayListePais)
{
    int todoOk=-1;
    char datos[5][100];
     /* 1-Id
        2-Nombre Pais
        3-Curados
        4-Infectados
        5-Muertos
     */
    int cant;
    ePais* pAuxPais;
    int auxID,auxCurados,auxInfectados,auxMuertos;
    char auxPais[50];

    if(pFile!=NULL && pArrayListePais!=NULL)
    {
        //BARRIDO FANTASMA PARA EL ENCABEZADO DEL LA LISTA
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",datos[0],datos[1],datos[2],datos[3],datos[4]);
        printf("  %s          %s  %s  %s  %s \n",datos[0],datos[1],datos[2],datos[3],datos[4]);

        while( !feof(pFile))
        {
            cant=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",datos[0],datos[1],datos[2],datos[3],datos[4]);

            if(cant == 5)
            {

                pAuxPais = Pais_newParametros(datos[0],datos[1],datos[2],datos[3],datos[4]);

                if(pAuxPais!=NULL)
                {ll_add(pArrayListePais,pAuxPais);

                pais_getId(pAuxPais,&auxID);
                pais_getNombre(pAuxPais,auxPais);
                pais_getCurados(pAuxPais,&auxCurados);
                pais_getInfectados(pAuxPais,&auxInfectados);
                pais_getMuertos(pAuxPais,&auxMuertos);

                printf("  %03d %17s   %06d   %06d   %06d\n",auxID,auxPais,auxCurados,auxInfectados,auxMuertos);
                todoOk=0;
                }
            }
        }
    }


    return todoOk;
}
