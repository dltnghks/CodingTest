#include <iostream>
#include <vector>
#include <algorithm>

#define INF 10000

using namespace std;

int main(){
   
    int n = 0;
    cin >> n;
    vector<int> map(n);

    for(int i = 0; i < n; i++){
        int a = 0;
        cin >> a;
        map[i] = a;
    }

    vector<int> dp(n, INF);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= map[i]; j++){
            if(i+j >= n) continue;
            dp[i+j] = min(dp[i+j], dp[i] + 1);
        }
    }

    if(dp[n-1] == INF) dp[n-1] = -1;
    cout << dp[n-1];

    return 0;
}