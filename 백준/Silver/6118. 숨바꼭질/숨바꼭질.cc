#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> ans;
    int maxDist = 0;

    vector<bool> visited(n+1, false);
    visited[1] = true;
    queue<pair<int, int>> q;
    q.push({1, 0});

    while(!q.empty()){
        int cur = q.front().first;
        int curDis = q.front().second;
        q.pop();

        if(curDis > maxDist){
            ans.clear();
            ans.push_back(cur);
            maxDist = curDis;
        }else if(curDis == maxDist){
            ans.push_back(cur);
        }

        for(auto& num : graph[cur]){
            if(visited[num] == false){
                visited[num] = true;
                q.push({num, curDis+1});
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans[0] << " " << maxDist << " " << ans.size() << '\n';
    

    return 0;
}