#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pais.h"
#include "UTN.h"


int menu()
{
    int indice;

    printf(" :::::::::::::: MENU PRINCIPAL ::::::::::::::\n\n");

    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Listar paises\n");
    printf("3. Asignar estadisticas\n");
    printf("4. Filtrar por paises exitosos( tasaMortalidad<5000 )\n");
    printf("5. Filtrar por paises en el horno(tasa de infeccion 3veces mayor a cantCurados)\n");
    printf("6. Ordenar por nivel de infeccion\n");
    printf("7. Mostrar mas castigado\n");
    printf("8. Salir\n\n");

    utn_getNumero(&indice,"Ingrese una opcion: ","Error. Opcion inexistente",1,9,-1);

    return indice;
}

ePais* pais_new()
{
    ePais* auxPais;

    return auxPais = (ePais*) malloc (sizeof(ePais));
}
ePais* Pais_newParametros(char* idStr,char* paisStr,char* curadosStr,char* infecStr,char* muertosStr)
{
    ePais* auxPais;

    auxPais = pais_new();

    if(auxPais != NULL)
    {
        auxPais->id=atoi(idStr);
        strncpy(auxPais->pais,paisStr,50);
        auxPais->curados = atoi(curadosStr);
        auxPais->infectados = atoi(infecStr);
        auxPais->muertos = atoi(muertosStr);

    }
    else
    {
        free(auxPais);
        auxPais=NULL;
    }

    return auxPais;
}


/*-▬----[SETERS INICIO]------*/
int pais_setId(ePais* elemento,int auxId)
{
    int okey = -1;

    if(elemento != NULL && auxId>0)
    {
        elemento->id=auxId;
        okey=0;
    }

    return okey;
}

int pais_setNombre(ePais* elemento,char* auxName)
{
    int okey = -1;

    if(elemento != NULL && auxName != NULL)
    {
        strncpy(elemento->pais,auxName,50);
        okey=0;
    }

    return okey;
}

int pais_setCurados(ePais* elemento,int auxCurados)
{
    int okey = -1;

    if(elemento != NULL && auxCurados>0)
    {
        elemento->curados=auxCurados;
        okey=0;
    }

    return okey;
}

int pais_setInfectados(ePais* elemento,int auxInfectados)
{
    int okey = -1;

    if(elemento != NULL && auxInfectados>0)
    {
        elemento->infectados=auxInfectados;
        okey=0;
    }

    return okey;
}

int pais_setMuertos(ePais* elemento,int auxMuertos)
{
    int okey = -1;

    if(elemento != NULL && auxMuertos>0)
    {
        elemento->muertos=auxMuertos;
        okey=0;
    }

    return okey;
}
/*-▬----[SETERS FINAL]------*/



/*-▬----[GETERS INICIO]------*/

int pais_getId(ePais* elemento,int* auxId)
{
    int okey = -1;

    if(elemento != NULL && auxId!=NULL)
    {
        *auxId=elemento->id;
        okey=0;
    }

    return okey;
}

int pais_getNombre(ePais* elemento,char* auxName)
{
    int okey = -1;

    if(elemento != NULL && auxName != NULL)
    {
        strncpy(auxName,elemento->pais,50);
        okey=0;
    }

    return okey;
}

int pais_getCurados(ePais* elemento,int* auxCurados)
{
    int okey = -1;

    if(elemento != NULL)
    {
        *auxCurados = elemento->curados;
        okey=0;
    }

    return okey;
}

int pais_getInfectados(ePais* elemento,int* auxInfectados)
{
    int okey = -1;

    if(elemento != NULL )
    {
        *auxInfectados = elemento->infectados;
        okey=0;
    }

    return okey;
}

int pais_getMuertos(ePais* elemento,int* auxMuertos)
{
    int okey = -1;

    if(elemento != NULL && auxMuertos>0)
    {
        *auxMuertos = elemento->muertos;
        okey=0;
    }

    return okey;
}

/*-▬----[GETERS FINAL]------*/

int printfPais(ePais* pais1)
{
    int todoOk=-1;
    ePais auxPais;

    if(pais1 != NULL)
    {
        pais_getId(pais1,&auxPais.id);
        pais_getNombre(pais1,auxPais.pais);
        pais_getCurados(pais1,&auxPais.curados);
        pais_getInfectados(pais1,&auxPais.infectados);
        pais_getMuertos(pais1,&auxPais.muertos);

        printf("| %04d | %22s | %05d | %05d | %05d |\n",auxPais.id,auxPais.pais,auxPais.curados,auxPais.infectados,auxPais.muertos);
        todoOk=0;
    }

    return todoOk;
}
void* addInfoRandom(void* elemento)
{
    void* pElemen;
    ePais* auxPais;
    int cantCurados,cantInfec,cantMuertos;

    if(elemento!=NULL)
    {
        auxPais = (ePais*) elemento;

        /*
            Esta una manera que ya utilice en otros proyectos para dar numeros aleatorios ya que
            la que me paso en block de notas me tiraba error
        */

        cantCurados = rand () % (100000-50000+1) + 50000;
        cantInfec =  rand () % (200000-40000+1) + 40000;
        cantMuertos =  rand () % (50000-1000+1) + 1000;

        pais_setCurados(auxPais,cantCurados);
        pais_setInfectados(auxPais,cantInfec);
        pais_setMuertos(auxPais,cantMuertos);

        pElemen=elemento;
    }
    return pElemen;
}

int pais_exitosos(void* element)
{
    int criterio = 0;
    ePais* pPais = (ePais*) element;

    if( pPais!= NULL && (pPais->muertos < 5000))
    {
        criterio=1;
    }

    return criterio;
}


int pais_infeccion(void* element)
{
    int criterio = 0;
    ePais* pPais = (ePais*) element;
    int cantidadCurados = 0;
    int paisCantCurados;
    int paisCantInfectados;

    if( pPais!= NULL)
    {
        pais_getCurados(pPais,&paisCantCurados);
        pais_getInfectados(pPais,&paisCantInfectados);
        cantidadCurados = paisCantCurados * 3;

        if(paisCantInfectados>=cantidadCurados)
        {
            criterio=1;
        }
    }

    return criterio;
}

int pais_ordenarInfecionDecendente(void* element1,void* element2)
{
    int criterio = 0;
    ePais* pPais1;
    ePais* pPais2;
    int cantInfec1;
    int cantInfec2;

    if( element1!= NULL && element2!= NULL)
    {
        pPais1 = (ePais*) element1;
        pPais2 = (ePais*) element2;

        pais_getInfectados(pPais1,&cantInfec1);
        pais_getInfectados(pPais2,&cantInfec2);

        if( cantInfec1 > cantInfec2 )
        {
            criterio = 1;
        }
        else if(cantInfec1 < cantInfec2 )
        {
            criterio = -1;
        }
    }

    return criterio;
}

int pais_masCastigado(LinkedList* this)
{
    int valido= 0;
    int len= ll_len(this);
    int cantMuertos;
    int cantMaxMuertos;
    int flag=1;
    ePais* pPais;
    void* elemento;
    LinkedList* pListaAux= ll_newLinkedList();

    //busco cantidad max de muertos
    if(this!= NULL )
    {
        for(int i=0 ; i<len ; i++)
        {
            pPais=(ePais*) ll_get(this,i);
            pais_getMuertos(pPais,&cantMuertos);

            if(cantMuertos>cantMaxMuertos || flag==1)
            {
                cantMaxMuertos=cantMuertos;
                flag=0;
            }
        }
    }

    // busco si hay mas de un pais con esa misma cantidad de muertos
    if(pListaAux!= NULL)
    {
        for(int i=0 ; i<len ; i++)
        {
            pPais=(ePais*) ll_get(this,i);
            pais_getMuertos(pPais,&cantMuertos);

            if(cantMuertos==cantMaxMuertos)
            {
                elemento= (void*) pPais;
                ll_add(pListaAux,elemento);
            }
        }
    }

    controller_ListPais(pListaAux);

    return valido;
}
