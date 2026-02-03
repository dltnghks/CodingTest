#include <iostream>
#include <cstring>

#define INF 1e9

using namespace std;

int dp[1 << 16];
int graph[16][16];
int n;
int p;

int CountBit(int bit){
    int count = 0;

    while(bit > 0){
        if(bit & 1) count++;
        bit = bit >> 1;
    }

    return count;
}

int solve(int state){
    // 1. 종료 조건: 켜진 발전소가 P개 이상이면 끝
    if(CountBit(state) >= p){
        return 0;
    }

    // 2. 메모이제이션
    if(dp[state] != -1) return dp[state];

    // 3. 로직 수행
    dp[state] = INF;
    
    // (1) 현재 켜져 있는 발전소(i)를 하나 찾는다.
    for(int i = 0; i < n; i++){
        if(!(state & (1 << i))){
            continue;
        }
        // (2) 꺼져 있는 발전소(j)를 찾아서 고친다.
        for(int j = 0; j < n; j++){
            if((state & (1 << j)))
                continue;
            
            // 다음 상태로 이동 (비용 = 현재까지 비용 + i가 j를 고치는 비용)
            int nextCost = solve(state | (1 << j)) + graph[i][j];
            dp[state] = min(dp[state], nextCost);
        }

    }

    return dp[state];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    string s;
    cin >> s;
    int initialState = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'Y'){
            initialState |= (1 << i);
        }
    }
    cin >> p;

    if(CountBit(initialState) > p){
        cout << "0\n";
        return 0;
    }

    if(initialState == 0 && p > 0){
        cout << "-1\n";
        return 0;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(initialState) << '\n';
}