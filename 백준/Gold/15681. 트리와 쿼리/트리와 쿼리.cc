#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<int> dp;

int solve(int root, int parent){
    // 채워져있으면 리턴
    if(dp[root] != -1) return dp[root];
    
    // 1로 초기화
    dp[root] = 1;
    
    // root는 모든 하위 노드들이 가진 정점의 합
    for(int val : graph[root]){
        if(parent == val) continue;
        dp[root] += solve(val, root);
    }

    return dp[root];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n, r, q;
    cin >> n >> r >> q;

    graph = vector<vector<int>>(n+1, vector<int>());
    dp = vector<int>(n+1, -1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    solve(r, 0);

    for(int i = 0; i < q; i++){
        int a;
        cin >> a;

        cout << dp[a] << '\n';
    }

    return 0;
}