#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

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

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            this->filter = al_filter;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param this ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;

    if(pElement!=NULL && this!=NULL)
    {
        resizeUp(this);
        this->pElements[this->size]=pElement;
        this->size++;
        returnAux=0;

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->pElements!=NULL)
        {
        free(this->pElements);
        this->pElements=NULL;
        }
        free(this);
        this=NULL;
        returnAux=0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param this ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [this is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [this is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL)
    {
        if(index<this->size && index>=0)
        {
        returnAux=this->pElements[index];
        }
    }

    return returnAux;
}


/** \brief  Find if this contains at least one element pElement
 * \param this ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int i;
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL)
    {
        for(i = 0; i <this->len(this);i++)
        {
            returnAux=0;

            if(*(this->pElements+i)==pElement)
            {
            returnAux=1;
            break;
            }
        }

    }

    return returnAux;
}


/** \brief  Set a element in this at index position
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL && (index >=0 && index <= this->size))
    {
        if(index==this->len(this))
        {
            if(this->add(this,pElement)==0)
            {
            returnAux=0;
            }
        }

        else
        {
            this->pElements[index]=pElement;
            returnAux=0;
        }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;

    if(this!=NULL && (index >=0 && index<this->len(this)) && this->pElements!=NULL)
    {
        if(contract(this,index)==0)
            {
                returnAux=0;
            }
    }


    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL && this->pElements!=NULL)
    {

    free(this->pElements);
    this->size=0;
    this->reservedSize=AL_INITIAL_VALUE;
    this->pElements = (void**)malloc(sizeof(void*)*AL_INITIAL_VALUE);
    returnAux = 0;
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && (index>=0 && index <= this->len(this)) && pElement!=NULL)
    {

        if(index==this->len(this))
        {
                if(this->add(this,pElement)==0)
                {
                returnAux=0;
                }
        }

        else
        {
            if(expand(this,index)==0)
            {
            this->set(this,index,pElement);
            returnAux=0;
            }
        }

    }

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param this ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [this or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    if(this!=NULL && pElement!=NULL)
    {
        for(i=0; i <= this->len(this);i++)
        {
            if(this->pElements[i]==pElement)
            {
                returnAux=i;
                break;
            }
        }
    }


    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->len(this)>0)
        {
            returnAux=0;
        }
        else
        {
            returnAux=1;
        }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [this is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL && (index>=0 && index < this->len(this) && this->pElements !=NULL))
       {
           returnAux=this->get(this,index);
           contract(this,index);
       }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of this between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param this ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [this is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* returnAux=NULL;
    int i;
    void* aux = NULL;


    if(this!=NULL && from>=0 && to <= this->len(this) && from < to)
    {
      returnAux=al_newArrayList();
      if(returnAux!=NULL)
      {
          for(i=from; i < to;i++)
          {
              resizeUp(returnAux);
              aux=this->get(this,i);
              returnAux->add(returnAux,aux);
          }
      }
    }

    return returnAux ;
}





/** \brief Returns true if this list contains all of the elements of this2
 * \param this ArrayList* Pointer to arrayList
 * \param this2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this or this2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1;
    int counter=0;
    int i;
    int j;

    if(this!=NULL && this2 != NULL)
    {
        for(i=0;i<this->len(this);i++)
        {
            for(j=0; j<this2->len(this2);j++)
            {
                if(this->pElements[i]==this2->pElements[j])
                {
                    counter++;
                    break;
                }
            }
        }

        if(counter==this2->len(this2))
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

/** \brief Sorts objects of list, use compare pFunc
 * \param this ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [this or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pElementAux=NULL;
    void* pElementA=NULL;
    void* pElementB=NULL;
    int i;
    int j;

    if(this!=NULL && pFunc!=NULL && (order == 1 || order == 0))
    {
        for(i=0;i<this->len(this)-1;i++)
        {
            for( j=i+1; j<this->len(this);j++)
            {
                pElementA=this->get(this,i);
                pElementB=this->get(this,j);

                if(order==1)
                {
                    if(pFunc(pElementA,pElementB))
                    {
                        pElementAux=this->pElements[i];
                        this->pElements[i]=this->pElements[j];
                        this->pElements[j]=pElementAux;

                    }
                }

                if(order==0)
                {
                    if(pFunc(pElementA,pElementB)==-1)
                    {
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


/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param this ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [this is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    //void* aux=NULL;
    int i;
    if(this!=NULL)
    {
        returnAux= al_newArrayList();
        if(returnAux!=NULL)
        {
            for( i=0;i<this->len(this);i++)
            {
            //resizeUp(returnAux);
            //aux=this->get(this,i);
            al_add(returnAux,this->pElements[i]);
            }
        }
    }

    return returnAux;
}




ArrayList* al_filter(ArrayList* this, int(*filtro)(void*))
{
    ArrayList* returnAux=NULL;
    int i;
    if(this!=NULL && filtro!=NULL)
    {
        returnAux=al_newArrayList();
        for( i=0;i<this->len(this);i++)
        {

            if(filtro(this->pElements[i]))
            {
                returnAux->add(returnAux,this->pElements[i]);

            }
        }
    }
    return returnAux;
}


/** \brief Increment the number of elements in this in AL_INCREMENT elements.
 * \param this ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [this is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{


    int returnAux = -1;
    void* aux=NULL;

    if(this->size==this->reservedSize)
    {
    aux=(void*)realloc(this->pElements,sizeof(void*)*(this->reservedSize+AL_INCREMENT));

        if(aux!=NULL)
        {
        this->pElements=aux;
        this->reservedSize+=AL_INCREMENT;
        returnAux=0;
        }


    }



    return returnAux;

}

/** \brief  Expand an array list
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {

    this->size++;
    resizeUp(this);
        for( i = this->size; i > index;i--)
        {
            this->pElements[i]=this->pElements[i-1];
        }
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param this ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [this is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL)
    {

    this->size--;
        for( i = index; i < this->size;i++)
        {
            this->pElements[i]=this->pElements[i+1];
        }
        returnAux=0;
    }

    return returnAux;
}
