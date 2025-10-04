#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;

struct Point{
    int x;
    int y;
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

int moveX[] = {1, 0, -1, 0};
int moveY[] = {0, -1, 0, 1};

int main() {

    // 입력
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    // 로직
    int res = 0;
    bool isloop = true;
    while(isloop){
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        isloop = false;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == true) continue;

                queue<Point*> q;
                vector<Point*> sharedVec;
                int sum = 0;
                q.push(new Point(j, i));
                visited[i][j] = true;

                while(!q.empty()){
                    Point* curPoint = q.front();
                    q.pop();

                    sum += grid[curPoint->y][curPoint->x];
                    sharedVec.push_back(curPoint);
                    
                    for(int k = 0; k < 4; k++){
                        int nextX = curPoint->x + moveX[k];
                        int nextY = curPoint->y + moveY[k];

                        // 범위를 벗어나면 패쓰
                        if(0 > nextX || nextX >= n || 0 > nextY || nextY >= n || visited[nextY][nextX]) continue;
                        
                        // L <= difference <= R을 만족하지 않으면 패쓰
                        int difference = abs(grid[curPoint->y][curPoint->x] - grid[nextY][nextX]);
                        if(difference < l || difference > r) continue;

                        isloop = true;
                        visited[nextY][nextX] = true;
                        q.push(new Point(nextX, nextY));
                    }
                }

                // 모두 연결했으면 인원 배분
                int population = sum / sharedVec.size();
                for(Point* p : sharedVec){
                    grid[p->y][p->x] = population;
                }
            }
        } 

        if(isloop == true)
            res++;
        
    }

    
    // 결과
    cout << res << '\n';

    return 0;
}
