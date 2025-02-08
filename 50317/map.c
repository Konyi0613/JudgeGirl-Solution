#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

typedef struct map Map;

int compare_element(const void *a, const void *b) {
    const struct element *c1 = (const struct element *)a;
    const struct element *c2 = (const struct element *)b;
    return strcmp(c1->key, c2->key);
}

static int find_index(Map *m, char key[]) {
    int left = 0;
    int right = m->end - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(key, m->elements[mid].key);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

void insert(Map *m, char key[], int value) {
    int idx = find_index(m, key);
    if (idx != -1) {
        m->elements[idx].value = value;
        return;
    }
    struct element *new_element = &m->elements[m->end];
    strncpy(new_element->key, key, 24);
    new_element->key[24] = '\0';
    new_element->value = value;
    m->end++;
    qsort(m->elements, m->end, sizeof(struct element), compare_element);
}

int delete(Map *m, char key[]) {
    int idx = find_index(m, key);
    if (idx == -1)
        return 0;
    m->elements[idx] = m->elements[m->end - 1];
    m->end--;
    qsort(m->elements, m->end, sizeof(struct element), compare_element);
    return 1;
}

int query(Map *m, char key[]) {
    int idx = find_index(m, key);
    if (idx == -1)
        return -1;
    return m->elements[idx].value;
}