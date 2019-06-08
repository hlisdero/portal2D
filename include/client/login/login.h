#ifndef LOGIN_H
#define LOGIN_H

#include <string>
#include <QApplication>
#include <QDesktopWidget>
#include "client/login/login_screen.h"

class Login {
public:
    explicit Login();

    Login(const Login&) = delete;
    Login& operator=(const Login&) = delete;
    Login(Login&& other) = delete;
    Login& operator=(Login&& other) = delete;

    int run(int argc, char *argv[]);
    const std::string& getHostname() const;
    const std::string& getPort() const;

private:
    std::string hostname;
    std::string port;
};

#endif  // LOGIN_H
