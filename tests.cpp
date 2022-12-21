#include <iostream>
using namespace std;
#define INF 1000000001;
typedef long long ll;

int n, m;
int base_idx = 1;

ll treeMin[1024 * 1024 * 2 + 1];
ll treeMax[1024 * 1024 * 2 + 1];


ll fnMin(int a,int b) {
	a += (base_idx - 1);
	b += (base_idx - 1);
	ll Min = INF;
	while (a <= b) {
		if ((a % 2) == 1) Min = min(Min, treeMin[a]);
		if ((b % 2) == 0) Min = min(Min, treeMin[b]);

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return Min;
}

ll fnMax(int a,int b) {
	a += (base_idx - 1);
	b += (base_idx - 1);
	ll Max = 0;
	while (a <= b) {
		if ((a % 2) == 1) Max = max(Max, treeMax[a]);
		if ((b % 2) == 0) Max = max(Max, treeMax[b]);

		a = (a + 1) / 2;
		b = (b - 1) / 2;
	}
	return Max;
}


void initTree() {
	for (int i = base_idx - 1; i > 0; i--) {	// 何葛飘府 积己窍扁
		treeMin[i] = min(treeMin[i * 2], treeMin[(i * 2) + 1]);
	}
	for (int i = base_idx - 1; i > 0; i--) {
		treeMax[i] = max(treeMax[i * 2], treeMax[(i * 2) + 1]);
	}
}


int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	while (base_idx < n) {
		base_idx *= 2;
	}

	int tmp;
	for (int i = 0; i < n; i++) {
		
		cin >> tmp;
		treeMin[base_idx + i] = treeMax[base_idx + i] = tmp;
		
	}
	initTree();


	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << fnMin(a, b) << ' ' << fnMax(a, b) << '\n';
	}



	
	

	return 0;
}