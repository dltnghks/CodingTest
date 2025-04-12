#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int map[500][500];

int n, m, b;
int maxNum = -1;

// 성공한 애들 확인
vector<bool> ansFail;
// 시간, 높이
vector<pair<int, int>> ans;

// 블럭 제거는 2초
// 블럭 설치는 1초
// 땅높이 최대 256

void cal(int num) {
    int sum = 0;
    int countB = b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] > num) {
                // 큰 경우 제거
                sum += (map[i][j] - num) * 2;
                countB += (map[i][j] - num);
            }
            else if (map[i][j] < num) {
                // 작은 경우 설치
                int tmpB = (num - map[i][j]);
                sum += tmpB;
                countB -= tmpB;

                
            }
        }
    }
    if (countB < 0) {
        ans[num] = { INT_MAX, INT_MAX };
    }
    else {
        ans[num] = { sum, num };
    }
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}


int main() {
    cin >> n >> m >> b;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            map[i][j] = num;
            maxNum = max(maxNum, num);
        }
    }
    ansFail = vector<bool>(maxNum + 1);
    ans = vector<pair<int, int>>(maxNum + 1);


    for (int i = 0; i <= maxNum; i++) {
        cal(i);
    }

    sort(ans.begin(), ans.end(), compare);

    cout << ans[0].first << " " << ans[0].second;


    return 0;
}