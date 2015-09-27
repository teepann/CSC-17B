#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <ctime>
#include <QLabel>
#include <QGraphicsProxyWidget>

/**
 * @brief The MainScene class
 * This is the main graphics scene of the game
 * It is used to manage all the moving items (the birds and flowers) as well as the background
 */
class MainScene : public QGraphicsScene
{

private:

    /*Path to the back ground image*/
    const QString BG_FILE_NAME = ":/Images/BackGround.png";

    /*Path to the upward flower image*/
    const QString UF_FILE_NAME = ":/Images/UpwardFlower.png";

    /*Path to the downward flower image*/
    const QString DF_FILE_NAME = ":/Images/DownwardFlower.png";

    /*Path to the flappig bird image*/
    const QString FB_FILE_NAME = ":/Images/FlappingBird.gif";

    /*The minimum height of a flower in the scene*/
    const short MIN_FLOWER_HEIGHT = 150;

    /*The maximum height of a flower in the scene*/
    const short MAX_FLOWER_HEIGHT = 200;

    /*This scalar of the flapping bird in the scene*/
    const float BIRD_PIC_SCALE = 0.2;

    /*The Background Image Object*/
    QImage bgImage;

    /*The Upward Flower Image Object*/
    QImage upFlowerIm;

    /*The Downward Flower Image Object*/
    QImage downFlowerIm;

    /*The Flapping Bird Image Object*/
    QImage birdImage;

    /*This object helps to create flowers in the scene*/
    QGraphicsPixmapItem *flower;

    /*A vetors of all available flowers in the scene*/
    QVector<QGraphicsPixmapItem *> flowers;

    /*This graphics proxy object is used for managing the bird in the main scene*/
    QGraphicsProxyWidget *bird;

public:

    /**
     * The main constructor is uesed for initating all components in this scene
     */
    MainScene(QObject *parent = 0);

protected:
    /**
     * Overriding function from QGraphicsScene
     * This function will draw the background being one of three layers of the scene
     * @brief drawBackground
     * @param painter
     * @param rect
     */
    void drawBackground(QPainter *painter, const QRectF &rect);

private:
    /*Generate a scale for the height of a flower in a reasonable range*/
    short getHeightScale();

    /*Update lists of flowers for processing theirs movements*/
    void addNewFlower(QGraphicsPixmapItem *flower);

    /*Deleting the flower that passed the scence*/
    void deletePFlower(QGraphicsPixmapItem *flower);

    /*Creating a bird and putting it on the main scene*/
    void createABird();

signals:


public slots:

public:
    /*Add moving flowers to the scene*/
    void createFlowers();

    /*Move flowers to the scene*/
    void moveFlowers();

    /*Locate the bird to start the game*/
    void play();

};

#endif // MAINSCENE_H
