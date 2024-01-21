/*
*@file abstract_bag.hpp
*@Purpose of this abstract class is to define the names of function names that will be shared amognst different classes to represent a bag
*@author University of Pittsburgh and Noble Woodall 
*@date 1/17/2024
*/

#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

//@class AbstractBag/abstract_bag.hpp
//Purpose is to define methods to be used for teh bag classes

template<typename T> class AbstractBag
{
public:

    /*Gets the currecnt size of the bag
    @param none
    @pre 
    @post Returns the size_t number
    @return size_t
    */
    virtual std::size_t getCurrentSize() const = 0;
    /*Checks if the bag is empty
    @param none
    @pre none
    @post must return a 1 or 0 
    @return returns a bool that represents whether the bag is empty
    */
    virtual bool isEmpty() const = 0;
    /*Adds to the bag
    @param A constant T variable passed by reference named as entry
    @pre must pass a const T variable
    @post A bool is returned 
    @return retruns a bool that tells you if you are succesful or not
    */
    virtual bool add(const T &entry) = 0;
    /*Removes from the bag
    @param a const T representing the item
    @pre has to pass in something in the bag
    @post must return a bool
    @return returns a bool that tells you whether you are succesful or not
    */
    virtual bool remove(const T &entry) = 0;
    /*Clears the bag out
    @param none
    @pre must have something in the bag
    @post bag will be empty
    @return nothing
    */
    virtual void clear() = 0;
    /*Gets the frequency of one item from the bag
    @param a reference to a T varible that represetns a type of ittem in the bag
    @pre must pass in the correct variable type 
    @post number shoul dbe shown that says teh total number of items
    @return the size of the amount of that specifc item in a variable size_t
    */
    virtual std::size_t getFrequencyOf(const T &entry) const = 0;
    /*
    @param a const reference to a T variable representing the item
    @pre make sure the data type passed in is correct
    @post make sure teh data type returned is bool
    @return a bool that tells you whether the item is in the bag or not
    */
    virtual bool contains(const T &entry) const = 0;

};

#endif