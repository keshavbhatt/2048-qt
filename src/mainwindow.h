#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebPage>
#include <QSettings>

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
    Q_INVOKABLE void update_high_score(QVariant var);

private slots:
    void on_actionAbout_triggered();

    void on_actionQuit_triggered();

    void on_actionDebug_triggered();

private:
    Ui::mainWindow *ui;
    QWebPage *page;
    QSettings settings;
};

#endif // MAINWINDOW_H
