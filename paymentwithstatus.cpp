#include "paymentwithstatus.h"
#include "ui_paymentwithstatus.h"
#include <QDebug>
#include <QWebPage>
#include <QWebFrame>

PaymentWithStatus::PaymentWithStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PaymentWithStatus)
{
    ui->setupUi(this);
}

void PaymentWithStatus::SetReply(const QVariantMap &reply)
{
    qDebug ()<< "made it this far";

    /* QStringList SplitURL;
     SplitURL = reply["status_url"].toString().split('?');
     qDebug () << SplitURL;
     QByteArray data;
     data.append(SplitURL.last());
     QByteArray PubKey = "a48ef0ca947fc892b79e07129bae15a80ba54d54d6ea42fa4c50cb14a34c96d5";
     QByteArray PrivKey = "1C0AEf6D6289D0bB0aaffa47ad3Aa8B3Ea0F4589419834Bdc845a3fF8774223a";

      // list: ["Arial", "Helvetica", "Times", "Courier"]
     QByteArray HMAC = QMessageAuthenticationCode::hash(data, PrivKey, QCryptographicHash::Sha512).toHex();

     QUrl qrl("https://www.coinpayments.net/index.php");
     qDebug() << "Calling url: " << qrl.toString();
     QNetworkAccessManager *manager = new QNetworkAccessManager(this);
     QNetworkRequest request(qrl);

     request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
     request.setRawHeader("HMAC", HMAC);
    // qDebug() << request.rawHeader("HMAC:");

     QNetworkReply *netreply = manager->post(request, data);
     QEventLoop eventLoop;
     connect(netreply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
     eventLoop.exec();
     if (netreply->error() == QNetworkReply::NoError)
     {
         QString strReply = (QString)netreply->readAll();

         //parse json
         qDebug() << "Response:" << strReply;
         QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
         QJsonObject jsonObj2;
         QJsonObject jsonObj = jsonResponse.object();
         // Access subtier of JSON result and store in DB

        jsonObj2 = jsonObj["result"].toObject();
     }
*/
     ui->webView->setUrl(reply["status_url"].toString());

}


PaymentWithStatus::~PaymentWithStatus()
{
    delete ui;
}


void PaymentWithStatus::on_webView_loadFinished(bool arg1)
{
    ui->webView->page()->mainFrame()->setScrollBarValue(Qt::Vertical, ((ui->webView->page()->mainFrame()->scrollBarMaximum(Qt::Vertical)/2)));

}
