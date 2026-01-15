#include <iostream>
#include <vector>
#include <tuple> // 간선 리스트를 저장하기 위해 사용

#define INF 1e18 // long long 범위에 맞춰 충분히 큰 값

using namespace std;

int main(){

    /* 입력 */
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    int a, b, c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    /* 로직 */
    vector<long long> dist(n + 1, INF);
    dist[1] =0;

    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < m; j++){
            int cur = get<0>(edges[j]);
            int next = get<1>(edges[j]);
            int cost = get<2>(edges[j]);

            if(dist[cur] != INF && dist[next] > dist[cur] + cost){
                dist[next] = dist[cur] + cost;
            }
        }
    }

    // 음수 사이클 확인
    bool hasNegativeCycle = false;
    for(int j = 0; j < m; j++){
        int cur = get<0>(edges[j]);
        int next = get<1>(edges[j]);
        int cost = get<2>(edges[j]);

        if(dist[cur] != INF && dist[next] > dist[cur] + cost){
            hasNegativeCycle = true;
            break;
        }
    }

    if(hasNegativeCycle){
        cout << -1 << '\n';
    }
    else{
        /* 출력 */
        for(int i = 2; i <= n; i++){
            if(dist[i] == INF) 
                cout << -1 << '\n';
            else
                cout << dist[i] << '\n';
        }
    }

    return 0;
}

