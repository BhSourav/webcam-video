#include "videoplay.h"

videoPlay::videoPlay(QObject *parent)
    : QThread(parent)
{
    cout<<"Thread Started"<<endl;
    stop = true;
}

void videoPlay::Play()
{
    if (!isRunning()) {
        if (isStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

void videoPlay::run()
{
    capVideo(capture);
}

videoPlay::~videoPlay()
{
    mutex.lock();
    stop = true;
    capture.release();
    condition.wakeOne();
    mutex.unlock();
    wait();
}

void videoPlay::Stop()
{
    stop = true;
}

void videoPlay::msleep(int ms)
{
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

bool videoPlay::isStopped() const{
    return this->stop;
}

void videoPlay::capVideo(VideoCapture capture)
{
    capture.open(0);
    if(!capture.isOpened())
    {
        std::cout<<"Camera did not open";
        exit(1);
    }
    bool b =0;
    while (!stop)
    {
        // Grab the next camera frame.
        b = capture.read(frame);
        if (!b)
        {
            std::cerr << "ERROR: Couldn't grab a camera frame." <<std::endl;
            //exit(1);
            stop = true;
        }
        //imshow("CamerOP",frame);
        //cv::waitKey(30);
        if (frame.channels()== 3)
        {
            cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
            img = QImage((const unsigned char*)(RGBframe.data),
                         RGBframe.cols,RGBframe.rows,QImage::Format_RGB888);
        }
        else
        {
            img = QImage((const unsigned char*)(frame.data),
                         frame.cols,frame.rows,QImage::Format_Indexed8);
        }
        emit processedImage(img);
    }
}

