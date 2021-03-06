#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
        this->size=0;
        this->pFirstNode=NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux=this->size;
    }
    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* auxGetNodo=NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <ll_len(this))
    {
        auxGetNodo=this->pFirstNode;

        for(int i=0 ; i<nodeIndex ; i++)

        {
            auxGetNodo=auxGetNodo->pNextNode;
        }
    }
    return auxGetNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* newNode=NULL;
    Node* auxNode=NULL;

    //verificar si pElement es distinto de NULL tira error
    if(this !=NULL  && nodeIndex>=0 && nodeIndex<=ll_len(this))
    {
        newNode=(Node*)malloc(sizeof(Node));
        auxNode=(Node*)malloc(sizeof(Node));

        if(auxNode!= NULL && newNode != NULL)
        {
            newNode->pElement=pElement;

            if(nodeIndex==0)
            {
                newNode->pNextNode = this->pFirstNode;
                this->pFirstNode=newNode;
            }
            else if(nodeIndex==ll_len(this))
            {
                auxNode=getNode(this,nodeIndex -1);
                if(auxNode != NULL)
                {
                    auxNode->pNextNode=newNode;
                    newNode->pNextNode=NULL;
                }
            }
            else
            {
                auxNode=getNode(this,nodeIndex -1);
                if(auxNode != NULL)
                {
                    newNode->pNextNode=auxNode->pNextNode;
                    auxNode->pNextNode=newNode;
                }
            }
            this->size++;
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        addNode(this,ll_len(this),pElement);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returAux=NULL;
    Node* auxNode=NULL;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode=getNode(this,index);

        if(auxNode!=NULL)
        {
            returAux=auxNode->pElement;
        }
    }

    return returAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL &&  0<=index && index<ll_len(this) )
    {
        auxNode=getNode(this,index);

        if(auxNode != NULL)
        {
            auxNode->pElement=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int flag=0;
    Node* auxNode1;
    Node* auxNode2;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        //obtengo el nodo a remover
        auxNode1=getNode(this,index);

        if(auxNode1 != NULL)
        {

            if(index==0)
            {
                this->pFirstNode=auxNode1->pNextNode;
                flag=1;
            }
            else
            {
                //obtengo el elemento anterior a remover
                auxNode2=(getNode(this,index -1));

                if(auxNode2 != NULL)
                {
                    //caso si es el ultimo elemento a remover
                    if(index==(ll_len(this)-1))
                    {
                        auxNode2->pNextNode=NULL;
                    }
                    else
                    {
                        auxNode2->pNextNode=auxNode1->pNextNode;
                    }
                    flag=1;
                }
            }
            if(flag)
            {
                this->size--;

                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len ;

    if( this != NULL )
    {
        len=ll_len(this)-1;

        for(int i=len ; i>=0 ; i--)
        {
            ll_remove(this,i);

            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {

        if(this->pFirstNode==NULL)
        {
            free(this);
            returnAux=1;
        }
        else
        {
            ll_clear(this);
            free(this);
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* auxNode;

    if(this != NULL)
    {
        for(int i=0 ; i<len ; i++)
        {
            auxNode=getNode(this,i);

            if(auxNode != NULL)
            {
                if(auxNode->pElement==pElement)
                {
                    returnAux=i;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->pFirstNode==NULL)
        {
            returnAux=1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(!addNode(this,index,pElement))
    {
        returnAux=0;
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int flag=0;
    Node* auxNode1;
    Node* auxNode2;

    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode1=(Node*)malloc(sizeof(Node));
        auxNode2=(Node*)malloc(sizeof(Node));

        //obtengo el nodo a remover
        auxNode1=getNode(this,index);

        if(auxNode1 != NULL)
        {
            if(index==0)
            {
                auxNode2=this->pFirstNode;
                returnAux=auxNode2->pElement;
                this->pFirstNode=auxNode1->pNextNode;
                flag=1;
            }
            else
            {
                //obtengo el elemento anterior a remover
                auxNode2=(getNode(this,index -1));

                if(auxNode2 != NULL)
                {
                    //caso si es el ultimo elemento a remover
                    if(index==(ll_len(this)-1))
                    {
                        returnAux=auxNode2->pNextNode->pElement;
                        auxNode2->pNextNode=NULL;
                    }
                    else
                    {
                        returnAux=auxNode2->pNextNode->pElement;
                        auxNode2->pNextNode=auxNode1->pNextNode;
                    }
                    flag=1;
                }
            }
            if(flag)
            {
                this->size--;
            }
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    //Si es null return-1
    if(this != NULL)
    {
        //Si no esta en lista retur 0
        if(ll_indexOf(this,pElement)==-1)
        {
            returnAux=0;
        }
        //Si esta en la lista
        else
        {
            returnAux=1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
    void* auxElement;

    if(this2 != NULL && this != NULL )
    {
        len=ll_len(this2);
        returnAux=1;

        for(int i=0 ; i<len ; i++)
        {
            auxElement=ll_get(this2,i);

            if(auxElement != NULL)
            {
                if( !ll_contains(this,auxElement))
                {
                    returnAux=0;
                    break;
                }
            }
        }
    }
    return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;

    if(this != NULL && !(from<0 || from>ll_len(this) || to<=from || to>ll_len(this)) )
    {
        cloneArray=ll_newLinkedList();

        if(cloneArray != NULL)
        {

            for(int i=from ; i<to ; i++)
            {
                pElement=ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
        }
    }
    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
    void* pElement;

    if(this != NULL)
    {
        cloneArray=ll_newLinkedList();

        if(cloneArray != NULL)
        {
            len=ll_len(this);

            for(int i=0 ; i<len ; i++)
            {
                pElement=ll_get(this,i);
                ll_add(cloneArray,pElement);
            }
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int len;
    void* pElement1;
    void* pElement2;
    void* auxElement;
    Node* auxNode1;
    Node* auxNode2;

                    //Nota personal: Los punteros a funciones pueden traer un NULL
    if(this != NULL && pFunc != NULL && (order==1 || order==0))
    {
        len=ll_len(this);

        for(int i=0 ; i<len-1 ; i++)
        {
            for(int j=i+1 ; j<len ; j++)
            {

                pElement1=ll_get(this,i);
                pElement2=ll_get(this,j);
                auxNode1=getNode(this,i);
                auxNode2=getNode(this,j);

                if(pElement1 != NULL && pElement2 != NULL)
                {
                    switch(order)
                    {
                    case 0:
                        if((pFunc(pElement1,pElement2))<0)
                        {
                            auxElement=pElement2;
                            auxNode2->pElement=pElement1;
                            auxNode1->pElement=auxElement;
                        }
                        break;
                    case 1:
                        if( (pFunc(pElement1,pElement2))>0)
                        {
                            auxElement=pElement2;
                            auxNode2->pElement=pElement1;
                            auxNode1->pElement=auxElement;
                        }
                        break;
                    }
                }
            }
        }
        returnAux=0;
    }

    return returnAux;

}


/** \brief retorna una nueva lista con los elemento editados dependindo de la funcion pasada
 *
 * \param pPais void*
 * \return LinkedList* ll_map(LinkedList* this,void*
 *
 */
LinkedList* ll_map(LinkedList* this,void* (*pFunc)(void* pPais))
{
    LinkedList* pLista= ll_newLinkedList();
    int len = ll_len(this);
    void* auxPais;

    if(pLista!= NULL && pFunc!= NULL && this!= NULL)
    {
        for(int i=0 ; i<len ; i++)
        {
            auxPais = ll_get(this,i);

            if(auxPais != NULL)
            {
                auxPais= pFunc(auxPais);
                ll_add(pLista,auxPais);
            }
        }
    }
    return pLista;
}

/** \brief crea una linkedList agregado segun el criterio de la funcion pasada como parametro
 *
 * \param pPais void*
 * \return LinkedList* ll_filter(LinkedList* this,int
 *
 */
LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void* pPais))
{
    int len = ll_len(this);
    void* element;
    LinkedList* auxLista = ll_newLinkedList();

    if(this!=NULL && pFunc!=NULL && auxLista!=NULL)
    {
        for(int i=0 ; i<len ; i++)
        {
            element = ll_get(this,i);
            if( element!= NULL && pFunc(element))
            {
                ll_add(auxLista,element);
            }
        }
    }
    return auxLista;
}

