#include "sorted_linked_list.hpp"
#include <stdexcept>

template <typename T>
SortedLinkedList<T>::SortedLinkedList() : LinkedList<T>()
{
  LinkedList<T>::clear();
}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(LinkedList<T> unsorted_list)
{

  size_t listLength = unsorted_list.getLength(); // saves the length of the list into listLength

  for (size_t i = 0; i < listLength - 1; i++) // loops through length of the list
  {
    for (size_t j = 0; j < listLength - 1; j++) // nested loop through list
    {
      T temp = unsorted_list.getEntry(j); // gets copy of list entry saved as so we can put it in another spot if we need to

      if (unsorted_list.getEntry(j) > unsorted_list.getEntry(j + 1)) // checks whether current list entry is greater than the next list entry
      {
        unsorted_list.setEntry(j, unsorted_list.getEntry(j + 1)); // if it is switch them
        unsorted_list.setEntry(j + 1, temp);                      // make sure to put copied value into this one because it would be changed from above line
      }
    }
  }

  LinkedList<T>::operator=(unsorted_list);

}

template <typename T>
SortedLinkedList<T>::SortedLinkedList(const SortedLinkedList<T> &x) : LinkedList<T>(x)
{
}

template <typename T>
SortedLinkedList<T> &SortedLinkedList<T>::operator=(SortedLinkedList<T> x)
{
  LinkedList<T>::operator=(x);
  return *this;
}

template <typename T>
SortedLinkedList<T>::~SortedLinkedList()
{
  // base destructor gets called automatically
}

template <typename T>
bool SortedLinkedList<T>::isEmpty() const noexcept
{
  return LinkedList<T>::isEmpty();
}

template <typename T>
std::size_t SortedLinkedList<T>::getLength() const noexcept
{
  return LinkedList<T>::getLength();
}

template <typename T>
void SortedLinkedList<T>::insert(const T &item)
{
  int i =0;

  if(LinkedList<T>::getLength() == 0){
    LinkedList<T>::insert(i, item);
    return;
  }

while (i < LinkedList<T>::getLength() && item > LinkedList<T>::getEntry(i))
    {
        i++;
    }
    
 LinkedList<T>::insert(i, item);
   
}

template <typename T>
void SortedLinkedList<T>::remove(const T &item)
{
  if (isEmpty())
    throw std::range_error("empty list in remove");

  for (int i = 0; i < LinkedList<T>::getLength(); i++)
  {
    if (item == LinkedList<T>::getEntry(i))
    {
      LinkedList<T>::remove(i);
      break;
    }
  }
}

template <typename T>
void SortedLinkedList<T>::removeAt(std::size_t position)
{
  if (isEmpty())
    throw std::range_error("empty list in remove");

  LinkedList<T>::remove(position);
}

template <typename T>
void SortedLinkedList<T>::clear()
{
  LinkedList<T>::clear();
}

template <typename T>
T SortedLinkedList<T>::getEntry(std::size_t position) const
{
  return LinkedList<T>::getEntry(position);
}

template <typename T>
long int SortedLinkedList<T>::getPosition(const T &item)
{
  // return the position of the item if it occurs in the list, -1 otherwise
   for (int i = 0; i < LinkedList<T>::getLength(); i++)
  {
    if (item == LinkedList<T>::getEntry(i))
    {
      return i;
    }

  } 

  return -1;
}
