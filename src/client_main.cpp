#include <iostream>
#include <stdexcept>
#include <string>
#include "client/client.h"
#include "client/login/login.h"
#include "client/screen_recorder/screen_recorder.h"

int main(int argc, char *argv[]) {
    Login login;
    ScreenRecorder screen_recorder;
    // login.run(argc, argv);

    try {
        Client client(login.getHostname(), login.getPort());
        if (argc == 2 && std::string(argv[1]) == "--record") {
            screen_recorder.start();
        }
        client.run();
    } catch (const std::runtime_error& err) {
        std::cerr << err.what() << std::endl;
        return 1;
    }

    return 0;
}
