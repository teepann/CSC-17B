#ifndef ABSTRACT_ARRAY //Solving duplicated librarys for derived classes
#define ABSTRACT_ARRAY

/*
 * This is a Two Dimensional Dynamic Array Abstract class
 */
class AbstractArray{

protected:

    /**
     * @brief fillArray
     * The pure virtual function being used for filling the array with random 2 digit numbers.
     */
    virtual void fillArray() = 0;

public:
    /**
     * @brief toPrint
     * The pure virtual function being used for printing an array on the console.
     */
    virtual void toPrint() = 0;

};

#endif
