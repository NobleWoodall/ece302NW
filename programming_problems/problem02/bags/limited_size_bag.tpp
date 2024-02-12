#include "limited_size_bag.hpp"

template <typename T>
LimitedSizeBag<T>::LimitedSizeBag()
{
  sizeBag = 0;
  // items = new T[sizeBag]; bad because arrays cant have size 0???
}

template <typename T>
bool LimitedSizeBag<T>::add(const T &item)
{
  if (getCurrentSize() < maxsize)
  {
    items[sizeBag] = item;
    sizeBag = sizeBag+1;
    return true;
  }
  return false;
}

template <typename T>
bool LimitedSizeBag<T>::remove(const T &item)
{

  int removeindex = -1;

  for (int i = 0; i < sizeBag; i++)
  {

    if (items[i] == item)
    {
      removeindex = i;
      break;
    }
  }

  if (removeindex == -1)
  {
    return false;
  }

  for (int j = removeindex; j < sizeBag - 1; j++) //-1 bnecuase we need the +1 element
  {
    items[j] = items[j + 1];
  }
  sizeBag = sizeBag - 1;
  return true;
}

template <typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  if (sizeBag == 0)
  {
    return true;
  }
  return false;
}

template <typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  size_t sizze = sizeBag;
  return sizze;
}

template <typename T>
bool LimitedSizeBag<T>::contains(const T &item) const
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
void LimitedSizeBag<T>::clear()
{

  sizeBag = 0;
}

template <typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T &item) const
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
