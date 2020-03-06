#ifndef TYPE_MODEL_H
#define TYPE_MODEL_H

enum Unit {
    UINT8,
    UINT16,
    UINT32,
    UINT64,
};

class TypeModel {
    public:
        TypeModel(Unit unit, int minUnitCount, int maxUnitCount, long typeParentId);
        TypeModel(Unit unit, int minUnitCount, long typeParentId);

        int getMinUnitCount() const;
        void setMinUnitCount(int value);

        int getMaxUnitCount() const;
        void setMaxUnitCount(int value);

        bool getHaveMaxUnitCount() const;
        void setHaveMaxUnitCount(bool value);

        long getId() const;
        void setId(long value);

        Unit getUnit() const;
        void setUnit(const Unit &value);

        long getTypeParentId() const;
        void setTypeParentId(long value);

private:
        Unit unit;
        int minUnitCount = -1;
        int maxUnitCount = -1;
        long typeParentId = -1;
        long id = -1;
        bool haveMaxUnitCount = false;
};

#endif // TYPE_MODEL_H
