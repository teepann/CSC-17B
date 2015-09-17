#include "basearray.cpp" //BaseArray class

/*
 * This is a Two Dimensional Dynamic float Array class
 */
class FloatArray: public BaseArray<float>{

private:

    /*The minimum value of a 2 digit number*/
    static const float MIN_2_DIGIT_NUMBER = 0.0;

    /*The minimum value of a 3 digit number*/
    static const float MAX_2_DIGIT_NUMBER = 9.0;


public:

    /*
     * The 2DArray default contructor;
     */
    FloatArray(){

    }

    /* The 2DArray contructor which has 2 paraments:
     * nRows: the number of rows in the array
     * nCols: the number of cols in the array
     */
    FloatArray(int nRows, int nCols): BaseArray<float>(nRows,nCols){

    }

    /**
     * @brief fillArray()
     * Implementing the pure virtual method from AbstractArray class
     */
    void fillArray(){

        // Fill the array with random 2 digit numbers.
        for (int i = 0; i < this->nRows; i++){
            for (int j = 0; j < this->nCols; j++){
                array[i][j] = MIN_2_DIGIT_NUMBER
                        + (rand() / static_cast<float> (RAND_MAX) ) * (MAX_2_DIGIT_NUMBER - MIN_2_DIGIT_NUMBER);
            }
        }

    }


};
