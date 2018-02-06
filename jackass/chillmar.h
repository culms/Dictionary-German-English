#ifndef CHILLMAR_H
#define CHILLMAR_H
#include "mainwindow.h"
#include <QtSql>
#include <QDialog>
#include <QMainWindow>
#include<QFile>;
#include<QTextStream>
namespace Ui {
class chillmar;
}

class chillmar : public QDialog
{
    Q_OBJECT

public:
    explicit chillmar(QWidget *parent = 0);
    //QString username;
    ~chillmar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::chillmar *ui;
};

#endif // CHILLMAR_H
