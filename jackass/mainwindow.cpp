#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd("as.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Background, bkgnd);
       this->setPalette(palette);

 //   QPixmap pix("e.jpg");
  //  ui->label_pic->setPixmap(pix);

    mydb=QSqlDatabase::addDatabase("QSQLITE");
   // mydb.setDatabaseName("E:/ger.db");
   mydb.setDatabaseName("ger.db");
    if(!mydb.open())
        ui->label->setText("Failed to open");
    else
        ui->label->setText("Connected");
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pushButton_clicked()
{
    QString username,password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_Password->text();

    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open Database";
        return;
    }
    QSqlQuery qry;
    if(qry.exec("select * from alldo where ENGLISH='"+username+"'and GERMAN='"+password+"'"))
    { int count=0;
        while(qry.next())
        {count++;}
        if(count==1)
           { ui->label->setText("U ARE ENTER");
        this->hide();
        chillmar chill;
        chill.setModal(true);
        chill.exec();
        }
        else
        {
        if(count==2)
            ui->label->setText("U ARE ENTER 2");
        else
        {ui->label->setText("U ARE NOT  ENTER");}

}}


}



*/
void MainWindow::on_pushButton_2_clicked()
{  QString password;
    username=ui->lineEdit_username->text();
   // password=ui->lineEdit_Password->text();
 /*   QSqlQueryModel * modal=new QSqlQueryModel();
    if(!mydb.isOpen())
    {
        qDebug()<<"Failed to open Database";
        return;
    }
     QSqlQuery * qry=new QSqlQuery();
    //QSqlQuery qry;

    qry->prepare("select GERMAN from alldo where ENGLISH='"+username+"'");
    qry->exec();
            modal->setQuery(*qry);
    ui->tableView->setModel(modal);*/

   QSqlQuery qwe;
   qwe.prepare("select * from alldo where ENGLISH='"+username+"'");
   qwe.exec();
   qwe.next();
   ui->lab2->setText(qwe.value(1).toString());

}

void MainWindow::on_pushButton_clicked()
{

    QString filename = "Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream stream(&file);
        stream <<username << endl;
        }
    chillmar chill;
    chill.setModal(true);
    chill.exec();
}

void MainWindow::on_pushButton_3_clicked()
{





}

