#include <iostream>
#include <vector>
#include <limits.h>

#define INF 1000000000

using namespace std;

int main() {

	int n, m;	
	cin >> n;
	cin >> m;

	vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) graph[i][j] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				graph[j][k] = min(graph[j][k], (graph[j][i] + graph[i][k]));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (graph[i][j] == INF) {
				cout << "0 ";
			}
			else {
				cout << graph[i][j] << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}