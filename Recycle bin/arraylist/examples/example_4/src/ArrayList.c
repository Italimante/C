#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

//Hacer tambien la practica donde usamos las funciones que hay que hacer aca --

//El al_push es agarrar el elemento y ponerlo al final
//Agregar al final es un add
// -Segmentos de memoria.
// - Matar pelement y list
// lo unico que se puede liberar con free es lo que contruimos con el array list, pelements y el arraylist
/*
    nunca hacer un free al dato
    hay que liberar todo lo que hicimos malloc
    primero voy a borrar pelemnts porque es lo primero que se creo, y despues el arraylist
    liberar la lista y despues el arraylist

    --------
        El expand te corre todo del indice,  te deja el lugar vacio o con el repetido anterior, corre todo para un costado
        y el contract lo contrario
        (el add solucionaba que faltara lugar)
    --------

    Ponerlo en nulo

*/


// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL){
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL){
            this->size = 0;
            this->pElements = pElements;
            this->reservedSize = AL_INITIAL_VALUE;
            this->add = al_add;
            this->len = al_len;
            this->set = al_set;
            this->remove = al_remove;
            this->clear = al_clear;
            this->clone = al_clone;
            this->get = al_get;
            this->contains = al_contains;
            this->push = al_push;
            this->indexOf = al_indexOf;
            this->isEmpty = al_isEmpty;
            this->pop = al_pop;
            this->subList = al_subList;
            this->containsAll = al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else{
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement){
    int returnAux = -1;
    int flag = 0;
    void** aux;

    if(this!=NULL && pElement!=NULL){
        //Si quiero cargar mas datos de los que elegi por defecto voy a hacer realloc
        if(this->size==this->reservedSize){
            aux = (void**) realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));
            if(aux!=NULL){
                this->pElements = aux;
                this->reservedSize = this->reservedSize + AL_INCREMENT;
            }else{
                flag = 1;
            }
        }
        //Esta funcion es resize up, despues la llamo, tambien la necesito para al_push, etc...
        //Con el size podemos saber en que posicion vamos a cargar la estructura
        //Si pudo agregar el elemento entonces hago lo siguiente:
        if(flag == 0){
            this->pElements[this->size] = pElement;
            //*(this->pElements+i) == vec[0]
            this->size++; //Para que cuando tenga que cargar otro elemento no me lo pise
            returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this){
    int returnAux = -1;

    if(this != NULL){
        free(this->pElements);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Return arraylist size
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this!= NULL){
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index < this->size){
        returnAux = this->pElements[index];
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement != NULL){
        returnAux = 0;
        for(i=0;i<this->size;i++){
            if(this->pElements[i] == pElement){
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement){ //TRATAR DE ENTENDER ESTO
    //Si conincide con el index lo agrega al final, si no lo mandaria al principio

    int returnAux = -1;

    if(this!=NULL && pElement!=NULL && index>=0 && index < this->size){

        if(index == this->len(pElement) && this->add(this,pElement)==0 ){
                returnAux=0;
            }
            else{
            this->pElements[index]=pElement;
            returnAux = 0;
        }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;

    if(this!=NULL && index < this->size && index>=0){
        if(index == this->len(this)){

        }
    }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;

    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux = -1;
    void* pElementA=NULL;
    void* pElementB=NULL;
    void* pElementAux=NULL;

    if(this!=NULL && pFunc!=NULL && (order == 1 || order == 0)){
        for(int i=0;i<this->len(this)-1;i++){
            for(int j=i+1; j<this->len(this);j++){
                pElementA=this->get(this,i);
                pElementB=this->get(this,j);

                if(order==1){
                    if(pFunc(pElementA,pElementB)){
                        pElementAux=this->pElements[i];
                        this->pElements[i]=this->pElements[j];
                        this->pElements[j]=pElementAux;
                    }
                }

                if(order==0){
                    if(pFunc(pElementA,pElementB)==-1){
                        pElementAux=this->pElements[i];
                        this->pElements[i]=this->pElements[j];
                        this->pElements[j]=pElementAux;
                    }
                }
            }
        }
        returnAux=0;
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this){
    int returnAux = -1;
    void* aux = NULL;
    if(this->size == this->reservedSize){
        aux = (void*)realloc(this->pElements,sizeof(void*) * (this->reservedSize+AL_INCREMENT));
        if(aux != NULL){
            this->pElements = aux;
            this->reservedSize += AL_INCREMENT;
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index){
    int returnAux = -1;
    int i;
    if(this!=NULL){
        this->size++;
        resizeUp(this);
        for(i = index; i > this->size; i--){
            this->pElements[i]=this->pElements[i-1];
        }
        returnAux=0;
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index){
    int returnAux = -1;
    int i;
    if(this!=NULL){
        this->size--;
        for(i = index; i < this->size; i++){
            this->pElements[i]=this->pElements[i+1];
        }
        returnAux=0;
    }
    return returnAux;
}
