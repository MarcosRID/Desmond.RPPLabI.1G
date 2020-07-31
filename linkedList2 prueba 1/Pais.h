#include "LinkedList.h"
#ifndef PAIS_H_INCLUDED
#define PAIS_H_INCLUDED

typedef struct
{

    int id;
    char pais[50];
    int curados;
    int infectados;
    int muertos;

}ePais;

#endif // PAIS_H_INCLUDED

int menu();
ePais* pais_new();
ePais* Pais_newParametros(char* idStr,char* paisStr,char* curadosStr,char* infecStr,char* muertosStr);
void* addInfoRandom(void* elemento);
int pais_exitosos(void* element);
int pais_infeccion(void* element);
int pais_ordenarInfecionDecendente(void* element1,void* element2);
int pais_masCastigado(LinkedList* this);
int printfPais(ePais* pais1);


int pais_setId(ePais* elemento,int auxId);
int pais_setNombre(ePais* elemento,char* auxName);
int pais_setInfectados(ePais* elemento,int auxInfectados);
int pais_setMuertos(ePais* elemento,int auxMuertos);

int pais_getId(ePais* elemento,int* auxId);
int pais_getNombre(ePais* elemento,char* auxName);
int pais_getCurados(ePais* elemento,int* auxCurados);
int pais_getInfectados(ePais* elemento,int* auxInfectados);
int pais_getMuertos(ePais* elemento,int* auxMuertos);

