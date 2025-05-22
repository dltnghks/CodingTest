#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main() {

    int k, l;
    cin >> k >> l;

    map<string, int> studentsCount;
    vector<string> students(l);
    vector<string> ans;

    for (int i = 0; i < l; i++) {
        cin >> students[i];
        if (studentsCount[students[i]]) {
            studentsCount[students[i]]++;
        }
        else {
            studentsCount[students[i]] = 1;
        }
    }

    for (auto& student : students) {
        if (ans.size() == k) break;

        if (studentsCount[student] == 1) {
            ans.push_back(student);
        }
        studentsCount[student]--;
    }

    for (auto& student : ans) {
        cout << student << '\n';
    }
    return 0;
}
