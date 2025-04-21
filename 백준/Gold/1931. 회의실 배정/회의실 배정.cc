#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> timeVec(n);
    for (int i = 0; i < n; i++) {
        cin >> timeVec[i].first >> timeVec[i].second;
    }

    sort(timeVec.begin(), timeVec.end(), compare);

    /*for (auto& t : timeVec) {
        cout << t.first << " , " << t.second << '\n';
    }*/

    int ans = 1;
    int cur = timeVec[0].second;
    for (int i = 1; i < n; i++) {
        if (cur <= timeVec[i].first) {
            cur = timeVec[i].second;
            ans++;
            continue;
        }
    }

    cout << ans << '\n';

    return 0;
}