#include "mainscene.h"
#include "mainwindow.h"

/**
 * Reference to the declaration of this constructor
 * @brief MainScene::MainScene
 * @param paren
 */
MainScene::MainScene(QObject *parent) : QGraphicsScene(parent)
{

    /*Seeding the value for a random*/
    qsrand(time(NULL));

    /*Loading a background picture into the equivalent image object*/
    bgImage.load(BG_FILE_NAME);

    /*Loading a upper flower picture into the equivalent image object*/
    upFlowerIm.load(UF_FILE_NAME);

    /*Loading a bottom flower picture into the equivalent image object*/
    downFlowerIm.load(DF_FILE_NAME);

    /*Loading a bird picture into the equivalent image object*/
    birdImage.load(FB_FILE_NAME);

    createABird();
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
 * @brief MainScene::getHeightScale
 * @return
 */
short MainScene::getHeightScale()
{
    return MIN_FLOWER_HEIGHT + qrand()%(MAX_FLOWER_HEIGHT - MIN_FLOWER_HEIGHT + 1);
}

/**
 * Reference to the declaration of this function
 * @brief MainScene::addNewFlower
 * @param flower
 */
void MainScene::addNewFlower(QGraphicsPixmapItem *flower)
{
    this->addItem(flower);
    flowers.append(flower);
}

/**
 * Reference to the declaration of this function
 * @brief MainScene::deletePFlower
 * @param flower
 */
void MainScene::deletePFlower(QGraphicsPixmapItem *flower)
{
    if (flower->pos().x() < this->sceneRect().bottomLeft().x()){
        this->removeItem(flower);
        flowers.removeOne(flower);
    }
}


/**
 * Reference to the declaration of this function
 * @brief MainScene::createABird
 */
void MainScene::createABird()
{
    //Loading animated bird gif to a label
    QMovie *birdMovie = new QMovie(FB_FILE_NAME);
    QLabel *birdLabel = new QLabel();

    //Let the bird image occupy the whole scene at the beginning
    birdMovie->setScaledSize((QSize(static_cast<MainWindow*>(this->parent())->geometry().width()
                                    ,static_cast<MainWindow*>(this->parent())->geometry().height())));
    birdLabel->setMovie(birdMovie);

    //Make the gif look transparent on the main scene
    birdLabel->setAttribute(Qt::WA_TranslucentBackground,true);
    birdMovie->start();

    //Using a graphics proxy object to manage the bird in the main scene
    bird = addWidget(birdLabel);

}

/**
 * Reference to the declaration of this function
 * @brief MainScene::createFlowers
 */
void MainScene::createFlowers()
{

    //Creating a top flower
    flower = new QGraphicsPixmapItem(QPixmap::fromImage(upFlowerIm.scaledToHeight(getHeightScale())));

    flower->setPos(sceneRect().bottomRight().x() - flower->sceneBoundingRect().width()
                   , sceneRect().bottom() - flower->sceneBoundingRect().height());

    addNewFlower(flower);

    //Creating a bottom flower
    flower = new QGraphicsPixmapItem(QPixmap::fromImage(downFlowerIm.scaledToHeight(getHeightScale())));

    flower->setPos(sceneRect().topRight().x() - flower->sceneBoundingRect().width()
                   , sceneRect().top());

    addNewFlower(flower);
}

/**
 * Reference to the declaration of this function
 * @brief MainScene::moveFlowers
 */
void MainScene::moveFlowers()
{
    for (int i = 0; i < flowers.size(); i++) {
        //Moving flowers from right to left
        flowers[i]->setPos(flowers[i]->pos().x() - 1,flowers[i]->pos().y());
        //Remove the one that was out of sight
        deletePFlower(flowers[i]);
    }

}

/**
 * Reference to the declaration of this function
 * @brief MainScene::play
 */
void MainScene::play()
{
    bird->setScale(BIRD_PIC_SCALE);
    qDebug() << bird->geometry().width()*BIRD_PIC_SCALE<< endl;
    qDebug() << bird->geometry().height()*BIRD_PIC_SCALE;
    bird->setPos(100,250);
}
