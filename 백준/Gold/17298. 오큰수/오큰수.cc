#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> vec(n);
    vector<int> ans(n, -1);
    stack<int> s;

    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    for(int i = 0; i < n; i++){
        while(!s.empty() && vec[s.top()] < vec[i]){
            ans[s.top()] = vec[i];
            s.pop();
        }
        s.push(i);
    }

    for(int a : ans){
        cout << a << " ";
    }

    return 0;
}