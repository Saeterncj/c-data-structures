#include "DoubleLinkedList.h"



Node* getNewNode(int data) {
	Node* temp = new Node();
	temp->next = NULL;
	temp->prev = NULL;
	temp->data = data;
	return temp;
}
void InsertAtHead(Node** head,int data) {
	struct Node* newNode = getNewNode(data);
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
	
}
void InsertAtTail(Node** head, int data) {
	Node* newNode = getNewNode(data);
	Node* tempHead = *head;
	if (*head == NULL) {
		*head = newNode; return;
	} 
	while (tempHead->next != NULL) {
		tempHead = tempHead->next;
	}
	newNode->prev = tempHead;
	tempHead->next = newNode;
}

int DoubleLinkedList() {
	Node* head = NULL;
	InsertAtHead(&head, 1);
	InsertAtHead(&head, 5);
	InsertAtHead(&head, 9);
	InsertAtTail(&head, 7);
	//insert(&head, 9, 2);
	print(head);
	printReverse(head);
	//std::cout << "hellow World\n";
	system("pause");
	return 0;
}

void printReverse(Node* head) {
	Node* temp = head;
	if (temp == NULL)return;
	// Traverse our linklist to the end 
	while (temp->next != NULL) {
		temp = temp->next;
	}
	printf("The reverse list is:");
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->prev;
	}
	printf("\n");
}
//InsertAtHead();
//InsertAtTail();