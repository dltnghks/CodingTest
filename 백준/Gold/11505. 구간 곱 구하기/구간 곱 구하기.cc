#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
long long numbers[1000001];
long long tree[1000001 * 4 + 1];

long long MakeTree(int cur, int left, int right){
    if(left >= right){
        tree[cur] = numbers[left];
        return numbers[left];
    }

    int mid = (left + right) / 2;
    tree[cur] = MakeTree(cur * 2, left , mid) * MakeTree(cur * 2 + 1, mid + 1, right);
    tree[cur] %= 1000000007;
    return tree[cur];
}

long long Change(int cur, int left, int right, int target, int num){

    if(left == target && right == target){
        numbers[left] = num;
        tree[cur] = num;
        return tree[cur];
    }

    if(left >= right){
        return tree[cur];
    }

    if(left > target || right < target){
        return tree[cur];
    }

    int mid = (left + right) / 2;
    tree[cur] = Change(cur * 2, left, mid, target, num) * Change(cur * 2 + 1, mid + 1, right, target, num);
    tree[cur] %= 1000000007;
    return tree[cur];
}

long long Solve(int cur, int left, int right, int targetL, int targetR){
    // 범위 안에 들어오는 경우
    if(targetL <= left && right <= targetR){
        return tree[cur];
    }
    
    // 범위를 벗어나는 경우
    if(left >= right){
        return 1;
    }
    if(left > targetR || right < targetL){
        return 1;
    }

    int mid = (left + right) / 2;
    long long res = Solve(cur * 2, left, mid, targetL, targetR) * Solve(cur * 2 + 1, mid + 1, right, targetL, targetR);
    res %= 1000000007;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }

    MakeTree(1, 1, n);

    for(int i = 0; i < m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 1){
            Change(1, 1, n, b, c);
        }
        else if(a == 2){
            cout << Solve(1, 1, n, b, c) << '\n';
        }


    }


    return 0;
}
