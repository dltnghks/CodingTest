#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int main() {

    
    int n, m;
    cin >> n >> m;

    vector <ll> hVec;
    ll hMax = 0;
    for (int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        hVec.push_back(h);
        hMax = max(hMax, h);
    }


    ll res = 0;
    ll left = 0;
    ll right = hMax;
    ll hCur = 0;
    ll ans = 0;
    // 이분 탐색으로 진행
    while (left <= right) {

        hCur = (left+right) / 2;
        res = 0;

        for (int i = 0; i < n; i++) {
            res += max((ll)0, hVec[i] - hCur);
        }

        if (res >= m) {
            ans = ans < hCur ? hCur : ans;
        }

        // 부족하면 더 낮은 곳에서 자르기
        if (res < m) {
            right = hCur - 1;
        }
        // 많으면 더 높은 곳에서 자르기
        else{
            left = hCur + 1;
        }

    }

    cout << ans;

    return 0;
}