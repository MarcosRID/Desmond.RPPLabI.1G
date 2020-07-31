
#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif

int controller_loadFromText(char* path , LinkedList* pArrayListPais);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPais);
int controller_ListPais(LinkedList* pArrayListPais);
int controller_saveAsText(char* path , LinkedList* pArrayListPais);
int controller_cargarDataEnElemento(LinkedList* this,LinkedList* this2);
int controller_mostrarPaisesCastigados(LinkedList* pArrayListePais);
int controller_createPath(char* array,char* pathRelativ);
LinkedList* controller_paisExitoso(LinkedList* pLista);
LinkedList* controller_paisMayorInfeccion(LinkedList* pLista);
int controller_sortPais(LinkedList* pArrayListePais);
