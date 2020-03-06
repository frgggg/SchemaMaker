#include "SchemaMaker.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SchemaMaker w;
    w.show();
    return a.exec();
}
