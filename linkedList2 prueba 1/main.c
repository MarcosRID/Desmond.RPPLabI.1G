#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pais.h"
#include "UTN.h"

int main()
{
    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesCargados= ll_newLinkedList();
    LinkedList* listaExitosos = ll_newLinkedList();
    LinkedList* listainfectados = ll_newLinkedList();
    char confirmar;
    int out=1;
    int trigger=0;
    char namePath[50];

    do
    {
        system("cls");
        switch( menu())
        {
        case 1:
            if(!trigger)
            {
                system("cls");
                controller_createPath(namePath,"file\\");
                if(!controller_loadFromText(namePath,listaPaises))//cargo los dato en Texto
                {
                    printf("Se logro cargar los datos Formato texto\n");
                    trigger=1;
                }
                else
                {
                    printf("Se produjo un eRror al cargar los datos en Formato Texto\n");
                }
            }
            else
            {
                printf("Solo se puede cargar una vez los datos\n");
            }
            system("pause");

            break;
        case 2:
        if(trigger)
            {
                system("cls");
                if( !(controller_ListPais(listaPaises)) )
                {
                    printf("\n");
                }
                else
                {
                    printf("no\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;

        case 3:
            if(trigger)
            {
                system("cls");
                printf("............... Cargando datos ............... \n\n");
                if( !(controller_cargarDataEnElemento(listaPaises,listaPaisesCargados)) )
                {
                    printf("Operacion exitosa (cargar datos)\n");
                }
                else
                {
                    printf("Error en la operacion (ALTA)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 4:
            if(trigger)
            {
                system("cls");
                printf("........... Archivo (tasa baja : mortalidad)...........\n");
                listaExitosos=controller_paisExitoso(listaPaises);

                if( listaExitosos != NULL )
                {
                    controller_saveAsText("file\\dataExito.csv",listaExitosos);
                    printf("Operacion Exitosa (archivo nuevo exito)\n");
                }
                else
                {
                    printf("Error en la operacion (MODIFICAR)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 5:
             if(trigger)
            {
                system("cls");
                printf("........... Archivo (tasa baja : mortalidad)...........\n");

                listainfectados=controller_paisMayorInfeccion(listaPaises);

                if( listainfectados != NULL )
                {
                    controller_saveAsText("file\\dataInfectados.csv",listainfectados);
                    printf("Operacion Exitosa (archivo nuevo exito)\n\n");

                    if(ll_len(listainfectados)==0)
                    {
                        printf("No hay paises que sus infectados tripliquen a los curados\n\n");
                    }
                }
                else
                {
                    printf("Error en la operacion \n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;
        case 6:
            if(trigger)
            {
                system("cls");
                printf("........... Lista de Infectados (Desendente) ...........\n");

                if( !controller_sortPais(listaPaises) )
                {
                    printf("Operacion Exitosa (Se ordeno correctamente)\n");
                }
                else
                {
                    printf("Error en la operacion (ordenar)\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");

            break;
        case 7:
            if(trigger)
            {
                system("cls");
                if( !(controller_mostrarPaisesCastigados(listaPaises)) )
                {
                    printf("Cambios realizados con exito (Reordenamiento)\n");
                }
                else
                {
                    printf("Error al intentar ordenar\n");
                }
            }
            else
            {
                printf("Para acceder primero carge los datos (modo TXT o BIN)\n");
            }
            system("pause");
            break;

        case 8:

            utn_getCaracter(&confirmar,"confirmar la baja (S=SI  N=NO)\n","Error solo letras S o N\n",'N','s',-1);

            if(tolower(confirmar)== 's')
            {
                out=0;
            }
            break;
        }
    }
    while(out);
    return 0;
}


