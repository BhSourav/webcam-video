#include "videoshow.h"

videoShow::videoShow()
{}

void videoShow::open(VideoCapture camera)
{
    camera.open(0);
        if(!camera.isOpened())
        {
            std::cout<<"Camera did not open";
            exit(1);
        }

        camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
        camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
}

void videoShow::showVideo()
{
    bool b =0;

    //open(camera);
    while (true)
    {
      // Grab the next camera frame.
        Mat cframe;
         b=camera->read(cframe);
          if (!b)
          {
            std::cerr << "ERROR: Couldn't grab a camera frame." <<std::endl;
            exit(1);
          }
          imshow("CamerOP",cframe);
          cv::waitKey(30);
    }
}
