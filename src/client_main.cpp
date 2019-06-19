#include <iostream>
#include <stdexcept>
#include <string>
#include "client/client.h"
#include "client/login/login.h"
#include "client/screen_recorder/screen_recorder.h"

int main(int argc, char *argv[]) {
    try {
        Login login;
        ScreenRecorder screen_recorder;
        // login.run(argc, argv);
        Client client(login.getHostname(), login.getPort());
        if (argc == 2 && std::string(argv[1]) == "--record") {
            screen_recorder.start();
        }
        client.run();
        return 0;
    } catch (std::runtime_error err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }
}
