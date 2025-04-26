#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

bool Compare(Item& a, Item& b) {
    if (a.weight == b.weight) {
        return a.value> b.value;
    }
    return a.weight < b.weight;
}

int dp[101][100001];

int main() {

    int n, k;
    cin >> n >> k;
    vector<Item> itemVec(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> itemVec[i].weight >> itemVec[i].value;
    }

    sort(itemVec.begin(), itemVec.end(), Compare);


    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            // 현재 무게(j)에서 i번째 아이템을 넣을 수 있는 경우
            if (j >= itemVec[i].weight) {
                dp[i][j] = max(dp[i-1][j], dp[i - 1][j-itemVec[i].weight] + itemVec[i].value);
            }
            // 못 넣는 경우
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }*/

    cout << dp[n][k];

    return 0;
}