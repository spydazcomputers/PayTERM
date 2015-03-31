#include "create_order.h"
#include "ui_create_order.h"
#include "login_dialog.h"
#include "mainwindow.h"
#include "paymentwithstatus.h"




Create_Order::Create_Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_Order)
{
    ui->setupUi(this);
    ui->Price->setFocus();

}

Create_Order::~Create_Order()
{

    delete ui;
}

void Create_Order::on_Create_Order_rejected()
{

    this->destroy();
    Login_Dialog ldialog;
    ldialog.setModal(true);
    ldialog.exec();
}

void Create_Order::on_pushButton_clicked()
{
    // Coin Payments Api Key's stored here need to move to database and config through admin landing page

    QByteArray PubKey = "a48ef0ca947fc892b79e07129bae15a80ba54d54d6ea42fa4c50cb14a34c96d5";
    QByteArray PrivKey = "1C0AEf6D6289D0bB0aaffa47ad3Aa8B3Ea0F4589419834Bdc845a3fF8774223a";

   // Initialize parameters for
    QByteArray data;
    QUrlQuery params;
    params.addQueryItem("amount", ui->Price->text());
    params.addQueryItem("currency1", "USD");
    params.addQueryItem("currency2", ui->buttonGroup->checkedButton()->text());
    params.addQueryItem("address", "");
    params.addQueryItem("ipn_url", "");
    params.addQueryItem("version", "1");
    params.addQueryItem("cmd", "create_transaction");
    params.addQueryItem("key", PubKey);
    params.addQueryItem("format", "json");
    data.append(params.toString());

   // qDebug() << data;

    QByteArray HMAC = QMessageAuthenticationCode::hash(data, PrivKey, QCryptographicHash::Sha512).toHex();

    QUrl qrl("https://www.coinpayments.net/api.php");
    qDebug() << "Calling url: " << qrl.toString();
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(qrl);

    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("HMAC", HMAC);
   // qDebug() << request.rawHeader("HMAC:");

    QNetworkReply *reply = manager->post(request, data);
    QEventLoop eventLoop;
    connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    if (reply->error() == QNetworkReply::NoError)
    {
        QString strReply = (QString)reply->readAll();

        //parse json
        //qDebug() << "Response:" << strReply;
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

        QJsonObject jsonObj = jsonResponse.object();
        // Access subtier of JSON result and store in DB

       jsonObj2 = jsonObj["result"].toObject();
       if (!jsonObj2.isEmpty())
       {
            if(connOpen())
            {
            QString qrystring = "Insert into main.orders values ('"+jsonObj2["amount"].toString()+"', '"+jsonObj2["address"].toString()+"', '"+jsonObj2["txn_id"].toString()+"', '"+jsonObj2["confirms_needed"].toString()+"', '"+jsonObj2["timeout"].toString()+"', '"+jsonObj2["status_url"].toString()+"', '"+ui->buttonGroup->checkedButton()->text()+"')";
            QSqlQuery *qry = new QSqlQuery(mydb);
            qry->prepare(qrystring);
            qry->exec();
             }
        }

       connClose();
       PaymentWithStatus PayWindow;
       QObject::connect(this, SIGNAL(SendReply(QVariantMap)), &PayWindow, SLOT(SetReply(QVariantMap)));
       PayWindow.setModal(true);
       //qDebug() << jsonObj2;
       emit SendReply(jsonObj2.toVariantMap());
       PayWindow.exec();

       close();
        return;
    }

    else
    {


        qDebug() << "Network error: " << reply->error();
         delete reply;

    }






}

void Create_Order::on_pushButton_2_clicked()
{
    this->reject();

     return;
}

void Create_Order::on_KP1_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier, "1", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);


}

void Create_Order::on_KP2_clicked()
{

    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier, "2", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP3_clicked()
{

    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_3, Qt::NoModifier, "3", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);

}

void Create_Order::on_KP4_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_4, Qt::NoModifier, "4", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP5_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_5, Qt::NoModifier, "5", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);;
}

void Create_Order::on_KP6_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_6, Qt::NoModifier, "6", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP7_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_7, Qt::NoModifier, "7", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP8_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_8, Qt::NoModifier, "8", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP9_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_9, Qt::NoModifier, "9", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP0_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_0, Qt::NoModifier, "0", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}

void Create_Order::on_KP0_2_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, ".", false, 0 );
        QApplication::sendEvent(this->focusWidget(), &key);
}


