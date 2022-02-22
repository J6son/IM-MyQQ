
QT       += core gui

INCLUDEPATH+=F:\ColinOpenCV\include\opencv\
                    F:\ColinOpenCV\include\opencv2\
                    F:\ColinOpenCV\include

LIBS+=F:\ColinOpenCV\lib\libopencv_calib3d2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_contrib2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_core2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_features2d2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_flann2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_gpu2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_highgui2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_imgproc2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_legacy2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_ml2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_objdetect2410.dll.a\
        F:\ColinOpenCV\lib\libopencv_video2410.dll.a

HEADERS += \
    $$PWD/screen_read.h \
    $$PWD/video_read.h \
    $$PWD/common.h \
    $$PWD/myfacedetect.h

SOURCES += \
    $$PWD/screen_read.cpp \
    $$PWD/video_read.cpp \
    $$PWD/myfacedetect.cpp



