#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "MyRect.h"

#include <QGraphicsRectItem>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->connect( ui->actionSystemInformation, &QAction::triggered, this, &MainWindow::showSystemInformation);

    this->connect( ui->actionHowToPlay, &QAction::triggered, this, &MainWindow::showHowToPlay);

    MyRect* rectangle = new MyRect();
    rectangle->setRect(10,10,100,100);

    //make item focusable
    rectangle->setFlag(QGraphicsItem::ItemIsFocusable);
    rectangle->setFocus();

    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->addItem(rectangle);

    ui->graphicsView->setScene(scene);
    //this->startTimer(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

const char* systemInformationText =
        "Monster Flag Eater Game v1.0.\n"
        "Juan Ignacio Pacheco & David Xie Li\n\n"
        "This is free software with no warranties.\nUse it at your own risk.";

void MainWindow::showSystemInformation()
{
    QMessageBox systemInformationBox;
    systemInformationBox.setIcon(QMessageBox::Information);
    systemInformationBox.setText(systemInformationText);
    systemInformationBox.exec();
}

const char* howtoplayText =
        "Press arrow keys to move around.\nReach the flag.\nPress R to reset.";

void MainWindow::showHowToPlay()
{
    QMessageBox howtoplayBox;
    howtoplayBox.setIcon(QMessageBox::Question);
    howtoplayBox.setText(howtoplayText);
    howtoplayBox.exec();
}

/*void MainWindow::timerEvent(QTimerEvent* event)
{
    qreal x= this->rectangle->x();
    qreal y = this->rectangle->y();
    this->rectangle->setPos( x + 1, y - 1 );
}*/
