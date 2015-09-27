#include "uicontroller.h"

/**
 *Reference to the function declaration
 * @brief UIController::createAFlower
 */
UIController::UIController(QObject *parent) : QObject(parent)
{
    mainWindow = new MainWindow();
    mainWindow->show();

    qsrand(time(NULL));

    //Initializing all the timers
    cFlowerTimer = new QTimer(this);
    mFlowerTimer = new QTimer(this);

    //Connecting timer to the behaviors of flowers in the main scene
    connect(cFlowerTimer,SIGNAL(timeout()),mainWindow,SLOT(createFlowers()));
    connect(mFlowerTimer,SIGNAL(timeout()),mainWindow,SLOT(moveFlowers()));

    //Testing
    cFlowerTimer->start(1000 + qrand()%(5000 - 1000 + 1));
    mFlowerTimer->start(15);

}



