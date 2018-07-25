/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList{

    void** pElements;
    int size;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

}typedef ArrayList;
#endif


/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 *         [ES]: Crea y retorna un nuevo ArrayList. Es el constructor, ya que en él daremos valores iniciales a
 *         las variables y asignaremos las funciones a sus punteros.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void);


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 *          [ES]: Agrega un elemento al final de ArrayList. Verificando que tanto el puntero pList como pElement
 *          sean distintos de NULL. Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement);


/** \brief  Delete arrayList
 *           [ES]: Elimina el ArrayList . Verificando que el puntero pList sea distinto de NULL. Si la verificación
 *           falla la función retorna (-1), si esta vacío (1) y si contiene elementos (0).
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this);


/** \brief  Return arrayList size
 *          [ES]: Retorna el tamaño del ArrayList. Verificando que el puntero pList sea distinto de NULL. Si la
 *          verificación falla la función retorna (-1) y si tiene éxito retorna la longitud del array.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this);


/** \brief  Get an element by index
 *          [ES]: Retorna un puntero al elemento que se encuentra en el índice especificado. Verificando que el
 *          puntero pList sea distinto de NULL y que index sea positivo e inferior al tamaño del array.
 *          Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el elemento.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index);


/** \brief  Find if pList contains at least one element pElement
 *          [ES]: Comprueba si existe el elemento que se le pasa como parámetro. Verificando que tanto el
 *          puntero pList como pElement sean distintos de NULL. Si la verificación falla la función retorna
 *          (-1) , si encuentra el elemento (1) y si no lo encuentra (0).
 *
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement);


/** \brief  Set a element in pList at index position
 *          [ES]: Inserta un elemento en el ArrayList, en el índice especificado. Verificando que tanto el puntero
 *          pList como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del
 *          array. Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 *
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement);


/** \brief  Remove an element by index
 *           [ES]: Elimina un elemento del ArrayList, en el índice especificado. Verificando que el puntero pList
 *           sea distinto de NULL y que index sea positivo e inferior al tamaño del array. Si la verificación
 *           falla la función retorna (-1) y si tiene éxito (0).
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index);



/** \brief Removes all of the elements from this list
 *         [ES]: Borra todos los elementos de ArrayList. Verificando que el puntero pList sea distinto de NULL.
 *         Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this);


/** \brief Returns an array containing all of the elements in this list in proper sequence
 *           [ES]:Retorna un nuevo ArrayList copia del ArrayList original. Verificando que el puntero pList sea
 *           distinto de NULL. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el
 *           nuevo array.
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this);


/** \brief Inserts the element at the specified position
 *         [ES]: Desplaza los elementos e inserta en la posición index. Verificando que tanto el puntero pList
 *         como pElement sean distintos de NULL y que index sea positivo e inferior al tamaño del array.
 *         Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement);



/** \brief Returns the index of the first occurrence of the specified element
 *         [ES]: Retorna el índice de la primera aparición de un elemento (element) en el ArrayList. Verificando
 *         que tanto el puntero pList como pElement sean distintos de NULL. Si la verificación falla o no
 *         encuentra el elemento la función retorna (-1) y si encuentra el elemento retorna su índice.
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement);



/** \brief Returns true if this list contains no elements.
 *         [ES]: Retorna cero si contiene elementos y uno si no los tiene. Verificando que el puntero pList sea
 *         distinto de NULL. Si la verificación falla la función retorna (-1), si esta vacío (1) y si contiene
 *         elementos (0).
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this);



/** \brief Remove the item at the given position in the list, and return it.
 *        [ES]:Retorna un puntero al elemento que se encuentra en el índice especificado y luego lo elimina
 *        de la lista. Verificando que el puntero pList sea distinto de NULL y que index sea positivo e
 *        inferior al tamaño del array. Si la verificación falla la función retorna (NULL) y si tiene éxito
 *        retorna el elemento.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index);



/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 *           [ES]:Retorna un nuevo ArrayList con el subconjunto de elementos. Verificando que el puntero pList
 *           sea distinto de NULL y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño
 *           del array. Si la verificación falla la función retorna (NULL) y si tiene éxito retorna el nuevo array.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to);



/** \brief Returns true if pList list contains all of the elements of pList2
 *         [ES]:Comprueba si los elementos pasados son contenidos por el ArrayList. Verificando que tanto el
 *         puntero pList como pList2 sean distintos de NULL. Si la verificación falla o no encuentra el
 *         elemento la función retorna (-1), si las listas difieren (0) y si ambas listas son iguales retorna
 *         (1).
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2);


/** \brief Sorts objects of list, use compare pFunc
 *          [ES]:Ordena los elementos del array recibiendo como parámetro la función que sera la encargada
 *          de determinar que elemento es mas grande que otro y si se debe ordenar de manera
 *          ascendente o descendente. Verificando que tanto el puntero pList como el puntero a la funcion
 *          pFunc sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order);



/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this);


/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index);


/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index);

// Private function
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);
//___________________

ArrayList* al_filter(ArrayList* this , int (*funcionQueFiltra)(void*));
