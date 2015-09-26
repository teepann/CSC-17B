#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <QObject>
#include "mainwindow.h"
#include <QTimer>


/**
 * @brief The SceneController class
 * This is the primary controller of the GUI.
 * It controls all the behaviors on the main window and its scene
 */
class UIController : public QObject
{

private:
    /*The main window of Flappy Bird*/
    MainWindow *mainWindow;

    /*This timer is used for controlling the movements of flowers*/
    QTimer *flowerTimer;

public:
    /*The constructor of this main UI controller*/
    explicit UIController(QObject *parent = 0);

};

#endif // UICONTROLLER_H
