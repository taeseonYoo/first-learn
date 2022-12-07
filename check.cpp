#include <iostream>
using namespace std;

int main() {


	int out[10000];
	int in[10000];
	int tmp[10000];


	for (int i = 0; i < 10; i++) {
		cin >> out[i] >> in[i];
	}

	for (int j = 0; j < 10; j++) {
		if (j != 0) {
			tmp[j] = tmp[j - 1] - out[j] + in[j];
		}
		else tmp[j] = in[j];

	}
	int max = tmp[0];
	for (int k = 0; k < 10; k++) {
		if (max < tmp[k]) max = tmp[k];

	}
	cout << max;





	return 0;

}