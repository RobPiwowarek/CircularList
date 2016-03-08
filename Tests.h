//
// Created by aaron on 06.03.16.
//

#ifndef CYCLELIST_TESTS_H
#define CYCLELIST_TESTS_H

#include "CycleList.h"

class Tests {
public:
    static bool shouldAddAtStart();

    static bool shouldAddAfterVal();

    static bool shouldAddAtTheEndIfNoValFound();

    static bool shouldAddOnIndex();

    static bool shouldRemove();

    static bool shouldRemoveAll();

    static bool shouldRemoveByValueRange();

    static bool shouldRemoveByValue();

    static bool shouldRemoveDuplicates();

    static bool shouldRemoveByIndexRange();

    static bool shouldGet();

    static bool shouldBeEqual();

    static bool shouldBeSmaller();

    static bool shouldBeBigger();

    static void assert(bool val);
};


#endif //CYCLELIST_TESTS_H
