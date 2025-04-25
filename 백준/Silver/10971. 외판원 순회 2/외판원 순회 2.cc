#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n;
vector<vector<int>> graph;
vector<bool> visited;
int ans = INF;

void DFS(int index, int depth, int sum){
 
    //cout << index << '\n';

    if(depth == n){
        if(graph[index][0] != 0){
            ans = min(ans, sum + graph[index][0]);
            //cout << "ans :" << ans << '\n';
        }
        
        //cout << "=========================\n";
    }
        
    for(int i = 1; i < n; i++){
        if(visited[i] == false && graph[index][i] != 0){
            visited[i] = true;
            if(index == -1)
                index = i;
            DFS(i, depth+1, sum + graph[index][i]);
            visited[i] = false;
        }
    }
    
}

int main() {

    cin >> n;
    visited = vector<bool>(n, false);
    graph = vector<vector<int>>(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j =0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    visited[0] = true;
            
    DFS(0, 1, 0);

    cout << ans << '\n';

    return 0;
}