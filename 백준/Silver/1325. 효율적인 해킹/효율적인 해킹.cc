#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int Cal(int index, vector<vector<int>>& trustLines) {

    int count = 0;
    queue<int> q;
    vector<int> visited(n+1, false);
    q.push(index);
    visited[index] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();


        count++;

        for (auto& num : trustLines[cur]) {
            if (visited[num] == false) {
                visited[num] = true;
                q.push(num);
            }
        }
    }

    return count;
}



int main() {
    cin >> n >> m;

    vector<vector<int>> trustLines(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        trustLines[b].push_back(a);
    }

    vector<int> ans;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        int count = Cal(i, trustLines);
        if (max < count) {
            ans.clear();
            ans.push_back(i);
            max = count;
        }
        else if (max == count) {
            ans.push_back(i);
        }
    }

    for (auto& num : ans) {
        cout << num << " ";
    }

    return 0;
}
