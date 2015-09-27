#include "uicontroller.h"

/**
 *Reference to the function declaration
 * @brief UIController::createAFlower
 */
UIController::UIController(QObject *parent) : QObject(parent)
{
    mainWindow = new MainWindow();
    mainWindow->show();

    //Seeding the value for a random
    qsrand(time(NULL));

    //Initializing all the timers
    cFlowerTimer = new QTimer(this);
    mFlowerTimer = new QTimer(this);

    //Connecting timer to the behaviors of flowers in the main scene
    connect(cFlowerTimer,SIGNAL(timeout()),this,SLOT(createFlowers()));
    connect(mFlowerTimer,SIGNAL(timeout()),mainWindow,SLOT(moveFlowers()));

    //Testing
    cFlowerTimer->start(MIN_TIME_IN_MIL);
    mFlowerTimer->start(FLOWER_DEFAULT_SPEED);

}

/**
 * Reference to the function declaration
 * @brief UIController::createNewFLowers
 */
void UIController::createFlowers()
{
    cFlowerTimer->stop();
    mainWindow->createFlowers();
    cFlowerTimer->start(MIN_TIME_IN_MIL + (qrand()%(MAX_TIME_IN_MIL - MIN_TIME_IN_MIL + 1)));
}



