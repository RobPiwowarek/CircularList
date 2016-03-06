//
// Created by aaron on 06.03.16.
//

#ifndef CYCLELIST_TESTS_H
#define CYCLELIST_TESTS_H

#include "CycleList.h"

class Tests {
public:
    bool shouldAddAtStart();

    bool shouldAddAfterVal();

    bool shouldAddOnIndex();

    bool shouldRemove();

    bool shouldRemoveAll();

    bool shouldRemoveByValue();

    bool shouldRemoveDuplicates();

    bool shouldRemoveByIndexRange();

    bool shouldGet();

    bool shouldCompare();
};


#endif //CYCLELIST_TESTS_H
