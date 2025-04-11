#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int n, m;
int map[500][500]; 

struct Node{
    int count;
    int sum;
    int x;
    int y;
};

bool visited[500][500] = {false, };

int moveX[] = {-1 ,1, 0, 0};
int moveY[] = {0, 0, -1 ,1};
int fuckMove[] = {1, -1};

int res = 0;

void DFS(int x, int y, int depth, int sum){
    
    // 凸 모양 처리
    if(depth == 2){
        int fuckMoveX[] = {1, 0};
        int fuckMoveY[] = {0, 1};
        
        for(int i = 0; i < 2; i++){
            pair<int,int> fuckPos1 = {x + fuckMoveX[i], y + fuckMoveY[i]};
            pair<int,int> fuckPos2 = {x - fuckMoveX[i], y - fuckMoveY[i]};

            if(0 <= fuckPos1.first && fuckPos1.first < m && 0 <= fuckPos2.first && fuckPos2.first < m &&
                0 <= fuckPos1.second && fuckPos1.second < n && 0 <= fuckPos2.second && fuckPos2.second < n &&
                visited[fuckPos1.second][fuckPos1.first] == false && visited[fuckPos2.second][fuckPos2.first] == false
            )
            {
                //cout << cur.x << ", " << cur.y << " : " << cur.sum + map[fuckPos1.second][fuckPos1.first] + map[fuckPos2.second][fuckPos2.first]<< '\n';
                //cout << cur.sum + map[fuckPos1.second][fuckPos1.first] + map[fuckPos2.second][fuckPos2.first] << '\n';
                res = max(res, sum + map[fuckPos1.second][fuckPos1.first] + map[fuckPos2.second][fuckPos2.first]);
            }

        }
    }

    if(depth == 4){
        //cout << "====\n";
        //cout << cur.x << ", " << cur.y << " : " << cur.sum << '\n';
        res = max(res , sum);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if( 0 <= nextX && nextX < m && 0 <= nextY && nextY < n &&
            visited[nextY][nextX] == false)
        {
            visited[y][x] = true;
            DFS(nextX, nextY, depth+1, sum + map[nextY][nextX]);
            visited[y][x] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int num;
            cin >> num;
            map[i][j] = num;
        }
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            visited[i][j] = true;
            DFS(j, i, 1, map[i][j]);
            visited[i][j] = false;
        }
    }

    cout << res << '\n';

    return 0;
}