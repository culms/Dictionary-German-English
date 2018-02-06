#include "chillmar.h"
#include "ui_chillmar.h"
#include "mainwindow.h"

chillmar::chillmar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chillmar)
{
    ui->setupUi(this);
}

chillmar::~chillmar()
{
    delete ui;
}

void chillmar::on_pushButton_clicked()
{  QString username;
    QFile inputFile("Data.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          username = in.readLine();

       }
       inputFile.close();
    }

  //  username="dfdf";
    ui->lineEdit->setText( username);
   QSqlQuery qwe;
   qwe.prepare("select * from jabro where ENGLISH='"+username+"'");
    qwe.exec();
    qwe.next();
   ui->textEdit->setText(qwe.value(2).toString());
}
