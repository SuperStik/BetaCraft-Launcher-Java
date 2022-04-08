#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>>

class QWebEngineView;
class QUrl;
class QLineEdit;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QWebEngineView* _webView;
    QLineEdit* _username;
};

#endif
