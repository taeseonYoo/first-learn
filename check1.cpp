#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[100005];
int dist[100005];



int main() {

	ios::sync_with_stdio(NULL);
	cin.tie(NULL);



	int N, K;
	cin >> N >> K;

	queue<int> q;

	q.push(N);

	visit[N] = true;


	while (!q.empty()) {
	
		int s = q.front();
		q.pop();
		int u = 0;
		for (int i = 0; i < 3; i++) {
			
			switch (i) {
			case 0:
				if (s - 1 >= 0) {
					if (visit[s - 1]) break;
					u = s - 1;

				}
				break;

				
			case 1:
				if (s + 1 <= K) {
					if(visit[s + 1]) break;
					u = s + 1;
				}
				break;
			default:
				if ((s * 2) <= 100000) {
					if (s > K && (s * 2) > K) break;
					if (visit[s * 2]) break;
					u = s * 2;
				}
				
			}
			
			if (u == K) {
				cout << dist[s] + 1;
				return 0;
			}

			q.push(u);
			visit[u] = true;
			dist[u] =  dist[s] + 1;
			
		}
		

	}

	cout << dist[K];
	



	return 0;

}