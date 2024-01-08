#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , Ui::MainWindow()
{
    setupUi(this);
    m_pages = {
        welcome,
        teamInfo
    };

    connect(nextButton, &QPushButton::clicked, this, [this] {
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() + 1);
    });

    connect(backButton, &QPushButton::clicked, this, [this] {
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() - 1);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
