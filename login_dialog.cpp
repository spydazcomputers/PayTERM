#include "login_dialog.h"
#include "ui_login_dialog.h"
#include "create_order.h"
#include "admin.h"
#include "mainwindow.h"

Login_Dialog::Login_Dialog(QWidget * parent) :
    QDialog(parent),
    ui(new Ui::Login_Dialog)
{
    ui->setupUi(this);

    connOpen();
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery* qry = new QSqlQuery(mydb);
    qry->prepare("select UNAME from USERS");
    qry->exec();
    modal->setQuery(*qry);
    ui->comboBox_USER->setModel(modal);
    ui->comboBox_USER->setFocus();



}

Login_Dialog::~Login_Dialog()
{
    delete ui;
}

void Login_Dialog::on_pushButton_clicked()
{

    QString username, password;
    username=ui->comboBox_USER->currentText();
    password=ui->lineEdit->text();

    if (!connOpen())
    {
        qDebug() <<("Database Not Open");

    }
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(mydb);
    qry->prepare("select * from USERS where UNAME = '"+username+"' and PIN = '"+password+"'");




    if (qry->exec())
    {

                 int count = 0;

                 while (qry->next())
                 {
                     count++;

                 }
                    if (count == 1){
                        modal->setQuery(*qry);
                        if (modal->record(0).value("UTYPE").toInt() == 1){

                        Admin admin;
                        admin.setModal(true);
                        admin.exec();

                        }
                        else if (modal->record(0).value("UTYPE").toInt() == 2){

                            connClose();
                            Create_Order cOrder;
                            cOrder.setModal(true);
                            emit SetText(username);
                            this->reject();
                            cOrder.exec();


                        }

                    }
                    else
                        ui->UserStatus->setText("Invalid");



    }

    connClose();

}


void Login_Dialog::on_KP1_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier, "1", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);


}

void Login_Dialog::on_KP2_clicked()
{

    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier, "2", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP3_clicked()
{

    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_3, Qt::NoModifier, "3", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);

}

void Login_Dialog::on_KP4_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_4, Qt::NoModifier, "4", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP5_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_5, Qt::NoModifier, "5", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);;
}

void Login_Dialog::on_KP6_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_6, Qt::NoModifier, "6", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP7_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_7, Qt::NoModifier, "7", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP8_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_8, Qt::NoModifier, "8", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP9_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_9, Qt::NoModifier, "9", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP0_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_0, Qt::NoModifier, "0", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Login_Dialog::on_KP0_2_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, ".", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}
