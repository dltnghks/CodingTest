#include <iostream>
#include <vector>
#include <algorithm> // sort 사용

using namespace std;

// 간선 정보 저장용 구조체
struct Edge {
    int u, v, w;
    // 가중치(w) 기준 오름차순 정렬을 위한 연산자 오버로딩
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int parent[10001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); 
}

void merge(int a, int b){
    int rootA = find(a); 
    int rootB = find(b); 
    
    if(rootA != rootB){
        parent[rootB] = rootA; 
    }
}

int main() {
    // 1. 입력 받기
    int V, E;
    cin >> V >> E;
    
    // parent 초기화
    for(int i = 1; i <= V; i++) parent[i] = i;
    
    vector<Edge> edges;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    
    // 2. 간선 정렬 (가중치 작은 순서대로)
    sort(edges.begin(), edges.end());
    
    // 3. 크루스칼 알고리즘 수행
    int totalWeight = 0;
    int edgeCount = 0; // 연결된 간선 개수 카운트 (선택 사항이지만 최적화용)
    
    for(int i = 0; i < edges.size(); i++) {
        // 싸이클이 발생하지 않는다면 합치기
        int a = edges[i].u;
        int b = edges[i].v;
        int cost = edges[i].w;
        if(find(a) != find(b)){
            totalWeight += cost;
            merge(a, b);
        }
    }
    
    cout << totalWeight;
    
    return 0;
}