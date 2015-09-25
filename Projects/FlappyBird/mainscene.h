#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QGraphicsScene>
#include <QtGui>

class MainScene : public QGraphicsScene
{
private:

    const QString BG_FILE_NAME = ":/Images/BackGround.png";

    QImage bgImage;

public:
    MainScene();

    MainScene(QObject *parent = 0);

protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

signals:

public slots:
};

#endif // MAINSCENE_H
