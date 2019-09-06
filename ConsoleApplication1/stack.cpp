
/******************************************************************************
*
* @file     stack.cpp
* @brief    Bit manipulation functions
* @version  V1.00
* @date     16, February 2017
*
* @note
*
******************************************************************************/


/*----------------------------------------------------------------------------
*
* Place #include files required to compile this source file here.
*
*----------------------------------------------------------------------------*/
#include "System.h"
#include "Stack.h"


/*----------------------------------------------------------------------------
*
* Place function prototypes that will be used only by this file here.
* This section need only include "forward referenced" functions.
*
*----------------------------------------------------------------------------*/
// function for stack using a known size stack.
void Push(int);
void Pop();
int Top();
void print();
bool isEmpty();
// functions for Linked listed stack
void Push(Node**,int);
void Pop(Node**);
bool isEmpty(Node*);
int Top(Node*);
void printList(Node* head);
/*----------------------------------------------------------------------------
*
* Place #define constants and macros that will be used only by this
* source file here.
*
*----------------------------------------------------------------------------*/

#define MAX_SIZE 100

/*----------------------------------------------------------------------------
*
* Define global variables that will be used by both this source file
* and by other source files here.
*	must add extern on System.h
*----------------------------------------------------------------------------*/

int A[MAX_SIZE];
int top = -1;
struct stack {
};
/*----------------------------------------------------------------------------
*
* Place typedefs, structs, unions, and enums that will be used only
* by this source file here.
*
*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
*
* Place static variables that will be used only by this file here.
*
*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------
*
* Place function bodies here.
*
*----------------------------------------------------------------------------*/

void Push(int val) {
	if (top == MAX_SIZE - 1) {
		std::cout << "Max Size of Stack\n";
		return;
	}
	A[++top] = val;
}
// Push using Linked List below
void Push(Node** pointerToHead, int data) {
	struct Node* temp = new Node();
	temp->data = data;
	temp->next = *pointerToHead;
	*pointerToHead = temp;
}
void Pop() {
	if (isEmpty()) {
		std::cout << "Stack already empty\n"; return;
	}
	top--;
}
// Pop using Linked List below
void Pop(Node** pointerToHead) {
	if (*pointerToHead == NULL) {
		std::cout << "Stack already empty\n"; return;
	}
	Node* temp = *pointerToHead;
	(*pointerToHead) = temp->next;
	delete temp;
}
// getting Top of a node
int Top(Node* head) {
	return head->data;
}
int Top() {
	return A[top];
}
bool isEmpty(Node* head) {
	return (head == NULL) ? true : false;
}
bool isEmpty() {
	return (top == -1) ? true:false;
}

void print() {
	for (int i = 0; i <= top;i++) {
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
}
// Link llist way of printing
void printList(Node* head) {
	Node* temp = head;
	printf("The list is: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int stackLoop() {
	Node* head = NULL;
	Push(&head,2); print(head);
	Push(&head, 8); print(head);
	Push(&head, 10); print(head);
	Pop(&head); print(head);
	Push(&head, 5); print(head);
	system("pause");
	return 0;
}

