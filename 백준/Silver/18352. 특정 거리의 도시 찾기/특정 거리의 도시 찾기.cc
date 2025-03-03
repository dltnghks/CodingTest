#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	// 입력
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	n++;

	vector<vector<int>> graph(n, vector<int>());

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		
		graph[s].push_back(e);
	}

	
	// bfs
	queue<pair<int, int>> q;
	vector<bool> visited(n, false);
	vector<int> answer;
	q.push({x, 0});
	visited[x] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int count = q.front().second;
		q.pop();

		// k가 넘어가는 부분부터 자르기
		if (count == k) {
			answer.push_back(cur);
			continue;
		}

		for (int v : graph[cur]) {
			if (visited[v] == false) {
				visited[v] = true;
				q.push({ v, count + 1 });
			}
		}
	}


	// 출력
	if (answer.empty()) {			// 하나도 없는 경우
		cout << -1 << '\n';
		return 0;
	}

	sort(answer.begin(), answer.end());
	for (int val : answer) {		// 있는 경우
		cout << val << '\n';
	}

	return 0;
}