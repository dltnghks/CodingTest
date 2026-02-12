#include <iostream>
#include <vector>

#define INF 1e10

using namespace std;

int n, m;
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
    return tree[cur] = min(MakeTree(childL, left, mid), MakeTree(childR, mid+1, right));    
}

long long Solve(int cur, int left, int right, int targetL, int targetR){
    // 범위 안에 들어오면 그 값을 리턴
    if(targetL <= left && right <= targetR){
        return tree[cur];
    }
    // 완전 범위를 벗어나면 0
    else if(targetL > right || left > targetR){
        return INF;
    }

    long long minVal = 0;
    int mid = (left + right) / 2;
    int childL = cur * 2;
    int childR = cur * 2 + 1;    
    minVal = min(Solve(childL, left, mid, targetL, targetR), Solve(childR, mid+1, right, targetL, targetR));

    return minVal;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    numbers = vector<long long>(n+1);
    tree = vector<long long>(4 * n + 1, INF);

    // 초기 숫자.
    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }

    MakeTree(1, 1, n);

    // 숫자 변경
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        cout << Solve(1, 1, n, a, b) << '\n';
    }

    return 0;
}