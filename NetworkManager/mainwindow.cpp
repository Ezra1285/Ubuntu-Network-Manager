// QT libs
#include "mainwindow.h"
#include <QMessageBox>
#include "./ui_mainwindow.h"
//  SQL libs
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
// std libs
#include <string>
#include <vector>


namespace windowSupport {
enum UserPermission {
    NONE=1,
    BASIC=2,
    ADMIN=3
};
}

class User {
    std::string mUserName;
    std::string mPassword;
    windowSupport::UserPermission mPermissions;

public:
    User(std::string user_name, std::string password, windowSupport::UserPermission permissions): mUserName(user_name), mPassword(password), mPermissions(permissions) {}
};

class SqlWrapper {
    std::vector<User> mUserList;
public:
    SqlWrapper(): mUserList({}) {}
};


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string user_name = ui->txtUsername->toPlainText().toStdString();
    std::string password = ui->txtPassword->toPlainText().toStdString();

    QMessageBox msgBox;
    if (user_name == "") {
        msgBox.setText("Please enter a valid username");
        msgBox.exec();
    }
    else if (password == "") {
        msgBox.setText("Please enter a valid password");
        msgBox.exec();
    }


}

