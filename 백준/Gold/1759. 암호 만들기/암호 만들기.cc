#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;

char vowelVec[] = {'a', 'e', 'i', 'o', 'u'};
vector<char> cVec; 
vector<char> ans;

bool Check(){
    int vowelCount = 0;
    int consonantCount = 0;
    for(char& val : ans)
    {
        consonantCount++;
        for(char& vowel : vowelVec){
            if(val == vowel){
                vowelCount++;
                consonantCount--;
                break;
            }
        }
    }

    if(vowelCount >= 1 && consonantCount >= 2){
        return true;
    }

    return false;
            
}

void DFS(int index, int depth){
    
    if(depth == l){
        if(Check()){
            for(char& val : ans)
                cout << val;
            cout << '\n';
        }
        return;
    }

    for(int i = index + 1; i < c; i++){
        ans.push_back(cVec[i]);
        DFS(i, depth+1);
        ans.pop_back();
    }
}

int main() {
    cin >> l >> c;
    
    cVec = vector<char>(c);
    for(auto& input : cVec){
        cin >> input;
    }

    sort(cVec.begin(), cVec.end());

    // 암호에서 증가하는 순서로 배열
    // 모음1, 자음최소 2개로 구성된 순열 찾기
    // 모든 순열을 구하면서 조건에 만족하지 못하면 PASS

    for(int i = 0; i < c; i++){
        ans.push_back(cVec[i]);
        DFS(i, 1);
        ans.pop_back();
    }



    
    return 0;
}