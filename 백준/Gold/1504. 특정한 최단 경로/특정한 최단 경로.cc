#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int dijkstra(int startV, int endV, vector<vector<pair<int, int>>>& graph){
    int n = graph.size();
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n, INF);

    dist[startV] = 0;
    pq.push({0, startV});

    while(!pq.empty()){
        int cur = pq.top().second;
        int curCost = -pq.top().first;
        pq.pop();

        if(curCost > dist[cur]) continue;

        for(auto value : graph[cur]){
            int next = value.first;
            int nextCost = curCost + value.second;
            if(dist[next] > nextCost){
                dist[next] = nextCost;
                pq.push({-nextCost, next});
            }
        }
    }
    
    if(dist[endV] == INF){
        return -1;;
    }else{
        return dist[endV];
    }
}

int main(){

    /* 입력 */
    int n, e;
    cin >> n >> e;

    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int,int>>());

    for(int i = 0; i < e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int requiredV1, requiredV2; 
    cin >> requiredV1 >> requiredV2;


    /* 로직*/
    int result = -1;

    int requiredPath = dijkstra(requiredV1, requiredV2, graph);
    
    if(requiredPath != -1){
        // 1 -> v1, v2 -> n
        int path1 = dijkstra(1, requiredV1, graph);
        int path2 = dijkstra(requiredV2, n, graph);

        if(path1 != -1 && path2 != -1)
            result = path1 + path2 + requiredPath;

        // 1 -> v2, v1 -> n
        path1 = dijkstra(1, requiredV2, graph);
        path2 = dijkstra(requiredV1, n, graph);

        if(path1 != -1 && path2 != -1)
            result = min(result, path1 + path2 + requiredPath);
    }

    /* 출력 */
    cout << result << '\n';

    return 0;
}

