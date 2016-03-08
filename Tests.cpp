//
// Created by aaron on 06.03.16.
//

#include "Tests.h"
#include <iostream>
using namespace std;

bool Tests::shouldAddAtStart() {
    CycleList list;

    list.add(5);

    if (list[0]->value != 5) return false;

    return true;
}

bool Tests::shouldAddAfterVal() {
    CycleList *list = new CycleList();
    list->add(5);
    list->add(6);
    list->add(7);
    list->add(8, 6);

    while (list->value != 6) {
        list = list->next;
    }

    if (list->next->value != 8) {
        cout << " shouldAddAfterVal - list.next->value = " << list->next->value << ", expected 8" << endl;
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
        cout << " shouldAddAfterVal - 2 not at the end of the list" << endl;
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
    while (list.value != 8) {
        list = *list.next;
    }

    if (list.index != 2) {
        cout << " shouldAddOnIndex - index mismatch: expected 2 got " << list.index << endl;
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
    list.add(9);
    list.add(10);

    list.remove(6, 9); // nooooooo!

    if (list.value == 5 && list.next->value == 10)
        return true;

    return false;
}

bool Tests::shouldRemoveAll() {
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

bool Tests::shouldRemoveByValue() {
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

bool Tests::shouldRemoveDuplicates() {
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

bool Tests::shouldRemoveByIndexRange() {
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

bool Tests::shouldGet() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    if (list.get(-2) == 7 && list.get(2) == 7) return true;

    return false;
}

bool Tests::shouldBeEqual() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(5);
    list2.add(2);
    list2.add(5);

    if (list1 != list2) return false;

    return true;
}

bool Tests::shouldBeSmaller() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(3);
    list2.add(5);
    list2.add(6);
    list2.add(7);

    if (!(list1 < list2) || !(list1 <= list2)) return false;

    return true;
}

bool Tests::shouldBeBigger() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(3);
    list2.add(5);
    list2.add(6);
    list2.add(7);

    if ((list1 < list2) || list1 <= list2) return false;

    return true;
}

void Tests::assert(bool val) {

    if (val)
        cout << " passed" << endl;
    else
        cout << " failed" << endl;
}

int main(void) {
    cout << ">>>>>>>>>TESTING START<<<<<<<<<<<" << endl;
    cout << "shouldAddAtStart -";
    Tests::assert(Tests::shouldAddAtStart());
    cout << "shouldAddAfterVal -";
    Tests::assert(Tests::shouldAddAfterVal());
    cout << "shouldAddAtTheEndIfNoValFound -";
    Tests::assert(Tests::shouldAddAtTheEndIfNoValFound());
    cout << "shouldAddOnIndex -";
    Tests::assert(Tests::shouldAddOnIndex());
    cout << "shouldRemove -";
    Tests::assert(Tests::shouldRemove());
    cout << "shouldRemoveAll -";
    Tests::assert(Tests::shouldRemoveAll());
    cout << "shouldRemoveByValueRange -";
    Tests::assert(Tests::shouldRemoveByValueRange());
    cout << "shouldRemoveByValue -";
    Tests::assert(Tests::shouldRemoveByValue());
    cout << "shouldRemoveDuplicates -";
    Tests::assert(Tests::shouldRemoveDuplicates());
    cout << "shouldRemoveByIndexRange -";
    Tests::assert(Tests::shouldRemoveByIndexRange());
    cout << "shouldGet -";
    Tests::assert(Tests::shouldGet());
    cout << "shouldBeEqual -";
    Tests::assert(Tests::shouldBeEqual());
    cout << "shouldBeSmaller -";
    Tests::assert(Tests::shouldBeSmaller());
    cout << "shouldBeBigger -";
    Tests::assert(Tests::shouldBeBigger());
}
