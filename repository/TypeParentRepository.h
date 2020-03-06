#ifndef TYPE_PARENT_REPOSITORY_H
#define TYPE_PARENT_REPOSITORY_H

#include <QList>
#include <QString>
#include "../model/TypeParentModel.h"

class TypeParentRepository {
    public:
        virtual ~TypeParentRepository() = default;

        virtual TypeParentModel* save(QString name) = 0;
        virtual QList<TypeParentModel>* getAll() = 0;
        virtual TypeParentModel* getByName(QString name) = 0;

};
#endif // TYPE_PARENT_REPOSITORY_H
