#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {

    int t;
    cin >> t;

    for(int i = 0; i < t; i++){
        int n, k;
        cin >> n >> k;
        vector<int> times(n+1);
        vector<int> usedTimes(n+1, 0);

        for(int j = 1; j <= n; j++){
            cin >> times[j];
        }

        vector<vector<int>> graph(n+1, vector<int>());
        vector<int> inDegree(n+1, 0);
        for(int j = 0; j < k; j++){
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            inDegree[y]++;
        }

        int w;
        cin >> w;


        int totalTime = 0;

        queue<pair<int, int>> q;
        for(int j = 1; j <= n; j++){
            if(inDegree[j] == 0){
                q.push({j, times[j]});
                usedTimes[j] = times[j];
            }
        }

        while(!q.empty()){
            int cur = q.front().first;
            int curTime = q.front().second;
            q.pop();

            for(int next : graph[cur]){
                inDegree[next]--;
                usedTimes[next] = max(usedTimes[next], usedTimes[cur] + times[next]);
                    
                if(inDegree[next] == 0){
                    q.push({next, usedTimes[next]});
                }
            }
        }


        cout << usedTimes[w] << '\n';
    }
    

    return 0;
}
