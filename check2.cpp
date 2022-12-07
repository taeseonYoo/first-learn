#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 30000000;

vector<pair<pair<int,int>,int>> v;

int main() {

	cin.tie(NULL); 
	cout.tie(NULL); 
	ios_base::sync_with_stdio(false);

	int TC;
	cin >> TC;


	while (TC--) {

		int N, M, W;
		cin >> N >> M >> W;

		v.clear();

		int S, E, T;

		pair<pair<int, int>, int> p;

		for (int i = 0; i < M; i++) { //도로의 정보 
			cin >> S >> E >> T;
			
			v.push_back(make_pair(make_pair(S,E),T));
			
			v.push_back(make_pair(make_pair(E,S), T));

		}
		


		for (int j = 0; j < W; j++) { //웜홀의 정보 
			cin >> S >> E >> T;
			
			v.push_back(make_pair(make_pair(S, E), -T));
		}
		
		int distance[501];

		string result = "NO";
		// 벨만 포드 시작

		for (int i = 1; i <= N; i++) {
			distance[i] = INF;
		}

		distance[1] = 0;

		for (int i = 1; i <= N - 1; i++) {
			for (auto u : v) {
				int a, b, w;
				a = u.first.first;
				b = u.first.second;
				w = u.second;
				distance[b] = min(distance[b], distance[a] + w);

			}
		}
		for (auto u : v) {
			int a, b, w;
			a = u.first.first;
			b = u.first.second;
			w = u.second;
			if (distance[b] > distance[a] + w) {
				result = "YES";
				break;
			}
			
		}
		cout << result << '\n';

	}

	return 0;



}
