#include <iostream>
#include <vector>
#include <queue>

#define MAX 1e9

using namespace std;

vector<vector<int>> graph;

int Move(int curX, int curY, int nextX, int nextY){
    if(graph[curY][curX] > graph[nextY][nextX]){
        return 0;
    }else{
        return graph[nextY][nextX] - graph[curY][curX] + 1; 
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    graph = vector<vector<int>>(n+1, vector<int>(n+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int input;
            cin >> input;

            graph[i][j] = input;
        }
    }

    priority_queue<pair<int, pair<int,int>>> pq;
    vector<vector<int>> cost(n+1, vector<int>(n+1, MAX));
    pq.push({0, {1,1}});
    cost[1][1] = 0;

    while(!pq.empty()){
        int curCost = -pq.top().first;
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        pq.pop();

        //cout << curX << ", " << curY << '\n';
        
        if(cost[curY][curX] < curCost) continue;

        int nextX, nextY, nextCost;
       
        int moveX[] = {0, 1};
        int moveY[] = {1, 0};

        for(int i = 0; i < 2; i++){
            nextX = moveX[i] + curX;
            nextY = moveY[i] + curY;

            if(!(1 <= nextX && nextX <= n && 1 <= nextY && nextY <= n)){
                continue;
            }

            nextCost = cost[curY][curX] + Move(curX, curY, nextX, nextY);
            if(nextCost < cost[nextY][nextX]){
                cost[nextY][nextX] = nextCost;
                pq.push({-nextCost, {nextX, nextY}}); 
            }
        }
    }

    cout << cost[n][n] << '\n';

    return 0;
}