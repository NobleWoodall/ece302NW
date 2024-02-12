#include "array_list.hpp"

template <typename T>
ArrayList<T>::ArrayList()
{

  sizeList = 0;
  // items = new T[sizeBag]; bad because arrays cant have size 0???
  list = nullptr;
}

template <typename T>
ArrayList<T>::~ArrayList()
{

  delete[] list;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList &rhs)
{
  // used to copy one Bag into a non existing Bag
  sizeList = rhs.sizeList;
  list = new T[sizeList];

  for (int i = 0; i < sizeList; i++)
  {
    list[i] = rhs.list[i];
  }
}

template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList rhs)
{
  // used to copy the values of an exisiting bag into another
  if (this != &rhs)
  { // making sure we are not copying the same addresses

    delete[] list; // clearing the memory from the current bag

    sizeList = rhs.sizeList;
    list = new T[sizeList]; // reallocating memory for the bag with the new sie

    for (int i = 0; i < sizeList; i++)
    {
      list[i] = rhs.list[i];
    }
  }
  return *this;

}

template <typename T>
void ArrayList<T>::swap(ArrayList &rhs)
{

  // I did not implement this because it is not neccessary
}

template <typename T>
bool ArrayList<T>::isEmpty() const noexcept
{

  if (sizeList == 0)
  {
    return true;
  }
  else
  {
    return false;
  }

  return false;
}

template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept
{
  return sizeList;
}

template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T &item) //
{

  if (position > sizeList || position < 0)
  {
    return false;
  }
  
  T* temparray = new T[sizeList + 1];

  for (int i = 0; i < position; i++)
  {
    temparray[i] = list[i];
  }

  temparray[position] = item;

  for (int i = position; i < sizeList-1; i++)
  {
    temparray[i+1] = list[i];
  }

  delete[] list;

  sizeList=sizeList+1;

  list = new T[sizeList];

  for (int i = 0; i < sizeList; i++)
  {
    list[i] = temparray[i];
  }

  delete[] temparray;

  return true;
}

template <typename T>
bool ArrayList<T>::remove(std::size_t position)
{

  if (position > sizeList || position<0)
  {
    return false;
  }
  for (std::size_t i = position; i < sizeList - 1; i++)
  {
    list[i] = list[i + 1]; // shifts everything left, keeps the same bag size with an empty element at the end
  }

  sizeList = sizeList - 1;

  T *tempArray = new T[sizeList];
  for (std::size_t i = 0; i < sizeList; i++)
  {
    tempArray[i] = list[i];
  }

  delete[] list;

  list = new T[sizeList];
  for (std::size_t i = 0; i < sizeList; i++)
  {
    list[i] = tempArray[i];
  }

  delete[] tempArray;

  return true;
}

template <typename T>
void ArrayList<T>::clear()
{
  sizeList = 0;
  delete[] list;

  list = new T[sizeList];
}

template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const
{
  if (position > sizeList || position < 0)
  {
    return T();
  }
  else
  {
    return list[position];
  }
}

template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T &newValue)
{

  if (position > sizeList || position < 0)
  {
    return;
  }
  else
  {
    list[position] = newValue;
  }
  return;
}
