#include "client/screen_recorder/screen_recorder.h"

ScreenRecorder::ScreenRecorder() :
    screen_width(std::to_string(CLIENT_SETTINGS.INITIAL_SCREEN_WIDTH)),
    screen_height(std::to_string(CLIENT_SETTINGS.INITIAL_SCREEN_HEIGHT)),
    filename(CLIENT_SETTINGS.FILENAME),
    framerate(CLIENT_SETTINGS.FRAMERATE),
    offset_x(CLIENT_SETTINGS.OFFSET_X),
    offset_y(CLIENT_SETTINGS.OFFSET_Y) {}

ScreenRecorder::~ScreenRecorder() {
    if (process) {
        close();
        pclose(process);
    }
}

void ScreenRecorder::start() {
    std::string ffmpeg_command = getCommand();
    std::string remove_command = std::string("rm -f ") + "\"" + filename + "\"";

    if (std::system(remove_command.c_str()) != 0) {
        throw std::runtime_error("Error al borrar el archivo antiguo");
    }

    process = ::popen(ffmpeg_command.c_str(), "w");
    if (!process) {
        throw std::runtime_error("Error al llamar a ffmpeg");
    }
}

void ScreenRecorder::close() {
    char close_signal[] = "q";
    ::fwrite(close_signal, 1, 1, process);
}

std::string ScreenRecorder::getCommand() const {
    std::string command = "ffmpeg -loglevel quiet";
    std::string video_size = " -video_size " + screen_width + "x" + screen_height;
    std::string framerate_c = " -framerate " + framerate;
    std::string device = " -f x11grab";
    std::string offset = " -i :0.0+" + offset_x + "," + offset_y;

    return command + video_size + framerate_c + device + offset + " \"" + filename + "\"";
}
