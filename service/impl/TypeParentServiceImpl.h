#ifndef TYPE_PARENT_SERVICE_IMPL_H
#define TYPE_PARENT_SERVICE_IMPL_H

#include <QList>
#include <QString>
#include "../TypeParentService.h"

class TypeParentServiceImpl: public TypeParentService {
    public:
        TypeParentServiceImpl(TypeParentRepository *repository);
        ~TypeParentServiceImpl();

        TypeParentModel* save(QString name);
        QList<TypeParentModel>* getAll();
        TypeParentModel* getByName(QString name);
        private:
            TypeParentRepository* repository;
};

#endif // TYPE_PARENT_SERVICE_IMPL_H
