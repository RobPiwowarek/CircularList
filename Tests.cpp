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
    CycleList *temp;
    bool passed = true;
    (*list).add(5);
    (*list).add(6);
    (*list).add(7);
    (*list).add(8, 6);

    temp = list;

    // testing standard case
    while (temp->value != 6) {
        temp = temp->next;
    }

    if (temp->next->value != 8) {
        passed = false;
        printf("shouldAddAfterVal - list.next->value = %d, expected 8\n", temp->next->value);
    }

    // testing edge case (second argument not present in list)
    list->add(2, 10); // if 10 isn't there, should put 2 at the end of list
    if (list->prev->value != 2) {
        printf("shouldAddAfterVal - 2 not at the end of the list\n");
        passed = false;
    }

    if (passed) {
        printf("shouldAddAfterVal - passed\n");
        return true;
    }
    else {
        printf("shouldAddAfterVal - failed\n");
        return false;
    }
}

bool Tests::shouldAddOnIndex() {
    return true;    
}

bool Tests::shouldRemove() {
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

int main(void) {
    CycleList list1, list2;


}
