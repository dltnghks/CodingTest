#include <iostream>
#include <vector>

#define TRUE 1
#define FALSE 0
#define INF 1e9

using namespace std;

vector<int> populations;
vector<vector<int>> graph;
vector<vector<int>> dp;

int solve(int cur, int parent, bool state){

    if(dp[cur][state] != INF) return dp[cur][state];

    dp[cur][state] = (state == TRUE ?  populations[cur] : 0);

    int sum = 0;
    for(int val : graph[cur]){
        if(val == parent) continue;
        
        int trueVal = solve(val, cur, TRUE);
        int falseVal = solve(val, cur, FALSE);

        if(state == TRUE){
            sum += falseVal;
        }else{
            sum += max(trueVal, falseVal);
        }
    }

    dp[cur][state] += sum;

    return dp[cur][state];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
    cin >> n;

    populations = vector<int>(n+1, 0);
    graph = vector<vector<int>>(n+1, vector<int>());
    dp = vector<vector<int>>(n+1, vector<int>(2, INF));
    for(int i = 1; i <= n; i++){
        cin >> populations[i];
    }

    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout << max(solve(1, 0, TRUE), solve(1, 0, FALSE)) << '\n';
    return 0;
}