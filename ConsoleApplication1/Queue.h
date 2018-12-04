/* ----------------------------------------------------------------------------
@ file: Stack.h
Date Created: 2-14-17
Purpose: Header file for stack.c file.  Define functions, variables in this file
---------------------------------------------------------------------------- */
#ifndef Queue_h_
#define Queue_h_
/*----------------------------------------------------------------------------
*
* Include any additional header files that are needed to compile this
* header file here.
*
*----------------------------------------------------------------------------*/

#include "System.h"
/*-----------------------------------------------------------------------------
Meaningful name that describes what is about to follow
-----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
*
* Place #define constants and macros that are required for this header
* file or that need to be seen by more than one source file here.
*
*----------------------------------------------------------------------------*/

//#define STACK_MAX_SIZE 1000
#define MAX_SIZE 101 //maximum size of the array that will store Queue. 
/*----------------------------------------------------------------------------
*
* Place typedefs, structs, unions, and enums that need to be seen by
* multiple source files here.
*
*----------------------------------------------------------------------------*/
// Creating a class named Queue.
class Queue
{
private:
	int A[MAX_SIZE];
	int front, rear;
public:
	// Constructor - set front and rear as -1. 
	// We are assuming that for an empty Queue, both front and rear will be -1.
	Queue()
	{
		front = -1;
		rear = -1;
	}

	// To check wheter Queue is empty or not
	bool IsEmpty()
	{
		return (front == -1 && rear == -1);
	}

	// To check whether Queue is full or not
	bool IsFull()
	{
		return (rear + 1) % MAX_SIZE == front ? true : false;
	}

	// Inserts an element in queue at rear end
	void Enqueue(int x)
	{
		cout << "Enqueuing " << x << " \n";
		if (IsFull())
		{
			cout << "Error: Queue is Full\n";
			return;
		}
		if (IsEmpty())
		{
			front = rear = 0;
		}
		else
		{
			rear = (rear + 1) % MAX_SIZE;
		}
		A[rear] = x;
	}

	// Removes an element in Queue from front end. 
	void Dequeue()
	{
		cout << "Dequeuing \n";
		if (IsEmpty())
		{
			cout << "Error: Queue is Empty\n";
			return;
		}
		else if (front == rear)
		{
			rear = front = -1;
		}
		else
		{
			front = (front + 1) % MAX_SIZE;
		}
	}
	// Returns element at front of queue. 
	int Front()
	{
		if (front == -1)
		{
			cout << "Error: cannot return front from empty queue\n";
			return -1;
		}
		return A[front];
	}
	/*
	Printing the elements in queue from front to rear.
	This function is only to test the code.
	This is not a standard function for Queue implementation.
	*/
	void Print()
	{
		// Finding number of elements in queue  
		int count = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
		cout << "Queue       : ";
		for (int i = 0; i <count; i++)
		{
			int index = (front + i) % MAX_SIZE; // Index of element while travesing circularly from front
			cout << A[index] << " ";
		}
		cout << "\n\n";
	}
};
/*----------------------------------------------------------------------------
*
* Place global variables that are used by multiple source files here.
*
*----------------------------------------------------------------------------*/
//extern struct Node;
/*----------------------------------------------------------------------------
*
* Place function prototypes that need to be seen by multiple source files here.
*
*----------------------------------------------------------------------------*/
// ReturnedDataType functionName(ParametersDataType)

/*
The following are for SingleLinkList.c
*/


int queueLoop();
/*----------------------------------------------------------------------------
*
* End of file.
*
*----------------------------------------------------------------------------*/

#endif