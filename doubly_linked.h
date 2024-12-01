#include "stdio.h"
#include "stdbool.h"
#include <limits.h>


typedef struct doubly_linked{
    int key;
    struct  doubly_linked* next;
    struct  doubly_linked* prev;
} doubly;

typedef doubly* list;

void show_list(list);
void show_reversed(list);
void add_to_start(list*, int);
void add_to_end(list*, int);
void add_before_element(list*, int, int);
void add_after_element(list*, int, int);
void remove_first(list*);
void remove_last(list*);
bool find_element(list, int);
void remove_found(list*, int);
void read_from_a_file(list*);


void add_sort(list*, int);
int get_first_sort(list*);
int get_last_sort(list*);
bool find_element_sort(list, int);
void delete_found_sort(list*, int);


