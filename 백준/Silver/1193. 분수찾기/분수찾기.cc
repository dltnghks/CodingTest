#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    
    int x;
    cin >> x;

    int cur = 1;
    int curX = 1;
    int curY = 1;

    bool flag = true;
    while(cur != x){
        if(curX == 1 || curY == 1){
            cur++;
            if(flag) curX++;
            else curY++;
            
            if(cur == x) break;

            flag = !flag;
        }
        
        if(flag){
            curX++;
            curY--;
        }
        else{
            curX--;
            curY++;
        }
        cur++;
    }

    cout << curY << '/' << curX;

    return 0;
}