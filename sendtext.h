#ifndef SENDTEXT_H
#define SENDTEXT_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class SendText;
}

class SendText : public QDialog
{
    Q_OBJECT
    QString status_url;


public:


    explicit SendText(QWidget *parent = 0);
    ~SendText();

private slots:
    void on_buttonBox_accepted();
    void SetUrl(const QString &URL);


private:
    Ui::SendText *ui;
signals:
        void SendUrl(QString);
};



#endif // SENDTEXT_H
