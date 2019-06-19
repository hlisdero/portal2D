#include "client/screen_recorder/screen_recorder.h"

ScreenRecorder::ScreenRecorder(const std::string& filename) : filename(filename) {}

ScreenRecorder::~ScreenRecorder() {
    close();
    if (process) {
        pclose(process);
    }
}

void ScreenRecorder::start() {
    std::string called_command = command + filename;
    std::string remove_command = std::string("rm -f ") + filename;

    std::system(remove_command.c_str());
    process = ::popen(called_command.c_str(), "w");
    if (!process) {
        throw std::runtime_error("Error al llamar a ffmpeg");
    }
}

void ScreenRecorder::close() {
    char close_signal[] = "q";
    ::fwrite(close_signal, 1, 1, process);
}
