#include <iostream>
#include <vector>
#include <math.h>
#include <stack>

using namespace std;

vector<vector<int>> dp;
vector<int> p;

void dfs(int cur, vector<vector<int>>& tree, vector<int>& population){
    
    dp[cur][true] = population[cur];
    dp[cur][false] = 0;

    for(int idx : tree[cur]){
        if(p[cur] == idx) continue;
        p[idx] = cur;
        dfs(idx, tree, population);
        dp[cur][true] += dp[idx][false];
        dp[cur][false] += max(dp[idx][false], dp[idx][true]);
    }
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // 입력
    int n;
    cin >> n;
    // 인덱스를 맞춰주기 위해 +1
    n++;

    vector<int> populations(n);
    for(int i = 1; i < n; i++){
        cin >> populations[i];
    }

    vector<vector<int>> tree(n, vector<int>());
    for(int i = 1; i < n-1; i++){
        int to, from;
        cin >> to >> from;
        tree[to].push_back(from);
        tree[from].push_back(to);
    }

    dp = vector<vector<int>>(n, vector<int>(2));
    p = vector<int>(n);

    // 로직
    dfs(1, tree, populations);
    int res = max(dp[1][true], dp[1][false]);
    
    // 결과
    cout << res;

    return 0;
}
