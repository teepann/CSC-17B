#include <cstdlib>  //Random Library
/*
 * This is a Two Dimensional Dynamic Array class
 */
class TDArray{

private:


    /* The default number of rows or cols in the array */
    const int ROW_COL_DEFAULT = 1;

    /* An invalid value of the number of rows or cols in the array */
    const int ROW_COL_INVALID_VALUE = 0;

    /*The minimum value of a 2 digit number*/
    const int MIN_2_DIGIT_NUMBER = 10;

    /*The minimum value of a 3 digit number*/
    const int MIN_3_DIGIT_NUMBER = 100;

    /* The number of rows in the array */
    int nRows;

    /* The number of columns in the array */
    int nCols;

    /* The 2D Dynamic Array */
    int **array;

public:

    /* The TDArray contructor which has 2 paraments:
     * nRows: the number of rows in the array
     * nCols: the number of cols in the array
    */
    TDArray(int nRows = ROW_COL_DEFAULT, int nCols = ROW_COL_DEFAULT){

        //Row and Col validation
        if (nRows <= ROW_COL_INVALID_VALUE || nCols <= ROW_COL_INVALID_VALUE){
            return 1;
        }

        //Set random number seed with respect to time.
        srand(static_cast<unsigned int>(time(NULL)));

        //Allocating the memory for the 2D Array
        array = new int* [nRows];
        for (int i = 0; i < nRows; ++i) {
            array[i] = new int [nCols];
        }



    }

}
