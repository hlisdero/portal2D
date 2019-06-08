#include "client/login/login_screen.h"

LoginScreen::LoginScreen(std::string& hostname, std::string& port) :
    QWidget(0),
    hostname(hostname), port(port),
    buttonConnect("Conectar") {
    QVBoxLayout* loginLayout = new QVBoxLayout();
    QHBoxLayout* inputLayout = new QHBoxLayout();

    inputLayout->addWidget(&inputHostname);
    inputLayout->addWidget(&inputPort);
    inputLayout->addWidget(&buttonConnect);

    loginLayout->addWidget(&label);
    loginLayout->addLayout(inputLayout);
    setLayout(loginLayout);

    label.setText("Ingrese un hostname y un puerto:");

    QObject::connect(&buttonConnect, &QPushButton::clicked,
                     this, &LoginScreen::readHostname);
    QObject::connect(&buttonConnect, &QPushButton::clicked,
                     this, &LoginScreen::readPort);
    QObject::connect(&buttonConnect, &QPushButton::clicked,
                     this, &LoginScreen::quit);
}

void LoginScreen::readHostname() {
    QString str = inputHostname.text();
    hostname = str.toStdString();
}

void LoginScreen::readPort() {
    QString str = inputPort.text();
    port = str.toStdString();
}

void LoginScreen::quit() {
    close();
}
