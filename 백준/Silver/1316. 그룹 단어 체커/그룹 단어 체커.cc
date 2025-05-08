#include <iostream>

using namespace std;

int main() {
    
    int n;
    cin >> n;

    int ans = n;
    for(int i = 0 ; i < n; i++){
        bool check[28] = {false, };

        string s;
        cin >> s;
        
        char cur = s[0];
        for(char c : s){

            if(check[c - 'a'] == true){
                ans--;
                break;
            }

            if(cur != c){
                check[cur - 'a'] = true;
                cur = c;
            }
        }
    }

    cout << ans;

    return 0;
}