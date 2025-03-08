#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using namespace std;

vector<set<int>> graph;
vector<bool> visited;
bool flag = true;

void dfs(int cur) {
    if (!flag) return;
    for (int val : graph[cur]) {
        if (visited[val] == true) {
            flag = false;
            return;
        }
        visited[val] = true;
        dfs(val);
        visited[val] = false;
    }
}

int main()
{
    // 입력
    int n;
    cin >> n;

    graph = vector<set<int>>(n+1, set<int>());

    // n번은 도착지점이라 입력 X
    for (int i = 1; i < n; i++) {
        int connection;
        cin >> connection;

        for (int j = 0; j < connection; j++) {
            int edge;
            cin >> edge;
            graph[i].insert(edge);
        }
    }

    visited = vector<bool>(n + 1, false);
    dfs(1);

    if (flag) {
        cout << "NO CYCLE";
    }
    else {
        cout << "CYCLE";
    }

    return 0;
}
