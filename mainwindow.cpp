#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login_dialog.h"
#include "QDesktopWidget"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width(); // get width of screen
    screenHeight = desktop->height(); // get height of screen

    windowSize = size(); // size of our application window
    width = windowSize.width();
    height = windowSize.height();

    // little computations
    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    y -= 50;

    // move window to desired coordinates
    move ( x, y );


}

MainWindow::~MainWindow()
{
    delete ui;
    this->destroy();

}






void MainWindow::on_actionLogin_triggered()
{
    Login_Dialog ldialog;
    QObject::connect(&ldialog, SIGNAL(SetText(QString)), this, SLOT(LabelChange(QString)));

    ldialog.setModal(true);
    ldialog.exec();

}

void MainWindow::LabelChange(const QString &newText)
{
    ui->Status_Label->setText(newText);
    qDebug()<<"Message from textValue Function \n";
}
