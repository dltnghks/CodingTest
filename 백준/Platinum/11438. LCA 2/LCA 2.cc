#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100001; 

int depth[MAX_N];   
int dp[18][MAX_N];

vector<int> graph[MAX_N]; 

void MakeTree(int cur, int p, int dep){
    depth[cur] = dep;
    dp[0][cur] = p;

    for(int child : graph[cur]){
        if(child == p) continue;
        MakeTree(child, cur, dep+1);
    }
}

void BuildSparseTable(int num_nodes) {
    for (int k = 1; k < 17; ++k) {
        // 각 노드 v에 대해 계산
        for (int v = 1; v <= num_nodes; ++v) {
            if (dp[k-1][v] != 0) {
                dp[k][v] = dp[k-1][dp[k-1][v]];
            }
        }
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

    BuildSparseTable(n);

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        if(depth[a] < depth[b])
            swap(a, b);

        // 높이 맞추기
        int diff = depth[a] - depth[b];
        for(int k = 17; k >= 0; --k){
            if((diff >> k) & 1){
                a = dp[k][a];
            }                
        }

        if(a == b){
            cout << a << '\n';
            continue;
        }

        for(int k = 17; k >= 0; --k){
            if(dp[k][a] != dp[k][b]){
                a = dp[k][a];
                b = dp[k][b];
            }
        }

        cout << dp[0][a] << '\n';
    }
    
    return 0;
}