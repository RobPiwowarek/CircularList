//
// Created by aaron on 06.03.16.
//

#include "Tests.h"
#include "stdio.h"

static bool Tests::shouldAddAtStart() {
    CycleList list;

    list.add(5);

    if (list.start->value != 5) return false;

    return true;
}

static bool Tests::shouldAddAfterVal() {
    CycleList *list = new CycleList();,
    list->add(5);
    list->add(6);
    list->add(7);
    list->add(8, 6);

    while (list->value != 6) {
        list = list->next;
    }

    if (list->next->value != 8) {
        printf(" shouldAddAfterVal - list.next->value = %d, expected 8\n", list->next->value);
        return false;
    }

    return true;
}

static bool Tests::shouldAddAtTheEndIfNoValFound() {
    CycleList *list = new CycleList();
    list->add(5);
    list->add(6);
    list->add(7);

    list->add(2, 10); // if 10 isn't there, should put 2 at the end of list
    if (list->prev->value != 2) {
        printf(" shouldAddAfterVal - 2 not at the end of the list\n");
        return false;
    }

    return true;
}

static bool Tests::shouldAddOnIndex() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    list.addOnIndex(8, 2);
    while (list.value != 8) {
        list = *list.next;
    }

    if (list.index != 2) {
        printf(" shouldAddOnIndex - index mismatch: expected 2 got %d\n", list.index);
        return false;
    }

    return true;
}

static bool Tests::shouldRemove() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    int temp = list.remove(2);

    if (temp != 7 || list.get(2) == 7)
        return false;

    return true;
}

static bool Tests::shouldRemoveByValueRange() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(9);
    list.add(10);

    list.remove(6, 9); // nooooooo!

    if (list.value == 5 && list.next->value == 10)
        return true;

    return false;
}

static bool Tests::shouldRemoveAll() {
    CycleList list, *temp;
    list.add(5);
    list.add(6);
    list.add(5);
    list.add(9);
    list.add(5);

    list.removeAll(5);

    temp = list.next;
    while (temp != &list) {
        if (temp->value == 5)
            return false;

        temp = temp->next;
    }

    return true;
}

static bool Tests::shouldRemoveByValue() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(5);
    list.add(9);
    list.add(5);

    list.removeByValue(5);

    if (list.value != 6 || list.next->value != 5)
        return false;

    return true;
}

static bool Tests::shouldRemoveDuplicates() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(5);
    list.add(6);
    list.add(5);

    list.removeDuplicates();

    if (list.value != 5 || list.next->value != 6 || list.next->next != &list) return false;

    return true;
}

static bool Tests::shouldRemoveByIndexRange() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(9);
    list.add(10);

    list.removeByIndexRange(1, 3);

    if (list.value != 5 || list.next->value != 10)
        return false;

    return true;
}

static bool Tests::shouldGet() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    if (list.get(-2) == 7 && list.get(2) == 7) return true;

    return false;
}

static bool Tests::shouldBeEqual() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(5);
    list2.add(2);
    list2.add(5);

    if (list1 != list2) return false;

    return true;
}

static bool Tests::shouldBeSmaller() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(3);
    list2.add(5);
    list2.add(6);
    list2.add(7);

    if (!(list1 < list2) || !(list1 <= list2)) return false;

    return true;
}

static bool Tests::shouldBeBigger() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(3);
    list2.add(5);
    list2.add(6);
    list2.add(7);

    if ((list1 < list2) || list1 <= list2) return false;

    return true;
}

static void Tests::assert(bool val) {
    if (val)
        printf(" passed\n");
    else
        printf(" failed\n");
}

int main(void) {
    printf(">>>>>>>>>TESTING START<<<<<<<<<<<\n");
    printf("shouldAddAtStart -");
    Tests::assert(Tests::shouldAddAtStart());
    printf("shouldAddAfterVal -");
    Tests::assert(Tests::shouldAddAfterVal());
    printf("shouldAddAtTheEndIfNoValFound -");
    Tests::assert(Tests::shouldAddAtTheEndIfNoValFound());
    printf("shouldAddOnIndex -");
    Tests::assert(Tests::shouldAddOnIndex());
    printf("shouldRemove -");
    Tests::assert(Tests::shouldRemove());
    printf("shouldRemoveAll -");
    Tests::assert(Tests::shouldRemoveAll());
    printf("shouldRemoveByValueRange -");
    Tests::assert(Tests::shouldRemoveByValueRange());
    printf("shouldRemoveByValue -");
    Tests::assert(Tests::shouldRemoveByValue());
    printf("shouldRemoveDuplicates -");
    Tests::assert(Tests::shouldRemoveDuplicates());
    printf("shouldRemoveByIndexRange -");
    Tests::assert(Tests::shouldRemoveByIndexRange());
    printf("shouldGet -");
    Tests::assert(Tests::shouldGet());
    printf("shouldBeEqual -");
    Tests::assert(Tests::shouldBeEqual());
    printf("shouldBeSmaller -");
    Tests::assert(Tests::shouldBeSmaller());
    printf("shouldBeBigger -");
    Tests::assert(Tests::shouldBeBigger());
}
