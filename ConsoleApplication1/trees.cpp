
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
#include "Trees.h"
#include <algorithm>
#include <queue>
/*----------------------------------------------------------------------------
*
* Place function prototypes that will be used only by this file here.
* This section need only include "forward referenced" functions.
*
*----------------------------------------------------------------------------*/
BstNode* GetNewNode(int data);
void Insert(BstNode** root, int data);
bool Search(BstNode* root, int data);
int findMin(BstNode * root);
int findMax(BstNode * root);
int findHeight(BstNode * root);
void LevelOrder(BstNode *root);
void Preorder(BstNode *root);
void Postorder(BstNode *root);
void Inorder(BstNode *root);
bool isBstUtil(BstNode *root, int minValue, int maxValue);
bool isBinarySearchTree(BstNode *root);
void Delete(BstNode **root, int data);
/*----------------------------------------------------------------------------
*
* Place #define constants and macros that will be used only by this
* source file here.
*
*----------------------------------------------------------------------------*/
#define MIN_VAL -100000
#define MAX_VAL 100000
/*----------------------------------------------------------------------------
*
* Define global variables that will be used by both this source file
* and by other source files here.
*	must add extern on System.h
*----------------------------------------------------------------------------*/


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

// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it 

//Definition of Node for Binary search tree

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}
// To insert data in BST, returns address of root node 
void Insert(BstNode** root, int data) {
	if (*root == NULL) { // empty tree
		*root = GetNewNode(data);
	}
	// if data to be inserted is lesser, insert in left subtree. 
	else if (data <= (*root)->data) {
		Insert(&(*root)->left, data);
	}
	// else, insert in right subtree. 
	else {
		Insert(&(*root)->right, data);
	}
}

//To search an element in BST, returns true if element is found
bool Search(BstNode* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}

//Find minimum value in binary search tree using recursion
int findMin(BstNode * root) {
	if (root == NULL) {
		cout << "ERROR: The root is empty\n";
		return -1;
	}
	else if (root->left == NULL) {
		return root->data;
	}
	findMin(root->left);
}

//find maximum value in binary search tree using nonrecursion
int findMax(BstNode * root) {
	if (root == NULL) {
		cout << "ERROR: The root is empty\n";
		return -1;
	}
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

//find height of the tree
int findHeight(BstNode * root) {
	int leftHeight,rightHeight;
	if (root == NULL) {
		return -1;
	}
	leftHeight = findHeight(root->left);
	rightHeight = findHeight(root->right);
	return max(leftHeight, rightHeight) + 1;
	//find height of left, find height of right
	
}

// Function to print Nodes in a binary tree in Level order
void LevelOrder(BstNode *root) {
	if (root == NULL) return;
	queue<BstNode*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while (!Q.empty()) {
		BstNode* current = Q.front();
		Q.pop(); // removing the element at front
		cout << current->data << " ";
		if (current->left != NULL) Q.push(current->left);
		if (current->right != NULL) Q.push(current->right);
	}
}

//Function to visit nodes in Preorder
void Preorder(struct BstNode *root) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if (root == NULL) return;

	printf("%d ", root->data); // Print data
	Preorder(root->left);     // Visit left subtree
	Preorder(root->right);    // Visit right subtree
}

//Function to visit nodes in Inorder
void Inorder(BstNode *root) {
	if (root == NULL) return;

	Inorder(root->left);       //Visit left subtree
	printf("%d ", root->data);  //Print data
	Inorder(root->right);      // Visit right subtree
}

//Function to visit nodes in Postorder
void Postorder(BstNode *root) {
	if (root == NULL) return;

	Postorder(root->left);    // Visit left subtree
	Postorder(root->right);   // Visit right subtree
	printf("%d ", root->data); // Print data
}

// 
bool isBstUtil(BstNode *root, int minValue, int maxValue) {
	if (root == NULL) return true;
	if (root->data > minValue && root->data < maxValue
		&& isBstUtil(root->left, minValue, root->data)
		&& isBstUtil(root->right, root->data, maxValue)
		)
		return true;
	else
		return false;
}

bool isBinarySearchTree(BstNode *root) {
	return isBstUtil(root, MIN_VAL, MAX_VAL);
}

//Function to find minimum in a tree. 
BstNode* FindMin(BstNode* root)
{
	while (root->left != NULL) root = root->left;
	return root;
}

// Function to search a delete a value from tree.
void Delete(BstNode **root, int data) {
	if (root == NULL) return;
	else if (data < (*root)->data) Delete(&(*root)->left, data);
	else if (data >(*root)->data) Delete(&(*root)->right, data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if ((*root)->left == NULL && (*root)->right == NULL) {
			delete *root;
			*root = NULL;
		}
		//Case 2: One child 
		else if ((*root)->left == NULL) {
			struct BstNode *temp = *root;
			*root = (*root)->right;
			delete temp;
		}
		else if ((*root)->right == NULL) {
			struct BstNode *temp = (*root);
			*root = (*root)->left;
			delete temp;
		}
		// case 3: 2 children
		else {
			struct BstNode *temp = FindMin((*root)->right);
			(*root)->data = temp->data;
			Delete(&(*root)->right, temp->data);
		}
	}
	//return root;
}

//Function to find some data in the tree
BstNode* Find(BstNode*root, int data) {
	if (root == NULL) return NULL;
	else if (root->data == data) return root;
	else if (root->data < data) return Find(root->right, data);
	else return Find(root->left, data);
}

//Function to find Inorder Successor in a BST.
BstNode* Getsuccessor(BstNode* root, int data) {
	// Search the Node - O(h)
	BstNode* current = Find(root, data);
	if (current == NULL) return NULL;
	if (current->right != NULL) {  //Case 1: Node has right subtree
		return FindMin(current->right); // O(h)
	}
	else {   //Case 2: No right subtree  - O(h)
		BstNode* successor = NULL;
		BstNode* ancestor = root;
		while (ancestor != current) {
			if (current->data < ancestor->data) {
				successor = ancestor; // so far this is the deepest node for which current node is in left
				ancestor = ancestor->left;
			}
			else
				ancestor = ancestor->right;
		}
		return successor;
	}
}
int treesLoop() {
	BstNode* root = NULL;  // Creating an empty tree
						   /*Code to test the logic*/
	Insert(&root, 18);
	Insert(&root, 10);
	Insert(&root, 20);
	Insert(&root, 25);
	Insert(&root, 14);
	Insert(&root, 16);
	Insert(&root, 17);
	Insert(&root, 15);
	Insert(&root, 12);
	Insert(&root, 11);
	Insert(&root, 13);
	Insert(&root, 8);
	Insert(&root, 6);
	Insert(&root, 4);
	Insert(&root, 2);
	cout << "The max is " << findMax(root) << " and the min is " << findMin(root)<<"\n";
	cout << "The height of the tree is " << findHeight(root) << "\n";
	Delete(&root, 12);
	cout << "Level Order: ";
	LevelOrder(root);
	cout << "\n";
	cout << "PreOrder: ";
	Preorder(root);
	cout << "\n";
	cout << "InOrder: ";
	Inorder(root);
	cout << "\n";
	cout << "PostOrder: ";
	Postorder(root);
	cout << "\nIs the tree a binary search tree?";
	cout << (isBinarySearchTree(root) ? " YES\n": " NO\n");
	int number = -1;
	while (number > 0) {
		cout << "Enter number be searched\n";
		cin >> number;
		if (Search(root, number) == true) cout << "Found\n";
		else cout << "Not Found\n";
	}
	int data = 7;
	BstNode *successor = Getsuccessor(root, data);
	if (successor == NULL)
		cout << "There is no successor found\n";
	else
		cout << "The successor of " << data << " is: " << successor->data << "\n";
	return 0;
}