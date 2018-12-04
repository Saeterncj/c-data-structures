/* ----------------------------------------------------------------------------
@ file: Stack.h
Date Created: 2-14-17
Purpose: Header file for stack.c file.  Define functions, variables in this file
---------------------------------------------------------------------------- */
#ifndef SingleLinkList_h_
#define SingleLinkList_h_
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

void print(Node*);					// print list
void printForwardRecursion(Node*);	// print  list using recursion
void printReverseRecursion(Node*);	// print list reverse order using recursion
void Delete(Node**, int);			// delete a Node at nth position
void insert(Node**, int);			// insert a data in the beginning
void insert(Node**, int, int);		// insert node with data at nth position
void reverseOrder(Node **);			// reverse order of the list
void reverseOrderRecursion(Node **, Node*);// reveres order of the list using recursion
void userInputLink(Node**);			// User inputs Own list
int singleLinkedList();
/*----------------------------------------------------------------------------
*
* End of file.
*
*----------------------------------------------------------------------------*/

#endif