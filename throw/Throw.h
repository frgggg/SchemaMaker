#ifndef THROW_H
#define THROW_H

#include <QString>

enum TypeParentRepositoryImplThrow {
    NO_BD,
    WRONG_INIT,
    WRONG_QUERY_GET_ALL,
    WRONG_QUERY_GET_BY_NAME,
    WRONG_QUERY_SAVE,
    WRONG_NAME,
    EXIST_NAME,
    NOT_EXIST_NAME,
};

static QString TypeParentRepositoryImplThrowStr[] = {
    "NO_BD",
    "WRONG_INIT",
    "WRONG_QUERY_GET_ALL",
    "WRONG_QUERY_GET_BY_NAME",
    "WRONG_QUERY_SAVE",
    "WRONG_NAME",
    "EXIST_NAME",
    "NOT_EXIST_NAME"
};



#endif
