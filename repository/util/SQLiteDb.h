#ifndef SQLITE_DB_H
#define SQLITE_DB_H

#include <QDebug>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>

#include <QList>
#include <QString>

class SQLiteDb {

    #define SQLITE_DB_TYPE "QSQLITE"
    #define SQLITE_DB_NAME "/local/progects/qt/qt_progects/SchemaMaker/SchemaMaker/schema_maker.db3"

    private:
        static QSqlDatabase db;
        static bool openFlag;
        static bool setNameFlag;

    public:
        static QSqlDatabase* getSQLiteDb();
};

#endif
