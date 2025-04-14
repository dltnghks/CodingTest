#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

int n;
vector<ll> vec;

ll ans = -1;

bool DFS(int index, ll sum, ll target, int depth){

    if(sum > target){
        return false;
    }

    if(depth == 3){
        return sum == target;
    }

    for(int i = index; i >= 0; i--){
        if(DFS(i, sum + vec[i], target, depth+1)){
            return true;
        }
    }
    return false;
}

bool Making(ll num, int index){
    for(int i = index-1; i >= 0; i--){
        if(DFS(i, vec[i], num, 1)){
            return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    // // k번째 수가 최대가 되는 경우
    // // x,y,z로 3갈래로 나눠짐
    // for(int i = 0; i < n; i++){
    //     DFS(i, vec[i], 1);
    // }
    
    // cout << ans << '\n';


    // 역으로 뒤에서부터 만들 수 있는지 확인
    for(int i = n - 1; i >= 0; i--){
        // 만들어지면 종료
        if(Making(vec[i], i)){
            cout << vec[i] << '\n';
            break;
        }
    }

    return 0;
}