#include "lista_enlazada.h"
#include <stddef.h>
#include <stdbool.h>

void NodoListaEnlazada_inicializa(NodoListaEnlazada *nodo,int valor)
{
    nodo->valor = valor;             // Asigna el valor al nodo
    nodo->siguiente = NULL;          // Inicializa el puntero siguiente a NULL
}
void ListaEnlazada_inicializa(ListaEnlazada *lista)
{
    *lista = NULL;                   // Inicializa la lista como vacía (NULL)
}
void ListaEnlazada_inserta(ListaEnlazada *lista, NodoListaEnlazada *nodo)
{
    nodo->siguiente = *lista;        // El nodo siguiente del nuevo nodo es el actual primer nodo
    *lista = nodo; 
}
NodoListaEnlazada *ListaEnlazada_obtNodoCabeza(ListaEnlazada *lista)
{
    return *lista;                   // Retorna el nodo cabeza de la lista (puede ser NULL)
}
bool ListaEnlazada_esVacia(ListaEnlazada *lista)
{
    return *lista == NULL;           // Retorna true si la lista es NULL (vacía)
}
int ListaEnlazada_obtCabeza(ListaEnlazada *lista, int *valor)
{
    if (ListaEnlazada_esVacia(lista)) {
        return -1;                   // Retorna -1 si la lista está vacía
    }
    *valor = (*lista)->valor;        // Obtiene el valor de la cabeza de la lista
    return 0;                        // Retorna 0 indicando éxito
}
ListaEnlazada *ListaEnlazada_obtCola(ListaEnlazada *lista)
{
    if (ListaEnlazada_esVacia(lista)) {
        return lista;                // Retorna la misma lista si está vacía
    }
    return &((*lista)->siguiente);   // Retorna la dirección del puntero al siguiente nodo
}
NodoListaEnlazada *ListaEnlazada_remueveCabeza(ListaEnlazada *lista)
{
    if (ListaEnlazada_esVacia(lista)) {
        return NULL;                 // Retorna NULL si la lista está vacía
    }
    NodoListaEnlazada *nodoRemovido = *lista;  // Guarda el nodo removido
    *lista = nodoRemovido->siguiente;          // Actualiza la cabeza de la lista
    nodoRemovido->siguiente = NULL;            // Desconecta el nodo removido
    return nodoRemovido;                       // Retorna el nodo removido
}
