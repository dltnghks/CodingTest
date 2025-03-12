#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int n;

    cin >> n;

    int a = 0;
    int b = 0;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    while(true)
    {
        cin >> a >> b;

        if (a == -1 && b == -1) break;

        graph[a][b] = 1;
        graph[b][a] = 1;
    } 

    vector<int> res(n+1);
    int minScore = 51;
    for (int i = 1; i <= n; i++) {

        queue<int> q;
        vector<int> dis(n + 1, -1);
        q.push(i);
        dis[i] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int j = 1; j <= n; j++) {
                if (i != j && graph[cur][j] == 1 && dis[j] == -1) {
                    dis[j] = dis[cur] + 1;
                    q.push(j);
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            res[i] = max(res[i], dis[j]);
        }
        minScore = min(minScore, res[i]);
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (minScore == res[i]) {
            ans.push_back(i);
        }
    }

    cout << minScore << " " << ans.size() << '\n';

    for (int val : ans) {
        cout << val << " ";
    }


    return 0;
}