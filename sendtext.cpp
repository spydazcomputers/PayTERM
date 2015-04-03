#include "sendtext.h"
#include "ui_sendtext.h"
#include <QtNetwork>
#include <QDebug>

QString status_url;

SendText::SendText(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SendText)
{
    ui->setupUi(this);

}

SendText::~SendText()
{
    delete ui;
}

void SendText::on_buttonBox_accepted()
{
    QString username = "feb9a33f9866";
    QString password = "5bd52659b79bd4d0";

    QUrl qrl("https://www.callfire.com/api/1.1/rest/text");

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkRequest request(qrl);

    QString message =  "visit "+status_url+" to make your payment";
    QByteArray data;
    QUrlQuery params;
    params.addQueryItem("Type", "TEXT");
    params.addQueryItem("To", ui->MobileNum->text());
    params.addQueryItem("Message", message);
    data.append(params.toString());

    qDebug () << "Status_Url" << status_url;

    // HTTP Basic authentication header value: base64(username:password)
    QString concatenated = username + ":" + password;
    QByteArray Authdata = concatenated.toLocal8Bit().toBase64();
    QString headerData = "Basic " + Authdata;
    request.setRawHeader("Authorization", headerData.toLocal8Bit());


    QNetworkReply *reply = manager->post(request, data);
    QEventLoop eventLoop;
    connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();
    if (reply->error() == QNetworkReply::NoError)
    {
        //Read the CoinPayments Response to String
        QString strReply = (QString)reply->readAll();
        qDebug() << strReply;

    }
    else
    {
        qDebug () << "ERROR" << reply->readAll();
    }
}

void SendText::SetUrl(const QString &URL)
{
  status_url = URL;
  qDebug () << "SetURL Activated";

}
