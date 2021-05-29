#ifndef MARL_LIST_H
#define MARL_LIST_H

typedef struct MARL_List {
  void **data;
  unsigned int size;
  unsigned int capacity;
} MARL_List;

MARL_List *MARL_ListCreate();

void MARL_ListAdd(MARL_List* list, void *elem);

void *MARL_ListGet(MARL_List* list, int index);

void *MARL_ListPop(MARL_List *list);

void *MARL_ListPeek(MARL_List *list);

void MARL_ListRemove(MARL_List *list, int index);


/**
 * Saves storage when the list is accessed not often.
 */
void MARL_ListCompress(MARL_List *list);

void MARL_ListFree(MARL_List *list);

#endif /* end of include guard: MARL_LIST_H */
