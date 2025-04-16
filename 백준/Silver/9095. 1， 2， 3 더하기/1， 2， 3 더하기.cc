#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(int target, int sum, int depth, int& calSum){
    if(sum == target){
        calSum++;
    }
    else if(sum > target){
        return;
    }

    for(int i = 1; i <= 3; i++){
        DFS(target, sum+i, depth+1, calSum);
    }
}

int Cal(int n){
    int calSum = 0;
    DFS(n, 0, 0, calSum);
    return calSum;
}

int main() {
    int t, n;
    cin >> t;

    for(int i = 0; i < t; i++){
        cin >> n;
        cout << Cal(n) << '\n';
    }
 
    return 0;
}