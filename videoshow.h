#ifndef VIDEOSHOW_H
#define VIDEOSHOW_H

#include <opencv2/core/core.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class videoShow
{
private:
    VideoCapture *camera;
public:
    videoShow();
    void open(VideoCapture);
    void showVideo(void);
};

#endif // VIDEOSHOW_H
