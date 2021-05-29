
#include <stdlib.h>
#include "marl_list.h"

MARL_List *MARL_ListCreate() {
  MARL_List *list = malloc(sizeof(MARL_List));
  list->size = 0;
  list->capacity = 5;
  list->data = malloc(sizeof(void*) * list->capacity);

  return list;
}

void MARL_ListAdd(MARL_List* list, void *elem) {
  if (list->size == list->capacity) { // should not be greater!!!
    list->capacity *= 2;
    list->data = realloc(list->data, sizeof(void*) * list->capacity);
  }

  list->data[list->size] = elem;
  list->size++;
}

void *MARL_ListGet(MARL_List* list, int index) {
  return list->data[index];
}

void *MARL_ListPop(MARL_List *list) {
  void *ret = list->data[list->size-1];
  MARL_ListRemove(list, list->size-1);
  return ret;
}

void *MARL_ListPeek(MARL_List *list) {
  return list->data[list->size-1];
}

void MARL_ListRemove(MARL_List *list, int index) {
  // WTF
  if(index >= list->size || index < 0) {
    return; // TODO Error
  }

  if (list->size < 0.6 * list->capacity) {
    list->capacity *= 0.6;
    list->data = realloc(list->data, sizeof(void*) * list->capacity);
  }

  for (size_t i = index; i < (list->size-1); i++) {
    list->data[i] = list->data[i + 1];
  }
  list->size--;
}

void MARL_ListCompress(MARL_List *list) {
  list->capacity = list->size;
  list->data = realloc(list->data, sizeof(void*) * list->capacity);
}

void MARL_ListFree(MARL_List *list) {
  free(list->data);
  free(list);
}
