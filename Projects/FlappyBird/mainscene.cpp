#include "mainscene.h"
#include <QDebug>

MainScene::MainScene()
{

}

MainScene::MainScene(QObject *parent) : QGraphicsScene(parent)
{
    bgImage.load(BG_FILE_NAME);
}

void MainScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawImage(rect,bgImage);

}

