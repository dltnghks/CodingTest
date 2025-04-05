#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;


int n, m;
vector <ll> posVec;
ll res = 0;

ll cal(ll mid) {
    // 거리가 mid일 때, count가 m을 만족하는지 확인
    ll tmp = 1e11;
    int count = 1;
    ll cur = posVec[0];
    for (int i = 1; i < n; i++) {
        if (posVec[i] - cur >= mid) {
            count++;
            tmp = min(tmp, (posVec[i] - cur));
            cur = posVec[i];
        }
    }

    //cout << count << "res : " << res << " tmp : " << tmp <<  '\n';

    // 조건을 만족할 때만 갱신
    if(count >= m)
        res = max(res, tmp);

    return count;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        ll h;
        cin >> h;
        posVec.push_back(h);
    }

    sort(posVec.begin(), posVec.end());

    ll left = 0;                          // 최소 거리
    ll right = posVec[n - 1] - posVec[0]; // 최대 거리
    ll mid = 0;

    while (left <= right) {
        // mid는 거리
        mid = (left + right) / 2;

        ll tmp = cal(mid);
        //cout << "mid : " << mid << ", tmp : " << tmp << '\n';


        // 많이 남으면 거리 더 늘리기
        if (tmp >= m) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << res << '\n';

    return 0;
}