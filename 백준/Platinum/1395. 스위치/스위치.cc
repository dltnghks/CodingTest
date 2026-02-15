#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool switchList[100001];
int tree[100000 * 4 + 1];

// 반전된 횟수를 기록
int lazy[100000 * 4 + 1];

void Push(int cur, int left, int right){
    int size = (right - left + 1);
    // 반전횟수가 홀수일 때만 반전
    if((lazy[cur] % 2) != 0)
        tree[cur] = (size - tree[cur]);

    // 자식들은? 반전 횟수 추가
    if(left != right){
        lazy[cur * 2] += lazy[cur];
        lazy[cur * 2 + 1] += lazy[cur];
    }

    // 반전이 끝난 cur은 lazy값을 0으로 설정
    lazy[cur] = 0;
}

void Reverse(int cur, int left, int right, int targetL, int targetR){
    //cout << cur << '\n';
    Push(cur, left, right);

    if(left > targetR || right < targetL){
        return;
    }

    if(left >= targetL && right <= targetR){
        lazy[cur]++;
        Push(cur, left, right);
        return;
    }

    int mid = (left+right) / 2;
    Reverse(cur * 2, left, mid, targetL, targetR);
    Reverse(cur * 2 + 1, mid+1, right, targetL, targetR);
    tree[cur] = tree[cur * 2] + tree[cur * 2 + 1];
}

int Solve(int cur, int left, int right, int targetL, int targetR){
    Push(cur, left, right);

    if(left > targetR || right < targetL){
        return 0;
    }

    if (left >= targetL && right <= targetR) {
        return tree[cur];
    }

    int mid = (left+right) / 2;
    int res = Solve(cur * 2, left, mid, targetL, targetR) + Solve(cur * 2 + 1, mid+1, right, targetL, targetR);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int o, s, t;
        cin >> o >> s >> t;

        int size = t - s + 1;
        // o == 0 s~t 스위치 반전
        if(o == 0){
            Reverse(1, 1, n, s, t);
        }
        // o == 1 s~t 켜져있는 스위치 개수 확인
        else if(o == 1){
            cout << Solve(1, 1, n, s, t) << '\n';
        }
    }

    return 0;
}
