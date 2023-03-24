#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List *movies = (List *) malloc (sizeof(List));
  movies->head = NULL;
  movies->tail = NULL;
  movies->current = NULL;
     return movies;
}

void * firstList(List * list) {
  if (list->head == NULL) return NULL;
  list->current = list->head;
    return (list->head->data);
}

void * nextList(List * list) {
  if (list->current == NULL) return NULL;
  if (list->current->next == NULL) return NULL;
  Node *aux = list->current;
  list->current = list->current->next;
    return (aux->next->data);
}

void * lastList(List * list) {
  
  list->current = list->tail;
    return (list->current->data);
}

void * prevList(List * list) {
  if(list->current == NULL) return NULL;
  if (list->current == list->head) return NULL;
  list->current = list->current->prev;
    return (list->current->data);
}

void pushFront(List * list, void * data) {
  
  Node *nodoParaInicio = createNode(data);
  if (list->head == NULL)
  {
    list->head = nodoParaInicio; 
    list->tail = nodoParaInicio;
  }
  else
  {
    nodoParaInicio->next = list->head;
    list->head->prev = nodoParaInicio;
    list->head = nodoParaInicio;
    nodoParaInicio->prev = NULL;
    
  }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  
  Node *aux = createNode(data);
 aux->prev = list->current;
  
  if (list->current == list->tail)
  {
    list->current->next = aux;
      aux->next = NULL;
    list->tail = aux;
  }
  else
  {
    //aux->next = list->current->next;
    list->current->next = aux;
  }
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  Node *nodoAEliminar = list->current;
  Node *nodoPrevioAlEliminado = list->current->prev;
  Node *nodoNextAlEliminado = list->current->next;

  if(list->current == list->head)
  {
    
  }
  else
  {
     list->current =  nodoNextAlEliminado;
      if(nodoNextAlEliminado != NULL)
      {
        nodoNextAlEliminado->prev = list->tail;
      }
  }


  return (nodoAEliminar->data);
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}