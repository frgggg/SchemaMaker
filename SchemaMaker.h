#ifndef SCHEMAMAKER_H
#define SCHEMAMAKER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SchemaMaker; }
QT_END_NAMESPACE

class SchemaMaker : public QMainWindow
{
    Q_OBJECT

public:
    SchemaMaker(QWidget *parent = nullptr);
    ~SchemaMaker();

private:
    Ui::SchemaMaker *ui;
};
#endif // SCHEMAMAKER_H
