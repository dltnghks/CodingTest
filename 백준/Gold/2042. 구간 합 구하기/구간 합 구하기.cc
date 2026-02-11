#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<long long> numbers;
vector<long long> tree;

long long MakeTree(int cur, int left, int right){

    if(left > right){
        return 0;
    }
    if(left == right){
        tree[cur] = numbers[left];
        return numbers[left];
    }

    int mid = (left + right) / 2;
    int childL = cur * 2;
    int childR = cur * 2 + 1; 
    return tree[cur] = MakeTree(childL, left, mid) + MakeTree(childR, mid+1, right);    
}

void Change(int cur, int left, int right, int target, long long diff){

    if(left > target || target > right){
        return;
    }

    int mid = (left + right) / 2;
    int childL = cur * 2;
    int childR = cur * 2 + 1;
    tree[cur] += diff;
        
    if(left != right){
        Change(childL, left, mid, target, diff);
        Change(childR, mid+1, right, target, diff);
    }
}

long long Solve(int cur, int left, int right, int targetL, int targetR){
    // 범위 안에 들어오면 그 값을 리턴
    if(targetL <= left && right <= targetR){
        return tree[cur];
    }
    // 완전 범위를 벗어나면 0
    else if(targetL > right || left > targetR){
        return 0;
    }

    long long sum = 0;
    int mid = (left + right) / 2;
    int childL = cur * 2;
    int childR = cur * 2 + 1;    
    sum = Solve(childL, left, mid, targetL, targetR) + Solve(childR, mid+1, right, targetL, targetR);

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    numbers = vector<long long>(n+1);
    tree = vector<long long>(4 * n + 1);

    // 초기 숫자.
    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }

    MakeTree(1, 1, n);

    // 숫자 변경
    for(int i = 0; i < m+k; i++){
        int a, b;
        long long c;
        cin >> a >> b >> c;
        // a가 1인 경우 변경(b번째 숫자를 c로)
        if(a == 1){
            long long diff = c - numbers[b];
            numbers[b] = c;
            Change(1, 1, n, b, diff);
        }
        // a가 2인 경우 구간 합(b~c) 구하기
        else if(a == 2){
            cout << Solve(1, 1, n, b, c) << '\n';
        }

    }

    return 0;
}