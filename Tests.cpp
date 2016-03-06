//
// Created by aaron on 06.03.16.
//

#include "Tests.h"
#include "stdio.h"

bool Tests::shouldAddAtStart() {
    CycleList list;

    list.add(5);

    if (list.start->value != 5) {
        printf("shouldAddAtStart - failed");
        return false;
    }

    printf("shouldAddAtStart - passed\n");
    return true;
}

bool Tests::shouldAddAfterVal() {
    CycleList *list = new CycleList();,
    list->add(5);
    list->add(6);
    list->add(7);
    list->add(8, 6);

    while (list->value != 6) {
        list = list->next;
    }

    if (list->next->value != 8){
        printf("shouldAddAfterVal - list.next->value = %d, expected 8\n", list->next->value);
        return false;
    }

    return true;
}

bool Tests::shouldAddAtTheEndIfNoValFound() {
    CycleList *list = new CycleList();
    list->add(5);
    list->add(6);
    list->add(7);

    list->add(2, 10); // if 10 isn't there, should put 2 at the end of list
    if (list->prev->value != 2) {
        printf("shouldAddAfterVal - 2 not at the end of the list\n");
        return false;
    }

    return true;
}

bool Tests::shouldAddOnIndex() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    list.addOnIndex(8, 2);
    while (list.value != 8){
        list = *list.next;
    }

    if (list.index != 2){
        printf("shouldAddOnIndex - index mismatch: expected 2 got %d\n", list.index);
        return false;
    }

    return true;
}

bool Tests::shouldRemove() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    int temp = list.remove(2);

    if (temp != 7 || list.get(2) == 7)
        return false;

    return true;
}

bool Tests::shouldRemoveByValueRange() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    

    return true;
}

bool Tests::shouldRemoveAll() {
    return true;
}

bool Tests::shouldRemoveByValue() {
    return true;
}

bool Tests::shouldRemoveDuplicates() {
    return true;
}

bool Tests::shouldRemoveByIndexRange() {
    return true;
}

bool Tests::shouldGet() {
    return true;
}

bool Tests::shouldCompare() {
    return true;
}

void Tests::assert(bool val) {
    if (val)
        printf(" passed\n");
    else
        printf(" failed\n");
}

int main(void) {
    CycleList list1, list2;


}
