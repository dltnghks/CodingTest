#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 문제 조건에 따라 최대 노드 수 설정 (LCA 2 기준 10만, LCA 1 기준 5만)
const int MAX_N = 100001; 

int parent[MAX_N];  
int depth[MAX_N];   

// graph[i]는 i번 노드와 연결된 노드들의 리스트
vector<int> graph[MAX_N]; 

void MakeTree(int cur, int p, int dep){
    depth[cur] = dep;
    parent[cur] = p; // cur의 부모는 p

    // graph[cur]는 벡터이므로 range-based for 사용 가능
    for(int child : graph[cur]){
        if(child == p) continue;
        MakeTree(child, cur, dep+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
    cin >> n;

    // 그래프 입력
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); 
    }

    // 트리 생성
    MakeTree(1, 0, 0);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        // 1. 깊이 맞추기 (한 칸씩 이동 - O(N))
        while (depth[a] > depth[b]) a = parent[a];
        while (depth[b] > depth[a]) b = parent[b];

        // 2. 같이 올라가기 (한 칸씩 이동 - O(N))
        while (a != b) {
            a = parent[a];
            b = parent[b];
        }
        cout << a << '\n';
    }
    
    return 0;
}