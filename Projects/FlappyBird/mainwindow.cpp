#include "mainwindow.h"
#include "ui_mainwindow.h"

/*Reference to the function declaration*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Assemblying the main scene of the game to this window
    mainScene = new MainScene(this);
    ui->graphicsView->setScene(mainScene);

}

/*Reference to the function declaration*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*Reference to the function declaration*/
void MainWindow::createFlowers()
{
    mainScene->createFlowers();
}

/*Reference to the function declaration*/
void MainWindow::deleteFlowers()
{
    mainScene->deleteFlowers();
}




