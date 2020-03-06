#include "TypeParentModel.h"

TypeParentModel::TypeParentModel(QString name, long grandParentId):
    name(name),
    grandParentId(grandParentId) {

}

TypeParentModel::TypeParentModel(long id, QString name, long grandParentId):
    id(id),
    name(name),
    grandParentId(grandParentId) {

}

QString TypeParentModel::getName() {
    return this->name;
}

void TypeParentModel::setName(QString name) {
    this->name = name;
}

long TypeParentModel::getId() {
    return this->id;
}

void TypeParentModel::setId(long id) {
    this->id = id;
}

long TypeParentModel::getGrandParentId() const
{
    return grandParentId;
}

void TypeParentModel::setGrandParentId(long value)
{
    grandParentId = value;
}
