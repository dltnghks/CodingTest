#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int n, k;
vector<vector<int>> graph;

void Input(){
    cin >> n >> k;
    
    graph = vector<vector<int>>(n+1);

    for(int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    } 
}

bool Cal(){
    // 모든 노드를 다 돌아야 됨.
    for(int i = 1; i <= n; i++){

        vector<bool> visited(n+1, false);
        // first - 노드 번호, second - 거리
        queue<pair<int, int>> q;
        q.push({i, 1});
        visited[i] = true;

        // 모든 노드 BFS로 확인하기
        while(!q.empty()){
            int cur = q.front().first;
            int curCount = q.front().second;
            //cout << "cur : " << cur << '\n';
            //cout << "curCount : " << curCount << '\n';
            q.pop();

            // 자신이 갈 수 있는 모든 노드를 돌아야 됨.
            for(int val : graph[cur]){
                if(visited[val] == false){
                    if(curCount == 7) return false;
                    visited[val] = true;
                    q.push({val, curCount+1});
                }
            }
        }

        for(int i = 1; i <=n; i++){
            if(visited[i] == false) return false;
        }
    }
    return true;
}

int main()
{
	// 입력
    Input();

    // 계산
    if(Cal()){
        cout << "Small World!" << '\n';
    }else{
        cout << "Big World!" << '\n';
    }

	return 0;
}