#include "dynamic_bag.hpp"
#include <iostream>

template <typename T>
DynamicBag<T>::DynamicBag()
{
  sizeBag = 0;
  //items = new T[sizeBag]; bad because arrays cant have size 0???

  items = nullptr;

}

template <typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T> &x)
{

  // used to copy one Bag into a non existing Bag

  sizeBag = x.sizeBag;
  items = new T[sizeBag];

  for (int i = 0; i < sizeBag; i++)
  {
    items[i] = x.items[i];
  }
}

template <typename T>
DynamicBag<T>::~DynamicBag()
{

  delete[] items;
}

template <typename T>
DynamicBag<T> &DynamicBag<T>::operator=(DynamicBag<T> x)
{
  // used to copy the values of an exisiting bag into another

  if (this != &x)
  { // making sure we are not copying the same addresses

    delete[] items; // clearing the memory from the current bag

    sizeBag = x.sizeBag;
    items = new T[sizeBag]; // reallocating memory for the bag with the new sie

    for (int i = 0; i < sizeBag; i++)
    {
      items[i] = x.items[i];
    }
  }
  return *this;
}

template <typename T>
void DynamicBag<T>::swap(DynamicBag<T> &x)
{

  // we do nothing with swap?
}

template <typename T>
bool DynamicBag<T>::add(const T &item)
{
  sizeBag = sizeBag + 1;
  T *tempBag;
  tempBag = new T[sizeBag];

  for (int i = 0; i < sizeBag - 1; i++)
  { // fills the temp bag almost full, only the last element not full

    tempBag[i] = items[i];
  }

  tempBag[sizeBag - 1] = item; // fills the last element with the item

  delete[] items; // deletes the original bag so we can remake it with a larger size

  items = new T[sizeBag];

  for (int i = 0; i < sizeBag; i++)
  {

    items[i] = tempBag[i]; // fills the new bag with the items from the temp bag
 
  }

  delete[] tempBag;

  return true;
}

template <typename T>
bool DynamicBag<T>::remove(const T &item)
{

  int removeIndex = -1; // make -1 so definitley not in array
  for (int i = 0; i < sizeBag; i++)
  {

    if (items[i] == item)
    {
      removeIndex = i;
      break; // break because we only want to remove one item
    }
  }
  if (removeIndex == -1)
  {
    return false;
  }
  for (int i = removeIndex; i < sizeBag - 1; i++)
  {
    items[i] = items[i + 1]; // shifts everything left, keeps the same bag size with an empty element at the end
  }

  sizeBag = sizeBag - 1;

  T *tempArray = new T[sizeBag];
  for (int i = 0; i < sizeBag; i++)
  {
    tempArray[i] = items[i];
  }

  delete[] items;

  items = new T[sizeBag];
  for (int i = 0; i < sizeBag; i++)
  {
    items[i] = tempArray[i];
  }

  delete[] tempArray;

  return true;
}

template <typename T> 
bool DynamicBag<T>::isEmpty() const
{
  if (sizeBag == 0){
    return true;
  }
  else{
    return false;
    }
}

template <typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return sizeBag;
}

template <typename T>
bool DynamicBag<T>::contains(const T &item) const
{
    for (int i = 0; i < sizeBag; i++)
  {
    if (items[i] == item)
    {
      return true;
    }
  }
  return false;
}

template <typename T>
void DynamicBag<T>::clear()
{

  sizeBag = 0;
  delete[] items;

  items = new T[sizeBag];
}

template <typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T &item) const
{
  size_t count = 0;
  for (int i = 0; i < sizeBag; i++)
  {
    if (items[i] == item)
    {
      count = count + 1;
    }
  }
  return count;
};
