#include <iostream>
#include <vector>
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

int n;
vector<vector<char>> grid;
int moveX[] = {1, 0, -1, 0};
int moveY[] = {0, -1, 0, 1};

int cal(bool isColorWeakness){
    int count = 0;
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visited[i][j] == false){
                count++;
                queue<Point*> q;
                q.push(new Point(j, i));
                visited[i][j] = true;

                while(!q.empty()){
                    Point* curPoint = q.front();
                    q.pop();
                    
                    char curColor = grid[curPoint->y][curPoint->x];
                    for(int i = 0 ; i < 4 ; i++){
                        int nextX = curPoint->x + moveX[i];
                        int nextY = curPoint->y + moveY[i];
                        if(0 <= nextX && nextX < n && 0 <= nextY && nextY < n &&
                        visited[nextY][nextX] == false)
                        {
                            if(isColorWeakness && 
                            (curColor == 'R' || curColor == 'G') && (grid[nextY][nextX] == 'R' || grid[nextY][nextX] == 'G')
                            )
                            {
                                visited[nextY][nextX] = true;
                                q.push(new Point(nextX, nextY));
                            }
                            else if(curColor == grid[nextY][nextX]){
                                visited[nextY][nextX] = true;
                                q.push(new Point(nextX, nextY));
                            }
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main() {

    // 입력
    cin >> n;

    grid = vector<vector<char>>(n, vector<char>(n, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    // 로직
    int res1, res2;
    res1 = cal(false);
    res2 = cal(true);

    // 결과
    cout << res1 << " " << res2 << '\n';
    
    return 0;
}
