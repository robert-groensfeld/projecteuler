#ifndef PROJECTEULER_LIST_H
#define PROJECTEULER_LIST_H

#include <stdbool.h>
#include <malloc.h>

typedef struct IntList IntList;

IntList * createIntList();
void freeIntList(IntList *list);
bool isEmptyIntList(IntList *list);
bool containsInt(IntList *list, int element);
int getInt(IntList *list, size_t nodeIndex);
void addInt(IntList *list, int element);
void removeLastInt(IntList *list);
size_t getSizeOfIntList(IntList *list);
int getIntSum(IntList *list);

#endif //PROJECTEULER_LIST_H
