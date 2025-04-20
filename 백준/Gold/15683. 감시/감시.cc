#include <iostream>
#include <vector>

#define CHECK -1
#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3

using namespace std;

struct Fcctv {
    int num;
    int x;
    int y;
};

int map[8][8];
vector<Fcctv> cctvVec;
int cctvNum;
int n, m;
int ans;
int cctvDirection[6] = { 0, 4, 2, 4, 4, 1 };

int Cal(int direction, int x, int y, vector<pair<int, int>>& backtracking) {

    int sum = 0;
    int dirX[] = { -1, 0, 1, 0 };
    int dirY[] = { 0, 1, 0, -1 };
    int nextX = x;
    int nextY = y;
    while (true) {
        nextX += dirX[direction];
        nextY += dirY[direction];
        if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n || map[nextY][nextX] == 6) {
            break;
        }
        if (map[nextY][nextX] == 0) {
            map[nextY][nextX] = 1;
            backtracking.push_back({ nextY, nextX });
            sum++;
        }
    }

    return sum;
}

void PrintMap() {
    cout << "====================================\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }
    cout << "====================================\n";
}

void DFS(int depth, int index,int sum) {
    if (depth == cctvNum) {
        //cout << sum << '\n';
        ans = min(ans, sum);
        return;
    }

    for (int i = index + 1; i < cctvNum; i++) {
        int cctvType = cctvVec[i].num;
        for (int j = 0; j < cctvDirection[cctvType]; j++) {
            //cout << "type : " << cctvType << " direction : " << j << '\n';
            int calValue = 0;
            vector<pair<int, int>> backtracking;
            switch (cctvType)
            {
            case 1:
                // 한 방향     4
                calValue = Cal(j, cctvVec[i].x, cctvVec[i].y, backtracking);
                break;
            case 2:
                // 2방향 반대   2
                calValue += Cal(j, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal(j+2, cctvVec[i].x, cctvVec[i].y, backtracking);
                break;
            case 3:
                // 2방향 직각   4
                calValue += Cal(j, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal((j+1)%4, cctvVec[i].x, cctvVec[i].y, backtracking);
                // j 기준점
                break;
            case 4:
                // 3방향      4
                calValue += Cal(j, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal((j + 1) % 4, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal((j + 2) % 4, cctvVec[i].x, cctvVec[i].y, backtracking);
                // j 비어있는 공간
                break;
            case 5:
                // 4방향      1
                calValue += Cal(j, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal((j + 1) % 4, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal((j + 2) % 4, cctvVec[i].x, cctvVec[i].y, backtracking);
                calValue += Cal((j + 3) % 4, cctvVec[i].x, cctvVec[i].y, backtracking);
                break;
            default:
                break;
            }


            //PrintMap();
            //cout << "calValue : " << calValue << '\n';
            DFS(depth + 1, i, sum - calValue);


            for (auto& pos : backtracking) {
                map[pos.first][pos.second] = 0;
            }

        }
    }
}

int main() {

    cin >> n >> m;
    ans = n * m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0) ans--;
            if (1 <= map[i][j] && map[i][j] <= 5) cctvVec.push_back({ map[i][j], j,i});
        }
    }
    cctvNum = cctvVec.size();

    // 모든 경우 탐색
    DFS(0, -1, ans);

    cout << ans << '\n';

    return 0;
}