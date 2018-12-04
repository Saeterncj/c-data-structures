#pragma once
/* ----------------------------------------------------------------------------
@ file: System.h
Date Created: 2-14-17
Purpose: Header file for the whole system. For anything that will be used
in multiple files should be here.
---------------------------------------------------------------------------- */

#ifndef System_h_
#define System_h_
/* ----------------------------------------------------------------------------
defining essential stuff
---------------------------------------------------------------------------- */
using namespace std;

/* ----------------------------------------------------------------------------
Place global variables here
---------------------------------------------------------------------------- */
// uint8_t MAZE[MaxNumOfRows][MaxNumOfRows] = { 0 };

/*----------------------------------------------------------------------------
*
* Include any additional header files that are needed to compile this
* header file here.
*
*----------------------------------------------------------------------------*/
#include <iostream>
#include "SingleLinkList.h"
#include "DoubleLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Trees.h"
/*-----------------------------------------------------------------------------
Meaningful name that describes what is about to follow
-----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
*
* Place #define constants and macros that are required for this header
* file or that need to be seen by more than one source file here.
*
*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
*
* Place typedefs, structs, unions, and enums that need to be seen by
* multiple source files here.
*
*----------------------------------------------------------------------------*/
struct Node {
	int data;
	Node* next;
	Node* prev;
};

/*----------------------------------------------------------------------------
*
* Place global variables that are used by multiple source files here.
*
*----------------------------------------------------------------------------*/
// extern 
/*----------------------------------------------------------------------------
*
* Place function prototypes that need to be seen by multiple source files here.
*
*----------------------------------------------------------------------------*/

// ReturnedDataType functionName(ParametersDataType)

/*----------------------------------------------------------------------------
*
* End of file.
*
*----------------------------------------------------------------------------*/
#endif