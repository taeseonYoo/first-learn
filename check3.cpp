#include <iostream>
#include <vector>
using namespace std;
const int INF = 500005;

int map[101][101];
int dist[101][101];


int main() {


	int N; //유저의 수 
	int M; // 친구 관계의 수


	cin >> N>>M;


	for (int i = 0; i < M; i++) { // 친구 관계를 입력받는다. 

		int a, b;

		cin >> a >> b;
		
		map[a][b] = 1;
		map[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) dist[i][j] = 0;
			else if (map[i][j]) dist[i][j] = map[i][j];
			else dist[i][j] = INF;

		}
	}

	
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}

		}
	}

	int max = INF;
	int maxIndex;

	for (int i = 1; i <= N; i++) {
		int hap = 0;
		for (int j = 1; j <= N; j++) {
			hap += dist[i][j]; 
		}
		if (max > hap) {
			max = hap;
			maxIndex = i;
		}
	
	}
	cout << maxIndex;
















	return 0;
}