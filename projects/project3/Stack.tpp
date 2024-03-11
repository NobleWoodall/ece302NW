#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"
#include <memory>

// TODO: Implement the constructor here
template <class ItemType>
Stack<ItemType>::Stack()
{
	headPtr = nullptr; // Pointer to first node
	currentSize = 0;   // Current depth of the stack
} // end default constructor

// TODO: Implement the destructor here
template <class ItemType>
Stack<ItemType>::~Stack()
{
//smart pointer
} // end destructor

// TODO: Implement the isEmpty method here
template <class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	return (currentSize == 0);
} // end isEmpty

// TODO: Implement the size method here
template <class ItemType>
int Stack<ItemType>::size() const
{
	//	currentSize = 0;
	//	Node<ItemType> *temppointer = headPtr;
	//	while(temppointer != nullptr){
	//		temppointer = temppointer->getNext();
	//		currentSize++;
	//}
	return currentSize;
} // end size

// TODO: Implement the push method here
template <class ItemType>
bool Stack<ItemType>::push(const ItemType &newItem)
{

	auto pushNode = std::make_shared<Node<ItemType>>(newItem, headPtr);
	headPtr = pushNode;
	currentSize++;

	return true;
} // end push

// TODO: Implement the peek method here
template <class ItemType>
ItemType Stack<ItemType>::peek() const
{
	if (currentSize > 0)
	{
		return headPtr->getItem();
	}
	else{
		throw(std::logic_error("cant be empty"));
	}
}

// TODO: Implement the pop method here
template <class ItemType>
bool Stack<ItemType>::pop()
{
	if (currentSize != 0)
	{
		std::shared_ptr<Node<ItemType>> tempPtr = headPtr;
		headPtr = headPtr->getNext();
		currentSize--;
		// delete temppointer->getNext();

		return true;
	}
	else
	{
		return false;
	}

} // end pop

// TODO: Implement the clear method here
template <class ItemType>
void Stack<ItemType>::clear()
{
	if (currentSize == 0)
	{
		return;
	}
	else
	{
		while (currentSize != 0)
		{
			pop();
		}
	}

} // end clear
