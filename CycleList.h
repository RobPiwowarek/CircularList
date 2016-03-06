//
// Created by aaron on 06.03.16.
//

#ifndef CYCLELIST_CYCLELIST_H
#define CYCLELIST_CYCLELIST_H


class CycleList {

public:
    int value;

    void add(int val); // add at the beginning of the list
    void add(int val1, int val2); // add val1 to list after the first appearance of val2
    bool add(int val, int index); // add val on given index (returns false if list isn't long enough)
    int remove(int index); // remove element by index, returns removed value
    void remove(int val); // remove by value (first appearance)
    void remove(int val1, int val2); // remove by range <val1, val2> or <val2, val1>
    bool remove(int index1, int index2); // remove values between indexes (index1, index2);
    void removeAll(int val); // remove all given values from list
    int get(int index);

    int length();

    void removeDuplicates();

    bool compare(CycleList list); // returns true if equal, false otherwise

    int operator+(int val); // add(val)
    CycleList operator+(CycleList list); // merge()
    CycleList operator-(CycleList list); // subtract()
    void operator-(int val); // remove by index
    int operator[](int index); // access by index
    bool operator==(CycleList list); // compare
    CycleList operator=(CycleList list); // copy

private:
    CycleList merge(CycleList list); // merge list with this list
    CycleList subtract(CycleList list); // subtract one list from this list

};

#endif //CYCLELIST_CYCLELIST_H
