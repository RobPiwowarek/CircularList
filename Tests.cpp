//
// Created by aaron on 06.03.16.
//

#include "Tests.h"

using namespace std;

bool Tests::shouldAddAtStart() {
    CycleList *list = new CycleList();

    list->add(5);

    return list->first->value == 5;

}

bool Tests::shouldAddAfterVal() {
    CycleList *list = new CycleList();
    list->add(5);
    list->add(6);
    list->add(7);
    list->add(8, 6);

    Node *temp = list->first;

    for (int i = 0; i < list->size; i++) {
        if (temp->value == 6) {
            if (temp->next->value != 8) {
                cout << " shouldAddAfterVal - list.next->value = " << temp->next->value << ", expected 8" << endl;
                return false;
            }
        }

        temp = temp->next;
    }

    return true;
}

bool Tests::shouldAddAtTheEndIfNoValFound() {
    CycleList *list = new CycleList();
    list->add(5);
    list->add(6);
    list->add(7);

    list->add(2, 10); // if 10 isn't there, should put 2 at the end of list
    if (list->first->prev->value != 2) {
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

    if (list[2] != 8) {
        cout << " shouldAddOnIndex - expected 8 got " << list[2] << endl;
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

    return !(temp != 7 || list.get(2) == 7);
}

bool Tests::shouldRemoveByValueRange() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(9);
    list.add(10);

    list.remove(6, 9); // nooooooo!

    return list.first->value == 5 && list.first->next->value == 10;
}

bool Tests::shouldRemoveAll() {
    CycleList list;
    Node *temp;
    list.add(5);
    list.add(6);
    list.add(5);
    list.add(9);
    list.add(5);

    list.removeAll(5);

    temp = list.first;

    if (temp->value == 5) return false;

    temp = temp->next;

    while (temp != list.first) {
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

    return !(list.first->value != 6 || list.first->next->value != 5);
}

bool Tests::shouldRemoveDuplicates() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(5);
    list.add(6);
    list.add(5);

    list.removeDuplicates();

    return !(list.first->value != 5 || list.first->next->value != 6 || list.first->next->next != list.first);

}

bool Tests::shouldRemoveByIndexRange() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(9);
    list.add(10);

    list.removeByIndexRange(1, 3);

    return !(list.first->value != 5 || list.first->value != 10);
}

bool Tests::shouldGet() {
    CycleList list;
    list.add(5);
    list.add(6);
    list.add(7);

    return list.get(-2) == 7 && list.get(2) == 7;
}

bool Tests::shouldBeEqual() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(5);
    list2.add(2);
    list2.add(5);

    return !(list1 != list2);

}

bool Tests::shouldBeSmaller() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(3);
    list2.add(5);
    list2.add(6);
    list2.add(7);

    return !(!(list1 < list2) || !(list1 <= list2));

}

bool Tests::shouldBeBigger() {
    CycleList list1, list2;
    list1.add(2);
    list1.add(3);
    list2.add(5);
    list2.add(6);
    list2.add(7);

    return !((list1 < list2) || list1 <= list2);

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
