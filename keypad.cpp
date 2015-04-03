#include "keypad.h"
#include "ui_keypad.h"

Keypad::Keypad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keypad)
{
    ui->setupUi(this);
}

Keypad::~Keypad()
{
    delete ui;
}

void Keypad::on_KP1_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_1, Qt::NoModifier, "1", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);


}

void Keypad::on_KP2_clicked()
{

    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_2, Qt::NoModifier, "2", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}

void Keypad::on_KP3_clicked()
{

    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_3, Qt::NoModifier, "3", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);

}

void Keypad::on_KP4_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_4, Qt::NoModifier, "4", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}

void Keypad::on_KP5_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_5, Qt::NoModifier, "5", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);;
}

void Keypad::on_KP6_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_6, Qt::NoModifier, "6", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}

void Keypad::on_KP7_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_7, Qt::NoModifier, "7", false, 0 );
        QApplication::sendEvent(parentWidget()->focusWidget(), &key);
}

void Keypad::on_KP8_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_8, Qt::NoModifier, "8", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}

void Keypad::on_KP9_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_9, Qt::NoModifier, "9", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}

void Keypad::on_KP0_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_0, Qt::NoModifier, "0", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}

void Keypad::on_KP0_2_clicked()
{
    QKeyEvent key(QKeyEvent::KeyPress, Qt::Key_Period, Qt::NoModifier, ".", false, 0 );
        QApplication::sendEvent(parentWidget(), &key);
}


