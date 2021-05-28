#ifndef MARL_LINKED_LIST_H
#define MARL_LINKED_LIST_H

typedef MARL_LinkedContainer {
  MARL_LinkedContainer *prev;
  MARL_LinkedContainer *next;
  void *value;
} MARL_LinkedContainer;



#endif /* end of include guard: MARL_LINKED_LIST_H */
