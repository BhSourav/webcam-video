#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    cout<<"before obbject created"<<endl;
    myVideo = new videoPlay();
    cout<<"obbject created"<<endl;
    QObject::connect(myVideo, SIGNAL(processedImage(QImage)),
                                  this, SLOT(updatePlayerUI(QImage)));
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    cout<<"object destroyed"<<endl;
    delete myVideo;
    delete ui;
}

void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->video->setAlignment(Qt::AlignCenter);
        ui->video->setPixmap(QPixmap::fromImage(img).scaled(ui->video->size(),Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::on_startButton_clicked()
{
    cout<<"here 1"<<endl;
    if (myVideo->isStopped())
    {
        cout<<"here stop"<<endl;
        myVideo->Play();
        ui->startButton->setText(tr("Stop"));
    }
    else
    {
        cout<<"here start"<<endl;
        myVideo->Stop();
        ui->startButton->setText(tr("Play"));
    }
}

void MainWindow::on_pushButton_2_clicked(){}
