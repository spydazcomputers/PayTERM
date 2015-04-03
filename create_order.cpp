#include "create_order.h"
#include "ui_create_order.h"
#include "login_dialog.h"
#include "mainwindow.h"
#include "paymentwithstatus.h"
#include <QValidator>




Create_Order::Create_Order(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Create_Order)
{
    ui->setupUi(this);
    //Set the focus of the dialog box to the username box

    ui->Price->setFocus();

}

Create_Order::~Create_Order()
{

    delete ui;
}

void Create_Order::on_Create_Order_rejected()
{
    //Close the logon Dialog and return to Main_Window
    this->close();

}

void Create_Order::on_pushButton_clicked()
{

    // Google API Key for URL Shortenting
    QByteArray GOOGLEAPI = "AIzaSyButuygbH6-0Y4uKWuKPCu8mXVhGuAT31E";

    // Coin Payments Api Key's stored here need to move to database and config through admin landing page

    QByteArray PubKey = "a48ef0ca947fc892b79e07129bae15a80ba54d54d6ea42fa4c50cb14a34c96d5";
    QByteArray PrivKey = "1C0AEf6D6289D0bB0aaffa47ad3Aa8B3Ea0F4589419834Bdc845a3fF8774223a";

   // Initialize parameters for CoinPayments RESTful Post
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


    // Generate the HMAC header neaded by CoinPayments API for Authentication
    QByteArray HMAC = QMessageAuthenticationCode::hash(data, PrivKey, QCryptographicHash::Sha512).toHex();

    QUrl qrl("https://www.coinpayments.net/api.php");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(qrl);

   // Setup the Header to include the Content Type and HMAC
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("HMAC", HMAC);


    QNetworkReply *reply = manager->post(request, data);
    QEventLoop eventLoop;
    connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    if (reply->error() == QNetworkReply::NoError)
    {
        //Read the CoinPayments Response to String
        QString strReply = (QString)reply->readAll();

        //Parse the Coinpayments Respons string as JSON

        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
        QJsonObject jsonObj = jsonResponse.object();

        // Create a new JSON object Containing only the result portion of the reply
        QJsonObject jsonObj2 = jsonObj["result"].toObject();
       //Store the Result in the Database
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

       // Shorten the URL

       QByteArray status_url;
       status_url.append(jsonObj2["status_url"].toString());
       qDebug() << "Status URL " << status_url;

       QByteArray urldata = "{\"longUrl\":\""+status_url+"\"}";
       qDebug()<< "json" << urldata;

       // For your "Content-Length" header

       QUrl urlqrl("https://www.googleapis.com/urlshortener/v1/url?key="+GOOGLEAPI);

       QNetworkAccessManager *urlmanager = new QNetworkAccessManager(this);
       QNetworkRequest urlrequest(urlqrl);

      // Setup the Header to include the Content Type and HMAC
       urlrequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

       QNetworkReply *urlreply = urlmanager->post(urlrequest, urldata);
       //qDebug() << urlqrl << urldata;

       QEventLoop urleventLoop;
       connect(urlreply, SIGNAL(finished()), &urleventLoop, SLOT(quit()));
       urleventLoop.exec();
      // if (urlreply->error() == QNetworkReply::NoError)
      // {
           QString urlReply = (QString)urlreply->readAll();

           //Parse the Goo.gl Respons string as JSON

           QJsonDocument urljsonResponse = QJsonDocument::fromJson(urlReply.toUtf8());
           QJsonObject urljsonObj = urljsonResponse.object();
         //  qDebug() << "URL SHORT" << urljsonObj;
     /*  }
       else
       {
           qDebug() << "URL Shorting Error" << urlreply->errorString();
       }*/

       // Create the Payment Window
       PaymentWithStatus PayWindow;
       QObject::connect(this, SIGNAL(SendReply(QVariantMap)), &PayWindow, SLOT(SetReply(QVariantMap)));
       PayWindow.setModal(true);

       // Send the Status URL
       emit SendReply(urljsonObj.toVariantMap());

       //Close the Create Order Window
       this->close();

       //Open The  Payment Status Window
       PayWindow.exec();

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


