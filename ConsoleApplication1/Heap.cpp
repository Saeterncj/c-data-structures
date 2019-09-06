/// C file layout

/******************************************************************************
*
* @file     Heap.cpp
* @brief    Bit manipulation functions
* @version  V1.00
* @date     26, March 2016
* @note
*
******************************************************************************/


/*----------------------------------------------------------------------------
*
* Place #include files required to compile this source file here.
*
*----------------------------------------------------------------------------*/
#include "Heap.h"
/*----------------------------------------------------------------------------
*
* Place function prototypes that will be used only by this file here.
* This section need only include "forward referenced" functions.
*
*----------------------------------------------------------------------------*/

void removeMaxHeap(vector<int> &v1, int val);
void removeMinHeap(vector<int> &v1, int val);
void printVect(vector <int> vect);
/*----------------------------------------------------------------------------
*
* Define global variables that will be used by both this source file
* and by other source files here.
*
*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
*
* Place #define constants and macros that will be used only by this
* source file here.
*
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

void heapLoop() {
	// Initializing a vector 
	vector<int> v1 = { 1,9,22,4,11,45,667,87,17,11,33,27,21,19,12,13,35,36,30,28,24,5,76,5,34,5,};

	// Converting vector into a heap 
	// using make_heap() 
	make_heap(v1.begin(), v1.end(),greater<int>());

	// Displaying heap elements  

	//v1.push_back(45);
	//push_heap(v1.begin(), v1.end(),greater<int>());



	//v1.push_back(22);
	//push_heap(v1.begin(), v1.end(),greater<int>());


	//pop_heap(v1.begin(), v1.end(), greater<int>());  v1.pop_back();

	cout << "The heap elementss : ";
	printVect(v1);

	//removing a certain element?
	//v1.back() = 10;
	removeMinHeap(v1, 1);v1.pop_back();
	removeMinHeap(v1, v1[3]);v1.pop_back();
	removeMinHeap(v1, v1[13]);v1.pop_back();
	removeMinHeap(v1, v1[5]);v1.pop_back();
	removeMinHeap(v1, v1[4]);v1.pop_back();
	removeMinHeap(v1, v1[3]);v1.pop_back();
	removeMinHeap(v1, v1[3]);v1.pop_back();
	removeMinHeap(v1, v1[3]);v1.pop_back();

	v1.pop_back();
	cout << "The heap elements after popping : ";
	printVect(v1);
	//remove(v1, 26);
	if (!std::is_heap(v1.begin(), v1.end(), greater<int>()))
		cout << "Theres an error!!!\n";
	else
		cout << "Heap is OKAY!\n";
	// sorting heap using sort_heap() 
	//sort_heap(v1.begin(), v1.end());
	// Displaying heap elements  
	cout << "\n\nThe heap elements after sorting are : ";
	for (int &x : v1)
		cout << x << " ";
}

void printVect(vector <int> vect) {
	for (auto i : vect) {
		cout << i << " ";
	}cout << "\n";
}

void removeMaxHeap(vector<int> &v1, int val) {
	vector<int>::iterator it = find(v1.begin(), v1.end(), val);
	if (it == v1.begin()) { return; }
	if (it == v1.end()) {
		//cout << "The " << val << " does not belong in the maxHeap\n";
	}
	else {
		//cout << "REmoving " << val << " in the maxHeap\n";
		int pos = it - v1.begin();
		int last = v1.size() - 1;
		if (pos == last) {
			return;
		}
		else if (v1[pos] == v1[last]) {
			return;
		}
		swap(v1[pos], v1[last]);
		int p = (pos - 1) / 2;
		int l = pos * 2 + 1;
		int r = pos * 2 + 2;
		while (v1[pos] > v1[p]) {
			swap(v1[pos], v1[p]);
			pos = p;
			p = (pos - 1) / 2;
		}
		while (l <= last || r <= last) {
			// int biggerChild = max(v1[l], v1[r]);
			bool leftNodeExist, rightNodeExist;
			leftNodeExist = (l > last-1) ? false : true;
			rightNodeExist = (r > last-1) ? false : true;
			if (leftNodeExist&& v1[pos] < v1[l] && v1[l] >= v1[r]) {
				swap(v1[pos], v1[l]);
				pos = l;
			}
			else if (rightNodeExist && v1[pos] < v1[r]) {
				swap(v1[pos], v1[r]);
				pos = r;
			}
			else {
				break;
			}
			r = pos * 2 + 2;
			l = pos * 2 + 1;
		}
	}
}
void removeMinHeap(vector<int> &v1, int val) {
	vector<int>::iterator it = find(v1.begin(), v1.end(), val);
	if (it == v1.end()) {
		//cout << "The " << val << " does not belong in the minHeap\n";
	}
	else {
		// cout << "Its in the heap\n";
		//cout << "REmoving " << val << " in the minHeap\n";
		int pos = it - v1.begin();
		int last = v1.size() - 1;
		if (pos == last) {
			return;
		}
		else if (v1[pos] == v1[last]) {
			return;
		}
		swap(v1[pos], v1[last]);
		int p = (pos - 1) / 2;
		int l = pos * 2 + 1;
		int r = pos * 2 + 2;
		while (v1[pos] < v1[p]) {
			swap(v1[pos], v1[p]);
			pos = p;
			p = (pos - 1) / 2;
			l = pos * 2 + 1;
			r = pos * 2 + 2;
			//if(pos == 0) break;
		}
		while (l <= last || r <= last) {
			// int biggerChild = max(v1[l], v1[r]);
			bool leftNodeExist, rightNodeExist;
			leftNodeExist = (l > last-1) ? false : true;
			rightNodeExist = (r > last-1) ? false : true;
			if (leftNodeExist && v1[pos] > v1[l] && v1[l] <= v1[r]) {
				swap(v1[pos], v1[l]);
				pos = l;
			}
			else if (rightNodeExist && v1[pos] > v1[r]) {
				swap(v1[pos], v1[r]);
				pos = r;
			}
			else {
				break;
			}
			r = pos * 2 + 2;
			l = pos * 2 + 1;
		}
	}
}