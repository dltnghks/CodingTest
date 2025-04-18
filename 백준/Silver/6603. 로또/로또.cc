#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> printVec;
int k;

void PrintComb(int depth, int index, vector<int>& numVec)
{
    if(depth == 6){
        for(auto& num : printVec){
            cout << num << " ";
        }
        cout << '\n';
        return;
    }    

    for(int i = index + 1; i < k; i++){
        printVec.push_back(numVec[i]);
        PrintComb(depth+1, i, numVec);
        printVec.pop_back();
    }
    
}

int main() {

    while(true){
        cin >> k;
        
        if(k == 0) {
            return 0;
        }
        
        vector<int> numVec(k);
        for(auto& num : numVec){
            cin >> num;
        }

        PrintComb(0, -1, numVec);

        cout << '\n';
    }
    
    return 0;
}