//
// Created by aaron on 06.03.16.
//

#ifndef CYCLELIST_TESTS_H
#define CYCLELIST_TESTS_H

#include "CycleList.h"

class Tests {
public:
    bool shouldAddAtStart(CycleList);
    bool shouldAddAfterVal(CycleList);
    bool shouldAddOnIndex(CycleList);
    bool shouldRemove(CycleList);
    bool shouldRemoveAll(CycleList);
    bool shouldRemoveByValue(CycleList);
    bool shouldRemoveDuplicates(CycleList);
    bool shouldRemoveByIndexRange(CycleList);
    bool shouldGet(CycleList);
    bool shouldCompare();
};


#endif //CYCLELIST_TESTS_H
