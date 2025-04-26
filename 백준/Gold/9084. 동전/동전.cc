#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        
        int dp[10001][21] = { 0, };
        int n, m;
        cin >> n;
        vector<int> coin(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> coin[i];
            dp[coin[i]][i] = 1;
        }

        cin >> m;

        for (int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++){
                if (i >= coin[j]) {
                    dp[i][j] += (dp[i - coin[j]][j]+dp[i][j-1]);
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }

        /*for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                cout << dp[i][j] << ' ';
            }
            cout << '\n';
        }*/


        cout << dp[m][n] << '\n';

    }
    return 0;
}