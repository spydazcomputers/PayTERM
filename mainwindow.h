#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include "login_dialog.h"
#include <QKeyEvent>
#include <QApplication>
namespace Ui {

class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:

    void on_actionLogin_triggered();
    void LabelChange(const QString &newtext);
private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
