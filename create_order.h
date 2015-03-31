
#ifndef CREATE_ORDER_H
#define CREATE_ORDER_H

#include <QDialog>
#include <QtNetwork>
#include <QMessageAuthenticationCode>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "mainwindow.h"


namespace Ui {
class Create_Order;
}

class Create_Order : public QDialog
{
    Q_OBJECT

public:

    explicit Create_Order(QWidget *parent = 0);
     QJsonObject jsonObj2;
    ~Create_Order();
     QSqlDatabase mydb;
     void connClose()
     {
         mydb.close();
         mydb.removeDatabase(QSqlDatabase::defaultConnection);
     }

     bool connOpen()
     {
         mydb = QSqlDatabase::addDatabase("QSQLITE");
         mydb.setDatabaseName("PAYTERM.db");
         if (!mydb.open())
         {
             qDebug()<<("Failed To Open Database");
             return false;

         }
         else {
             qDebug()<<("Connected....");
             return true;
         }
     }
private slots:
    void on_Create_Order_rejected();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_KP1_clicked();

    void on_KP9_clicked();

    void on_KP2_clicked();

    void on_KP3_clicked();

    void on_KP4_clicked();

    void on_KP5_clicked();

    void on_KP6_clicked();

    void on_KP7_clicked();

    void on_KP8_clicked();

    void on_KP0_clicked();

    void on_KP0_2_clicked();


private:
    Ui::Create_Order *ui;

signals:
       void SendReply(QVariantMap);
};

#endif // CREATE_ORDER_H
