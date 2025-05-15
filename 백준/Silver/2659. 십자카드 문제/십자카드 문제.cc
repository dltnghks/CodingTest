#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>

#define SIZE 4

using namespace std;

int GetClockNum(vector<int>& vec){
    int minNum = 9999;
    for(int i = 0; i < SIZE; i++){
        int makeNum = 0;
        makeNum += vec[i] * 1000;
        makeNum += vec[(i+1) % SIZE] * 100;
        makeNum += vec[(i+2) % SIZE] * 10;
        makeNum += vec[(i+3) % SIZE];
        
        minNum = min(minNum, makeNum);
    }
    return minNum;
}

int main() {

    vector<int> num(SIZE);
    for(int i = 0; i < SIZE; i++){
        cin >> num[i];
    }


    set<int> clockNum;
    stack<vector<int>> s;
    s.push(vector<int>());
    while(!s.empty()){
        vector<int> cur = s.top();
        int curSize = cur.size();
        s.pop();

        if(curSize == 4){
            clockNum.insert(GetClockNum(cur));
            continue;
        }

        for(int i = 1; i <= 9; i++){
            vector<int> newVec(cur);
            newVec.push_back(i);
            s.push(newVec);
        }
    }

    int minNum = GetClockNum(num);


    int index = 0;
    for(int n : clockNum){
        if(n == minNum){
            cout << index+1;
            break;
        }
        index++;
    }
    
    
    return 0;
}