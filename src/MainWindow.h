#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QGraphicsRectItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT

//private:
  //  QGraphicsRectItem* rectangle = nullptr;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    //void timerEvent(QTimerEvent* evnet);

protected slots:
    /// Shows information about this game
    void showSystemInformation();

    /// Shows information on how to play
    void showHowToPlay();

    //QLabel* interactibleObject;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
