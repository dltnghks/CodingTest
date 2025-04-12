#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int map[65][65];

void Quad(int sx, int ex, int sy, int ey) {
    int snum = map[sy][sx];
    bool pass = false;
    for (int i = sy; i < ey; i++) {
        for (int j = sx; j < ex; j++) {
            if (snum != map[i][j]) {
                cout << "(";
                Quad(sx, (sx+ex)/2, sy, (sy+ey)/2);     // 왼쪽 위     
                Quad((sx+ex)/2, ex, sy, (sy+ey)/2);     // 오른쪽 위   
                Quad(sx, (sx+ex)/2, (sy+ey)/2, ey);     // 왼쪽 아래   
                Quad((sx + ex)/2, ex, (sy+ey)/2, ey);   // 오른쪽 아래
                cout << ")";
                pass = true;
                return;
            }
        }
    }
    cout << snum;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            int num = s[j] - '0';
            map[i][j] = num;
        }
    }
    Quad(0, n, 0, n);
    return 0;
}