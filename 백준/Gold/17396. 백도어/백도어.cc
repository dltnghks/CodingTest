#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

#define INF 9e12

struct Edge{
    int e;
    long long t;
};

int n, m;

int main(){
    cin >> n >> m;

    vector<int> observation(n);
    vector<vector<Edge>> graph(n, vector<Edge>());

    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        observation[i] = input;
    }

    for(int i = 0; i < m; i++){
        int s, e;
        long long t;
        cin >> s >> e >> t;

        if((observation[s] == 0 && observation[e] == 0 ) || s == n-1 || e == n-1){
            graph[s].push_back({e, t});
            graph[e].push_back({s, t});
        }   
    }
    


    // for(int i = 0; i < n; i++){
    //     cout << "cur : " << i << '\n';
    //     for(Edge& val : graph[i]){
    //         cout << " e : " << val.e << " , t : " << val.t << '\n';
    //     }
    // }


    vector<long long> dis(n, INF);
    dis[0] = 0;

    priority_queue<pair<long long, int>> pq;
    pq.push({0, 0});

    while(!pq.empty()){
        int cur = pq.top().second;
        long long curDis = -pq.top().first;
        pq.pop();

        if(dis[cur] < curDis) continue;
        
        for(Edge& val : graph[cur]){
            if(dis[val.e] > dis[cur] + val.t){
                dis[val.e] = dis[cur]+val.t;
                pq.push({-dis[val.e], val.e});
            }
        }
    }

    if(dis[n-1] == INF){
        cout << -1;
    }else{
        cout << dis[n-1];
    }

    return 0;
}