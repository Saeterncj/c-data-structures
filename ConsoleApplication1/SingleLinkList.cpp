#include "SingleLinkList.h"

int singleLinkedList() {
	Node* head = NULL;
	//userInputLink(&head);
	insert(&head, 5); // Assumes that position is a valid position to enter!!!
	insert(&head, 7,2);
	userInputLink(&head);
	printReverseRecursion(head);
	printf("\n");
	Delete(&head, 2);
	printForwardRecursion(head);
	reverseOrder(&head);
	print(head); 
	reverseOrderRecursion(&head, head);
	print(head);
	system("pause");
	return 0;
}

void printForwardRecursion(Node *temp) {
	//Node* temp = head;
	if (temp == NULL) { printf("\n");return; }
	printf("%d ", (*temp).data );
	printForwardRecursion(temp->next);;
}
void printReverseRecursion(Node *temp) {
	if (temp == NULL) {;return; }
	printReverseRecursion(temp->next);;
	printf("%d ", temp->data);
}
void print(Node* head) {
	Node* temp = head;
	printf("The list is:");
	
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}

	printf("\n");
}
void insert(Node** pointerToHead, int data) {
	struct Node* temp = new Node();
	temp->data = data;
	temp->next = NULL;
	if (*pointerToHead != NULL) temp->next = *pointerToHead;
	*pointerToHead = temp;
}
void insert(Node** pointerToHead, int data, int position) {
	struct Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;
	if (position == 1) {
		temp1->next = *pointerToHead;
		*pointerToHead = temp1;
		return;
	}
	struct Node* temp2 = *pointerToHead;
	for (int i = 0; i < position - 2;i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}
void Delete(Node** pointerToHead, int position) {
	struct Node* temp1 = *pointerToHead;
	if (position == 1) {
		(*pointerToHead) = temp1->next;
		delete(temp1);
		return;
	}
	for (int i = 0; i < position - 2; i++) {
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2);
}
void reverseOrder(Node ** pointerToHead) {
	struct Node* prev = NULL;
	struct Node* current = *pointerToHead;
	//struct Node* next;
	while (current != NULL) {
		*pointerToHead = current->next;
		current->next = prev;
		prev = current;
		current = (*pointerToHead);

	}
	*pointerToHead = prev;
	//delete()
}
/*
This function reverses the order of the linkedlist
*/
void reverseOrderRecursion(Node ** pointerToHead, Node* p) {
	if (p->next == NULL) { *pointerToHead = p; return; }
	reverseOrderRecursion(pointerToHead, p->next);
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
}

void userInputLink(Node** head) {
	int x, inData;
	printf("Enter the number for list\n");
	scanf("%d",&x);
	for (int i = 0; i < x; i++) {
		printf("Enter the number you want to add to list.\n");
		scanf("%d", &inData);
		insert(head, inData);
		print(*head);
	}
}