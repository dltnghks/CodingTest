#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n = 0;

    std::cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        graph.push_back(vector<int>(n));
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            std::cin >> tmp;
            if (tmp == 1) graph[i][j] = 1;
        }
    }

    vector<vector<int>> answer(graph.begin(), graph.end());

    // first - i, second - j
    for (int p = 0; p < n; p++) {
        vector<int> visited(n, 0);
        queue<int> q;

        q.push(p);
        while (!q.empty()) {
            int curP = q.front();
            q.pop();

            for (int j = 0; j < n; j++) {
                if (visited[j] == 0 && graph[curP][j] == 1) {
                    visited[j] = 1;
                    answer[p][j] = 1;
                    q.push(j);
                }
            }

        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] << " ";
        }
        cout << '\n';
    }


    return 0;
}