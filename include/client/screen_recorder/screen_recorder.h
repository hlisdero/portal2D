#ifndef SCREEN_RECORDER_H
#define SCREEN_RECORDER_H

#include <cstdio>
#include <stdexcept>
#include <cstdlib>

class ScreenRecorder {
public:
    explicit ScreenRecorder(const std::string& filename = "output.mp4");

    ~ScreenRecorder();

    void start();

private:
    const std::string filename;
    const std::string command = "ffmpeg -loglevel quiet -video_size 1152x864 -framerate 25 -f x11grab -i :0.0+0,0 ";
    FILE *process = nullptr;

    void close();
};

#endif  // SCREEN_RECORDER_H
