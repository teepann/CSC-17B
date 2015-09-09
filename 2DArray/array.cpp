#include <cstdlib>  //Random Library
#include <ctime>    //Time Library
#include <sstream> //String Stream Library

using namespace std;//Utilize standard name-space directly

/*
 * This is a Two Dimensional Dynamic Array class
 */
class TDArray{

private:


    /* The default number of rows or cols in the array */
    static const int ROW_COL_DEFAULT = 1;

    /* An invalid value of the number of rows or cols in the array */
    static const int ROW_COL_INVALID_VALUE = 0;

    /*The minimum value of a 2 digit number*/
    static const int MIN_2_DIGIT_NUMBER = 10;

    /*The minimum value of a 3 digit number*/
    static const int MIN_3_DIGIT_NUMBER = 100;

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
            return;
        }

        //Assigning private properties of the array
        this->nRows = nRows;
        this->nCols = nCols;

        //Set random number seed with respect to time.
        srand(static_cast<unsigned int>(time(NULL)));

        //Allocating the memory for the 2D Array
        array = new int* [nRows];
        for (int i = 0; i < nRows; i++) {
            array[i] = new int [nCols];
        }

        // Fill the array with random 2 digit numbers.
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                array[i][j] = ((rand() % (MIN_3_DIGIT_NUMBER - MIN_2_DIGIT_NUMBER)) + MIN_2_DIGIT_NUMBER);
            }
        }

    }

    /*The TDArray destructor*/
    ~TDArray(){

        //Deallocating all columned memories
        for (int i = 0; i < nRows; i++){
            delete [] array[i];
        }

        //Deallocating rowed memory
        delete [] array;
    }

    /*This function returns a string with the contents of the array in character array format*/
    char* toString(){

        stringstream result;

        //Creating a string stream of all the array elements
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                result << array[i][j] << " ";
            }
            result << endl;
        }

        return (char*)result.str().c_str();
    }

};
