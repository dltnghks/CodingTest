#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    // 입력
    int n, l;
    cin >> n >> l;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 로직
    vector<int> ans(n);
    // 인덱스만 저장하기
    deque<int> minValIndexDeque;

    // A[i - l + 1] ~ A[i] 중 최솟값 찾기
    for(int i = 0; i < n; i++){

        if(!minValIndexDeque.empty() && minValIndexDeque.front() <= i - l){
            minValIndexDeque.pop_front();
        }

        while(!minValIndexDeque.empty() && arr[minValIndexDeque.back()] >= arr[i]){
            minValIndexDeque.pop_back();
        }
        minValIndexDeque.push_back(i);

        ans[i] = arr[minValIndexDeque.front()];
    }

    // 출력
    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}