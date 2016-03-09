//
// Created by aaron on 06.03.16.
//

#ifndef CYCLELIST_CYCLELIST_H
#define CYCLELIST_CYCLELIST_H

#include <iostream>

class Node {
public:
    Node *next;
    Node *prev;
    int value;
};

class CycleList {

public:
    Node *first;
    int size;

    CycleList();

    CycleList(const CycleList &list);

    ~CycleList();

    void add(int val); // add at the beginning of the list
    void add(int val1, int val2); // add val1 to list after the first appearance of val2
    void addOnIndex(int val, int index); // add val on given index (returns false if list isn't long enough)

    int remove(int index); // remove element by index, returns removed value
    void remove(int val1, int val2); // remove by value range <val1, val2> or <val2, val1>
    void removeAll(int val); // remove all given values from list
    void removeByValue(int val); // (first appearance)
    void removeDuplicates();

    bool removeByIndexRange(int index1, int index2); // remove values between indexes (index1, index2);

    const int get(int index) const;

    const int length() const;

    bool isEqual(CycleList list); // returns true if equal, false otherwise

    void operator+=(int val); // add(val)
    bool operator==(CycleList list); // compare
    bool operator!=(CycleList list); // compare
    bool operator<=(CycleList list); // length <=
    bool operator<(CycleList list);

    bool operator>=(CycleList list);

    bool operator>(CycleList list);

    int operator-=(int index); // remove by index

    int operator[](int index); // access by index
    CycleList *operator+(CycleList list); // merge()
    CycleList *operator-(CycleList list); // subtract()
    CycleList *operator=(CycleList list); // copy

private:
    void removeAll(); // deletes every node
    CycleList *merge(CycleList list); // merge list with this list
    CycleList *subtract(CycleList list); // subtract one list from this list
};


#endif //CYCLELIST_CYCLELIST_H
