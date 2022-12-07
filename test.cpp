#include <iostream>
using namespace std;


int main() {

	int whole;
	int tmp = 0;
	int book[9];

	cin >> whole;


	for (int i = 0; i < 9; i++) {
		cin>>book[i];
	}

	for (int j = 0; j < 9; j++) {
		tmp += book[j];
	}
	cout << whole - tmp;


}
