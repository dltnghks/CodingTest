#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> wVec;

int main() {

    int n;
    cin >> n;

    wVec = vector<int>(n);

    for (int i = 0; i < n; i++) {
        cin >> wVec[i];
    }

    sort(wVec.begin(), wVec.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int tmp = wVec[i] * (n - i);
        ans = max(ans, tmp);
    }
    cout << ans << '\n';

    return 0;
}