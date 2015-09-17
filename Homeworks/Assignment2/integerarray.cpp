#include "basearray.cpp" //BaseArray class

/*
 * This is a Two Dimensional Dynamic Integer Array class
 */
class IntegerArray: public BaseArray<int>{

private:

    /*The minimum value of a 2 digit number*/
    static const int MIN_2_DIGIT_NUMBER = 10;

    /*The minimum value of a 3 digit number*/
    static const int MIN_3_DIGIT_NUMBER = 100;

public:

    /*
     * The 2DArray default contructor;
     */
    IntegerArray(){

    }

    /* The 2DArray contructor which has 2 paraments:
     * nRows: the number of rows in the array
     * nCols: the number of cols in the array
     */
    IntegerArray(int nRows, int nCols): BaseArray<int>(nRows,nCols){

    }

    /**
     * @brief fillArray()
     * Implementing the pure virtual method from AbstractArray class
     */
    void fillArray(){

        // Fill the array with random 2 digit numbers.
        for (int i = 0; i < this->nRows; i++){
            for (int j = 0; j < this->nCols; j++){
                array[i][j] = ((rand() % (MIN_3_DIGIT_NUMBER - MIN_2_DIGIT_NUMBER)) + MIN_2_DIGIT_NUMBER);
            }
        }

    }

};
