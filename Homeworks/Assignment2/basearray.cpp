#ifndef BASE_CLASS //Solving duplicated librarys for derived classes
#define BASE_CLASS

#include <cstdlib>  //Random Library
#include <ctime>    //Time Library
#include <sstream> //String Stream Library
#include <iostream> // Input/Output Stream Library
#include "abstractarray.cpp" //AbstractArray class

#include <iomanip>

using namespace std;//Utilize standard name-space directly

template <class T> //Template is used for supporting integer and float arrays
/*
 * This is a Two Dimensional Dynamic Array Template Base class
 */
class BaseArray : public AbstractArray{

private:

    /* The default number of rows or cols in the array */
    static const int ROW_COL_DEFAULT = 1;

    /* An invalid value of the number of rows or cols in the array */
    static const int ROW_COL_INVALID_VALUE = 0;

protected:

    /* The number of rows in the array */
    int nRows;

    /* The number of columns in the array */
    int nCols;

    /* The 2D Dynamic Array */
    T **array;

public:

    /* The 2DArray contructor which has 2 paraments:
     * nRows: the number of rows in the array
     * nCols: the number of cols in the array
    */
    BaseArray(int nRows = ROW_COL_DEFAULT, int nCols = ROW_COL_DEFAULT){

        //Row and Col validation
        if (nRows <= ROW_COL_INVALID_VALUE || nCols <= ROW_COL_INVALID_VALUE){

            this->nRows = this->nCols = ROW_COL_DEFAULT;

        }else{

            //Assigning private properties of the array
            this->nRows = nRows;
            this->nCols = nCols;
        }

        //Set random number seed with respect to time.
        srand(static_cast<unsigned int>(time(NULL)));

        //Allocating the memory for the 2D Array
        array = new T* [this->nRows];
        for (int i = 0; i < this->nRows; i++) {
            array[i] = new T [this->nCols];
        }

    }

    /*The TDArray destructor*/
    ~BaseArray(){

        //Deallocating all columned memories
        for (int i = 0; i < nRows; i++){
            delete [] array[i];
        }

        //Deallocating rowed memory
        delete [] array;
    }

private:

    /*This function returns a string with the contents of the array in character array format*/
    char* toString(){

        stringstream result;

        //Creating a string stream of all the array elements
        for (int i = 0; i < nRows; i++){
            for (int j = 0; j < nCols; j++){
                result << fixed << setprecision(1) << array[i][j] << " ";
            }
            result << endl;
        }

        return (char*)result.str().c_str();
    }

public:
    /**
     * @brief toPrint
     * Implementing the pure virtual method from AbstractArray class
     */
    void toPrint(){

        // Polymorphism
        fillArray();

        cout << this->toString();
    }


};

#endif
