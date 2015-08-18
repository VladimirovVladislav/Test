#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_sendZapros, SIGNAL(clicked()),
            SLOT(close())
            );

    connect(ui->pushButton_connect, SIGNAL (clicked()),
          this, SLOT(slotDebug())
          );    

}
void MainWindow::slotDebug() {


     Client client;

     connect(&client, SIGNAL(clientInformation(QString)),
             ui->textEdit_info, SLOT(setText(QString))
             );

     client.exec();

     qDebug () << "после connect";

}
MainWindow::~MainWindow()
{
    delete ui;
}

