#ifndef VIDEOPLAY_H
#define VIDEOPLAY_H

#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class videoPlay : public QThread
{
    Q_OBJECT
private:
    bool stop;
    QMutex mutex;
    QWaitCondition condition;
    Mat frame;
    int frameRate;
    VideoCapture capture, camera;
    Mat RGBframe;
    QImage img;
signals:
    //Signal to output frame to be displayed
    void processedImage(const QImage &image);
protected:
    void run();
    void msleep(int ms);
public:
    //Constructor
    videoPlay(QObject *parent = 0);
    //Destructor
    ~videoPlay();
    //Load a video from webcam
    void capVideo(VideoCapture);
    //Play the video
    void Play();
    //Stop the video
    void Stop();
    //check if the player has been stopped
    bool isStopped() const;
};

#endif // VIDEOPLAY_H
