#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int posVecSize = 0;
vector<pair<int,int>> posVec;
vector<vector<int>> combVec;
vector<pair<int, int>> virusPosVec;
vector<vector<int>> map(8, vector<int>(8, 0));


void FindComb(vector<int> comb){
    if(comb.size() == 3){
        combVec.push_back(comb);
        return;
    }

    int last = comb.back();

    for(int i = last + 1; i < posVecSize; i++){
        int x = posVec[i].second;
        int y = posVec[i].first;
        if(map[y][x] == 0){
            vector<int> newComb(comb);
            newComb.push_back(i);
            FindComb(newComb);
        }
    }
}

int main() {
    int n, m;
    
    int spaceSum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            map[i][j] = num;
            posVec.push_back({i, j});
            if(num == 2) virusPosVec.push_back({i, j});
            if(num == 0) spaceSum++;
        }
    }
    posVecSize = posVec.size();
    
    for(int i = 0; i < posVecSize; i++)
    {
        if(map[posVec[i].first][posVec[i].second] == 0)
           FindComb(vector<int>(1, i));
    }

    int ans = 0;

    int moveX[] = {-1, 1, 0 ,0};
    int moveY[] = {0, 0, -1, 1};

    for(auto& comb : combVec){
        // 모든 경우 BFS
        int tmpAns = spaceSum-3;

        vector<vector<int>> tmpMap(map);

        for(auto& index : comb){
            int x = posVec[index].second;
            int y = posVec[index].first;
            tmpMap[y][x] = 1;
        }

        queue<pair<int, int>> q;
        for(auto& virusPos : virusPosVec){
            q.push(virusPos);
        }

        while(!q.empty()){
            int curX = q.front().second;
            int curY = q.front().first;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nextX = curX + moveX[i];               
                int nextY = curY + moveY[i];

                if(0 <= nextX && nextX < m && 0 <= nextY && nextY < n &&
                    tmpMap[nextY][nextX] == 0
                ){
                    tmpMap[nextY][nextX] = 1;
                    tmpAns--;
                    q.push({nextY, nextX});
                }
            }
        }
        //cout << tmpAns << '\n';
        ans = max(ans, tmpAns);
    }

    cout << ans;

    return 0;
}