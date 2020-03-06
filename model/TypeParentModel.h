#ifndef TYPE_PARENT_H
#define TYPE_PARENT_H

#include <QString>

//table
#define TYPE_PARENT_TABLE_NAME "type_parent"

//filds
#define TYPE_PARENT_NAME_COL_NAME "name"
#define TYPE_PARENT_NAME_LEN_MIN 1
#define TYPE_PARENT_NAME_LEN_MAX 200

#define TYPE_PARENT_ID_COL_NAME "id"

#define TYPE_PARENT_GRAND_PARENT_ID_COL_NAME "grand_parent_id"
#define TYPE_PARENT_MAIN_GRAND_PARENT_NAME "Main Grand Parent"

class TypeParentModel {
    public:
        TypeParentModel(QString name, long grandParentId);
        TypeParentModel(long id, QString name, long grandParentId);
        QString getName();
        void setName(QString name);
        long getId();
        void setId(long id);
        long getGrandParentId() const;
        void setGrandParentId(long value);

private:
        long id = -1;
        QString name = nullptr;
        long grandParentId = -1;
};

#endif // TYPE_PARENT_H
