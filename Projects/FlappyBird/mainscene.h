#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsPixmapItem>
#include <ctime>

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

    /*The minimum height of a flower in the scene*/
    const short MIN_FLOWER_HEIGHT = 130;

    /*The maximum height of a flower in the scene*/
    const short MAX_FLOWER_HEIGHT = 160;

    /*The Background Image Object*/
    QImage bgImage;

    /*The Upward Flower Image Object*/
    QImage upFlowerIm;

    /*The Downward Flower Image Object*/
    QImage downFlowerIm;

    /*This object help to create flowers in the scene*/
    QGraphicsPixmapItem *flower;

    /*A vetors of all available flowers in the scene*/
    QVector<QGraphicsPixmapItem *> flowers;


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

signals:


public slots:

    /*Add moving flowers to the scene*/
    void createFlowers();

    /*Move flowers to the scene*/
    void moveFlowers();

};

#endif // MAINSCENE_H
