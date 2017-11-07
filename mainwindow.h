#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <videoplay.h>

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
    //Display video frame in player UI
    void updatePlayerUI(QImage img);
    //Slot for the load video push button.
    void on_startButton_clicked();
    // Slot for the play push button.
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    videoPlay* myVideo;
};

#endif // MAINWINDOW_H
