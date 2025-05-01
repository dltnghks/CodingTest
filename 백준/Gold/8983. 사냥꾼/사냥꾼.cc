#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int BinarySearch(vector<int>& shootingPos, int target) {
    int start = 0;
    int end = shootingPos.size() - 1;
    int best = shootingPos[0];
    int minDist = abs(best - target);

    while (start <= end) {
        int mid = (start + end) / 2;
        int curDist = abs(shootingPos[mid] - target);

        if (curDist < minDist) {
            minDist = curDist;
            best = shootingPos[mid];
        }
        else if (curDist == minDist && shootingPos[mid] < best) {
            best = shootingPos[mid];  // tie-breaker: 작은 쪽
        }

        if (shootingPos[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    return best;
}


int GetDist(pair<int, int> a, int b) {
    return abs(a.first - b) + a.second;
}

int main() {

    int m, n, l, ans;
    cin >> m >> n >> l;

    // 일단 모든 동물
    ans = n;

    vector<int> shootingPos(m);
    vector<pair<int, int>> animalPos(n);

    for (int i = 0; i < m; i++) {
        cin >> shootingPos[i];
    }
    sort(shootingPos.begin(), shootingPos.end());

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        animalPos[i] = { x,y };
    }
    sort(animalPos.begin(), animalPos.end());

    for (int i = 0; i < n; i++) {
        // 이진 탐색으로 가장 가까운 사대 찾기
        int closePos = BinarySearch(shootingPos, animalPos[i].first);
        // 거리 계산해서 조건 만족하는지 확인하기
        if (GetDist(animalPos[i], closePos) > l) {
            ans--;
        }
    }

    cout << ans;

    return 0;
}
