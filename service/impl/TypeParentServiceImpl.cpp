#include "TypeParentServiceImpl.h"

TypeParentServiceImpl::TypeParentServiceImpl(TypeParentRepository *repository) {
    this->repository = repository;
}

TypeParentServiceImpl::~TypeParentServiceImpl() {

}

TypeParentModel* TypeParentServiceImpl::save(QString name) {
    return this->repository->save(name);
}

QList<TypeParentModel>* TypeParentServiceImpl::getAll() {
    return this->repository->getAll();
}

TypeParentModel* TypeParentServiceImpl::getByName(QString name) {
    return this->repository->getByName(name);
}
