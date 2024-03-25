#include "list.hpp"

template <typename T>
List<T>::List()
{
  listLength = 0;
  // head.setNext(nullptr); //pretty sure this is redundant because in the Node class they start pointing to nothing
}

template <typename T>
List<T>::~List()
{
  Node<T> *current = head;
  Node<T> *next;
  while (current != nullptr)
  {
    next = current->getNext();
    delete current;
    current = next;
  }
  head = nullptr;
}

template <typename T>
List<T>::List(const List<T> &x)
{
  head = nullptr;
  temp = nullptr;

  Node<T> *movingNode = x.head;   // node to move through the original list (x)
  Node<T> *movingNode2 = nullptr; // node to move through new list (this)

  while (movingNode != nullptr)
  {

    Node<T> *newNode = new Node<T>(movingNode->getItem());

    if (head == nullptr)
    {
      head = newNode;
      movingNode2 = head; // i think you could also do = newNode here
    }
    else
    {
      movingNode2->setNext(newNode);
      movingNode2 = movingNode2->getNext();
    }
    movingNode = movingNode->getNext();
  }
}

template <typename T>
List<T> &List<T>::operator=(List<T> x)
{

  if (this != &x)
  {
    clear(); // makes the current list empty so we can remake it with new Nodes that match teh ones passed in
    Node<T> *passedinList = x.head;
    Node<T> *newList = nullptr;

    while (passedinList != nullptr)
    {
      Node<T> *newNode = new Node<T>(passedinList->getItem());

      if (newList == nullptr)
      {
        head = newNode;
      }
      else
      {
        newList->setNext(newNode);
      }
      newList = newNode;
      newList->setNext(nullptr);
      passedinList = passedinList->getNext();
    }
  }
  return *this;
}

template <typename T>
void List<T>::swap(List &x)
{
  // Avoided using this
}

template <typename T>
bool List<T>::isEmpty() const noexcept
{
  if (listLength == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
std::size_t List<T>::getLength() const noexcept
{

  Node<T> *startNode = head;
  std::size_t tempLength = 0;

  while (startNode != nullptr)
  {
    tempLength++;
    startNode = startNode->getNext();
  }
  listLength == tempLength;
  return tempLength;
}

template <typename T>
void List<T>::insert(std::size_t position, const T& item)
{
  if (position < 0 || position > getLength())
  {
    throw(std::range_error("cant insert if less than 0 or greater than position"));
  }
  else if (position == 0)
  {
    Node<T> *newNode = new Node<T>(item);
    newNode->setNext(head);
    head = newNode;
  }
  else
  {
    node = head;
    for (int i = 0; i < position - 1; i++)
    {

      node = node->getNext(); // gets us to the node before the insert
    }

    temp = node->getNext(); // the node after the insert position

    Node<T> *newNode = new Node<T>(item); // create the node being inserted

    node->setNext(newNode); // set the previous node to point to the insert

    newNode->setNext(temp); // set the insert to point to the after node
  }
  listLength++;// update length of the list'
  return;
}

template <typename T>
void List<T>::remove(std::size_t position)
{
  if (position < 0 || position >= getLength())
  {
 throw(std::range_error("cant remove if less than 0 or greater than position"));
  }
  else if (position == 0)
  {
    temp = head;
    head = head->getNext();
    delete temp;
  }
  else
  {
    node = head;
    for (int i = 0; i < position - 1; i++)
    {

      node = node->getNext(); // gets us to the node before the insert
    }

    temp = node->getNext(); // the node we want to remove

    node->setNext(temp->getNext()); // set the node before to the node after the node we want to remove

    delete temp;
  }
  listLength = getLength(); // update length of the list'
  return;
}

template <typename T>
void List<T>::clear()
{

  Node<T> *current = head;
  Node<T> *next;
  while (current != nullptr)
  {
    next = current->getNext();
    delete current;
    current = next;
  }
  head = nullptr;

  listLength = 0;
}

template <typename T>
T List<T>::getEntry(std::size_t position) const
{
  Node<T>* tempnode = head;
  if (position < 0 || position >= getLength())
  {
    throw(std::range_error("cant get if less than 0 or greater than position"));
    return T();
  }
  else if(position == 0){
    return head->getItem(); //redundant but just error checking
  }

  else
  {
    for (int i = 0; i < position; i++)
    {
      tempnode = tempnode->getNext(); // gets us to the node 
    }
  }
  return tempnode->getItem();
}

template <typename T>
void List<T>::setEntry(std::size_t position, const T &newValue)
{
  if (position < 0 || position >= getLength())
  {
    throw(std::range_error("cant remove if less than 0 or greater than position"));
    return;
  }

    Node<T>* node = head;
    for (int i = 0; i < position; i++)
    {
      node = node->getNext(); // gets us to the node insert loc
    }
    
    node->setItem(newValue);
  return;
}