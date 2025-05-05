#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

    int n;
    cin >> n;

    stack<int> s;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cur = 0;
    vector<char> ans;
    for (int i = 1; i <= n; i++) {

        s.push(i);
        ans.push_back('+');

        while(!s.empty() && arr[cur] == s.top()) {
            s.pop();
            ans.push_back('-');
            cur++;
        }

    }

    if (s.empty()) {
        for (auto& c : ans) {
            cout << c << '\n';
        }
    }
    else {
        cout << "NO\n";
    }


    return 0;
}
