#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include <QDebug>
#include "mainwindow.h"

namespace Ui {
class Login_Dialog;
}

class Login_Dialog : public QDialog
{
    Q_OBJECT

public:

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

public:
    explicit Login_Dialog(QWidget *parent = 0);
    ~Login_Dialog();

private slots:
    void on_pushButton_clicked();

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
signals:
        void SetText(QString);

private:
    Ui::Login_Dialog *ui;
};

#endif // LOGIN_DIALOG_H
