#include <QCoreApplication>
#include <integerarray.cpp> // IntegerArray class
#include <floatarray.cpp> // FloatArray class

int main(int argc, char *argv[])
{
    //Test the array with a square matrix 8*8
    const int NUM_ROW_COL_TEST = 8;

    QCoreApplication a(argc, argv);

    //Create 2D integer and float arrays in form of an abstract array
    AbstractArray* integerArray = new IntegerArray(NUM_ROW_COL_TEST,NUM_ROW_COL_TEST);
    AbstractArray* floatArray = new FloatArray(NUM_ROW_COL_TEST,NUM_ROW_COL_TEST);

    integerArray->toPrint();
    floatArray->toPrint();

    return a.exec();
}
