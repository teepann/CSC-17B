#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include <QTimer>
#include "mainwindow.h"

/**
 * @brief The SceneController class
 * This is the primary controller of the GUI.
 * It controls all the behaviors on the main window and its scene
 */
class UIController : public QObject
{
    Q_OBJECT

private:

    /*The minimum milisecond for creating flowers*/
    const int MIN_TIME_IN_MIL = 1500;

    /*The maximum milisecond for creating flowers*/
    const int MAX_TIME_IN_MIL = 5000;

    /*The default milisecond for moving flowers*/
    const int FLOWER_DEFAULT_SPEED = 15;

    /*The main window of Flappy Bird*/
    MainWindow *mainWindow;

    /*This timer is used for controlling the creation of flowers*/
    QTimer *cFlowerTimer;

    /*This timer is used for controlling the movement of flowers*/
    QTimer *mFlowerTimer;

    /*Identifying the current game mode*/
    bool isGameStarted;

public:
    /*The constructor of this main UI controller*/
    explicit UIController(QObject *parent = 0);

signals:

public slots:

    /*Randomly ask for new flowers to add to the main scene*/
    void createFlowers();

    /*Processing the items in the scene according to the key press*/
    void processKeyPress();
};

#endif // UICONTROLLER_H
