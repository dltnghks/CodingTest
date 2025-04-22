#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, ans;
        cin >> n;
        ans = 1;

        vector<pair<int, int>> vec(n);
        
        for (int j = 0; j < n; j++) {
            cin >> vec[j].first >> vec[j].second;
        }

        sort(vec.begin(), vec.end());
        
        int min = vec[0].second;
        for (int j = 1; j < n; j++) {
            if (min > vec[j].second) {
                min = vec[j].second;
                ans++;
            }
        }
        cout << ans << '\n';

    }

    return 0;
}