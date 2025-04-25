#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, endV;
vector<vector<int>> graph;
int dp[16][1 << 16]; 


int TSP(int index, int visited){
 
    if(visited == endV){
        //cout << "=========================\n";
        if(graph[index][0] > 0){
            return graph[index][0];
        }

        return INF;
    }

    if(dp[index][visited] != 0) return dp[index][visited];

    dp[index][visited] = INF;
    //cout << index << '\n';
        
    for(int i = 0; i < n; i++){
        
        if(graph[index][i] == 0) continue;
        if(visited & (1 << i)) continue;
        int tmp = TSP(i, visited | 1 << i);
        dp[index][visited] = min(dp[index][visited], graph[index][i] + tmp); 
    }
    return dp[index][visited];
}

int main() {

    cin >> n;
    endV = (1 << n) - 1;
    graph = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> graph[i][j];
        }
    }
      
    cout << TSP(0, 1) << '\n';

    return 0;
}