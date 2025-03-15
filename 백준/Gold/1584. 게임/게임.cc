#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define SIZE 501
#define DEAD -1
#define DANGEROUS 1
#define INF 1e6
#define CHANGE(a, b) if(a > b) { int tmp = a; a = b; b = tmp; } 

using namespace std;

int main() {

    vector<vector<int>> map(SIZE, vector<int>(SIZE, 0));
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        CHANGE(x1, x2);
        CHANGE(y1, y2);
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                map[k][j] = DANGEROUS;
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        CHANGE(x1, x2);
        CHANGE(y1, y2);
        for (int j = x1; j <= x2; j++) {
            for (int k = y1; k <= y2; k++) {
                map[k][j] = DEAD;
            }
        }
    }

    /*for (int i = 0; i < SIZE; i++) {
        for (int k = 0; k < SIZE; k++) {
            cout << map[i][k] << " ";
        }
        cout << '\n';
    }*/



    int moveX[4] = {-1, 1, 0, 0};
    int moveY[4] = { 0, 0, -1, 1, };

    vector<vector<int>> hpMap(SIZE, vector<int>(SIZE, INF));
    priority_queue<pair<int, pair<int, int>>> pq;
    hpMap[0][0] = 0;
    pq.push({ 0, { 0, 0 } });

    while (!pq.empty()) {
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        int curHP = pq.top().first;
        pq.pop();

        //cout << curX << " , " << curY << " : " << curHP << ", " << hpMap[curY][curX] << '\n';

        if (curX == SIZE - 1 && curY == SIZE - 1) break;
        if (hpMap[curY][curX] < curHP) continue;

       /* for (int i = 0; i < 10; i++) {
            for (int k = 0; k < 10; k++) {
                cout << hpMap[i][k] << " ";
            }
            cout << '\n';
        }*/

        for (int i = 0; i < 4; i++) {
            int nextX = curX + moveX[i];
            int nextY = curY + moveY[i];

            if (nextX >= 0 && nextX < SIZE && nextY >= 0 && nextY < SIZE &&
                map[nextY][nextX] != DEAD && hpMap[nextY][nextX] == INF
                ) {
                int nextHP = curHP;

                if (map[nextY][nextX] == DANGEROUS) nextHP--;

                if (hpMap[nextY][nextX] > nextHP) {
                    hpMap[nextY][nextX] = nextHP;
                    pq.push({ nextHP, { nextX, nextY } });
                }

            }
        }
    }

    
    if (hpMap[SIZE - 1][SIZE - 1] == INF) {
        cout << -1;
    }
    else {
        cout << -hpMap[SIZE - 1][SIZE - 1];
    }


    return 0;
}