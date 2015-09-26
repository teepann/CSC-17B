#include "uicontroller.h"


/*Reference to the function declaration*/
UIController::UIController(QObject *parent) : QObject(parent)
{
    mainWindow = new MainWindow();
    mainWindow->show();

    flowerTimer = new QTimer(this);
    connect(flowerTimer,SIGNAL(timeout()),mainWindow,SLOT(createFlowers()));
    flowerTimer->start(1000);

}











