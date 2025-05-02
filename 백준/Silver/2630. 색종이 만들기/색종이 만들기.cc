#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans[2] = { 0 };
int map[128][128];

void cal(int sx, int ex, int sy, int ey) {

    int num = map[sy][sx];
    for (int i = sy; i < ey; i++) {
        for (int j = sx; j < ex; j++) {
            if (num != map[i][j]) {
                cal(sx, (sx+ex)/2, sy, (sy + ey) / 2);
                cal((sx + ex) / 2, ex, sy, (sy + ey) / 2);
                cal(sx, (sx + ex) / 2, (sy + ey) / 2, ey);
                cal((sx + ex) / 2, ex, (sy + ey) / 2, ey);
                return;
            }
        }
    }
    ans[num]++;
}


int main() {

    int n;
    
    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    cal(0, n, 0, n);

    cout << ans[0] << '\n' << ans[1] << '\n';

    return 0;
}
