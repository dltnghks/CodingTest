#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <stdio.h>

using namespace std;

struct Edge {
    int e;
    int w; //w는 10 이하의 자연수
};

int v, e, s;
vector<vector<Edge>> graph;
vector<int> dis;

int main()
{
    // 입력
    scanf("%d %d %d", &v, &e, &s);

    graph = vector<vector<Edge>>(v+1, vector<Edge>());
    dis = vector<int>(v + 1, INT_MAX);

    for (int i = 1; i <= e; i++) {
        int first, second, weight;
        scanf("%d %d %d", &first, &second, &weight);

        graph[first].push_back({second, weight});
    }


    // 출력
    // 0~i 까지 최단 경로 출력
    // 다익스트라?
    priority_queue<pair<int, int>> pq;
    pq.push({ 0 , s});
    dis[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curDis = -pq.top().first;
        pq.pop();

        //cout << "cur : " << cur << '\n';

        if (dis[cur] < curDis) continue;
        for (Edge val : graph[cur]) {
            int num = val.e;
            int weight = val.w;

            //cout << "num : " << num << '\n';
            if (dis[num] > dis[cur] + weight) {
                dis[num] = dis[cur] + weight;
                //cout << num << " : " << dis[num] << '\n';
                pq.push({ -dis[num], num });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (dis[i] == INT_MAX) {
            printf("INF\n");
        }
        else {
            printf("%d\n", dis[i]);
        }
    }
   
    return 0;
}
