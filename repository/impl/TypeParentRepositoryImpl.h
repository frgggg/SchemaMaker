#ifndef TYPE_PARENT_REPOSITORY_IMPL_H
#define TYPE_PARENT_REPOSITORY_IMPL_H

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QList>
#include <QString>
#include "../TypeParentRepository.h"
#include "../../throw/Throw.h"

class TypeParentRepositoryImpl: public TypeParentRepository {
    public:
        TypeParentRepositoryImpl();
        ~TypeParentRepositoryImpl();

        TypeParentModel* save(QString name);
        QList<TypeParentModel>* getAll();
        TypeParentModel* getByName(QString name);

    private:
        QSqlDatabase *db;
        bool dbState = true;
        static QString initStr;
        static QString saveStr;
        static QString getAllStr;
        static QString getByNameStr;
};
#endif // TYPE_PARENT_REPOSITORY_IMPL_H
