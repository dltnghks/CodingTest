#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;

	vector<vector<int>> graph(n, vector<int>());

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'Y') {
				graph[i].push_back(j);
			}
		}
	}


	int answer = 0;


	// 계산
	for (int i = 0; i < n; i++) {
		vector<bool> visited(n, false);
		int count = graph[i].size();

		for (int val : graph[i]) {
			visited[val] = true;
		}

		for (int j = 0; j < n; j++) {
			if (i != j) {
				for (auto val : graph[j]) {
					for (auto val2 : graph[i]) {
						if (val == val2 && visited[j] == false) {
							visited[j] = true;
							count++;
							break;
						}
					}
				}
			}
		}

		answer = max(answer, count);
	}


	cout << answer;

	return 0;
}