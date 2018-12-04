#pragma once
/* ----------------------------------------------------------------------------
@ file: Stack.h
Date Created: 2-14-17
Purpose: Header file for stack.c file.  Define functions, variables in this file
---------------------------------------------------------------------------- */
#ifndef DoubleLinkedList_h_
#define DoubleLinkedList_h_
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

/*----------------------------------------------------------------------------
*
* Place typedefs, structs, unions, and enums that need to be seen by
* multiple source files here.
*
*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
*
* Place global variables that are used by multiple source files here.
*
*----------------------------------------------------------------------------*/
extern struct Node; 

/*----------------------------------------------------------------------------
*
* Place function prototypes that need to be seen by multiple source files here.
*
*----------------------------------------------------------------------------*/
// ReturnedDataType functionName(ParametersDataType)

/*
The following are for SingleLinkList.c
*/

int DoubleLinkedList();

extern void print(Node*);					// print list
extern void printForwardRecursion(Node*);	// print  list using recursion
extern void printReverseRecursion(Node*);	// print list reverse order using recursion
extern void Delete(Node**, int);			// delete a Node at nth position
extern void insert(Node**, int);			// insert a data in the beginning
extern void insert(Node**, int, int);		// insert node with data at nth position
extern void reverseOrder(Node **);			// reverse order of the list
extern void reverseOrderRecursion(Node **, Node*);// reveres order of the list using recursion
extern void userInputLink(Node**);			// User inputs Own list
Node* getNewNode(int);
void InsertAtHead(Node**, int);
void InsertAtTail(Node**, int);
void printReverse(Node*);



/*----------------------------------------------------------------------------
*
* End of file.
*
*----------------------------------------------------------------------------*/

#endif