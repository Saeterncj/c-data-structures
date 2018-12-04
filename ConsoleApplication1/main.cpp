
#include "System.h";
#include <string>
#include <vector>
string gString = "Remove the Last three";

void removeString(string myString) {
	if (myString.length() == 3) {
		cout << "\n";
		return;
	}
	cout << myString.front();
	myString.erase(myString.begin());
	removeString(myString);
	//return;
}
string writeSequence(int i) {
	int val;
	string toCC,temp;
	if (i == 1) {
		return "1";
	}
	else if (i == 2) {
		return "1 1";
	}
	val = (i + 1)/2;
	toCC = to_string(val);
	temp = writeSequence(i - 2);
	temp = toCC + " " + temp + " " + toCC;
	return temp;
	
}
#define MAX 10000
bool isPrime[MAX + 1];
vector<int> prime;

void SieveOfEratosthenes() {
	memset(isPrime, true, sizeof(isPrime));

	isPrime[1] = false;

	for (int p = 2; p * p <= MAX; p++) {

		// If prime[p] is not changed, then it is a prime
		if (isPrime[p] == true) {

			// Set all multiples of p to non-prime
			for (int i = p * 2; i <= MAX; i += p)
				isPrime[i] = false;
		}
	}
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			prime.push_back(i);
			//cout << i << " ";
		}
	}
}

int main() {
	//singleLinkedList();
	//DoubleLinkedList();
	//stackLoop();
	//queueLoop();
	//treesLoop();
	//use recurion on removing the last 3 strings
	//removeString(gString);
	//cout << writeSequence(8);
	//cout << endl;
	SieveOfEratosthenes();
	for (int i = 0; i < 10;i++) {
		cout << prime.size() << " ";
	}
	//gString.erase(gString.begin());
	//cout << gString;
	//cout << myNewString <<"\n";
	system("pause");
	return 0; 	
}

