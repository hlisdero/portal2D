#include "client/screen_recorder/screen_recorder.h"

ScreenRecorder::~ScreenRecorder() {
    // if (process) {
    //     pclose(process);
    // }
}

void ScreenRecorder::run() {
    std::system("ffmpeg -video_size 1152x864 -framerate 25 -f x11grab -i :0.0+0,0 output.mp4");
    // if (!process) {
    //     throw std::runtime_error("Error al llamar a ffmpeg");
    // }
}
