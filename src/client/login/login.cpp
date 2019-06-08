#include "client/login/login.h"

Login::Login() :
    hostname("localhost"), port("8080") {}

int Login::run(int argc, char *argv[]) {
    QApplication app(argc, argv);
    LoginScreen login_screen(hostname, port);

    QDesktopWidget* desktop = QApplication::desktop();
    QPoint screen_center = desktop->rect().center();
    login_screen.move(screen_center);
    login_screen.show();
    return app.exec();
}

const std::string& Login::getHostname() const {
    return hostname;
}

const std::string& Login::getPort() const {
    return port;
}
