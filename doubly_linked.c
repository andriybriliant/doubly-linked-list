#include <malloc.h>
#include "doubly_linked.h"

void show_list(list l){
    list p = l;
    printf("[ ");
    while(p){
        printf("%d ", p->key);
        p = p->next;
    }
    printf("]");
}


void show_reversed(list l){
    list p = l;
    printf("[ ");
    if(p){
        while(p->next){
            p = p->next;
        }
        while(p){
            printf("%d ", p->key);
            p = p->prev;
        }
    }
    printf("]");
}


void add_to_start(list* l, int key){
    list p = malloc(sizeof(doubly));
    p->key = key;
    p->next = *l;
    p->prev = 0;
    if((*l)) {
        p->prev = (*l)->prev;
        (*l)->prev = p;
    }
    *l = p;
}


void add_to_end(list* l, int key){
    list p = malloc(sizeof(doubly));
    p->key = key;
    p->next = 0;
    if(*l == NULL){
        p->prev = 0;
        *l = p;
        return;
    }
    while((*l)->next){
        l = &(*l)->next;
    }
    p->prev = *l;
    (*l)->next = p;
}


void add_before_element(list* l, int key, int target){
    list p = malloc(sizeof(doubly));
    p->key = key;
    p->next = 0;
    p->prev = 0;
    while((*l)){
        if((*l)->key == target){
            p->prev = (*l)->prev;
            p->next = *l;
            (*l)->prev = p;
            if(p->prev){
                p->prev->next = p;
            }
            else{
                *l = p;
            }
            return;
        }
        else{
            l = &(*l)->next;
        }
    }
}


void add_after_element(list* l, int key, int target){
    list p = malloc(sizeof(doubly));
    p->key = key;
    p->prev = 0;
    p->next = 0;
    while((*l)){
        if((*l)->key == target){
            p->prev = *l;
            p->next = (*l)->next;
            (*l)->next = p;
            if(p->next){
                p->next->prev = p;
            }
            return;
        }else{
            l = &(*l)->next;
        }
    }
}


void remove_first(list* l){
    list p = (*l);
    *l = (*l)->next;
    if(*l) {
        (*l)->prev = 0;
    }
    free(p);
}


void remove_last(list* l){
    if(*l == NULL){
        return;
    }
    while((*l)->next){
        l = &(*l)->next;
    }
    free(*l);
    *l = 0;
}


bool find_element(list l, int key){
    list p = l;
    while(p){
        if(p->key == key){
            return true;
        }
        p = p->next;
    }
    return false;
}


void remove_found(list* l, int key){
    list p = malloc(sizeof(doubly));
    while((*l)){
        if((*l)->key == key){
            if((*l)->prev == 0){
                remove_first(l);
                return;
            }
            if((*l)->next == 0){
                remove_last(l);
                return;
            }
            p = (*l)->prev;
            (*l)->next->prev = (*l)->prev;
            p->next = (*l)->next;

            free(*l);
            return;
        }
        l = &(*l)->next;
    }
}


//Lista posortowana
void add_sort(list* l, int key){
    while((*l)->key < key){
        l = &(*l)->next;
    }
    add_to_start(&(*l), key);
}


int get_first_sort(list* l){
    int value;
    l = &(*l)->next;
    list p;
    if((*l)->key != INT_MAX){
        value = (*l)->key;
        p = *l;
        (*l)->next->prev = (*l)->prev;
        (*l)->prev->next = (*l)->next;
        free(p);
        return value;
    }
    return 0;
}

int get_last_sort(list* l){
    int value;
    list p;
    while((*l)->key != INT_MAX){
        l = &(*l)->next;
    }
    if((*l)->prev->key != INT_MIN){
        l = &(*l)->prev;
        value = (*l)->key;
        p = *l;
        (*l)->next->prev = (*l)->prev;
        p->prev->next = (p)->next;
        free(p);
        return value;
    }
    return 0;
}


bool find_element_sort(list l, int key){
    while(l->key < key){
        if(l->key == key){
            return true;
        }
        l = l->next;
    }
    return false;
}


void delete_found_sort(list* l, int key){
    list p;
    while((*l)->key <= key){
        if((*l)->key == key){
            p = *l;
            (*l)->next->prev = (*l)->prev;
            (*l)->prev->next = (*l)->next;
            free(p);
            return;
        }
        l = &(*l)->next;
    }
}


