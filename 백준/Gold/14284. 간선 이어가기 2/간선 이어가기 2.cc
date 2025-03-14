#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Edge{
    int e;
    int w;
};

int n, m, s, t;

int main(){
    cin >> n >> m;

    vector<vector<Edge>> graph(n+1, vector<Edge>());
  
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> s >> t;

    priority_queue<pair<int, int>> pq;
    pq.push({0, s});

    vector<int> dis(n+1, INF);
    dis[s] = 0;

    while(!pq.empty()){
        int cur = pq.top().second;
        int curDis = -pq.top().first;
        pq.pop();

        if(dis[cur] < curDis) continue;

        for(Edge val : graph[cur]){
            int next = val.e;
            int nextW = val.w;
            if(dis[next] > curDis + nextW){
                dis[next] = curDis + nextW;
                pq.push({-dis[next], next});
            }
        }
    }

    cout << dis[t] << '\n';

    return 0;
}