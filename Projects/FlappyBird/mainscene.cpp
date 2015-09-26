#include "mainscene.h"

/**
 * Reference to the declaration of this constructor
 * @brief MainScene::MainScene
 * @param parent
 */
MainScene::MainScene(QObject *parent) : QGraphicsScene(parent)
{

    /*Loading a background picture into the equivalent image object*/
    bgImage.load(BG_FILE_NAME);

    /*Loading a upper flower picture into the equivalent image object*/
    upFlowerIm.load(UF_FILE_NAME);

    /*Loading a bottom flower picture into the equivalent image object*/
    downFlowerIm.load(DF_FILE_NAME);

}

/**
 * Reference to the declaration of this function
 * @brief MainScene::drawBackground
 * @param painter
 * @param rect
 */
void MainScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawImage(rect,bgImage);
}

/**
 * Reference to the declaration of this function
 * @brief MainScene::createFlowers
 */
void MainScene::createFlowers()
{
    static int i = 0;

    flowerProducer = new QGraphicsPixmapItem(QPixmap::fromImage(upFlowerIm.scaledToHeight(150)));

    flowerProducer->setPos(sceneRect().bottomRight().x() - i - flowerProducer->sceneBoundingRect().width(), sceneRect().bottom() - flowerProducer->sceneBoundingRect().height());

    this->addItem(flowerProducer);

    flowerProducer = new QGraphicsPixmapItem(QPixmap::fromImage(downFlowerIm.scaledToHeight(150)));

    flowerProducer->setPos(sceneRect().topRight().x() - i - flowerProducer->sceneBoundingRect().width(), sceneRect().top());

    this->addItem(flowerProducer);

    i+=100;

}

/**
 * Reference to the declaration of this function
 * @brief MainScene::deleteFlowers
 */
void MainScene::deleteFlowers()
{

}
