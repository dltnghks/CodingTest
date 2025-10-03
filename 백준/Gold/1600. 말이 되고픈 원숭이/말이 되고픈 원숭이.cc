#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point{
    int x;
    int y;
    int horseMoveNum;
    int moveCount;

    Point(int x, int y, int horseMoveNum, int moveCount){
        this->x = x;
        this->y = y;
        this->horseMoveNum = horseMoveNum;
        this->moveCount = moveCount;
    }
};

int main(){
    
    // 입력
    int k, w, h;
    cin >> k;
    cin >> w >> h;

    vector<vector<int>> map = vector<vector<int>>(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> map[i][j];
        }
    }

    // 로직
    int res = 1e9;

    // 말처럼 이동
    int horseMoveX[] = {1,2,2,1,-1,-2,-2,-1};
    int horseMoveY[] = {2,1,-1,-2,-2,-1,1,2};

    // 인접한 블럭으로 이동
    int moveX[] = {1,0,-1,0};
    int moveY[] = {0,-1,0,1};

    // 방문 여부
    vector<vector<vector<bool>>> visited = vector<vector<vector<bool>>>(k+1, vector<vector<bool>>(h, vector<bool>(w, false))); 

    queue<Point*> q;
    q.push(new Point(0, 0, k, 0));

    while(!q.empty()){
        Point* curPoint = q.front();
        q.pop();

        //cout << curPoint->x << " ," << curPoint->y << " : " << curPoint->moveCount << " | "<< curPoint->horseMoveNum << '\n';
        if(curPoint->x == w-1 && curPoint->y == h-1){
            res = min(res, curPoint->moveCount); 
            continue;
        }else if(curPoint->moveCount >= res){
            continue;
        }

        for(int i = 0; i < 4; i++){
            int nextX = curPoint->x + moveX[i];
            int nextY = curPoint->y + moveY[i];
                
            // 인접 이동하면서 큐에 넣기
            if(0 <= nextX && nextX < w && 0 <= nextY && nextY < h
                && visited[curPoint->horseMoveNum][nextY][nextX] == false && map[nextY][nextX] == 0){
                visited[curPoint->horseMoveNum][nextY][nextX] = true;
                q.push(new Point(nextX, nextY, curPoint->horseMoveNum, curPoint->moveCount+1));
            }
        }

        if(curPoint->horseMoveNum > 0){
            for(int i = 0; i < 8; i++){
                // 말 이동 하면서 q에 넣기
                int nextX = curPoint->x + horseMoveX[i];
                int nextY = curPoint->y + horseMoveY[i];
                if(0 <= nextX && nextX < w && 0 <= nextY && nextY < h
                 && visited[curPoint->horseMoveNum-1][nextY][nextX] == false && map[nextY][nextX] == 0){
                    visited[curPoint->horseMoveNum-1][nextY][nextX] = true;
                    q.push(new Point(nextX, nextY, curPoint->horseMoveNum-1, curPoint->moveCount+1));
                }
            }
        }
    }
    


    // 결과
    res = res == 1e9 ? -1 : res;
    cout << res << '\n';

    return 0;
}