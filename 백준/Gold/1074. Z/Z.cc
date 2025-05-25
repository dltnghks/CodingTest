#include <iostream>
#include <cmath>

using namespace std;

int n, c, r;
int ans = 0;
bool flag = false;

void Solve(int startX, int startY, int size) {

    if (flag) return;

    if ((startY + size <= r) || ((startX + size <= c) && (startY <= r))) {
        ans += (size * size);
        //cout << ans << '\n';
        return;
    }

    if (startX == c && startY == r && !flag) {
        flag = true;
        //cout << ans << '\n';
        return;
    }
    
    
    if(size == 1){
        ans++;
        //cout << ans << '\n';
        return;
    }
    else {
        int newSize = size / 2;
        Solve(startX, startY, newSize);
        Solve(startX + newSize, startY, newSize);
        Solve(startX, startY + newSize, newSize);
        Solve(startX + newSize, startY + newSize, newSize);
    }
}

int main() {

    cin >> n >> r >> c;
    // r - y, c - x
    // n의 위치를 파악
    int startX = 0, startY = 0;

    Solve(0, 0, pow(2, n));

    cout << ans << '\n';

    return 0;
}
