#include <iostream>
#include <cstddef>
#include "Stack.hpp"
#include "Node.hpp"

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
	clear(); // clear deals with memory
	//delete headPtr;

} // end destructor

// TODO: Implement the isEmpty method here
template <class ItemType>
bool Stack<ItemType>::isEmpty() const
{
	if (currentSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
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

	Node<ItemType> *pushNode = new Node<ItemType>(newItem);
	if (pushNode == nullptr)
	{
		return false; // Memory allocation failed
	}

	if (headPtr == nullptr)
	{
		// If the stack is empty, set pushNode as the new head
		headPtr = pushNode;
	}
	else
	{
		// If the stack is not empty, set the next pointer of pushNode to the current top of the stack
		pushNode->setNext(headPtr);
		// Update headPtr to point to pushNode
		headPtr = pushNode;
	}

	currentSize++;

	return true;
} // end push

// TODO: Implement the peek method here
template <class ItemType>
ItemType Stack<ItemType>::peek() const
{

	if (currentSize > 0)
	{
		ItemType returnItem;

		Node<ItemType> *peekNode = headPtr;

		returnItem = peekNode->getItem();

		return returnItem;
	}
	else
	{
		throw 505;
		exit(EXIT_FAILURE);
	}

} // end peek

// TODO: Implement the pop method here
template <class ItemType>
bool Stack<ItemType>::pop()
{
	if (currentSize != 0)
	{
		Node<ItemType> *tempPtr = headPtr;
		headPtr = headPtr->getNext();
		currentSize--;
		// delete temppointer->getNext();
		delete tempPtr;
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
