#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEnginePage>
#include <QWebEngineView>
#include <QWebEngineSettings>


namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private slots:
    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_actionDebug_triggered();

private:
    Ui::mainWindow *ui;
    QWebEngineView * webView = nullptr;
};

#endif // MAINWINDOW_H
