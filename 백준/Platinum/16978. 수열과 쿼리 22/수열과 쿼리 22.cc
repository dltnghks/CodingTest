#include <iostream>
#include <map>

using namespace std;

int n;
long long numbers[1000001];
map<int, long long> tree[1000001 * 4 + 1];

long long GetValueAtQuery(int cur, int queryIndex){
    auto it = tree[cur].upper_bound(queryIndex);
    if(it == tree[cur].begin()){
        return 0;
    }
    --it;
    return it->second;
}

long long MakeTree(int cur, int left, int right){
    if(left >= right){
        tree[cur][0] = numbers[left];
        return numbers[left];
    }

    int mid = (left+right) / 2;
    long long sum = MakeTree(cur * 2, left, mid) + MakeTree(cur * 2 + 1, mid + 1, right);
    tree[cur][0] = sum;
    return sum;
}

long long Change(int cur, int left, int right, int queryIndex, int target, long long num){
    // 타겟에 도달한 경우
    if(left == target && right == target){
        tree[cur][queryIndex] = num;
        return num;
    }

    // 범위를 벗어나거나 리프노드인 경우 처리
    if((left > target || right < target) || 
        (left >= right))
    {
        return GetValueAtQuery(cur, queryIndex);
    }

    int mid = (left+right) / 2;
    tree[cur][queryIndex] = Change(cur * 2, left, mid, queryIndex, target, num) + Change(cur * 2 + 1, mid + 1, right, queryIndex, target, num);
    return tree[cur][queryIndex];
}

long long Solve(int cur, int left, int right, int queryIndex, int targetL, int targetR){
    // 범위 안에 완전히 들어온 경우
    if((targetL <= left && right <= targetR))
    {
        return GetValueAtQuery(cur, queryIndex);
    }

    // 범위를 벗어난 경우
    if((left > targetR || right < targetL) || (left >= right)){
        return 0;
    }

    int mid = (left+right) / 2;
    long long sum = Solve(cur * 2, left, mid, queryIndex, targetL, targetR) + Solve(cur * 2 + 1, mid + 1, right, queryIndex, targetL, targetR);
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> numbers[i];
    }

    MakeTree(1, 1, n);

    int k = 0;
    int oneQueryCount = 1;
    cin >> k;
    for(int t = 0; t < k; t++){
        int q;
        cin >> q;
        if(q == 1){
            int i;
            long long v;
            cin >> i >> v;
            Change(1, 1, n, oneQueryCount, i, v);
            oneQueryCount++;
        }
        else if(q == 2){
            int k, i, j;
            cin >> k >> i >> j;
            cout << Solve(1, 1, n, k, i, j) << '\n';
        }
    }

    return 0;
}
