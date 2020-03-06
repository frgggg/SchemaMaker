#include "TypeParentRepositoryImpl.h"
#include "../util/SQLiteDb.h"

QString TypeParentRepositoryImpl::initStr =  QString("CREATE TABLE IF NOT EXISTS ") + TYPE_PARENT_TABLE_NAME + "(" +
                                                "   " + TYPE_PARENT_ID_COL_NAME + " INTEGER PRIMARY KEY AUTOINCREMENT," +
                                                "   " + TYPE_PARENT_NAME_COL_NAME + " VARCHAR( " + QString::number(TYPE_PARENT_NAME_LEN_MAX) + " ) NOT NULL," +
                                                "   CONSTRAINT type_parent_nameconstraint unique (name)" +
                                                ")";
QString TypeParentRepositoryImpl::saveStr = "INSERT INTO type_parent (name) VALUES (?)";

QString TypeParentRepositoryImpl::getAllStr = "SELECT * FROM type_parent";
QString TypeParentRepositoryImpl::getByNameStr = "SELECT * FROM type_parent WHERE name=?";

TypeParentRepositoryImpl::TypeParentRepositoryImpl() {
    this->db = SQLiteDb::getSQLiteDb();
    if(db) {
        QSqlQuery query(*this->db);
        if( !query.exec(initStr) ) {
            this->dbState = false;
            throw TypeParentRepositoryImplThrow::WRONG_INIT;
        }

    } else {
        this->dbState = false;
        throw TypeParentRepositoryImplThrow::NO_BD;
    }

}

TypeParentRepositoryImpl::~TypeParentRepositoryImpl() {

}

TypeParentModel* TypeParentRepositoryImpl::save(QString name) {
    if(!this->dbState) {
        throw TypeParentRepositoryImplThrow::NO_BD;
    }

    if(name == nullptr) {
        throw TypeParentRepositoryImplThrow::WRONG_NAME;
    } else if((name.size() < TYPE_PARENT_NAME_LEN_MIN) || (name.size() > TYPE_PARENT_NAME_LEN_MAX)) {
        throw TypeParentRepositoryImplThrow::WRONG_NAME;
    }

    try {
        TypeParentModel* tryTypeParent = this->getByName(name);
        if(tryTypeParent != nullptr) {
            tryTypeParent->~TypeParentModel();
            throw TypeParentRepositoryImplThrow::EXIST_NAME;
        }
    } catch(TypeParentRepositoryImplThrow e) {
        if(e != TypeParentRepositoryImplThrow::NOT_EXIST_NAME){
            throw e;
        }
    }


    QSqlQuery query(*this->db);
    query.prepare(saveStr);
    query.addBindValue(name);
    if(!query.exec()) {
        throw TypeParentRepositoryImplThrow::WRONG_QUERY_SAVE;
    }

    return this->getByName(name);
}

QList<TypeParentModel>* TypeParentRepositoryImpl::getAll() {
    if(!this->dbState) {
        throw TypeParentRepositoryImplThrow::NO_BD;
    }

    QList<TypeParentModel>* all = new QList<TypeParentModel>();
    QSqlQuery query(*this->db);
    query.prepare(getAllStr);
    if(!query.exec()) {
        throw TypeParentRepositoryImplThrow::WRONG_QUERY_GET_ALL;
    }

    while(query.next()) {
        QSqlRecord rec = query.record();
        const int nameIndex = rec.indexOf(TYPE_PARENT_NAME_COL_NAME);
        const int idIndex = rec.indexOf(TYPE_PARENT_ID_COL_NAME);

        all->append(
                    TypeParentModel(query.value(idIndex).toInt(), query.value(nameIndex).toString())
                    );
    }

    return all;
}

TypeParentModel* TypeParentRepositoryImpl::getByName(QString name) {
    if(!this->dbState) {
        throw TypeParentRepositoryImplThrow::NO_BD;
    }


    QSqlQuery query(*(this->db));
    query.prepare(getByNameStr);
    query.addBindValue(name);
    if(!query.exec()) {
        throw TypeParentRepositoryImplThrow::WRONG_QUERY_GET_BY_NAME;
    }

    if(!query.next()) {
        throw TypeParentRepositoryImplThrow::NOT_EXIST_NAME;
    }

    QSqlRecord rec = query.record();
    const int nameIndex = rec.indexOf(TYPE_PARENT_NAME_COL_NAME);
    const int idIndex = rec.indexOf(TYPE_PARENT_ID_COL_NAME);
    return new TypeParentModel(query.value(idIndex).toInt(), query.value(nameIndex).toString());

}
