#ifndef SCREEN_RECORDER_H
#define SCREEN_RECORDER_H

#include <cstdio>
#include <stdexcept>
#include <cstdlib>
#include "client/client_settings.h"

extern ClientSettings CLIENT_SETTINGS;

class ScreenRecorder {
public:
    explicit ScreenRecorder();

    ~ScreenRecorder();

    void start();

private:
    const std::string screen_width;
    const std::string screen_height;
    const std::string filename;
    const std::string framerate;
    const std::string offset_x;
    const std::string offset_y;
    FILE *process = nullptr;

    void close();
    std::string getCommand() const;
};

#endif  // SCREEN_RECORDER_H
