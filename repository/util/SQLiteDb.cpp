#include "SQLiteDb.h"

bool SQLiteDb::openFlag = false;
bool SQLiteDb::setNameFlag = false;
QSqlDatabase SQLiteDb::db = QSqlDatabase::addDatabase(SQLITE_DB_TYPE);

QSqlDatabase* SQLiteDb::getSQLiteDb(){
    if(!setNameFlag) {
        setNameFlag = true;
        db = QSqlDatabase::addDatabase(SQLITE_DB_TYPE);
        db.setDatabaseName(SQLITE_DB_NAME);
    }

    if(!openFlag) {
       if(db.open()) {
           openFlag = true;
       } else {
           qDebug() << "db->open() fail";
       }
   }

   if(openFlag) {
       return &db;
   }

   return nullptr;
}
