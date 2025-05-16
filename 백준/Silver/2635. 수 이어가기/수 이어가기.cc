#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    // 첫 번째 수 입력
    int n;
    cin >> n;

    int maxVal = 0;
    vector<int> maxVec;
    for(int i = n/2; i <= n; i++){

        int pre = n;
        int cur = i;
        int cnt = 1;
        vector<int> tmpVec;
        tmpVec.push_back(pre);
        tmpVec.push_back(cur);
        while(cur >= 0){
            int tmp = cur;
            cur = pre - cur;
            pre = tmp;  
            if(cur >= 0)        
                tmpVec.push_back(cur);
            cnt++;
        }

        if(maxVal < cnt){
            maxVec.clear();
            for(auto& val : tmpVec){
                maxVec.push_back(val);
            }        
            maxVal = cnt;
        }
    }

    cout << maxVal << '\n';
    for(auto& val : maxVec){
        cout << val << " ";
    }
    
    return 0;
}