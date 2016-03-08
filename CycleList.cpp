//
// Created by aaron on 06.03.16.
//

#include "CycleList.h"

CycleList::CycleList() {
    this->size = 0;
    this->first = 0; // = NULL
}

CycleList::~CycleList() {
    Node *temp, *temp2;
    temp = temp2 = this->first->next;

    while (temp != this->first) {
        temp = temp2->next;
        delete temp2;
    }

    delete this->first;
}

CycleList::CycleList(const CycleList &list) {
    delete this;

    //todo: remove this = new and manually alloc stuff.
    this = new CycleList();
    this->first = list.first;
    for (int i = 1; i < list.size; i++) {
        this->add(list.get(i));
    }
}

void CycleList::add(int val) {
    Node *_new = new Node();
    this->size++;

    this->first->prev->next = _new;
    _new->prev = this->first->prev;
    this->first->prev = _new;
    _new->next = this->first;

    _new->value = val;
}

void CycleList::add(int val1, int val2) {
    Node *temp = this->first;

    for (int i = 0; i < this->size; i++){
        if (temp->value == val2){
            Node *_new = new Node();
            Node *temp2 = temp->next;

            _new->value = val1;

            temp->next = _new;
            _new->prev = temp;
            _new->next = temp2;
            temp2->prev = _new;

            this->size++;
        }
        temp = temp->next;
    }
    add(val1);
}


void CycleList::addOnIndex(int val, int index) {
    if (index >= this->size){
        std::cout << "CycleList::addOnIndex: IndexOutOfBoundException" << std::endl;
        exit(600);
    }

    Node *temp = this->first;
    Node *temp2 = new Node();
    Node *_new = new Node();
    _new->value = val;

    for (int i = 0; i < index; i++){
        temp = temp->next;
    }

    temp2 = temp->next;

    temp->next = _new;
    _new->next = temp2;
    _new->prev = temp;
    temp2->prev = _new;

    this->size++;
}

int CycleList::remove(int index) {
    return 0;
}

void CycleList::remove(int val1, int val2) {

}

void CycleList::removeAll(int val) {

}

void CycleList::removeByValue(int val) {

}

void CycleList::removeDuplicates() {

}

bool CycleList::removeByIndexRange(int index1, int index2) {
    return false;
}

const int CycleList::get(int index) const {
    if (index >= this->size) {
        std::cout << "CycleList::get: IndexOutOfBoundException" << std::endl;
        exit(600);
    }

    Node *temp = this->first;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    return temp->value;
}

const int CycleList::length() const {
    return this->size;
}

bool CycleList::compare(CycleList list) {
    return false;
}

int CycleList::operator+(int val) {
    return 0;
}

int CycleList::operator[](int index) {
    return 0;
}

bool CycleList::operator==(CycleList list) {
    return false;
}

bool CycleList::operator!=(CycleList list) {
    return false;
}

bool CycleList::operator<=(CycleList list) {
    return false;
}

bool CycleList::operator<(CycleList list) {
    return false;
}

bool CycleList::operator>=(CycleList list) {
    return false;
}

bool CycleList::operator>(CycleList list) {
    return false;
}

void CycleList::operator-(int val) {

}

CycleList CycleList::operator+(CycleList list) {
    return CycleList();
}

CycleList CycleList::operator-(CycleList list) {
    return CycleList();
}

CycleList CycleList::operator=(CycleList list) {
    return CycleList();
}

CycleList CycleList::merge(CycleList list) {
    return CycleList();
}

CycleList CycleList::subtract(CycleList list) {
    return CycleList();
}
