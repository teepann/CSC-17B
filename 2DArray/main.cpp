#include <QApplication>
#include <QLabel>
#include "tdarray.cpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TDArray *tdArray = new TDArray();

    QLabel *label = new QLabel(tdArray->toString());
    label->show();

    return a.exec();
}
