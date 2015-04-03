#ifndef KEYPAD_H
#define KEYPAD_H

#include <QWidget>
#include <QKeyEvent>
namespace Ui {
class Keypad;
}

class Keypad : public QWidget
{
    Q_OBJECT

public:
   explicit Keypad(QWidget *parent = 0);
    ~Keypad();

private:
    Ui::Keypad *ui;

private slots:
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
};

#endif // KEYPAD_H
