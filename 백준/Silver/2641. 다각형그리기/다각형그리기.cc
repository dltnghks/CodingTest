#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int len;
    cin >> len;
    
    vector<int> input(len);
    vector<string> inputVec;
    for(int i = 0; i < len; i++){
        cin >> input[i];
    }

    // 하나씩 땡겨가며 모든 경우 만들기
    for(int i = 0; i < len; i++){
        // 정방향
        string tmp1 = "";
        for(int j = 0; j < len; j++)
        {
            tmp1 += '0' + input[(i + j) % len];
        }
        inputVec.push_back(tmp1);
       
        // 역방향
        string tmp2 = "";
        for(int j = len-1; j >= 0; j--){
            tmp2 += '1' + ((tmp1[j] + 1) % 4);
        }
        inputVec.push_back(tmp2);
       
    }

    int num;
    cin >> num;
    vector<string> ans;
    for(int j = 0; j < num; j++){
        string tmp = "";
        for(int i = 0; i < len; i++){
            int val;
            cin >> val;
            tmp += '0' + val;
        }

        // 비교
        for(string& str : inputVec){
            if(str == tmp){
                ans.push_back(str);
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    
    for(string& str : ans){
        for(char c : str){
            cout << c << " ";
        }
        cout << '\n';
    }

    return 0;
}