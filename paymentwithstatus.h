#ifndef PAYMENTWITHSTATUS_H
#define PAYMENTWITHSTATUS_H

#include <QDialog>
#include <QtNetwork>
#include <QMessageAuthenticationCode>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "mainwindow.h"

namespace Ui {
class PaymentWithStatus;
}

class PaymentWithStatus : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentWithStatus(QWidget *parent = 0);
    ~PaymentWithStatus();
    QString shortUrl;



private:
    Ui::PaymentWithStatus *ui;

private slots:
    void SetReply(const QVariantMap &reply);

    void on_webView_loadFinished(bool arg1);
    void on_pushButton_clicked();
signals:
        void SendUrl(QString);
};


#endif // PAYMENTWITHSTATUS_H
