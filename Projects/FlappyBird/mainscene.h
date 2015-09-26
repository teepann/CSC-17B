#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QtGui>
#include <QGraphicsPixmapItem>

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

    /*The Background Image Object*/
    QImage bgImage;

    /*The Upward Flower Image Object*/
    QImage upFlowerIm;

    /*The Downward Flower Image Object*/
    QImage downFlowerIm;

    /*This object help to create flowers in the scene*/
    QGraphicsPixmapItem *flowerProducer;


public:

    /**
     * The main constructor is uesed for initating all components in this scene
     */
    MainScene(QObject *parent = 0);

    /**
     * Destructor
     */
    ~MainScene();

protected:
    /**
     * Overriding function from QGraphicsScene
     * This function will draw the background being one of three layers of the scene
     * @brief drawBackground
     * @param painter
     * @param rect
     */
    void drawBackground(QPainter *painter, const QRectF &rect);

signals:


public slots:

    /*Add moving flowers to the scene*/
    void createFlowers();

    /*Free memory for the unused flowers */
    void deleteFlowers();
};

#endif // MAINSCENE_H
