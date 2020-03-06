#ifndef TYPE_PARENTRE_SERVICE_H
#define TYPE_PARENTRE_SERVICE_H

#include <QList>
#include <QString>
#include "../model/TypeParentModel.h"
#include "../repository/TypeParentRepository.h"

class TypeParentService {
    public:
        virtual ~TypeParentService() = default;

        virtual TypeParentModel* save(QString name) = 0;
        virtual QList<TypeParentModel>* getAll() = 0;
        virtual TypeParentModel* getByName(QString name) = 0;

};
#endif // TYPE_PARENTRE_SERVICE_H
