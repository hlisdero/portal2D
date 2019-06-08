#ifndef LOGIN_SCREEN_H
#define LOGIN_SCREEN_H

#include <string>
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>

class LoginScreen : public QWidget {
public:
    LoginScreen(std::string& hostname, std::string& port);

private:
    std::string& hostname;
    std::string& port;

    QLabel label;
    QLineEdit inputHostname;
    QLineEdit inputPort;
    QPushButton buttonConnect;

    void readHostname();
    void readPort();
    void quit();
};

#endif // LOGIN_SCREEN_H
