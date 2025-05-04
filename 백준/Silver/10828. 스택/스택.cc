#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {

    int n ;

    cin >> n;

    stack<int> s;

    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (cmd == "pop") {
            if (s.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << s.top() << '\n';
                s.pop();
            }

        }
        else if (cmd == "size") {
            cout << s.size() << '\n';
        }
        else if (cmd == "empty") {
            if (s.empty()) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (cmd == "top") {
            if (!s.empty()) {
                cout << s.top() << '\n';
            }
            else {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}
