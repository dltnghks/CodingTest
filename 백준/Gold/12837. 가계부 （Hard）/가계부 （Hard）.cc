#include <iostream>

using namespace std;

long long tree[1000001 * 4];

void Change(int cur, int left, int right, int target, long long num){
    if (target < left || target > right) return;

    tree[cur] += num;

    if (left != right) {
        int mid = (left + right) / 2;
        Change(cur * 2, left, mid, target, num);
        Change(cur * 2 + 1, mid + 1, right, target, num);
    }
}

long long Solve(int cur, int left, int right, int targetL, int targetR){
    if(left > targetR || right < targetL){
        return 0;
    }

    if(targetL <= left && right <= targetR){
        return tree[cur];
    }

    int mid = (left+right) / 2;
    return Solve(cur * 2, left, mid, targetL, targetR) + Solve(cur * 2 + 1, mid+1, right, targetL, targetR);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i < q; i++){
        int input;
        cin >> input;

        if(input == 1){
            int p;
            long long x;
            cin >> p >> x;
            Change(1, 1, n, p, x);
        }
        else if(input == 2){
            int p, q;
            cin >> p >> q;
            cout << Solve(1, 1, n, p, q) << '\n';
        }
    }
    
    return 0;
}
