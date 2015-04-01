#include "paymentwithstatus.h"
#include "ui_paymentwithstatus.h"
#include "sendtext.h"
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
    //Load the status_url of the order created on the Create_order page (From Coin Payments)
     ui->webView->setUrl(reply["status_url"].toString());

}


PaymentWithStatus::~PaymentWithStatus()
{
    delete ui;
}


void PaymentWithStatus::on_webView_loadFinished(bool arg1)
{
    //Scroll the webview box to the middle to display the payment info but not the header.
    ui->webView->page()->mainFrame()->setScrollBarValue(Qt::Vertical, ((ui->webView->page()->mainFrame()->scrollBarMaximum(Qt::Vertical)/2)));

}

void PaymentWithStatus::on_pushButton_clicked()
{
    SendText Sendatext;
    Sendatext.setModal(true);
    Sendatext.exec();
}
