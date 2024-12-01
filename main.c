#include <stdio.h>
#include <malloc.h>
#include "doubly_linked.h"

void show_menu(){
    printf("Program pozwalajacy operowac na listach jednokierunkowych posortowanych\n");
    printf("1. Wyswietlij liste\n");
    printf("2. Wczytaj liste z pliku\n");
    printf("3. Dodaj do listy\n");
    printf("4. Pobierz pierwszy element\n");
    printf("5. Pobierz ostatni element\n");
    printf("6. Wyszukaj element\n");
    printf("7. Usun szukany element\n");
    printf("8. Wyczysc liste\n");
    printf("0. Wyjdz");
}


void sentinel_list(){
    list l = 0;
    add_to_start(&l, INT_MIN);
    add_to_end(&l, INT_MAX);
    add_sort(&l, 4);
    add_sort(&l, 3);
    add_sort(&l, 5);
    add_sort(&l, 6);
    show_list(l);
    delete_found_sort(&l, 4);
    get_first_sort(&l);
    get_last_sort(&l);
    show_list(l);
}


int main() {
    sentinel_list();
    list l = 0;
    add_to_start(&l, 4);
    add_to_start(&l, 5);
    add_to_end(&l, 6);
    add_before_element(&l, 3, 6);
    add_after_element(&l, 10, 5);
    remove_first(&l);
    remove_last(&l);
    remove_found(&l, 3);
    show_list(l);
    show_reversed(l);
    printf("\n%d", find_element(l, 4));
    return 0;
}
