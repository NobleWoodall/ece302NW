#ifndef _SORT_HPP
#define _SORT_HPP

#include "linked_list.hpp"

/*

This is a bubble sort that can be used for any type of varible using a linked list
Note that when C++ compares string it does so lexicographically, or alphabetically

*/
template <typename T>
LinkedList<T> sort(LinkedList<T> list)
{

	size_t listLength = list.getLength(); //saves the length of the list into listLength

	for (size_t i = 0; i < listLength - 1; i++) //loops through length of the list 
	{
		for (size_t j = 0; j < listLength - 1; j++) //nested loop through list
		{
				T temp = list.getEntry(j); //gets copy of list entry saved as so we can put it in another spot if we need to 
			
			if (list.getEntry(j) > list.getEntry(j+1)) //checks whether current list entry is greater than the next list entry
			{
				list.setEntry(j, list.getEntry(j+1)); //if it is switch them 
				list.setEntry(j+1,temp); //make sure to put copied value into this one because it would be changed from above line
			}
		}
	}
	return list;
}

#endif
