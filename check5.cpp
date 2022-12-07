#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int, int>> v;



int main() {
	
	int n;

	cin >> n;


	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back(make_pair(b,a));

	}
	sort(v.begin(), v.end());

	int count = 1;
	int tmp = v.at(0).first; //끝나는 시간으로 정렬했으므로

	
	for (int i = 1; i < n; i++) {
		if (tmp <= v.at(i).second) {
			tmp = v.at(i).first;
			count++;
		}
		else continue;
	
	}
	

	cout << count;


	return 0;

}