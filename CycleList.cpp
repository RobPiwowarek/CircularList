//
// Created by aaron on 06.03.16.
//

#include "CycleList.h"

CycleList::CycleList() {
    this->size = 0;
    this->first = 0; // = NULL
}

CycleList::~CycleList() {
    this->removeAll();
}

CycleList::CycleList(const CycleList &list) {
    this->removeAll();

    this->first = list.first;
    for (int i = 1; i < list.size; i++) {
        this->add(list.get(i));
    }
}

void CycleList::removeAll() {
    Node *temp2;
    temp2 = this->first->next;

    //std::cout << std::endl << "BEFORE REMOVVE: " << this->first << " " << this->first->value << " " << this->first->prev << " " << this->first->next << std::endl;

    for (int i = 0; i < this->size; i++) {
        delete temp2->prev;
        temp2->prev = NULL;
        temp2 = temp2->next;
    }

    this->size = 0;
    delete this->first;
}

void CycleList::add(int val) {
    Node *_new = new Node();
    _new->value = val;

    if (this->size == 0) {
        _new->next = _new;
        _new->prev = _new;
        _new->value = val;
        this->first = _new;
    }
    else {
        Node* temp_prev;
        temp_prev = this->first->prev;

        temp_prev->next = _new;
        _new->prev = temp_prev;
        this->first->prev = _new;
        _new->next = this->first;
    }

    this->size++;
}

// todo: look for a way to change assigning
void CycleList::add(int val1, int val2) {
    Node *temp = this->first;

    for (int i = 0; i < this->size; i++) {
        if (temp->value == val2) {
            Node *_new = new Node();
            Node *temp2 = temp->next;

            _new->value = val1;

            temp->next = _new;
            _new->prev = temp;
            _new->next = temp2;
            temp2->prev = _new;

            this->size++;
            return;
        }
        temp = temp->next;
    }
    add(val1);
}

// todo: like before
void CycleList::addOnIndex(int val, int index) {
    if (index >= this->size) {
        std::cout << "CycleList::addOnIndex: IndexOutOfBoundException" << std::endl;
        exit(600);
    }

    Node *temp = this->first;
    Node *temp2;
    Node *_new = new Node();
    _new->value = val;

    for (int i = 0; i < index - 1; i++) {
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
    Node *temp;
    int temp_val;

    if (index == 0){
        temp = this->first->next;
        temp->prev = this->first->prev;
        this->first->prev->next = temp;
        delete this->first;
        this->first = temp;

    }
    //std::cout << std::endl << index << " " << this->size << std::endl;

    if (index > this->size) {
        std::cout << "int CycleList::remove: IndexOutOfBoundException" << std::endl;
        exit(600);
    }

    temp = this->first;

    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }

    temp_val = temp->value;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    this->size--;

    delete temp;

    return temp_val;
}

void CycleList::remove(int min, int max) {
    if (max < min) return;

    Node *temp;
    temp = this->first;

    for (int i = 0; i <= this->size; i++) {
        if (temp->value >= min && temp->value <= max) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == this->first){
                this->first = temp->next;
            }

            Node *_temp = temp;
            temp = temp->next;

            delete _temp;
            this->size--;
        }
        else
            temp = temp->next;
    }
}

void CycleList::removeAll(int val) {
    Node *temp = this->first;

    for (int i = 0; i <= this->size; i++) {
        if (temp->value == val) {

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == this->first){
                this->first = temp->next;
            }

            Node *newTemp = temp->prev;
            this->size--;


            if (temp == this->first){
                this->first = temp->next;
            }

            delete temp;
            temp = newTemp;
            i--;
        }
        else
            temp = temp->next;

    }
}

void CycleList::removeByValue(int val) {
    Node *temp = this->first;

    for (int i = 0; i < this->size; i++) {
        if (temp->value == val) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == this->first){
                this->first = temp->next;
            }
            Node *temp2 = temp;
            temp = temp->next;
            delete temp2;

            this->size--;
            return;
        }
        else
            temp = temp->next;
    }
}

void CycleList::removeDuplicates() {
    Node *temp = this->first;

    for (int i = 0; i < this->size; i++) {
        Node *temp2 = temp->next;
        for (int j = i + 1; j <= this->size; j++) {
            if (temp2->value == temp->value) {
                temp2->prev->next = temp2->next;
                temp2->next->prev = temp2->prev;

                if (temp2 == this->first){
                    this->first = temp2->next;
                }

                Node *_temp = temp2;
                temp2 = temp2->next;

                delete _temp;
                this->size--;
            }
            else
                temp2 = temp2->next;
        }

        temp = temp->next;
    }

}


// returns false if arguments don't make sense
bool CycleList::removeByIndexRange(int index1, int index2) {
    if (index1 > index2 || (index2 >= this->size || index1 >= this->size))
        return false;

    if (index1 == index2) {
        remove(index1);
        return true;
    }

    Node *temp = this->first;
    Node *temp_first;
    Node *temp_second;

    // find first and second nodes corresponding to indexes
    for (int i = 0; i <= index2; i++) {
        if (i == index1)
            temp_first = temp;

        if (i == index2) {
            temp_second = temp;
            break;
        }

        temp = temp->next;
    }

    // remove from list reattach first pointer
    if (temp_first == this->first){
        this->first = temp_second->next;
    }

    temp_first->prev->next = temp_second->next;
    temp_second->next->prev = temp_first->prev;

    // delete
    temp = temp_first->next;
    while (temp != temp_second->next) {
        delete temp->prev;
        temp = temp->next;
        this->size--;
    }

    return true;
}

const int CycleList::get(int index) const {
    if (index > this->size) {
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

bool CycleList::isEqual(CycleList& list) {
    if (this->size == list.size) {
        Node *temp1 = this->first;
        Node *temp2 = list.first;

        for (int i = 0; i < this->size; i++) {
            if (temp1->value != temp2->value) return false;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    else return false;

    return true;
}

void CycleList::operator+=(int val) {
    this->add(val);
}

int CycleList::operator[](int index) {
    return (this->get(index));
}

bool CycleList::operator==(CycleList &list) {
    return this->isEqual(list);
}

bool CycleList::operator!=(CycleList &list) {
    return !this->isEqual(list);
}

bool CycleList::operator<=(CycleList& list) {
    return (this->size <= list.size) || isEqual(list);
}

bool CycleList::operator<(CycleList& list) {
    return (this->size < list.size);
}

bool CycleList::operator>=(CycleList& list) {
    return (this->size >= list.size) || isEqual(list);
}

bool CycleList::operator>(CycleList& list) {
    return (this->size > list.size);
}

int CycleList::operator-=(int index) {
    return this->remove(index);
}

CycleList *CycleList::operator+(CycleList* list) {
    return merge(list);
}

CycleList *CycleList::operator-(CycleList* list) {
    return subtract(list);
}

CycleList *CycleList::operator=(CycleList* list) {
    if (this == list)
        return this;

    this->removeAll();

    Node *temp = list->first;

    for (int i = 0; i < list->size; i++) {
        this->add(temp->value);
        temp = temp->next;
    }

    return this;
}

CycleList *CycleList::merge(CycleList* list) {
    Node *temp = list->first;

    for (int i = 0; i < list->size; i++) {
        this->add(temp->value);
        temp = temp->next;
    }

    return this;
}

CycleList *CycleList::subtract(CycleList* list) {
    Node *temp = list->first;

    for (int i = 0; i < list->size; i++) {
        this->removeByValue(temp->value);
        temp = temp->next;
    }

    return this;
}
