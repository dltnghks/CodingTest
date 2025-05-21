#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    set<string, greater<string>> names;

    for (int i = 0; i < n; i++) {
        string name;
        string enter;
        cin >> name >> enter;

        if (enter == "enter") {
            names.insert(name);
        }
        else if(enter == "leave") {
            names.erase(name);
        }
    }

    for (auto& name : names) {
        cout << name << '\n';
    }
    return 0;
}
