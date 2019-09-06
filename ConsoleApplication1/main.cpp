
#include "System.h";
//#include <string>
//#include <vector>
#include <string>

// set::lower_bound/upper_bound
#include <iostream>
#include <set>

bool resolution(vector <string> ref, vector<string> prov) {
	int refS = ref.size();
	int provs = prov.size();
	int j = 0;
	bool flag = false;
	for (int i(0); i < provs; i++) {
		if (flag && j ==refS-1 || flag && prov[i] != ref[j] ) {
			return false;
		}
		else {
			if(j < refS-1)j++;
			while (prov[i] != ref[j] && i < provs) {
				i++;
				flag = true;
			}
		}	
	}
	return true;
}
int main()
{
	vector<string> ref = { "he", "is", "a", "star" };
	vector<string> prov = {"he", "is", "a", "super","star", "star"};
	if (resolution(ref, prov)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	getchar();
	return 0;
}
/*
int main() {
	//singleLinkedList();
	//DoubleLinkedList();
	//stackLoop();
	//queueLoop();
	//treesLoop();
	//heapLoop();
	//graphLoop();
	/*
	vector<int> vect1 = { 1,2,3,4,5,6,7,8 };
	int d = 5;
	vector<int> vect2(vect1.begin(), vect1.begin() + d/2);
	vector<int> vect3(vect1.begin()+d/2, vect1.begin() + d);
	for (auto i : vect1) {
		cout << i << " ";
	}cout << endl;
	for (auto i : vect2) {
		cout << i << " ";
	}cout << endl;
	for (auto i : vect3) {
		cout << i << " ";
	}cout << endl;

	vector<int> sj;
	cout << sj.size() << endl;
	*/
	/*
	unordered_set<int> comp;
	auto it = comp.find(5);
	if (it != comp.end()) {
		cout << "Im found";
	}
	else
		cout << "Im not found";
		
	system("pause");
	return 0; 	
}
*/


