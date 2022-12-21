#include <iostream>
#include <vector>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
priority_queue<int> pq;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;



	while (t--) {

		int n, m;
		cin >> n >> m;

		while (!pq.empty()) pq.pop();
		while (!q.empty()) q.pop();

		for (int i = 0; i < n; i++) {
			int a;
			cin >> a;
			q.push({ a,i });
			pq.push(a);
		}
		

		int k = 0;

		while(!q.empty()) {
			
			if (pq.top() > q.front().first) { //우선 순위가 낮은놈이 비교 
				q.push(q.front());
				q.pop();

			}
			else {
				k++;
				if (q.front().second == m) {
					cout << k<<'\n';
					break;
				}
				pq.pop();
				q.pop();

			}
			

		}
		





	}




	return 0;

}
