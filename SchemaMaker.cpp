#include "SchemaMaker.h"
#include "ui_SchemaMaker.h"

#include "repository/TypeParentRepository.h"
#include "repository/impl/TypeParentRepositoryImpl.h"

#include "service/TypeParentService.h"
#include "service/impl/TypeParentServiceImpl.h"

SchemaMaker::SchemaMaker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SchemaMaker)
{
    ui->setupUi(this);

    TypeParentRepository* repo = new TypeParentRepositoryImpl();
    TypeParentService *service = new TypeParentServiceImpl(repo);

    try {
        service->save("name1");
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->save(\"name1\"); - " << TypeParentRepositoryImplThrowStr[e];
    }
    try {
        service->save("name2");
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->save(\"name2\"); - " << TypeParentRepositoryImplThrowStr[e];
    }
    try {
        service->save("name1");
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->save(\"name1\"); - " << TypeParentRepositoryImplThrowStr[e];
    }
    try {
        service->save("name2");
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->save(\"name2\"); - " << TypeParentRepositoryImplThrowStr[e];
    }
    try {
        service->save("name3");
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->save(\"name3\"); - " << TypeParentRepositoryImplThrowStr[e];
    }

    QString bigName = "bigName ";
    int i = 0;
    for(i = 0; i < 300; i++)
        bigName += "1";

    try {
        service->save(bigName);
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->save(\"bigName\"); - " << TypeParentRepositoryImplThrowStr[e];
    }

    QList<TypeParentModel>* all = service->getAll();

    i = 0;
    foreach( TypeParentModel tpm, *all ) {
        qDebug() << "TypeParentModel[" + QString::number(i++) + "] = " + tpm.getName() + " with id = " + QString::number(tpm.getId());
    }

    TypeParentModel* r1 = service->getByName("name2");
    qDebug() << "service->getByName(\"name2\").getName() = " << r1->getName();

    try {
        TypeParentModel* r2 = service->getByName("name444");
    } catch(TypeParentRepositoryImplThrow e) {
        qDebug() << "throw in service->getByName(\"name444\"); - " << TypeParentRepositoryImplThrowStr[e];
    }
}

SchemaMaker::~SchemaMaker()
{
    delete ui;
}
