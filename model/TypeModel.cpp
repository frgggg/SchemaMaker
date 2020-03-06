#include "TypeModel.h"

TypeModel::TypeModel(Unit unit, int minUnitCount, int maxUnitCount, long typeParentId):
    unit(unit),
    minUnitCount(minUnitCount),
    maxUnitCount(maxUnitCount),
    typeParentId(typeParentId),
    haveMaxUnitCount(true) {

}
TypeModel::TypeModel(Unit unit, int minUnitCount, long typeParentId):
    unit(unit),
    minUnitCount(minUnitCount),
    typeParentId(typeParentId) {

}

int TypeModel::getMinUnitCount() const
{
    return minUnitCount;
}

void TypeModel::setMinUnitCount(int value)
{
    minUnitCount = value;
}

int TypeModel::getMaxUnitCount() const
{
    return maxUnitCount;
}

void TypeModel::setMaxUnitCount(int value)
{
    maxUnitCount = value;
}

bool TypeModel::getHaveMaxUnitCount() const
{
    return haveMaxUnitCount;
}

void TypeModel::setHaveMaxUnitCount(bool value)
{
    haveMaxUnitCount = value;
}

long TypeModel::getId() const
{
    return id;
}

void TypeModel::setId(long value)
{
    id = value;
}

Unit TypeModel::getUnit() const
{
    return unit;
}

void TypeModel::setUnit(const Unit &value)
{
    unit = value;
}

long TypeModel::getTypeParentId() const
{
    return typeParentId;
}

void TypeModel::setTypeParentId(long value)
{
    typeParentId = value;
}
