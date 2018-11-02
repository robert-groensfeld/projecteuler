#include "intlist.h"

static const size_t DEFAULT_CAPACITY = 16;

struct IntList {
    size_t size;
    size_t capacity;
    int *elements;
};

IntList * createIntList() {
    IntList *list = malloc(sizeof(*list));
    list->size = 0;
    list->capacity = DEFAULT_CAPACITY;
    list->elements = calloc(list->capacity, sizeof(int));
    return list;
}

void freeIntList(IntList *list) {
    free(list->elements);
    free(list);
}

bool isEmptyIntList(IntList *list) {
    return list->size == 0;
}

bool containsInt(IntList *list, int element) {
    for (size_t i = 0; i < list->size; ++i)
        if (list->elements[i] == element)
            return true;
    return false;
}

int getInt(IntList *list, size_t nodeIndex) {
    return list->elements[nodeIndex];
}

void addInt(IntList *list, int element) {
    if (list->size == list->capacity) {
        list->capacity = list->capacity + DEFAULT_CAPACITY;
        int *elements = calloc(list->capacity, sizeof(int));
        for (size_t i = 0; i < list->size; ++i)
            elements[i] = list->elements[i];
        free(list->elements);
        list->elements = elements;
    }

    list->elements[list->size] = element;
    list->size = list->size + 1;
}

void removeLastInt(IntList *list) {
    list->size = list->size - 1;
}

size_t getSizeOfIntList(IntList *list) {
    return list->size;
}

int getIntSum(IntList *list) {
    int sum = 0;
    for (size_t i = 0; i < list->size; ++i)
        sum += list->elements[i];
    return sum;
}