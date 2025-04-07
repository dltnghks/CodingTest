#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int n;

string ans = "";

// s -> e로 넘기는 함수
void Hanoi(int s, int m, int e, int n){
    if(n == 1) {
        // s -> e로 이동
        string moveS = std::to_string(s) + " " + std::to_string(e) + "\n";
        ans += moveS;
        return;
    }
    Hanoi(s, e, m, n-1);
    Hanoi(s, m, e, 1);
    Hanoi(m, s, e, n-1);
}

int num[100];
void CalNum(){

    int cnt = 1;
    num[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= cnt; j++){
            num[j] *= 2;
        }

        for(int j = 1; j <= cnt; j++){
            if(j == 1){
                num[j]++;
            }

            if(num[j] >= 10){
                num[j] -= 10;
                num[j+1]++;
                if(j+1 > cnt) cnt++;
            }
        }
    }

    for(int i = cnt; i >= 1; i--){
        std::cout << num[i];
    }
    std::cout << '\n';
}

int main(){
    cin >> n;
    
    CalNum();

    if(n <= 20){
        Hanoi(1, 2, 3, n);
        cout << ans;
    }

    return 0;
}
