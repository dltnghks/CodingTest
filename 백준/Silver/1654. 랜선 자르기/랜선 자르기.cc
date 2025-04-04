#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int lenVec[100001];
ll k, n;

ll cal(ll size){
    ll sum = 0;
    for(int i = 0; i < k; i++){
        sum += (lenVec[i] / size);
    }
    return sum;
}

int main(){
    cin >> k >> n;
    int max_len = 0; // 최대 길이를 저장할 변수
    for(int i = 0; i < k; i++){
        int len;
        cin >> len;
        lenVec[i] = len;
        max_len = max(max_len, len); // 최대 길이를 갱신
    }

    ll left = 1; // 길이는 최소 1 이상이어야 하므로 left를 1로 설정
    ll right = max_len; // right는 막대기들의 최대 길이로 설정
    ll res = 0;

    while(left <= right){
        ll mid = (left + right) / 2;
        ll tmp = cal(mid);

        if(tmp >= n){ // n개 이상을 만들 수 있다면 더 큰 크기를 찾는다.
            res = max(res, mid);
            left = mid + 1;
        }
        else { // n개를 만들 수 없다면 더 작은 크기를 찾는다.
            right = mid - 1;
        }
    }

    cout << res << '\n';
    return 0;
}
