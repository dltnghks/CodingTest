#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[1001][1001]; // 0 s1의 s2 위치, s2의 s1 위치
string s1, s2;

int main(){
    // 입력
    string s1, s2;
    cin >> s1;
    cin >> s2;

    s1 = " "+s1;
    s2 = " "+s2;

    int s1Size = s1.size();
    int s2Size = s2.size();

    // 로직   
    for(int i = 1; i < s1Size; i++){
        for(int j = 1; j < s2Size; j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // 역으로 추적하기
    vector<char> ans;
    int i = s1Size-1, j = s2Size-1;
    while(dp[i][j] != 0){
        if(dp[i][j] == 0){
            break;
        }
        else if(s1[i] == s2[j]){
            ans.push_back(s1[i]);
            i--; 
            j--;
        }
        else{
            if(dp[i-1][j] == dp[i][j]){
                i--;
            }else if(dp[i][j-1] == dp[i][j]){
                j--;
            }
        }
    }
    
    // 출력
    cout << dp[s1Size-1][s2Size-1] << '\n';
    for(int i = ans.size()-1; i >= 0; i--){
        cout << ans[i];
    }

    return 0;

}