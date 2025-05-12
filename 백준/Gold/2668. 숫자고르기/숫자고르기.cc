#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    vector<int> ans;
    vector<int> table(n+1);

    for(int i = 1; i <= n; i++){
        cin >> table[i];
        if(i == table[i]) ans.push_back(i);
    }

    vector<int> loopVec;
    vector<bool> visited(n+1, false);
    for(int i = 1; i <= n; i++){
        if(i == table[i] || visited[i]) continue;

        visited[i] = true;
    
        vector<int> tmp;
        tmp.push_back(i);

        int cur = table[i];
        while(!visited[cur]){
            tmp.push_back(cur);
            visited[cur] = true;
            cur = table[cur];
        }

        // 루프가 생긴 경우
        if(cur == i){
            for(int val : tmp){
                loopVec.push_back(val);
            }
        }else{
            for(int val : tmp){
                visited[val] = false;
            }
        }
    }
    
    for(int val : loopVec){
        ans.push_back(val);
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for(int val : ans){
        cout << val << '\n';
    }


    return 0;
}