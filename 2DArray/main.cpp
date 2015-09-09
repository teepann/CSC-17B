#include <QApplication>
#include <QLabel>
#include "array.cpp"

int main(int argc, char *argv[])
{
    //The number of rows or cols in a array
    const int ROW_COL_TEST_VALUE = 8;

    QApplication a(argc, argv);

    //Create a 2D Dynamic Array object
    TDArray *tdArray = new TDArray(ROW_COL_TEST_VALUE,ROW_COL_TEST_VALUE);

    QLabel *label = new QLabel();

    //populate data to the label
    label->setText(tdArray->toString());
    label->show();

    return a.exec();
}
