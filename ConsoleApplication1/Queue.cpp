/* Queue - Circular Array implementation in C++*/
//#include<iostream>

#include "Queue.h"

/*Queue - Linked List implementation*/

// Two glboal variables to store address of front and rear nodes. 
struct Node* front = NULL;
struct Node* rear = NULL;
// To Enqueue an integer
void Enqueue(int x) {
	struct Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

// To Dequeue an integer.
void Dequeue() {
	Node* temp = front;
	if (front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	delete temp;
}
// To see whats in front
int Front() {
	if (front == NULL) {
		printf("Queue is empty\n");
		return -1;
	}
	return front->data;
}

void Print() {
	struct Node* temp = front;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int queueLoop()
{
	/*
		Note that there is a standard c++ library for queue
	*/
	Queue Q; // creating an instance of Queue. 
	Q.Enqueue(2);  Q.Print();
	Q.Enqueue(4);  Q.Print();
	Q.Enqueue(6);  Q.Print();
	Q.Dequeue();	Q.Print();
	Q.Enqueue(8);  Q.Print();

	// Queue using LinkedList instead of Array.
	Enqueue(2); Print();
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();
	return 0;
}

