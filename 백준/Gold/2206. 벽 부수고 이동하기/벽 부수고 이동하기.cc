#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define INF 1e7

using namespace std;

struct Node {
    int dis;
    int x;
    int y;
    bool broken;
};


int map[1001][1001];
int disMap[1001][1001][2];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j - 1] - '0';
            disMap[i][j][0] = INF;
            disMap[i][j][1] = INF;
        }
    }

    // 1,1 -> n, m | 한개까지 부술 수 있음. 못가면 -1 출력
    queue<Node> q;
    q.push({ 1, 1,1,false});
    disMap[1][1][0] = 1;
    disMap[1][1][1] = 1;

    int moveX[] = {-1, 1, 0, 0};
    int moveY[] = {0, 0, -1, 1};


    while (!q.empty()) {
        Node curNode = q.front();

        //cout << curNode.x << ", " << curNode.y<< " : " << curNode.dis << " and " << curNode.broken << '\n';
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextX = moveX[i] + curNode.x;
            int nextY = moveY[i] + curNode.y;
            bool broken = curNode.broken;
            int curDis = curNode.dis;

            if (0 < nextX && nextX <= m && 0 < nextY && nextY <= n) {
                if (map[nextY][nextX] == 1) {
                    if (broken) continue;
                    broken = true;
                }

                // 갱신될 때만 이동
                if (disMap[nextY][nextX][broken] > curDis + 1) {
                    disMap[nextY][nextX][broken] = curDis + 1;
                    q.push({ curDis + 1, nextX, nextY, broken });
                }
            }

        }

    }

    int res = min(disMap[n][m][0], disMap[n][m][1]);
    if (res == INF) {
        cout << -1;
    }
    else {
        cout << res;
    }

    return 0;
}