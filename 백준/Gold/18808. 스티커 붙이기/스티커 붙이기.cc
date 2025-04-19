#include <iostream>
#include <vector>

using namespace std;

int board[41][41];
int n, m, k, y, x;
int ans;

vector<vector<int>> Rotate(vector<vector<int>>& sticker) {
    vector<vector<int>> rotateSticker(x+1, vector<int>(y+1, 0));


    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            rotateSticker[j][i] = sticker[y-i+1][j];
        }
    }

    // x, y 변경
    int tmp = x;
    x = y;
    y = tmp;

    /*for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            cout << rotateSticker[i][j];
        }
        cout << '\n';
    }*/

    return rotateSticker;
}

bool Put(vector<vector<int>>& sticker, int pivotX, int pivotY) {
    if (pivotX + x - 1 > m || pivotY + y - 1 > n) return false;

    for (int i = pivotY; i < pivotY+y; i++) {
        for (int j = pivotX; j < pivotX+x; j++) {
            if (sticker[i - pivotY + 1][j - pivotX + 1] == 1 && 
                board[i][j] == 1) {
                return false;
            }
        }
    }

    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            if (sticker[i][j] == 1) {
                board[pivotY+i-1][pivotX+j-1] = 1;
            }
        }
    }
    return true;
}

bool Check(vector<vector<int>>& sticker) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (Put(sticker, j, i)) {
                //cout << j << " ," << i << '\n';
                return true;
            }
        }
    }
    return false;
}

int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        cin >> y >> x;
        vector<vector<int>> sticker(y+1, vector<int>(x+1, 0));
        int sum = 0;
        for (int j = 1; j <= y; j++) {
            for (int k = 1; k <= x; k++) {
                cin >> sticker[j][k];
                if (sticker[j][k] == 1) sum++;
            }
        }

        for (int j = 0; j <= 3; j++) {
            if (Check(sticker)) {// 붙인 경우
                ans += sum;
                //cout << "ans :" << ans << '\n';
               
                break;
            }
            else { // 못 붙이는 경우
                //cout << "Rotate\n";
                sticker = Rotate(sticker);
            }
        }
    }


    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << board[i][j];
        }
        cout << '\n';
    }*/

    cout << ans;

    return 0;
}