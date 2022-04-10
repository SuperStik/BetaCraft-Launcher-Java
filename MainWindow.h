#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>>

class QWebEngineView;
class QUrl;
class QLineEdit;
class QTabWidget;
class QPushButton;
class QCheckBox;
class QLabel;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onPlayButton();

private:
    QWebEngineView* _webView;
    QLineEdit* _username;
    QTabWidget* _tabWidget;
    QWidget* _changelogSection;
    QWidget* _instancesSection;
    QPushButton* _playButton;
    QCheckBox* _onlineCheckbox;
    QLabel* _logo;
    QLabel* _background;
};

#endif
