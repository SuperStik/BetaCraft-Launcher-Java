#include <QtWidgets>
#include <QtWebEngineWidgets>
#include "MainWindow.h"

// Constructor for main window
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{;
    _webView = new QWebEngineView();
    _webView->load(QUrl("http://files.betacraft.uk/launcher/changelog/English.html"));

    _username = new QLineEdit;

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(_webView, 0, 0);
    mainLayout->addWidget(_username, 1, 0);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    setLayout(mainLayout);

    setWindowTitle("Betacraft");
    resize(800, 480);
    setMinimumSize(800, 480);
}

MainWindow::~MainWindow()
{
    delete _webView;
    delete _username;
}
