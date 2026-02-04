#include <iostream>
#include <vector>

#define TRUE 1
#define FALSE 0
#define INF 1e9

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> tree;
vector<vector<int>> dp;
vector<bool> visited;

void MakeTree(int root){
    visited[root] = true;
    for(int val : graph[root]){
        if(visited[val] == false){
            tree[root].push_back(val);
            visited[val] = true;
            MakeTree(val);
        }
    }
}

int solve(int cur, int curState, int preState){
    // leaf는 무조건 0
    if(tree[cur].size() == 0){
        dp[cur][curState] = curState;
        return curState;
    }

    // 메모제이션
    if(dp[cur][curState] != -1){
        return dp[cur][curState];
    }

    // 초기화
    dp[cur][curState] = curState;

    int sum = 0;
    bool isTrue = false;
    for(int i = 0; i < tree[cur].size(); i++){
        int next = tree[cur][i];
        int trueVal = solve(next, TRUE, curState);
        int falseVal = solve(next, FALSE, curState);
        if(curState == TRUE){
            sum += min(trueVal, falseVal);
        }else{
            sum += trueVal;
        }
    }
    //cout << cur << "(" << curState << " , " << tree[cur].size() << ") : " << sum << '\n'; 
    dp[cur][curState] += sum;

    return dp[cur][curState];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    graph = vector<vector<int>>(n+1, vector<int>());
    tree = vector<vector<int>>(n+1, vector<int>());
    dp = vector<vector<int>>(n+1, vector<int>(2, -1));
    visited = vector<bool>(n+1, false);

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    MakeTree(1);
    
    cout << min(solve(1, 0, 1), solve(1, 1, 1)) << '\n';

    // cout << "====================\n";

    // for(int i = 1; i <= n; i++){
    //     cout << i << "| " << dp[i][TRUE] << ", " << dp[i][FALSE] << '\n';
    // }
    return 0;
}