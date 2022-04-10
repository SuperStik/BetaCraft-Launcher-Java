#include <QtWidgets>
#include <QtWebEngineWidgets>
#include "MainWindow.h"

// Constructor for main window
MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{;
    _webView = new QWebEngineView;
    _username = new QLineEdit;
    _playButton = new QPushButton("PLAY");
    _onlineCheckbox = new QCheckBox("Online mode");
    _changelogSection = new QWidget;
    _instancesSection = new QWidget;
    _tabWidget = new QTabWidget;
    _logo = new QLabel;
    _background = new QLabel;

    //Set _tabWidget properties
    _tabWidget->setMaximumHeight(20);
    _tabWidget->setMaximumWidth(140);
    _tabWidget->setStyleSheet("QTabWidget::pane { border: 0; }");

    //Load changelog
    _webView->load(QUrl("http://files.betacraft.uk/launcher/changelog/English.html"));

    //Set logo
    QPixmap logoPix (":/Assets/logo.png");
    _logo->setPixmap(logoPix);

    //Add tabs
    _tabWidget->addTab(_changelogSection, "Changelog");
    _tabWidget->addTab(_instancesSection, "Instances");

    //THAT'S HOW YOU HIDE TABS
    //_tabWidget->setStyleSheet("QTabWidget::pane { border: 0; } QTabBar::tab {width: 0; height: 0; margin: 0; padding: 0; border: none;}");

    //Set mainLayout properties
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    //Add widgets
    mainLayout->addWidget(_webView, 0, 0, 1, 0);
    //mainLayout->addWidget(_background, 1, 0);
    mainLayout->addWidget(_username, 1, 2, 1, 2);
    mainLayout->addWidget(_playButton, 1, 4, 1, 1);
    mainLayout->addWidget(_onlineCheckbox, 2, 2, 1, 2);
    mainLayout->addWidget(_logo, 1, 0, 2, 1);
    mainLayout->addWidget(_tabWidget, 0, 0, Qt::AlignBottom | Qt::AlignLeft);

    setLayout(mainLayout);

    //Set window properties
    setWindowTitle("Betacraft");
    resize(800, 480);
    setMinimumSize(800, 480);
    setStyleSheet("background-image: url(:/Assets/dirt.png);");

    connect(_playButton, SIGNAL(released()), this, SLOT(onPlayButton()));
}

//Destructor
MainWindow::~MainWindow()
{
    delete _webView;
    delete _username;
    delete _tabWidget;
    delete _changelogSection;
    delete _instancesSection;
    delete _playButton;
    delete _onlineCheckbox;
    delete _logo;
    delete _background;
}

void MainWindow::onPlayButton()
{
    printf("%d", 69);
}
