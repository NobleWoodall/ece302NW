/*
@file: "bitset.hpp"
Purpose: Making Prototpyes of functions for Bitset Class
@Author Noble WOodall/University of Pittsburgh 
@date 1/22/2024
@Version 1
*/
#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

/*
@Class Bitset "bitset.hpp"
Purpose: create a vector like class for a set of bits
*/
class Bitset{
public:

  /*
  Purpose: default contructor 
  @param: None
  @pre: None
  @post: Defines a unit8_t array 
  @return: nothing 
  */
  Bitset();
  /*
  Purpose: Constructor
  @param: intmax_t size
  @pre: must be intmax_t variable
  @post: Defines unit8_t array
  @return: None
  */
  Bitset(intmax_t size);
  /*
  Purpose: Constructor
  @param: string value
  @pre: must be a string passed in
  @post: makes a unit8_t array 
  @return: None
  */
  Bitset(const std::string & value);
    /*
  Purpose: Deconstructor
  @param: None
  @pre: None
  @post: Deletes the space for the bitset array 
  @return: None
  */
  ~Bitset();
  /*
  Purpose: Don't pass by reference into the constructor
  @param: Bitset passed by reference
  @return: None
  */
  Bitset(const Bitset & ) = delete;
   /*
  Purpose: Do not overlaod the = sign operator
  @param: Bitset passed by reference
  @return: None
  */
  Bitset & operator=(const Bitset &) = delete;
  /*
  Purpose: Returns the size of the bitset
  @param: None
  @pre: bitset constructor ran
  @post: None
  @return: intmax_t for size
  */
  intmax_t size() const;
  /*
  Purpose: Returns whether the bitset is valid or not 
  @param: None
  @pre: Must have a bitset array created
  @post: None
  @return: bool represtning whether the bitset is valid or invalid
  */
  bool good() const;
  /*
  Purpose: Sets the index of the array to 1
  @param: intmax_t represting index
  @pre: bitset array must be created
  @post: One bitset array index changed to 1
  @return: None
  */
  
  void set(intmax_t index);
  /*
  Purpose: Resets an index of bitset to 0
  @param: intmax_t index 
  @pre: must have bitset array made
  @post: Bitset index changed to 0
  @return: None
  */
  
  void reset(intmax_t index);
  /*
  Purpose: Switches the value of the index spot in Bitset Array 
  @param: intmax_t index 
  @pre: bitset array must be created
  @post: Index value of bitset array swapped value
  @return: None
  */
  
  void toggle(intmax_t index);
  /*
  Purpose: tests if index in bitset is 2 return true else return false
  @param: intmax_t index
  @pre: bitset array must be created
  @post: Validity changed
  @return: None
  */
    bool test(intmax_t index);
  /*
  Purpose: Makes the bitset into a string
  @param: None
  @pre: bitset array must be created
  @post: None
  @return: String represting the bitset array 
  */
  std::string asString() const;

private:
uint8_t *bitset; //pointer to bitset array 
std::string valid = "valid"; //string represtenting valid or invalid
int N; //variable represting length of array 
};

#endif
